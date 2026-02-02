#include "smash64_launcher.h"
#include <atomic>
#include <random>

struct KeyframeRot {
    float seconds;
    float deg;
};

struct Keyframe2D {
    float seconds;
    float x;
    float y;
};

enum class InterpolationMethod {
    Linear,
    Smootherstep
};

struct AnimationData {
    uint32_t keyframe_index = 0;
    uint32_t loop_keyframe_index = UINT32_MAX;
    float seconds = 0.0f;
    InterpolationMethod interpolation_method = InterpolationMethod::Linear;
};

struct AnimatedSvg {
    recompui::Element *svg = nullptr;
    std::vector<Keyframe2D> position_keyframes;
    std::vector<Keyframe2D> scale_keyframes;
    std::vector<KeyframeRot> rotation_keyframes;
    AnimationData position_animation;
    AnimationData scale_animation;
    AnimationData rotation_animation;
    float width = 0;
    float height = 0;
};

struct LauncherContext {
    AnimatedSvg logo_svg;
    AnimatedSvg SmashBros_svg;
    std::array<AnimatedSvg, 7> symbol_svgs;
    recompui::Element *wrapper;
    float wrapper_phase = -1.0f;
    std::chrono::steady_clock::time_point last_update_time;
    float seconds = 0.0f;
    bool started = false;
    bool options_enabled = false;
    bool animation_skipped = false;
    std::atomic<bool> skip_animation_next_update = false;
} launcher_context;

float interpolate_value(float a, float b, float t, InterpolationMethod method) {
    switch (method) {
    case InterpolationMethod::Smootherstep:
        return a + (b - a) * (t * t * t * (t * (t * 6.0f - 15.0f) + 10.0f));
    case InterpolationMethod::Linear:
    default:
        return a + (b - a) * t;
    }
}

void calculate_rot_from_keyframes(const std::vector<KeyframeRot> &kf, AnimationData &an, float delta_time, float &deg) {
    if (kf.empty()) {
        return;
    }

    an.seconds += delta_time;

    while ((an.keyframe_index < (kf.size() - 1) && (an.seconds >= kf[an.keyframe_index + 1].seconds))) {
        an.keyframe_index++;
    }

    if (an.keyframe_index >= (kf.size() - 1)) {
        deg = kf[an.keyframe_index].deg;
    }
    else {
        float t = (an.seconds - kf[an.keyframe_index].seconds) / (kf[an.keyframe_index + 1].seconds - kf[an.keyframe_index].seconds);
        deg = interpolate_value(kf[an.keyframe_index].deg, kf[an.keyframe_index + 1].deg, t, an.interpolation_method);
    }
}

void calculate_2d_from_keyframes(const std::vector<Keyframe2D> &kf, AnimationData &an, float delta_time, float &x, float &y) {
    if (kf.empty()) {
        return;
    }

    an.seconds += delta_time;

    while ((an.keyframe_index < (kf.size() - 1) && (an.seconds >= kf[an.keyframe_index + 1].seconds))) {
        an.keyframe_index++;
    }

    if ((an.loop_keyframe_index != UINT32_MAX) && (an.keyframe_index >= (kf.size() - 1))) {
        an.seconds = kf[an.loop_keyframe_index].seconds + (an.seconds - kf[an.keyframe_index].seconds);
        an.keyframe_index = an.loop_keyframe_index;
    }

    if (an.keyframe_index >= (kf.size() - 1)) {
        x = kf[an.keyframe_index].x;
        y = kf[an.keyframe_index].y;
    }
    else {
        float t = (an.seconds - kf[an.keyframe_index].seconds) / (kf[an.keyframe_index + 1].seconds - kf[an.keyframe_index].seconds);
        x = interpolate_value(kf[an.keyframe_index].x, kf[an.keyframe_index + 1].x, t, an.interpolation_method);
        y = interpolate_value(kf[an.keyframe_index].y, kf[an.keyframe_index + 1].y, t, an.interpolation_method);
    }
}

AnimatedSvg create_animated_svg(recompui::ContextId context, recompui::Element *parent, const std::string &svg_path, float width, float height) {
    AnimatedSvg animated_svg;
    animated_svg.width = width;
    animated_svg.height = height;
    animated_svg.svg = context.create_element<recompui::Svg>(parent, svg_path);
    animated_svg.svg->set_position(recompui::Position::Absolute);
    animated_svg.svg->set_width(width, recompui::Unit::Dp);
    animated_svg.svg->set_height(height, recompui::Unit::Dp);
    return animated_svg;
}

