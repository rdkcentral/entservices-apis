/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2023 RDK Management
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

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL ISystemAudioPlayer : virtual public Core::IUnknown {
        enum { ID = ID_SYSTEMAUDIOPLAYER };

        struct INotification : virtual public Core::IUnknown {
            enum { ID = ID_SYSTEMAUDIOPLAYER_NOTIFICATION };

            virtual ~INotification() {}
            virtual void OnSAPEvents(const string &data) {}        
        };

        virtual ~ISystemAudioPlayer() {}

        virtual Core::hresult Configure(PluginHost::IShell* service) = 0;
        virtual Core::hresult Register(INotification* sink) = 0;
        virtual Core::hresult Unregister(INotification* sink) = 0;
        virtual Core::hresult Open(const string &input, string &output /* @out */) = 0;
        virtual Core::hresult Play(const string &input, string &output /* @out */) = 0;
        virtual Core::hresult PlayBuffer(const string &input, string &output /* @out */) = 0;
        virtual Core::hresult Pause(const string &input, string &output /* @out */) = 0;
        virtual Core::hresult Resume(const string &input, string &output /* @out */) = 0;
        virtual Core::hresult Stop(const string &input, string &output /* @out */) = 0;
        virtual Core::hresult Close(const string &input, string &output /* @out */) = 0;
        virtual Core::hresult SetMixerLevels(const string &input, string &output /* @out */) = 0;
        virtual Core::hresult SetSmartVolControl(const string &input, string &output /* @out */) = 0;
        virtual Core::hresult IsPlaying(const string &input, string &output /* @out */) = 0;
        virtual Core::hresult Config(const string &input, string &output /* @out */) = 0;
        virtual Core::hresult GetPlayerSessionId(const string &input, string &output /* @out */) = 0;

    };

} // Exchange
} // WPEFramework
