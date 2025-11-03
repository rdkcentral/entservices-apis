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
    /* @json 1.0.0 @text:keep */
    struct EXTERNAL IDeviceInfo : virtual public Core::IUnknown {
        enum { ID = ID_DEVICE_INFO };

        virtual ~IDeviceInfo() override = default;
        
        enum DeviceTypeInfo : uint8_t
        {
            IPTV     = 0  /* @text IpTv */,
            IPSTB    = 1  /* @text IpStb  */,
            QAMIPSTB = 2  /* @text QamIpStb */
        };

        struct EXTERNAL CpuLoadAvg {
            uint32_t avg1min;
            uint32_t avg5min;
            uint32_t avg15min;
        };

        struct EXTERNAL SystemInfos {
            string version;
            uint32_t uptime;
            uint32_t totalram;
            uint32_t freeram;
            uint32_t totalswap;
            uint32_t freeswap;
            string devicename;
            string cpuload;
            CpuLoadAvg cpuloadavg;
            string serialnumber;
            string time;
        };
        
        struct EXTERNAL FirmwareversionInfo {
            string imagename;
            string sdk;
            string mediarite;
            string yocto;
        };
        
        struct EXTERNAL AddressesInfo {
            string name;
            string mac;
            string ip;
        };

        using IAddressesInfoIterator = RPC::IIteratorType<AddressesInfo, ID_DEVICE_INFO_ADDRESSES_ITERATOR>;

        // @property
        // @text serialnumber
        // @brief Provides access to the serial number set by manufacture
        // @param serialNumber: Serial number set by manufacturer
        virtual Core::hresult SerialNumber(string& serialNumber /* @out */) const = 0;

        // @property
        // @text modelid
        // @brief Provides access to the device model number
        // @param sku: device model number
        virtual Core::hresult Sku(string& sku /* @out */) const = 0;

        // @property
        // @text make
        // @brief Provides access to the device manufacturer.
        // @param serialNumber: Device manufacturer
        virtual Core::hresult Make(string& make /* @out */) const = 0;

        // @property
        // @text modelname
        // @brief Provides access to the friendly device model name.
        // @param model: Device model name
        virtual Core::hresult Model(string& model /* @out */) const = 0;

        // @property
        // @text devicetype
        // @brief Provides access to the device type.
        // @param devicetype: Device Type
        virtual Core::hresult DeviceType(DeviceTypeInfo& devicetype /* @out */) const = 0;

        // @property
        // @text socname
        // @brief Provides access to the SOC Name.
        // @param socname: Name of the SOC
        virtual Core::hresult SocName(string& socname /* @out */) const = 0;

        // @property
        // @text distributorid
        // @brief Provides access to the partner ID or distributor ID for device.
        // @param distributorid: Partner ID or distributor ID for device
        virtual Core::hresult DistributorId(string& distributorId /* @out */) const = 0;

        // @property
        // @text brandname
        // @brief Provides access to device brand name
        // @param brand: Device brand name
        virtual Core::hresult Brand(string& brand /* @out */) const = 0;

        // @property
        // @text releaseversion
        // @brief Provides access to the ReleaseVersion of the Image
        // @param releaseversion: ReleaseVersion of the Image
        virtual Core::hresult ReleaseVersion(string& releaseversion /* @out */) const = 0;

        // @property
        // @text chipSet
        // @brief Provides access to the chipset of the device
        // @param chipSet: Chipset of the device
        virtual Core::hresult Chipset(string& chipSet /* @out */) const = 0;

        // @property
        // @text firmwareversion
        // @brief Provides access to the versions maintained in version.txt.
        // @param firmwareVersionInfo: Version information
        virtual Core::hresult FirmwareVersion(FirmwareversionInfo& firmwareVersionInfo/* @out */) const = 0;

        // @property
        // @text systeminfo
        // @brief Provides access to the system general information
        // @param systeminfo: System general information
        virtual Core::hresult SystemInfo(SystemInfos& systemInfo /* @out */) const = 0;
        
        // @property
        // @text ethmac
        // @brief Provides access to the Ethernet MAC addresses.
        // @param ethMac: Ethernet MAC addresses
        virtual Core::hresult EthMac(string& ethMac /* @out */) const = 0;
        
        // @property
        // @text estbmac
        // @brief Provides access to the STB MAC addresses.
        // @param estbMac: STB MAC addresses
        virtual Core::hresult EstbMac(string& estbMac /* @out */) const = 0;
        
        // @property
        // @text wifimac
        // @brief Provides access to the WIFI MAC addresses.
        // @param wifiMac: WIFI MAC addresses
        virtual Core::hresult WifiMac(string& wifiMac /* @out */) const = 0;
        
        // @property
        // @text estbip
        // @brief Provides access to the STB IP addresses.
        // @param estbIp: STB IP addresses
        virtual Core::hresult EstbIp(string& estbIp /* @out */) const = 0;
    };

    /* @json 1.0.0 @text:keep */
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

        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
        typedef RPC::IIteratorType<AudioOutput, ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT> IAudioOutputIterator;
        typedef RPC::IIteratorType<AudioCapability, ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY> IAudioCapabilityIterator;
        typedef RPC::IIteratorType<MS12Capability, ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY> IMS12CapabilityIterator;
        typedef RPC::IIteratorType<MS12Profile, ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE> IMS12ProfileIterator;

        // @property
        // @text supportedaudioports
        // @brief Provides access to the audio ports supported on the device.
        // @param supportedAudioPorts: Audio ports supported on the device.
        virtual Core::hresult SupportedAudioPorts(IStringIterator*& supportedAudioPorts /* @out */) const = 0;

        // @text audiocapabilities
        // @brief Audio capabilities for the specified audio port.
        // @param audioPort: Audio port name
        // @param AudioCapabilities: Audio capability
        virtual Core::hresult AudioCapabilities(const string& audioPort , IAudioCapabilityIterator*& AudioCapabilities /* @out */) const = 0;

        // @text ms12capabilities
        // @brief MS12 audio capabilities for the specified audio port.
        // @param audioPort: Audio port name
        // @param MS12Capabilities: MS12 audio capability
        virtual Core::hresult MS12Capabilities(const string& audioPort , IMS12CapabilityIterator*& MS12Capabilities /* @out */) const = 0;

        // @text supportedms12audioprofiles
        // @brief Supported MS12 audio profiles for the specified audio port.
        // @param audioPort: Audio port name
        // @param supportedMS12AudioProfiles: MS12 audio profiles
        virtual Core::hresult SupportedMS12AudioProfiles(const string& audioPort , IStringIterator*& supportedMS12AudioProfiles /* @out */) const = 0;
    };

    /* @json 1.0.0 @text:keep */
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

        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
        typedef RPC::IIteratorType<VideoOutput, ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT> IVideoOutputIterator;
        typedef RPC::IIteratorType<ScreenResolution, ID_DEVICE_CAPABILITIES_RESOLUTION> IScreenResolutionIterator;

        // @property
        // @text supportedvideodisplays
        // @brief Provides access to the video ports supported on the device.
        // @param supportedVideoDisplays: Video ports supported on the device
        virtual Core::hresult SupportedVideoDisplays(IStringIterator*& supportedVideoDisplays /* @out */) const = 0;

        // @text defaultresolution
        // @brief Default resolution on the selected video display port.
        // @param videoDisplay: Video display port name
        // @param defaultResolution: Default Resolutions
        virtual Core::hresult DefaultResolution(const string& videoDisplay , string& defaultResolution /* @out */) const = 0;

        // @text supportedresolutions
        // @brief Supported resolutions on the selected video display port.
        // @param videoDisplay: Video display port name
        // @param supportedResolutions: Supported Resolutions
        virtual Core::hresult SupportedResolutions(const string& videoDisplay, IStringIterator*& supportedResolutions /* @out */) const = 0;

        // @property
        // @text hostedid
        // @brief Provides access to the EDID of the host.
        // @param EDID: EDID of the host
        virtual Core::hresult HostEDID(string& EDID /* @out */) const = 0;

        // @text supportedhdcp
        // @brief Supported hdcp version on the selected video display port.
        // @param videoDisplay: Video display port name
        // @param supportedHDCPVersion: HDCP support
        virtual Core::hresult SupportedHdcp(const string& videoDisplay , CopyProtection& supportedHDCPVersion /* @out */) const = 0;
    };
}
}
