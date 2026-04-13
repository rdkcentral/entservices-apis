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
#include <string>

namespace WPEFramework {
namespace Exchange {

    // @json 1.0.0 @text:keep
    struct EXTERNAL IGStreamerPlayer : virtual public Core::IUnknown {
        enum { ID = ID_GSTREAMER_PLAYER };

        virtual ~IGStreamerPlayer() = default;

        // @text start
        virtual Core::hresult Start(const std::string& uri) = 0;

        // @text stop
        virtual Core::hresult Stop() = 0;

        // @text playPause
        virtual Core::hresult PlayPause() = 0;

        // @text seek
        virtual Core::hresult Seek(const int32_t offset) = 0;

        // @text setVolume
        virtual Core::hresult SetVolume(const double volume) = 0;

        // @text getState
        virtual Core::hresult GetState(std::string& state /* @out */) const = 0;

        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_GSTREAMER_PLAYER_NOTIFICATION };

            virtual ~INotification() = default;

            virtual void OnStateChanged(const std::string& state) = 0;
            virtual void OnError(const std::string& error) = 0;
        };

        virtual Core::hresult Register(INotification* notification) = 0;
        virtual Core::hresult Unregister(INotification* notification) = 0;
    };

}
}