/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Module.h"

namespace WPEFramework
{
    namespace Exchange
    {
        enum Modifier : uint32_t {
            NONE = 0 /* @text NONE */,
            CTRL = 1 /* @text CTRL */,
            ALT = 2 /* @text ALT */,
            ALT_CTRL = 3 /* @text ALT_CTRL */,
            SHIFT = 4 /* @text SHIFT */,
            SHIFT_CTRL = 5 /* @text SHIFT_CTRL */,
            SHIFT_ALT = 6 /* @text SHIFT_ALT */,
            SHIFT_ALT_CTRL = 7 /* @text SHIFT_ALT_CTRL */
        };

        enum RemoteKeyCode : uint32_t {
            KED_MENU = 102 /* @text KED_MENU */,              /* KEY_HOME */
            KED_GUIDE = 102 /* @text KED_GUIDE */,             /* KEY_HOME */
            KED_INFO = 67 /* @text KED_INFO */,               /* KEY_F9 */
            KED_STAR = 64 /* @text KED_STAR */,               /* KEY_F6 */
            KED_TVPOWER = 59 /* @text KED_TVPOWER */,            /* KEY_F1 */
            KED_INPUTKEY = 185 /* @text KED_INPUTKEY */,          /* KEY_F15 */
            KED_OK = 352 /* @text KED_OK */,                /* KEY_OK */
            KED_SELECT = 28 /* @text KED_SELECT */,             /* KEY_ENTER */
            KED_ENTER = 28 /* @text KED_ENTER */,              /* KEY_ENTER */
            KED_EXIT = 1 /* @text KED_EXIT */,                /* KEY_ESC */
            KED_BACK = 1 /* @text KED_BACK */,                /* KEY_ESC */
            KED_PERIOD = 63 /* @text KED_PERIOD */,             /* KEY_F5 */
            KED_PUSH_TO_TALK = 66 /* @text KED_PUSH_TO_TALK */,       /* KEY_F8 */
            KED_POWER = 116 /* @text KED_POWER */,             /* KEY_POWER */
            KED_CHANNELUP = 103 /* @text KED_CHANNELUP */,         /* KEY_UP */
            KED_CHANNELDOWN = 108 /* @text KED_CHANNELDOWN */,       /* KEY_DOWN */
            KED_VOLUMEUP = 78 /* @text KED_VOLUMEUP */,           /* KEY_KPPLUS */
            KED_VOLUMEDOWN = 74 /* @text KED_VOLUMEDOWN */,         /* KEY_KPMINUS */
            KED_MUTE = 55 /* @text KED_MUTE */,               /* KEY_KPASTERISK */
            KED_DIGIT1 = 2 /* @text KED_DIGIT1 */,              /* KEY_1 */
            KED_DIGIT2 = 3 /* @text KED_DIGIT2 */,              /* KEY_2 */
            KED_DIGIT3 = 4 /* @text KED_DIGIT3 */,              /* KEY_3 */
            KED_DIGIT4 = 5 /* @text KED_DIGIT4 */,              /* KEY_4 */
            KED_DIGIT5 = 6 /* @text KED_DIGIT5 */,              /* KEY_5 */
            KED_DIGIT6 = 7 /* @text KED_DIGIT6 */,              /* KEY_6 */
            KED_DIGIT7 = 8 /* @text KED_DIGIT7 */,              /* KEY_7 */
            KED_DIGIT8 = 9 /* @text KED_DIGIT8 */,              /* KEY_8 */
            KED_DIGIT9 = 10 /* @text KED_DIGIT9 */,             /* KEY_9 */
            KED_DIGIT0 = 11 /* @text KED_DIGIT0 */,             /* KEY_0 */
            KED_FASTFORWARD = 88 /* @text KED_FASTFORWARD */,        /* KEY_F12 */
            KED_REWIND = 68 /* @text KED_REWIND */,             /* KEY_F10 */
            KED_PAUSE = 87 /* @text KED_PAUSE */,              /* KEY_F11 */
            KED_PLAY = 87 /* @text KED_PLAY */,               /* KEY_F11 */
            KED_STOP = 31 /* @text KED_STOP */,               /* KEY_S */
            KED_RECORD = 65 /* @text KED_RECORD */,             /* KEY_F7 */
            KED_ARROWUP = 103 /* @text KED_ARROWUP */,           /* KEY_UP */
            KED_ARROWDOWN = 108 /* @text KED_ARROWDOWN */,         /* KEY_DOWN */
            KED_ARROWLEFT = 105 /* @text KED_ARROWLEFT */,         /* KEY_LEFT */
            KED_ARROWRIGHT = 106 /* @text KED_ARROWRIGHT */,        /* KEY_RIGHT */
            KED_PAGEUP = 104 /* @text KED_PAGEUP */,            /* KEY_PAGEUP */
            KED_PAGEDOWN = 109 /* @text KED_PAGEDOWN */,          /* KEY_PAGEDOWN */
            KED_LAST = 38 /* @text KED_LAST */,               /* KEY_L */
            KED_FAVORITE = 49 /* @text KED_FAVORITE */,           /* KEY_N */
            KED_KEYA = 110 /* @text KED_KEYA */,              /* KEY_INSERT */
            KED_KEYB = 107 /* @text KED_KEYB */,              /* KEY_END */
            KED_KEYC = 62 /* @text KED_KEYC */,               /* KEY_F4 */
            KED_KEYD = 111 /* @text KED_KEYD */,              /* KEY_DELETE */
            KED_HELP = 60 /* @text KED_HELP */,               /* KEY_F2 */
            KED_SETUP = 141 /* @text KED_SETUP */,             /* KEY_SETUP */
            KED_NEXT = 407 /* @text KED_NEXT */,              /* KEY_NEXT */
            KED_PREVIOUS = 412 /* @text KED_PREVIOUS */,          /* KEY_PREVIOUS */
            KED_ONDEMAND = 63 /* @text KED_ONDEMAND */,           /* KEY_F5 */
            KED_POUND = 236 /* @text KED_POUND */,             /* KEY_BATTERY */
            KED_AUDIO = 193 /* @text KED_AUDIO */,             /* KEY_F23 */
            KED_CLOSED_CAPTIONING = 194 /* @text KED_CLOSED_CAPTIONING */, /* KEY_F24 */
            KED_REPLAY = 48 /* @text KED_REPLAY */,             /* KEY_B */
            KED_SEARCH = 61 /* @text KED_SEARCH */,             /* KEY_F3 */
            KED_RF_PAIR_GHOST = 237 /* @text KED_RF_PAIR_GHOST */,     /* KEY_BLUETOOTH */
            KED_UNDEFINEDKEY = 240 /* @text KED_UNDEFINEDKEY */       /* KEY_UNKNOWN */
        };

