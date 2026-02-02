#ifndef __SMASH64_CONFIG_H__
#define __SMASH64_CONFIG_H__

#include <filesystem>
#include <string>
#include <string_view>

#include "json/json.hpp"

namespace smash64 {
    inline const std::u8string program_id = u8"Smash64Recompiled";
    inline const std::string program_name = "Smash64: Recompiled";

    namespace configkeys {
        namespace general {
        }

        namespace sound {
            inline const std::string bgm_volume = "bgm_volume";
        }

        namespace graphics {
            inline const std::string cutscene_aspect_ratio_mode = "cutscene_aspect_ratio_mode";
        }
    }

    // TODO: Move loading configs to the runtime once we have a way to allow per-project customization.
    void init_config();

    enum class CameraInvertMode {
        InvertNone,
        InvertX,
        InvertY,
        InvertBoth
    };

    CameraInvertMode get_camera_invert_mode();

    CameraInvertMode get_third_person_camera_mode();

    CameraInvertMode get_flying_and_swimming_invert_mode();

    CameraInvertMode get_first_person_invert_mode();

    enum class AnalogCamMode {
        On,
        Off,
        OptionCount
    };

    AnalogCamMode get_analog_cam_mode();

    uint32_t get_analog_cam_sensitivity();



    enum class CutsceneAspectRatioMode {
        Original,
        Clamp16x9,
        Full,
        OptionCount
    };

    CutsceneAspectRatioMode get_cutscene_aspect_ratio_mode();

    void open_quit_game_prompt();
}

// JSON serialization macros must be placed OUTSIDE the namespace
NLOHMANN_JSON_SERIALIZE_ENUM(smash64::AnalogCamMode, {
    {smash64::AnalogCamMode::On, "On"},
    {smash64::AnalogCamMode::Off, "Off"}
});



#endif
