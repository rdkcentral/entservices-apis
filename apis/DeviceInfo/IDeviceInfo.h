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

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL IDeviceInfo : virtual public Core::IUnknown {
        enum { ID = ID_DEVICE_INFO };

        virtual ~IDeviceInfo() override = default;

        virtual Core::hresult SerialNumber(string& serialNumber /* @out */) const = 0;
        virtual Core::hresult Sku(string& sku /* @out */) const = 0;
        virtual Core::hresult Make(string& make /* @out */) const = 0;
        virtual Core::hresult Model(string& model /* @out */) const = 0;
        virtual Core::hresult DeviceType(string& deviceType /* @out */) const = 0;
        virtual Core::hresult SocName(string& socName /* @out */) const = 0;
        virtual Core::hresult DistributorId(string& distributorId /* @out */) const = 0;
        virtual Core::hresult Brand(string& brand /* @out */) const = 0;
    };

    struct EXTERNAL IDeviceAudioCapabilities : virtual public Core::IUnknown {
        enum { ID = ID_DEVICE_CAPABILITIES_AUDIO };

        virtual ~IDeviceAudioCapabilities() override = default;

        enum AudioOutput : uint8_t {
            AUDIO_OTHER,
            AUDIO_RF_MODULATOR,
            AUDIO_ANALOG,
            AUDIO_SPDIF, //over RCA or TOSLINK
            AUDIO_HDMI0,
            AUDIO_HDMI1,
            AUDIO_DISPLAYPORT
        };

        enum AudioCapability : uint8_t {
            AUDIOCAPABILITY_NONE,
            ATMOS,
            DD,
            DDPLUS,
            DAD,
            DAPV2,
            MS12
        };

        enum MS12Capability : uint8_t {
            MS12CAPABILITY_NONE,
            DOLBYVOLUME,
            INTELIGENTEQUALIZER,
            DIALOGUEENHANCER
        };

        enum MS12Profile : uint8_t {
            MS12PROFILE_NONE,
            MUSIC,
            MOVIE,
            VOICE
        };

        typedef RPC::IIteratorType<AudioOutput, ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT> IAudioOutputIterator;
        typedef RPC::IIteratorType<AudioCapability, ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY> IAudioCapabilityIterator;
        typedef RPC::IIteratorType<MS12Capability, ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY> IMS12CapabilityIterator;
        typedef RPC::IIteratorType<MS12Profile, ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE> IMS12ProfileIterator;

        virtual Core::hresult SupportedAudioPorts(RPC::IStringIterator*& supportedAudioPorts /* @out */) const = 0;
        virtual Core::hresult AudioCapabilities(const string& audioPort /* @in */, IAudioCapabilityIterator*& audioCapabilities /* @out */) const = 0;
        virtual Core::hresult MS12Capabilities(const string& audioPort /* @in */, IMS12CapabilityIterator*& ms12Capabilities /* @out */) const = 0;
        virtual Core::hresult SupportedMS12AudioProfiles(const string& audioPort /* @in */, RPC::IStringIterator*& supportedMS12AudioProfiles /* @out */) const = 0;
    };

    struct EXTERNAL IDeviceVideoCapabilities : virtual public Core::IUnknown {
        enum { ID = ID_DEVICE_CAPABILITIES_VIDEO };

        virtual ~IDeviceVideoCapabilities() override = default;

        enum VideoOutput : uint8_t {
            VIDEO_OTHER,
            VIDEO_RF_MODULATOR,
            VIDEO_COMPOSITE, // also composite over SCART
            VIDEO_SVIDEO,
            VIDEO_COMPONENT,
            VIDEO_SCART_RGB,
            VIDEO_HDMI0,
            VIDEO_HDMI1,
            VIDEO_DISPLAYPORT // also DisplayPort over USB-C
        };

        enum ScreenResolution : uint8_t {
            SCREENRESOLUTION_UNKNOWN = 0,
            SCREENRESOLUTION_480I = 1,
            SCREENRESOLUTION_480P = 2,
            SCREENRESOLUTION_576I = 3,
            SCREENRESOLUTION_576P = 4,
            SCREENRESOLUTION_576P50HZ = 5,
            SCREENRESOLUTION_720P = 6,
            SCREENRESOLUTION_720P50HZ = 7,
            SCREENRESOLUTION_768P60HZ = 8,
            SCREENRESOLUTION_1080I = 9,
            SCREENRESOLUTION_1080I25HZ = 10,
            SCREENRESOLUTION_1080I50HZ = 11,
            SCREENRESOLUTION_1080P = 12,
            SCREENRESOLUTION_1080P24HZ = 13,
            SCREENRESOLUTION_1080P25HZ = 14,
            SCREENRESOLUTION_1080P30HZ = 15,
            SCREENRESOLUTION_1080P50HZ = 16,
            SCREENRESOLUTION_1080P60HZ = 17,
            SCREENRESOLUTION_2160P24HZ = 18,
            SCREENRESOLUTION_2160P25HZ = 19,
            SCREENRESOLUTION_2160P30HZ = 20,
            SCREENRESOLUTION_2160P50HZ = 21,
            SCREENRESOLUTION_2160P60HZ = 22,
            SCREENRESOLUTION_4320P30HZ = 23,
            SCREENRESOLUTION_4320P60HZ = 24
        };

        enum CopyProtection : uint8_t {
            HDCP_UNAVAILABLE,
            HDCP_14,
            HDCP_20,
            HDCP_21,
            HDCP_22
        };

        typedef RPC::IIteratorType<VideoOutput, ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT> IVideoOutputIterator;
        typedef RPC::IIteratorType<ScreenResolution, ID_DEVICE_CAPABILITIES_RESOLUTION> IScreenResolutionIterator;

        virtual Core::hresult SupportedVideoDisplays(RPC::IStringIterator*& supportedVideoDisplays /* @out */) const = 0;
        virtual Core::hresult DefaultResolution(const string& videoDisplay /* @in */, string& defaultResolution /* @out */) const = 0;
        virtual Core::hresult SupportedResolutions(const string& videoDisplay /* @in */, RPC::IStringIterator*& supportedResolutions /* @out */) const = 0;
        virtual Core::hresult HostEDID(string& edid /* @out */) const = 0;
        virtual Core::hresult SupportedHdcp(const string& videoDisplay /* @in */, CopyProtection& supportedHDCPVersion /* @out */) const = 0;
    };
}
}