        struct EXTERNAL ToolsKey {
            int code /* @text code */ /* @brief Linux key code as defined in linux/include/uapi/linux/input-event-codes.h. The full Linux key code list is supported. */;
            Modifier modifier /* @text modifier */ /* @brief Key modifier */;
            uint32_t delay /* @text delay */ /* @brief Seconds to wait before sending the key event */;
            uint32_t duration /* @text duration */ /* @brief Seconds between key press and key release; use 0 if not required */;
        };

        struct EXTERNAL RemoteKey {
            RemoteKeyCode code /* @text code */ /* @brief Remote key code */;
            uint32_t delay /* @text delay */ /* @brief Seconds to wait before sending the key event */;
            uint32_t duration /* @text duration */ /* @brief Seconds between key press and key release; use 0 if not required */;
        };

        // @json 1.0.0 @text:keep
        struct EXTERNAL ITools : virtual public Core::IUnknown {
            enum { ID = ID_TOOLS };

            // @json:omit
            virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

            // @text generateKeys
            // @brief Generates local key events for each key entry.
            // @param keys: List of keys to generate in order. Each entry supports delay and optional duration.
            // @param success: Indicates whether the operation was successful
            // @details Implementations should generate key press and key release events via /dev/uinput and honor delay/duration values.
            // @retval Core::ERROR_NONE: Keys generated successfully
            // @retval Core::ERROR_GENERAL: Failed to generate one or more key events
            // @retval Core::ERROR_INVALID_INPUT_LENGTH: Input key list is empty
            virtual Core::hresult GenerateKeys(const std::vector<ToolsKey>& keys /* @restrict:100 */, bool& success /* @out */) = 0;

            // @text generateRemoteKeys
            // @brief Generates remote key events for each key entry.
            // @param keys: List of remote keys to generate in order. Each entry supports delay and optional duration.
            // @param success: Indicates whether the operation was successful
            // @details Implementations should generate key press and key release events via /dev/uinput and honor delay/duration values.
            // @retval Core::ERROR_NONE: Remote keys generated successfully
            // @retval Core::ERROR_GENERAL: Failed to generate one or more remote key events
            // @retval Core::ERROR_INVALID_INPUT_LENGTH: Input key list is empty
            virtual Core::hresult GenerateRemoteKeys(const std::vector<RemoteKey>& keys /* @restrict:100 */, bool& success /* @out */) = 0;

        };
} // namespace Exchange
} // namespace WPEFramework
