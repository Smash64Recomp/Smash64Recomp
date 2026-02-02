#include "smash64_config.h"
#include "recompui/recompui.h"
#include "recompui/config.h"
#include "recompinput/recompinput.h"
#include "recompinput/profiles.h"
#include "smash64_sound.h"
#include "smash64_support.h"
#include "ultramodern/config.hpp"
#include "librecomp/files.hpp"
#include "librecomp/config.hpp"
#include "util/file.h"
#include <filesystem>
#include <fstream>
#include <iomanip>

#if defined(_WIN32)
#include <Shlobj.h>
#elif defined(__linux__)
#include <unistd.h>
#include <pwd.h>
#elif defined(__APPLE__)
#include "apple/rt64_apple.h"
#endif

static void add_general_options(recomp::config::Config &config) {
    using EnumOptionVector = const std::vector<recomp::config::ConfigOptionEnumOption>;



}

template <typename T = uint32_t>
T get_general_config_enum_value(const std::string& option_id) {
    return static_cast<T>(std::get<uint32_t>(recompui::config::get_general_config().get_option_value(option_id)));
}

template <typename T = uint32_t>
T get_general_config_number_value(const std::string& option_id) {
    return static_cast<T>(std::get<double>(recompui::config::get_general_config().get_option_value(option_id)));
}


template <typename T = uint32_t>
T get_graphics_config_enum_value(const std::string& option_id) {
    return static_cast<T>(std::get<uint32_t>(recompui::config::get_graphics_config().get_option_value(option_id)));
}

static void add_sound_options(recomp::config::Config &config) {
    config.add_percent_number_option(
        smash64::configkeys::sound::bgm_volume,
        "Background Music Volume",
        "Controls the overall volume of background music.",
        100.0f
    );
}
template <typename T = uint32_t>
T get_sound_config_number_value(const std::string& option_id) {
    return static_cast<T>(std::get<double>(recompui::config::get_sound_config().get_option_value(option_id)));
}

int smash64::get_bgm_volume() {
    return get_sound_config_number_value<int>(smash64::configkeys::sound::bgm_volume);
}

static void add_graphics_options(recomp::config::Config &config) {
    using EnumOptionVector = const std::vector<recomp::config::ConfigOptionEnumOption>;
    static EnumOptionVector cutscene_aspect_ratio_mode_options = {
        {smash64::CutsceneAspectRatioMode::Original, "Original", "Original"},
        {smash64::CutsceneAspectRatioMode::Clamp16x9, "Clamp16x9", "16:9"},
        {smash64::CutsceneAspectRatioMode::Full, "Expand", "Expand"},
    };

}

static void set_control_defaults() {
    using namespace recompinput;

    // Left shoulder -> C Down | Backwards eggs / zoom out
    set_default_mapping_for_controller(
        GameInput::C_DOWN,
        { 
            InputField::controller_analog(SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_RIGHTY, true),
            InputField::controller_digital(SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_LEFTSHOULDER)
        }
    );

    // Right shoulder -> C Up | Forwards eggs / first person
    set_default_mapping_for_controller(
        GameInput::C_UP,
        { 
            InputField::controller_analog(SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_RIGHTY, false),
            InputField::controller_digital(SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_RIGHTSHOULDER)
        }
    );

    // North button -> C Left | Talon trot / camera left
    set_default_mapping_for_controller(
        GameInput::C_LEFT,
        { 
            InputField::controller_analog(SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_RIGHTX, false),
            InputField::controller_digital(SDL_CONTROLLER_BUTTON_NORTH)
        }
    );

    // East button -> C Right | Wonderwing / camera right
    set_default_mapping_for_controller(
        GameInput::C_RIGHT,
        { 
            InputField::controller_analog(SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_RIGHTX, true),
            InputField::controller_digital(SDL_CONTROLLER_BUTTON_EAST)
        }
    );

    // R3 -> L | Unused in BK but can be used in mods
    set_default_mapping_for_controller(GameInput::L, { InputField::controller_digital(SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_RIGHTSTICK) });
}

