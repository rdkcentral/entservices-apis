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
            DEVICE_TYPE_IPTV     = 0  /* @text IpTv */,
            DEVICE_TYPE_IPSTB    = 1  /* @text IpStb  */,
            DEVICE_TYPE_QAMIPSTB = 2  /* @text QamIpStb */
        };

        struct EXTERNAL CpuLoadAvg {
            uint32_t avg1min /* @brief 1min cpuload average */;
            uint32_t avg5min /* @brief 5min cpuload average */;
            uint32_t avg15min /* @brief 15min cpuload average */;
        };

        struct EXTERNAL SystemInfos {
            string version /* @brief Software version (in form version#hashtag) */;
            uint32_t uptime /* @brief System uptime (in seconds) */;
            uint32_t totalram /* @brief Total installed system RAM memory (in bytes) */;
            uint32_t freeram /* @brief Free system RAM memory (in bytes) */;
            uint32_t totalswap /* @brief Total swap space (in bytes) */;
            uint32_t freeswap /* @brief Swap space still available (in bytes) */;
            string devicename /* @brief Host name */;
            string cpuload /* @brief Current CPU load (percentage) */;
            CpuLoadAvg cpuloadavg /* @brief CPU load average */;
            string serialnumber /* @brief Device serial number */;
            string time /* @brief Current system date and time */;
        };

        struct EXTERNAL FirmwareversionInfo {
            string imagename /* @brief Image name */;
            string sdk /* @brief sdk version */;
            string mediarite /* @brief mediarite */;
            string yocto /* @brief yocto version */;
	        string pdri /* @brief pdri version */;
        };

        struct EXTERNAL AddressesInfo {
            string name /* @brief Interface name */;
            string mac /* @brief Interface MAC address */;
            string ip /* @brief Interface IP address */;
        };

        struct EXTERNAL DeviceSerialNo {
            string serialnumber /* @brief Serial number set by manufacturer */;
        };

        struct EXTERNAL DeviceModelNo {
            string sku /* @brief Device model number or SKU */;
        };

        struct EXTERNAL DeviceMake {
            string make /* @brief Device manufacturer */;
        };

        struct EXTERNAL DeviceModel {
            string model /* @brief Friendly device model name */;
        };

        struct EXTERNAL DeviceTypeInfos {
            DeviceTypeInfo devicetype /* @brief Device type (must be one of the following: tv, IpStb, QamIpStb) */;
        };

        struct EXTERNAL DeviceSoc {
            string socname /* @brief SOC Name */;
        };

        struct EXTERNAL DeviceDistId {
            string distributorid /* @brief Partner ID or distributor ID for device */;
        };

        struct EXTERNAL DeviceBrand {
            string brand /* @brief Brand Name */;
        };

        struct EXTERNAL DeviceReleaseVer {
            string releaseversion /* @brief Release version */;
        };

        struct EXTERNAL DeviceChip {
            string chipset /* @brief Device chip set Name */;
        };

        struct EXTERNAL EthernetMac {
            string ethMac /* @text eth_mac */ /* @brief Ethernet Mac Address */;
        };

        struct EXTERNAL StbMac {
            string estbMac /* @text estb_mac */ /* @brief STB Mac Address */;
        };

        struct EXTERNAL WiFiMac {
            string wifiMac /* @text wifi_mac */ /* @brief Wifi Mac Address */;
        };

        struct EXTERNAL StbIp {
            string estbIp /* @text estb_ip */ /* @brief STB IP Address */;
        };

        using IAddressesInfoIterator = RPC::IIteratorType<AddressesInfo, ID_DEVICE_INFO_ADDRESSES_ITERATOR>;
        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

        // @property
        // @text serialnumber
        // @brief Provides access to the serial number set by manufacture
        // @param serialNumber: Serial number set by manufacturer
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult SerialNumber(DeviceSerialNo& deviceSerialNo /* @out */) const = 0;

        // @property
        // @text modelid
        // @brief Provides access to the device model number
        // @param sku: device model number
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Sku(DeviceModelNo& deviceModelNo /* @out */) const = 0;

        // @property
        // @text make
        // @brief Provides access to the device manufacturer.
        // @param serialNumber: Device manufacturer
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Make(DeviceMake& deviceMake /* @out */) const = 0;

        // @property
        // @text modelname
        // @brief Provides access to the friendly device model name.
        // @param model: Device model name
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Model(DeviceModel& deviceModel /* @out */) const = 0;

        // @property
        // @text devicetype
        // @brief Provides access to the device type.
        // @param devicetype: Device Type
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult DeviceType(DeviceTypeInfos& deviceTypeInfos /* @out */) const = 0;

        // @property
        // @text socname
        // @brief Provides access to the SOC Name.
        // @param socname: Name of the SOC
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult SocName(DeviceSoc& deviceSoc /* @out */) const = 0;

        // @property
        // @text distributorid
        // @brief Provides access to the partner ID or distributor ID for device.
        // @param distributorid: Partner ID or distributor ID for device
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult DistributorId(DeviceDistId& deviceDistId /* @out */) const = 0;

        // @property
        // @text brandname
        // @brief Provides access to device brand name
        // @param brand: Device brand name
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Brand(DeviceBrand& deviceBrand /* @out */) const = 0;

        // @property
        // @text releaseversion
        // @brief Provides access to the ReleaseVersion of the Image
        // @param releaseversion: ReleaseVersion of the Image
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult ReleaseVersion(DeviceReleaseVer& deviceReleaseVer /* @out */) const = 0;

        // @property
        // @text chipset
        // @brief Provides access to the chipset of the device
        // @param chipSet: Chipset of the device
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult ChipSet(DeviceChip& deviceChip /* @out */) const = 0;

        // @property
        // @text firmwareversion
        // @brief Provides access to the versions maintained in version.txt.
        // @param firmwareVersionInfo: Version information
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult FirmwareVersion(FirmwareversionInfo& firmwareVersionInfo/* @out */) const = 0;

        // @property
        // @text systeminfo
        // @brief Provides access to the system general information
        // @param systeminfo: System general information
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult SystemInfo(SystemInfos& systemInfo /* @out */) const = 0;

        // @property
        // @text addresses
        // @brief Provides access to the network interface addresses.
        // @param addressesInfo: Network interface addresses
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Addresses(IAddressesInfoIterator*& addressesInfo /* @out */) const = 0;

        // @property
        // @text ethmac
        // @brief Provides access to the Ethernet MAC addresses.
        // @param ethMac: Ethernet MAC addresses
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult EthMac(EthernetMac& ethernetMac /* @out */) const = 0;

        // @property
        // @text estbmac
        // @brief Provides access to the STB MAC addresses.
        // @param estbMac: STB MAC addresses
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult EstbMac(StbMac& stbMac /* @out */) const = 0;

        // @property
        // @text wifimac
        // @brief Provides access to the WIFI MAC addresses.
        // @param wifiMac: WIFI MAC addresses
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult WifiMac(WiFiMac& wiFiMac /* @out */) const = 0;

        // @property
        // @text estbip
        // @brief Provides access to the STB IP addresses.
        // @param estbIp: STB IP addresses
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult EstbIp(StbIp& stbIp /* @out */) const = 0;

        // @text supportedaudioports
        // @brief Provides access to the audio ports supported on the device.
        // @param supportedAudioPorts: Audio ports supported on the device.
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult SupportedAudioPorts(IStringIterator*& supportedAudioPorts /* @out */, bool& success /* @out */) const = 0;
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
            AUDIOCAPABILITY_NONE = 0 /* @text none */,
            ATMOS                = 1 /* @text ATMOS */,
            DD                   = 2 /* @text DOLBY_DIGITAL */,
            DDPLUS               = 3 /* @text DOLBY_DIGITAL_PLUS */,
            DAD                  = 4 /* @text Dual_Audio_Decode */,
            DAPV2                = 5 /* @text DAPv2 */,
            MS12                 = 6 /* @text MS12 */
        };

        enum MS12Capability : uint8_t {
            MS12CAPABILITY_NONE = 0 /* @text none */,
            DOLBYVOLUME         = 1 /* @text Dolby_Volume */,
            INTELIGENTEQUALIZER = 2 /* @text Inteligent_Equalizer */,
            DIALOGUEENHANCER    = 3 /* @text Dialogue_Enhancer */
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

        // @text audiocapabilities
        // @brief Audio capabilities for the specified audio port.
        // @param audioPort: Audio port name
        // @param AudioCapabilities: Audio capability
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        // @deprecated
        virtual Core::hresult AudioCapabilities(const string& audioPort , IAudioCapabilityIterator*& AudioCapabilities /* @out */, bool& success /* @out */) const = 0;

        // @text ms12capabilities
        // @brief MS12 audio capabilities for the specified audio port.
        // @param audioPort: Audio port name
        // @param MS12Capabilities: MS12 audio capability
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        // @deprecated
        virtual Core::hresult MS12Capabilities(const string& audioPort , IMS12CapabilityIterator*& MS12Capabilities /* @out */, bool& success /* @out */) const = 0;

        // @text supportedms12audioprofiles
        // @brief Supported MS12 audio profiles for the specified audio port.
        // @param audioPort: Audio port name
        // @param supportedMS12AudioProfiles: MS12 audio profiles
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        // @deprecated
        virtual Core::hresult SupportedMS12AudioProfiles(const string& audioPort , IStringIterator*& supportedMS12AudioProfiles /* @out */, bool& success /* @out */) const = 0;
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
            SCREENRESOLUTION_UNKNOWN = 0 /* @text unknown */,
            SCREENRESOLUTION_480I = 1 /* @text 480i */,
            SCREENRESOLUTION_480P = 2 /* @text 480p */,
            SCREENRESOLUTION_576I = 3 /* @text 576i */,
            SCREENRESOLUTION_576P = 4 /* @text 576p */,
            SCREENRESOLUTION_576P50HZ = 5 /* @text 576p50 */,
            SCREENRESOLUTION_720P = 6 /* @text 720p */,
            SCREENRESOLUTION_720P50HZ = 7 /* @text 720p50 */,
            SCREENRESOLUTION_768P60HZ = 8 /* @text 768p60 */,
            SCREENRESOLUTION_1080I = 9 /* @text 1080i */,
            SCREENRESOLUTION_1080I25HZ = 10 /* @text 1080i25 */,
            SCREENRESOLUTION_1080I50HZ = 11 /* @text 1080i50 */,
            SCREENRESOLUTION_1080P = 12 /* @text 1080p */,
            SCREENRESOLUTION_1080P24HZ = 13 /* @text 1080p24 */,
            SCREENRESOLUTION_1080P25HZ = 14 /* @text 1080p25 */,
            SCREENRESOLUTION_1080P30HZ = 15 /* @text 1080p30 */,
            SCREENRESOLUTION_1080P50HZ = 16 /* @text 1080p50 */,
            SCREENRESOLUTION_1080P60HZ = 17 /* @text 1080p60 */,
            SCREENRESOLUTION_2160P24HZ = 18 /* @text 2160p24 */,
            SCREENRESOLUTION_2160P25HZ = 19 /* @text 2160p25 */,
            SCREENRESOLUTION_2160P30HZ = 20 /* @text 2160p30 */,
            SCREENRESOLUTION_2160P50HZ = 21 /* @text 2160p50 */,
            SCREENRESOLUTION_2160P60HZ = 22 /* @text 2160p60 */,
            SCREENRESOLUTION_4320P30HZ = 23 /* @text 4320p30 */,
            SCREENRESOLUTION_4320P60HZ = 24 /* @text 4320p60 */
        };

        enum CopyProtection : uint8_t {
            HDCP_UNAVAILABLE = 0 /* @text unavailable */,
            HDCP_14          = 1 /* @text 1.4 */,
            HDCP_20          = 2 /* @text 2.0 */,
            HDCP_21          = 3 /* @text 2.1 */,
            HDCP_22          = 4 /* @text 2.2 */
        };

        struct EXTERNAL DefaultResln {
            /* @brief Resolution supported by the device */
            string defaultResolution;
        };

        struct EXTERNAL HostEdid {
            /* @brief A base64 encoded byte array string representing the EDID */
            string EDID;
        };

        struct EXTERNAL SupportedHDCPVer {
            /* @brief HDCP support (must be one of the following: unavailable, 1.4, 2.0, 2.1, 2.2) */
            CopyProtection supportedHDCPVersion;
        };

        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
        typedef RPC::IIteratorType<VideoOutput, ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT> IVideoOutputIterator;
        typedef RPC::IIteratorType<ScreenResolution, ID_DEVICE_CAPABILITIES_RESOLUTION> IScreenResolutionIterator;

        // @text supportedvideodisplays
        // @brief Provides access to the video ports supported on the device.
        // @param supportedVideoDisplays: Video ports supported on the device
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        // @deprecated
        virtual Core::hresult SupportedVideoDisplays(IStringIterator*& supportedVideoDisplays /* @out */, bool& success /* @out */) const = 0;

        // @text defaultresolution
        // @brief Default resolution on the selected video display port.
        // @param videoDisplay: Video display port name
        // @param defaultResolution: Default Resolutions
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        // @deprecated
        virtual Core::hresult DefaultResolution(const string& videoDisplay , DefaultResln& defaultResln /* @out */) const = 0;

        // @text supportedresolutions
        // @brief Supported resolutions on the selected video display port.
        // @param videoDisplay: Video display port name
        // @param supportedResolutions: Supported Resolutions
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
         // @deprecated
        virtual Core::hresult SupportedResolutions(const string& videoDisplay, IStringIterator*& supportedResolutions /* @out */, bool& success /* @out */ ) const = 0;

        // @property
        // @text hostedid
        // @brief Provides access to the EDID of the host.
        // @param EDID: EDID of the host
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        // @deprecated
        virtual Core::hresult HostEDID(HostEdid& hostEdid /* @out */) const = 0;

        // @text supportedhdcp
        // @brief Supported hdcp version on the selected video display port.
        // @param videoDisplay: Video display port name
        // @param supportedHDCPVersion: HDCP support
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        // @deprecated
        virtual Core::hresult SupportedHdcp(const string& videoDisplay , SupportedHDCPVer& supportedHDCPVer /* @out */) const = 0;
    };
}
}