void update_animated_svg(AnimatedSvg &animated_svg, float delta_time, float bg_width, float bg_height) {
    float position_x = 0.0f, position_y = 0.0f;
    float scale_x = 1.0f, scale_y = 1.0f;
    float rotation_degrees = 0.0f;
    calculate_2d_from_keyframes(animated_svg.position_keyframes, animated_svg.position_animation, delta_time, position_x, position_y);
    calculate_2d_from_keyframes(animated_svg.scale_keyframes, animated_svg.scale_animation, delta_time, scale_x, scale_y);
    calculate_rot_from_keyframes(animated_svg.rotation_keyframes, animated_svg.rotation_animation, delta_time, rotation_degrees);
    animated_svg.svg->set_translate_2D(position_x + bg_width / 2.0f - animated_svg.width / 2.0f, position_y + bg_height / 2.0f - animated_svg.height / 2.0f);
    animated_svg.svg->set_scale_2D(scale_x, scale_y);
    animated_svg.svg->set_rotation(rotation_degrees);
}

bool check_skip_input(SDL_Event* event) {
    switch (event->type) {
    case SDL_KEYDOWN:
        return event->key.keysym.scancode == SDL_SCANCODE_ESCAPE ||
            event->key.keysym.scancode == SDL_SCANCODE_SPACE ||
            (event->key.keysym.scancode == SDL_SCANCODE_RETURN && (event->key.keysym.mod & (KMOD_LALT | KMOD_RALT)) == KMOD_NONE);
    case SDL_CONTROLLERBUTTONDOWN:
    case SDL_MOUSEBUTTONDOWN:
        return true;
    default:
        return false;
    }
}

int launcher_event_watch(void* userdata, SDL_Event* event) {
    if (!launcher_context.animation_skipped && check_skip_input(event)) {
        launcher_context.animation_skipped = true;
        launcher_context.skip_animation_next_update = true;
        return 0;
    }
    else {
        return 1;
    }
}


const float animation_skip_time = 10.0f;

void smash64::launcher_animation_setup(recompui::LauncherMenu* menu) {
    auto context = recompui::get_current_context();

    menu->set_launcher_background_svg("background.svg");


    menu->set_background_color({ 0x9b, 0xa3, 0xcc, 0xFF });

    recompui::Element* background_container = menu->get_background_container();
    background_container->set_background_color({ 0x00, 0x00, 0x00, 0x00 });

    launcher_context.wrapper = context.create_element<recompui::Element>(background_container, 0);
    launcher_context.wrapper->set_position(recompui::Position::Absolute);
    launcher_context.wrapper->set_width(100, recompui::Unit::Percent);
    launcher_context.wrapper->set_height(100, recompui::Unit::Percent);
    launcher_context.wrapper->set_top(0);
    launcher_context.wrapper->set_background_color({ 0x00, 0x00, 0x00, 0x00 });

    // Disable and hide the options.
    for (auto option : menu->get_game_options_menu()->get_options()) {
        option->set_font_family("ITC Kabel Std");  // Try the filename without extension
        option->set_enabled(false);
        option->set_opacity(0.0f);
        option->set_padding(24.0f);
        auto label = option->get_label();
        label->set_font_size(60.0f);
        label->set_letter_spacing(4.0f);
    }


    launcher_context.symbol_svgs[0] = create_animated_svg(context, background_container, "Symbol1.svg", 200.0f, 200.0f);
    launcher_context.symbol_svgs[1] = create_animated_svg(context, background_container, "Symbol2.svg", 200.0f, 200.0f);
    launcher_context.symbol_svgs[2] = create_animated_svg(context, background_container, "Symbol3.svg", 295.0f, 295.0f);
    launcher_context.symbol_svgs[3] = create_animated_svg(context, background_container, "Symbol4.svg", 230.0f, 230.0f);
    launcher_context.symbol_svgs[4] = create_animated_svg(context, background_container, "Symbol5.svg", 120.0f, 120.0f);
    launcher_context.symbol_svgs[5] = create_animated_svg(context, background_container, "Symbol6.svg", 205.0f, 205.0f);
    launcher_context.symbol_svgs[6] = create_animated_svg(context, background_container, "Symbol7.svg", 200.0f, 200.0f);

    launcher_context.SmashBros_svg = create_animated_svg(context, background_container, "SmashBros.svg", 6187.0f * 0.125f, 6187.0f * 0.125f);


    launcher_context.SmashBros_svg.position_keyframes = {
        { 0.0f, 0.0f, 0.0f },
        { 0.75f, 0.0f, 0.0f },
        { 1.5f, -480.0f, 0.0f },
        { 3.0f, -480.0f, -5.0f },
        { 5.0f, -480.0f, 5.0f },
        { 7.0f, -480.0f, -5.0f },
    };

    launcher_context.SmashBros_svg.scale_keyframes = {
        { 0.0f, 0.0f, 0.0f },
        { 0.75f, 1.2f, 1.2f },
        { 1.5f, 1.2f, 1.2f },
    };

    launcher_context.SmashBros_svg.position_animation.interpolation_method = InterpolationMethod::Smootherstep;
    launcher_context.SmashBros_svg.position_animation.loop_keyframe_index = 3; // Loop from the floating keyframes
    launcher_context.SmashBros_svg.scale_animation.interpolation_method = InterpolationMethod::Smootherstep;

    launcher_context.logo_svg = create_animated_svg(context, background_container, "Logo.svg", 6187.0f * 0.125f, 6187.0f * 0.125f);


    launcher_context.logo_svg.position_keyframes = {
        { 0.0f, 405.0f, -900.0f },
        { 1.5f, 405.0f, -900.0f },
        { 2.5f, 405.0f, -270.0f },
    };

    launcher_context.logo_svg.scale_keyframes = {
        { 0.0f, 1.0f, 1.0f },     
        { 2.5f, 1.0f, 1.0f },
    };

    launcher_context.logo_svg.position_animation.interpolation_method = InterpolationMethod::Smootherstep;




    const float symbol_scale_duration = 0.3f;
    const float breathe_period = 8.0f;     
    const float breathe_amount = 0.10f;

    const float base_appear = 1.8f;


    std::array<std::pair<float, float>, 7> bases = { {
        {  720.0f, -480.0f },   // 0: top-right
        { -680.0f,  380.0f },   // 1: bottom-left
        { -620.0f, -320.0f },   // 2: top-left
        {  750.0f,  420.0f },   // 3: bottom-right
        {  690.0f, -100.0f },   // 4: right upper-middle
        { -30.0f,  280.0f },   // 5: left lower-middle
        {    0.0f, -420.0f },   // 6: top-center
    } };

    std::array<float, 7> staggers = { 0.0f, 0.4f, 0.8f, 1.2f, 1.6f, 2.0f, 2.4f };

    for (size_t i = 0; i < launcher_context.symbol_svgs.size(); ++i) {
        float px = bases[i].first;
        float py = bases[i].second;
        float appear = base_appear + staggers[i];

        launcher_context.symbol_svgs[i].position_keyframes = {
                { appear - 0.01f, px, py },
                { appear,         px, py },
        };

        launcher_context.symbol_svgs[i].scale_keyframes = {
            { 0.0f,                           0.0f,  0.0f  },
            { appear - 0.05f,                 0.0f,  0.0f  },
            { appear + symbol_scale_duration, 1.0f,  1.0f  },
            { appear + symbol_scale_duration + 0.1f, 1.0f,  1.0f  },
            { appear + symbol_scale_duration + breathe_period * 0.25f, 1.0f + breathe_amount, 1.0f + breathe_amount },
            { appear + symbol_scale_duration + breathe_period * 0.75f, 1.0f - breathe_amount, 1.0f - breathe_amount },
            { appear + symbol_scale_duration + breathe_period,         1.0f,  1.0f  },
        };


        launcher_context.symbol_svgs[i].position_animation.loop_keyframe_index = 0;
        launcher_context.symbol_svgs[i].position_animation.interpolation_method = InterpolationMethod::Smootherstep;
        launcher_context.symbol_svgs[i].scale_animation.interpolation_method = InterpolationMethod::Smootherstep;
    }

    SDL_AddEventWatch(&launcher_event_watch, nullptr);
}