static void set_control_descriptions() {
    recompinput::set_game_input_description(recompinput::GameInput::Y_AXIS_POS, "Used to move and for steering while flying and swimming. Axis inversion for flying and swimming can be configured in the General tab.");
    recompinput::set_game_input_description(recompinput::GameInput::Y_AXIS_NEG, "Used to move and for steering while flying and swimming. Axis inversion for flying and swimming can be configured in the General tab.");
    recompinput::set_game_input_description(recompinput::GameInput::X_AXIS_NEG, "Used to move and for steering while flying and swimming. Axis inversion for flying and swimming can be configured in the General tab.");
    recompinput::set_game_input_description(recompinput::GameInput::X_AXIS_POS, "Used to move and for steering while flying and swimming. Axis inversion for flying and swimming can be configured in the General tab.");
    recompinput::set_game_input_description(recompinput::GameInput::A, "Used to jump and select options in menus. Also used for flying upwards.");
    recompinput::set_game_input_description(recompinput::GameInput::B, "Used for attacks, which change depending on whether you are stationary, moving, in the air, or crouching.");
    recompinput::set_game_input_description(recompinput::GameInput::Z, "Used to crouch, which enables A, B and the C-Buttons to perform different actions.");
    recompinput::set_game_input_description(recompinput::GameInput::L, "Unused. Mods may use it for additional features.");
    recompinput::set_game_input_description(recompinput::GameInput::R, "Used to center the camera behind Smash64 on the ground, and to perform tighter turns while flying or swimming.");
    recompinput::set_game_input_description(recompinput::GameInput::START, "Used for pausing and for skipping certain cutscenes.");
    recompinput::set_game_input_description(recompinput::GameInput::C_UP, "Used to enter first-person mode, and to shoot eggs while holding Z.");
    recompinput::set_game_input_description(recompinput::GameInput::C_DOWN, "Used to toggle between the different camera zoom levels, and to shoot eggs backwards while holding Z.");
    recompinput::set_game_input_description(recompinput::GameInput::C_LEFT, "Used to rotate the camera sideways. Axis inversion can be configured in the General tab. Also used to enter Talon Trot while holding Z.");
    recompinput::set_game_input_description(recompinput::GameInput::C_RIGHT, "Used to rotate the camera sideways. Axis inversion can be configured in the General tab). Also used to enter Wonderwing while holding Z.");
    recompinput::set_game_input_description(recompinput::GameInput::DPAD_UP, "Unused. Mods may use it for additional features.");
    recompinput::set_game_input_description(recompinput::GameInput::DPAD_DOWN, "Unused. Mods may use it for additional features.");
    recompinput::set_game_input_description(recompinput::GameInput::DPAD_LEFT, "Unused. Mods may use it for additional features.");
    recompinput::set_game_input_description(recompinput::GameInput::DPAD_RIGHT, "Unused. Mods may use it for additional features.");
}

smash64::CutsceneAspectRatioMode smash64::get_cutscene_aspect_ratio_mode() {
    return get_graphics_config_enum_value<smash64::CutsceneAspectRatioMode>(smash64::configkeys::graphics::cutscene_aspect_ratio_mode);
}

void smash64::init_config() {
    std::filesystem::path recomp_dir = recompui::file::get_app_folder_path();

    if (!recomp_dir.empty()) {
        std::filesystem::create_directories(recomp_dir);
    }

    recompui::config::GeneralTabOptions general_options{};
    general_options.has_rumble_strength = true;
    general_options.has_gyro_sensitivity = false;
    general_options.has_mouse_sensitivity = false;

    auto &general_config = recompui::config::create_general_tab(general_options);
    add_general_options(general_config);

    auto &graphics_config = recompui::config::create_graphics_tab();
    add_graphics_options(graphics_config);

    set_control_defaults();
    set_control_descriptions();
    recompui::config::create_controls_tab();

    auto &sound_config = recompui::config::create_sound_tab();
    add_sound_options(sound_config);

    recompui::config::create_mods_tab();

    recompui::config::finalize();
    
    // Load saved controller profiles after config is initialized
    std::filesystem::path controls_config_path = recomp_dir / "controls.json";
    if (std::filesystem::exists(controls_config_path)) {
        recompinput::profiles::load_controls_config(controls_config_path);
    }
}
