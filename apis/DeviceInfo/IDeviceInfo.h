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
            string rdk /* @brief rdk version */;
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

        struct EXTERNAL DeviceIdInfo {
            string deviceId /* @brief Device ID */;
        };

        struct EXTERNAL HardwareIdInfo {
            string hardwareId /* @brief Hardware ID (first 6 characters of Device ID) */;
        };

        using IAddressesInfoIterator = RPC::IIteratorType<AddressesInfo, ID_DEVICE_INFO_ADDRESSES_ITERATOR>;
        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

        // @property
        // @text serialnumber
        // @brief Provides access to the serial number set by manufacture
        // @details Retrieves the serial number assigned to the device by the manufacturer.
        // @param serialNumber: Serial number set by manufacturer
        // @example deviceSerialNo: {"serialnumber":"XG1A2300012345"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult SerialNumber(DeviceSerialNo& deviceSerialNo /* @out */) const = 0;

        // @property
        // @text modelid
        // @brief Provides access to the device model number
        // @details Retrieves the model number or SKU assigned to the device by the manufacturer.
        // @param sku: device model number
        // @example sku: "X1234"
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Sku(DeviceModelNo& deviceModelNo /* @out */) const = 0;

        // @property
        // @text make
        // @brief Provides access to the device manufacturer.
        // @details Retrieves the manufacturer of the device.
        // @param serialNumber: Device manufacturer
        // @example deviceMake: {"make":"Technicolor"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Make(DeviceMake& deviceMake /* @out */) const = 0;

        // @property
        // @text modelname
        // @brief Provides access to the friendly device model name.
        // @details Retrieves the friendly model name of the device.
        // @param model: Device model name
        // @example deviceModel: {"model":"Technicolor XG1A"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Model(DeviceModel& deviceModel /* @out */) const = 0;

        // @property
        // @text devicetype
        // @brief Provides access to the device type.
        // @details Retrieves the type of the device (must be one of the following: IpTv, IpStb, QamIpStb).
        // @param devicetype: Device Type
        // @example deviceTypeInfos: {"devicetype":"IpStb"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult DeviceType(DeviceTypeInfos& deviceTypeInfos /* @out */) const = 0;

        // @property
        // @text socname
        // @brief Provides access to the SOC Name.
        // @details Retrieves the name of the system on chip (SOC).
        // @param socname: Name of the SOC
        // @example deviceSoc: {"socname":"BCM72180"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult SocName(DeviceSoc& deviceSoc /* @out */) const = 0;

        // @property
        // @text distributorid
        // @brief Provides access to the partner ID or distributor ID for device.
        // @details Retrieves the partner ID or distributor ID assigned to the device.
        // @param distributorid: Partner ID or distributor ID for device
        // @example deviceDistId: {"distributorid":"123456"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult DistributorId(DeviceDistId& deviceDistId /* @out */) const = 0;

        // @property
        // @text brandname
        // @brief Provides access to device brand name
        // @details Retrieves the brand name of the device.
        // @param brand: Device brand name
        // @example deviceBrand: {"brand":"Technicolor"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Brand(DeviceBrand& deviceBrand /* @out */) const = 0;

        // @property
        // @text releaseversion
        // @brief Provides access to the ReleaseVersion of the Image
        // @details Retrieves the release version of the image running on the device.
        // @param releaseversion: ReleaseVersion of the Image
        // @example deviceReleaseVer: {"releaseversion":"1.0.0"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult ReleaseVersion(DeviceReleaseVer& deviceReleaseVer /* @out */) const = 0;

        // @property
        // @text chipset
        // @brief Provides access to the chipset of the device
        // @details Retrieves the chipset of the device.
        // @param chipSet: Chipset of the device
        // @example deviceChip: {"chipset":"BCM72180"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult ChipSet(DeviceChip& deviceChip /* @out */) const = 0;

        // @property
        // @text firmwareversion
        // @brief Provides access to the versions maintained in version.txt.
        // @details Retrieves the versions maintained in version.txt.
        // @param firmwareVersionInfo: Version information
        // @example firmwareVersionInfo: {"imagename":"image1","middleware":"middleware1","sdk":"sdk1","mediarite":"mediarite1","yocto":"yocto1","pdri":"pdri1"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult FirmwareVersion(FirmwareversionInfo& firmwareVersionInfo/* @out */) const = 0;

        // @property
        // @text systeminfo
        // @brief Provides access to the system general information
        // @details Retrieves the system general information such as software version, uptime, total RAM, 
        // free RAM, total swap, free swap, host name, CPU load, CPU load average, serial number, and current system date and time.
        // @param systeminfo: System general information
        // @example systemInfo: {"version":"1.0.0#123456","uptime":3600,"totalram":2147483648,"freeram":1073741824,"totalswap":1073741824,"freeswap":536870912,"devicename":"device1","cpuload":"50%","cpuloadavg":{"avg1min":30,"avg5min":40,"avg15min":50},"serialnumber":"XG1A2300012345","time":"2024-06-01T12:00:00Z"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult SystemInfo(SystemInfos& systemInfo /* @out */) const = 0;

        // @property
        // @text addresses
        // @brief Provides access to the network interface addresses.
        // @details Retrieves the network interface addresses of the device.
        // @param addressesInfo: Network interface addresses
        // @example addressesInfo: [{"name":"eth0","mac":"00:11:22:33:44:55","ip":"192.168.1.2"}]
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Addresses(IAddressesInfoIterator*& addressesInfo /* @out */) const = 0;

        // @property
        // @text ethmac
        // @brief Provides access to the Ethernet MAC addresses.
        // @details Retrieves the Ethernet MAC addresses of the device.
        // @param ethMac: Ethernet MAC addresses
        // @example ethMac: {"ethMac":"00:11:22:33:44:55"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult EthMac(EthernetMac& ethernetMac /* @out */) const = 0;

        // @property
        // @text estbmac
        // @brief Provides access to the STB MAC addresses.
        // @details Retrieves the STB MAC addresses of the device.
        // @param estbMac: STB MAC addresses
        // @example estbMac: {"estbMac":"00:11:22:33:44:55"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult EstbMac(StbMac& stbMac /* @out */) const = 0;

        // @property
        // @text wifimac
        // @brief Provides access to the WIFI MAC addresses.
        // @details Retrieves the WIFI MAC addresses of the device.
        // @param wifiMac: WIFI MAC addresses
        // @example wifiMac: {"wifiMac":"00:11:22:33:44:55"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult WifiMac(WiFiMac& wiFiMac /* @out */) const = 0;

        // @property
        // @text estbip
        // @brief Provides access to the STB IP addresses.
        // @details Retrieves the STB IP addresses of the device.
        // @param estbIp: STB IP addresses
        // @example stbIp: {"estb_ip":"192.168.1.10"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult EstbIp(StbIp& stbIp /* @out */) const = 0;

        // @text supportedaudioports
        // @brief Provides access to the audio ports supported on the device.
        // @details Retrieves the audio ports supported on the device.
        // @param supportedAudioPorts: Audio ports supported on the device.
        // @example supportedAudioPorts: ["AUDIO_ANALOG","AUDIO_HDMI0"]
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult SupportedAudioPorts(IStringIterator*& supportedAudioPorts /* @out */, bool& success /* @out */) const = 0;

        // @property
        // @text deviceId
        // @brief Provides the Device ID info.
        // @details Retrieves the Device ID of the device.
        // @param deviceId: Device ID of the device
        // @example deviceIdInfo: {"deviceId":"1234567890abcdef"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult DeviceId(DeviceIdInfo& deviceIdInfo /* @out */) const = 0;

        // @property
        // @text hardwareId
        // @brief Provides the Hardware ID (first 6 characters of Device ID).
        // @details Retrieves the Hardware ID of the device.
        // @param hardwareId: Hardware ID of the device
        // @example hardwareIdInfo: {"hardwareId":"123456"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult HardwareId(HardwareIdInfo& hardwareIdInfo /* @out */) const = 0;
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
        // @details Retrieves the audio capabilities for the specified audio port.
        // @param audioPort: Audio port name
        // @example audioPort: "AUDIO_HDMI0"
        // @param AudioCapabilities: Audio capability
        // @example AudioCapabilities: ["ATMOS","DOLBY_DIGITAL","DOLBY_DIGITAL_PLUS"]
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        // @deprecated
        virtual Core::hresult AudioCapabilities(const string& audioPort , IAudioCapabilityIterator*& AudioCapabilities /* @out */, bool& success /* @out */) const = 0;

        // @text ms12capabilities
        // @brief MS12 audio capabilities for the specified audio port.
        // @details Retrieves the MS12 audio capabilities for the specified audio port.
        // @param audioPort: Audio port name
        // @example audioPort: "AUDIO_HDMI0"
        // @param MS12Capabilities: MS12 audio capability
        // @example MS12Capabilities: ["Dolby_Volume","Inteligent_Equalizer","Dialogue_Enhancer"]
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        // @deprecated
        virtual Core::hresult MS12Capabilities(const string& audioPort , IMS12CapabilityIterator*& MS12Capabilities /* @out */, bool& success /* @out */) const = 0;

        // @text supportedms12audioprofiles
        // @brief Supported MS12 audio profiles for the specified audio port.
        // @details Retrieves the supported MS12 audio profiles for the specified audio port.
        // @param audioPort: Audio port name
        // @example audioPort: "AUDIO_HDMI0"
        // @param supportedMS12AudioProfiles: MS12 audio profiles
        // @example supportedMS12AudioProfiles: ["MUSIC","MOVIE","VOICE"]
        // @param success: Indicates whether the operation was successful
        // @example success: true
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
        // @details Retrieves the video ports supported on the device.
        // @param supportedVideoDisplays: Video ports supported on the device
        // @example supportedVideoDisplays: ["VIDEO_HDMI0","VIDEO_HDMI1"]
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        // @deprecated
        virtual Core::hresult SupportedVideoDisplays(IStringIterator*& supportedVideoDisplays /* @out */, bool& success /* @out */) const = 0;

        // @text defaultresolution
        // @brief Default resolution on the selected video display port.
        // @details Retrieves the default resolution on the selected video display port.
        // @param videoDisplay: Video display port name
        // @example videoDisplay: "VIDEO_HDMI0"
        // @param defaultResolution: Default Resolutions
        // @example defaultResolution: {"defaultResolution":"1080p60"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        // @deprecated
        virtual Core::hresult DefaultResolution(const string& videoDisplay , DefaultResln& defaultResln /* @out */) const = 0;

        // @text supportedresolutions
        // @brief Supported resolutions on the selected video display port.
        // @details Retrieves the supported resolutions on the selected video display port.
        // @param videoDisplay: Video display port name
        // @example videoDisplay: "VIDEO_HDMI0"
        // @param supportedResolutions: Supported Resolutions
        // @example supportedResolutions: ["1080p60","1080p50","720p60"]
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
         // @deprecated
        virtual Core::hresult SupportedResolutions(const string& videoDisplay, IStringIterator*& supportedResolutions /* @out */, bool& success /* @out */ ) const = 0;

        // @property
        // @text hostedid
        // @brief Provides access to the EDID of the host.
        // @details Retrieves the EDID of the host.
        // @param EDID: EDID of the host
        // @example hostEdid: {"EDID":"base64encodedstring"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        // @deprecated
        virtual Core::hresult HostEDID(HostEdid& hostEdid /* @out */) const = 0;

        // @text supportedhdcp
        // @brief Supported hdcp version on the selected video display port.
        // @details Retrieves the supported hdcp version on the selected video display port.
        // @param videoDisplay: Video display port name
        // @example videoDisplay: "VIDEO_HDMI0"
        // @param supportedHDCPVersion: HDCP support
        // @example supportedHDCPVersion: {"supportedHDCPVersion":"2.2"}
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        // @deprecated
        virtual Core::hresult SupportedHdcp(const string& videoDisplay , SupportedHDCPVer& supportedHDCPVer /* @out */) const = 0;
    };
}
}