void smash64::launcher_animation_update(recompui::LauncherMenu* menu) {
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    float delta_time = launcher_context.started ? std::chrono::duration_cast<std::chrono::milliseconds>(now - launcher_context.last_update_time).count() / 1000.0f : 0.0f;
    if (launcher_context.skip_animation_next_update) {
        delta_time = std::max(animation_skip_time - launcher_context.seconds, 0.0f);
        launcher_context.skip_animation_next_update = false;
    }

    launcher_context.seconds += delta_time;
    launcher_context.last_update_time = now;
    launcher_context.started = true;

    recompui::Element* background_container = menu->get_background_container();
    float dp_to_pixel_ratio = background_container->get_dp_to_pixel_ratio();
    float bg_width = background_container->get_client_width() / dp_to_pixel_ratio;
    float bg_height = background_container->get_client_height() / dp_to_pixel_ratio;
    
    update_animated_svg(launcher_context.SmashBros_svg, delta_time, bg_width, bg_height);
    update_animated_svg(launcher_context.logo_svg, delta_time, bg_width, bg_height);

    for (size_t i = 0; i < launcher_context.symbol_svgs.size(); i++) {
        update_animated_svg(launcher_context.symbol_svgs[i], delta_time, bg_width, bg_height);
    }

    // Enable buttons after all animations complete
    const float button_show_time = 3.0f;
    if (!launcher_context.options_enabled && launcher_context.seconds >= button_show_time) {
        SDL_DelEventWatch(&launcher_event_watch, nullptr);

        for (auto option : menu->get_game_options_menu()->get_options()) {
            option->set_enabled(true);
            option->set_opacity(1.0f);
        }

        launcher_context.options_enabled = true;
    }
}










