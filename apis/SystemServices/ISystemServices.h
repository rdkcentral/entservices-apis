/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 RDK Management
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

namespace WPEFramework
{
    namespace Exchange
    {
        /* @json 1.0.0 @text:keep */
        struct EXTERNAL ISystemServices : virtual public Core::IUnknown
        {
            enum { ID = ID_SYSTEMSERVICES };

            using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            struct EXTERNAL DeviceInfo {
                string make /* @brief Device manufacturer */;
                string bluetoothMac /* @text bluetooth_mac */ /* @brief Bluetooth MAC Address */ /* @deprecated */;
                string boxIP /* @brief STB IP Address */;
                string buildType /* @text build_type */ /* @brief Image build type */;
                string deviceType /* @text device_type */ /* @brief Device type */ /* @deprecated */;
                string estbMac /* @text estb_mac */ /* @brief STB MAC Address */;
                string ethMac /* @text eth_mac */ /* @brief Ethernet MAC Address */;
                string friendlyId /* @text friendly_id */ /* @brief friendly device model name */;
                string imageVersion /* @brief Image version */;
                string version /* @brief Version Info */;
                string softwareVersion /* @text software_version */ /* @brief Software version */;
                string modelNumber /* @text model_number */ /* @brief Device model number */;
                string wifiMac /* @text wifi_mac */ /* @brief WIFI Mac Address */;
                string modelName /* @brief Device model name */;
                string hardwareID /* @brief Hardware ID */;
                string message /* @brief Error message if input failure */;
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL DownloadedFirmwareInfo {
                string currentFWVersion /* @brief The current firmware version */;
                string downloadedFWVersion /* @brief The downloaded firmware version */;
                string downloadedFWLocation /* @brief The location of the downloaded firmware */;
                bool isRebootDeferred /* @brief Whether the device should be rebooted */;
                bool success /* @brief Whether the request succeeded */;
                uint32_t sysSrvStatus /* @text SysSrv_Status */ /* @brief System service status error code if failure occurs */;
                string errorMessage /* @brief Error message if failure occurs */;
            };

            struct EXTERNAL SystemError {
                string message /* @brief Error Message */;
            };

            struct EXTERNAL BootType {
                string bootType /* @brief BOOT Type Info */;
            };

            struct EXTERNAL MigrationStatus {
                string migrationStatus /* @brief Migration Status */;
            };

            struct EXTERNAL ErrorInfo {
                string message /* @brief Error Message */;
                string code /* @brief Error Code */;
            };

            struct EXTERNAL BlocklistResult {
                bool blocklist /* @brief Whether the device is blocklisted */;
                ErrorInfo error /* @brief Error Information */;
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL SetBlocklistResult {
                ErrorInfo error /* @brief Error Information */;
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL SystemResult {
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL SystemVersionsInfo {
                string stbVersion /* @brief The STB version */;
                string receiverVersion /* @brief The receiver version */;
                string stbTimestamp /* @brief The STB timestamp */;
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL ModeInfo {
                string mode /* @brief The mode (must be one of the following: NORMAL, EAS, WAREHOUSE) */;
                int duration /* @brief The duration */;
            };

            struct EXTERNAL AccountInfoDetails {
                string accountId /* @brief Account Id */;
                string x1DeviceId /* @brief X1 Device Id */;
                bool xCALSessionTokenAvailable /* @text XCALSessionTokenAvailable */ /*@brief XCAL Session Token Available */;
                string experience /* @brief Experience */;
                string deviceMACAddress /* @brief Device MAC Address */;
                bool firmwareUpdateDisabled /* @brief Whether the firmwareUpdate Disabled */;
            };

            struct EXTERNAL WebBrowserInfo {
                string browserType /* @brief Browser Type*/;
                string version /* @brief Version */;
                string userAgent /* @brief User Agent*/;
            };

            struct EXTERNAL MIMETypeExclusions {
                string cdvr /* @text CDVR */;
                string dvr /* @text DVR */;
                string eas /* @text EAS */;
                string ipdvr /* @text IPDVR */;
                string ivod /* @text IVOD */;
                string linearTV /* @text LINEAR_TV */;
                string vod /* @text VOD */;
            };

            struct EXTERNAL Features {
                uint8_t allowSelfSignedWithIPAddress;
                uint8_t supportsSecure /* @text connection.supportsSecure */;
                uint8_t callJavaScriptWithResult /* @text htmlview.callJavaScriptWithResult */;
                uint8_t cookies /* @text htmlview.cookies */;
                uint8_t disableCSSAnimations /* @text htmlview.disableCSSAnimations */;
                uint8_t evaluateJavaScript /* @text htmlview.evaluateJavaScript */;
                uint8_t headers /* @text htmlview.headers */;
                uint8_t httpCookies /* @text htmlview.httpCookies */;
                uint8_t postMessage /* @text htmlview.postMessage */;
                uint8_t urlpatterns /* @text htmlview.urlpatterns */;
                uint8_t keySource;
                uint8_t uhd4kDecode /* @text uhd_4k_decode */;
            };

            struct EXTERNAL DeviceInfoDetails {
                string quirks /* @brief The list of installed “quirks” */;
                MIMETypeExclusions mimeTypeExclusions /* @brief mime Type Exclusions */;
                Features features /* @brief features */;
                string mimeTypes /* @brief mime Types*/;
                string model /* @brief  model */;
                string deviceType /* @brief Device Type*/;
                bool supportsTrueSD /* @brief SD Support */;
                WebBrowserInfo webBrowser /* @brief  webBrowser Info */;
                string hdrCapability /* @text HdrCapability @brief e.g. HDR10,Dolby Vision,Technicolor Prime */;
                bool canMixPCMWithSurround /* @brief PCM with Surround */;
                string publicIP /* @brief Public IP */;
            };

            struct EXTERNAL PlatformConfig {
                AccountInfoDetails accountInfo /* @text AccountInfo @brief AccountInfo Details */;
                DeviceInfoDetails deviceInfo /* @text DeviceInfo @brief DeviceInfo Details */;
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL MacAddressesInfo {
                string ecmMac /* @text ecm_mac */ /* @brief The embedded cable modem MAC address */;
                string estbMac /* @text estb_mac */ /* @brief The embedded set-top box MAC address */;
                string mocaMac /* @text moca_mac */ /* @brief The MOCA MAC address */;
                string ethMac /* @text eth_mac */ /* @brief The Ethernet MAC address */;
                string wifiMac /* @text wifi_mac */ /* @brief The Wifi MAC address */;
                string bluetoothMac /* @text bluetoothMac */ /* @brief The Bluetooth MAC address */;
                string rf4ceMac /* @text rf4ce_mac */ /* @brief The Rf4ce MAC address */;
                string info /* @brief Additional information (only if any of the above data is missing) */;
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL FirmwareUpdateInfo {
                int status /* @brief The firmware update status */;
                string responseString /* @brief A custom response */;
                string firmwareUpdateVersion /* @brief The next firmware update version */;
                bool rebootImmediately /* @brief The value true indicates that the device has to be rebooted immediately or false otherwise */;
                bool updateAvailable /* @brief The value false indicates that there is no update available */;
                int updateAvailableEnum /* @brief The update available details (must be one of the following: 0, 1, 2, 3) */;
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL TerritoryChangedInfo {
                string oldTerritory /* @brief old territory */;
                string newTerritory /* @brief new territory */;
                string oldRegion /* @brief old region */;
                string newRegion /* @brief new region */;
            };

            struct EXTERNAL TimeZoneDSTChangedInfo {
                string oldTimeZone /* @brief old time zone */;
                string newTimeZone /* @brief new time zone */;
                string oldAccuracy /* @brief old time zone accuracy */;
                string newAccuracy /* @brief new time zone accuracy */;
            };

             struct EXTERNAL WakeupSources {
                bool voice /* @text WAKEUPSRC_VOICE */ /* @brief Voice Wake up */;
                bool presenceDetection /* @text WAKEUPSRC_PRESENCE_DETECTION */ /* @brief Presence detection wake up */;
                bool bluetooth /* @text WAKEUPSRC_BLUETOOTH */ /* @brief Bluetooth Wakeup */;
                bool wifi /* @text WAKEUPSRC_WIFI */ /* @brief WiFi Wake up*/;
                bool ir /* @text WAKEUPSRC_IR */ /* @brief IR Remote Wake up */;
                bool powerKey /* @text WAKEUPSRC_POWER_KEY */ /* @brief Power Button Wake up - GPIO */;
                bool cec /* @text WAKEUPSRC_CEC */ /* @brief HDMI CEC command Wake up */;
                bool lan /* @text WAKEUPSRC_LAN */ /* @brief LAN wake up */;
                bool timer /* @text WAKEUPSRC_TIMER */ /* @brief Timer Wake up */;
            };


            using ISystemServicesWakeupSourcesIterator = RPC::IIteratorType<WakeupSources, ID_SYSTEMSERVICES_WAKEUPSOURCES_ITERATOR>;

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown 
            {
                enum { ID = ID_SYSTEMSERVICES_NOTIFICATION };

                // @text onFirmwareUpdateInfoReceived
                // @brief Triggered when the getFirmwareUpdateInfo asynchronous method is invoked.
                // @param FirmwareUpdateInfo: The firmware update information
                virtual void OnFirmwareUpdateInfoReceived(const FirmwareUpdateInfo &firmwareUpdateInfo) {};

                // @text onRebootRequest
                // @brief Triggers when a device reboot request is made
                // @param requestedApp: The source of the reboot
                // @param rebootReason: The reboot reason
                virtual void OnRebootRequest(const string& requestedApp, const string& rebootReason) {};

                // @text onSystemPowerStateChanged
                // @brief Triggered when the power manager detects a device power state change.
                // @param powerState: The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON)
                // @param currentPowerState: The current power state
                virtual void OnSystemPowerStateChanged(const string& powerState, const string& currentPowerState) {};

                // @text onTerritoryChanged
                // @brief Triggered when the device territory changed.
                // @param TerritoryChangedInfo: The Territory changed information
                virtual void OnTerritoryChanged(const TerritoryChangedInfo &territoryChangedInfo) {};

                // @text onTimeZoneDSTChanged
                // @brief Triggered when device time zone changed.
                // @param TimeZoneDSTChangedInfo: The TimeZoneDST changed information
                virtual void OnTimeZoneDSTChanged(const TimeZoneDSTChangedInfo& timeZoneDSTChangedInfo) {};

                // @text onMacAddressesRetreived
                // @brief Triggered when the getMacAddresses asynchronous method is invoked.
                // @param MacAddressesInfo: The Mac Addresses details 
                virtual void OnMacAddressesRetreived(const MacAddressesInfo& macAddressesInfo) {};

                // @text onSystemModeChanged
                // @brief Triggers when the system mode is changed successfully.
                // @param mode: The mode (must be one of the following: NORMAL, EAS, WAREHOUSE)
                virtual void OnSystemModeChanged(const string& mode) {};

                // @text onLogUpload
                // @brief Triggered when logs upload process is done or stopped.
                // @param logUploadStatus: Upload status (must be one of the following: UPLOAD_SUCCESS, UPLOAD_FAILURE, UPLOAD_ABORTED)
                virtual void OnLogUpload(const string& logUploadStatus) {};

                // @text onNetworkStandbyModeChanged
                // @brief Triggered when the network standby mode is changed.
                // @param nwStandby: The network standby mode
                virtual void OnNetworkStandbyModeChanged(const bool nwStandby) {};

                // @text onFirmwareUpdateStateChange
                // @brief Triggered when the firmware update state is changed.
                // @param firmwareUpdateStateChange: The firmware update state change
                virtual void OnFirmwareUpdateStateChanged(const int firmwareUpdateStateChange) {};

                // @text onTemperatureThresholdChanged
                // @brief Triggered when the temperature threshold is changed.
                // @param thresholdType: The type of temperature threshold
                // @param exceeded: Whether the threshold is exceeded
                // @param temperature: The current temperature
                virtual void OnTemperatureThresholdChanged(const string& thresholdType, const bool exceeded, const string& temperature) {};

                // @text onSystemClockSet
                // @brief Triggered when time source state has changed.
                virtual void OnSystemClockSet() {};

                // @text onFirmwarePendingReboot
                // @brief Triggered when system is in maintenance window
                // @param fireFirmwarePendingReboot: time in seconds for pending reboot
                virtual void OnFirmwarePendingReboot(const int fireFirmwarePendingReboot) {};

                // @text onFriendlyNameChanged
                // @brief Triggered when the friendly name is changed.
                // @param friendlyName: The new friendly name
                virtual void OnFriendlyNameChanged(const string& friendlyName) {};

                // @text onDeviceMgtUpdateReceived
                // @brief Triggered when Device Mgt settings update is received
                // @param source: The source of the update
                // @param type: The type of update
                // @param success: Whether the update was successful
                virtual void OnDeviceMgtUpdateReceived(const string& source, const string& type, const bool success) {};

                // @text onBlocklistChanged
                // @brief Triggered when blocklist flag has changed.
                // @param oldBlocklistFlag: The previous blocklist flag
                // @param newBlocklistFlag: The new blocklist flag
                virtual void OnBlocklistChanged(const string& oldBlocklistFlag, const string& newBlocklistFlag) {};

                // @text onTimeStatusChanged
                // @brief Triggered when time status has changed.
                // @param TimeQuality: The quality of the time
                // @param TimeSrc: The source of the time
                // @param Time: The current time
                virtual void OnTimeStatusChanged(const string& TimeQuality, const string& TimeSrc, const string& Time){};
            };

            virtual Core::hresult Register(ISystemServices::INotification* notification) = 0;
            virtual Core::hresult Unregister(ISystemServices::INotification* notification) = 0;

            // @text getDeviceInfo
            // @brief Collects device details
            // @param params: A list of Supported device keys
            // @param deviceInfo: Device Information
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetDeviceInfo(IStringIterator* const& params, DeviceInfo& deviceInfo /* @out */) = 0;

            // @text getDownloadedFirmwareInfo
            // @brief Returns information about firmware downloads.
            // @param DownloadedFirmwareInfo: Downloaded Firmware information
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetDownloadedFirmwareInfo(DownloadedFirmwareInfo& downloadedFirmwareInfo /* @out */) = 0;

            // @text getFirmwareDownloadPercent
            // @brief Gets the current download percentage.
            // @param downloadPercent: Current download percentage (0-100)
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetFirmwareDownloadPercent(int32_t & downloadPercent /* @out */, bool& success /* @out */) = 0;

            // @text getFirmwareUpdateInfo
            // @brief Checks the firmware update information.
            // @param GUID: A unique identifier
            // @param asyncResponse: Whether the event notification succeeded
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetFirmwareUpdateInfo(const string& GUID, bool &asyncResponse /* @out */, bool& success /* @out */) = 0;

            // @text getFirmwareUpdateState
            // @brief Checks the state of the firmware update.
            // @param firmwareUpdateState: The state (must be one of the following: Uninitialized, Requesting, Downloading, Failed, DownLoad Complete, Validation Complete, Preparing to Reboot)
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetFirmwareUpdateState(int& firmwareUpdateState /* @out */, bool& success /* @out */) = 0;

            // @text getLastFirmwareFailureReason
            // @brief Retrieves the last firmware failure reason.
            // @param failReason: The reason the failure occurred
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetLastFirmwareFailureReason(string& failReason /* @out */, bool& success /* @out */) = 0;

            // @text getLastWakeupKeyCode
            // @brief Returns the last wakeup keycode.
            // @param wakeupKeyCode: The last wakeup keycode
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetLastWakeupKeyCode(int& wakeupKeyCode /* @out */, bool& success /* @out */) = 0;

            // @text getMfgSerialNumber
            // @brief Gets the Manufacturing Serial Number.
            // @param mfgSerialNumber: Manufacturing Serial Number
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetMfgSerialNumber(string& mfgSerialNumber /* @out */, bool& success /* @out */) = 0;

            // @text getNetworkStandbyMode
            // @brief Returns the network standby mode of the device.
            // @param nwStandby: Whether WakeOnLAN and WakeOnWLAN is Supported (true); otherwise, false
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetNetworkStandbyMode(bool& nwStandby /* @out */, bool& success /* @out */) = 0;

            // @text getPowerState
            // @brief Returns the power state of the device.
            // @param powerState: The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON)
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetPowerState(string& powerState /* @out */, bool& success /* @out */) = 0;

            // @text getPowerStateBeforeReboot
            // @brief Returns the power state before reboot.
            // @param state: The power state
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetPowerStateBeforeReboot(string& state /* @out */, bool& success /* @out */) = 0;

            // @text getRFCConfig
            // @brief Returns information that is related to RDK Feature Control (RFC) configurations.
            // @param rfcList: A list of RFC properties to query
            // @param RFCConfig: A list of specified RFC properties
            // @param SysSrv_Status: System service status error code if failure occurs
            // @param errorMessage: Error message if failure occurs
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetRFCConfig(IStringIterator* const& rfcList, string& RFCConfig /* @out */, uint32_t& SysSrv_Status /* @out */, string& errorMessage /* @out */, bool& success /* @out */) = 0;

            // @text getSerialNumber
            // @brief Returns the device serial number.
            // @param serialNumber: The serial number
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetSerialNumber(string& serialNumber /* @out */, bool& success /* @out */) = 0;

            // @text getFriendlyName
            // @brief Returns the friendly name set by setFriendlyName API or default value.
            // @param friendlyName: The friendly name of the device which used to display on the client device list
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetFriendlyName(string& friendlyName /* @out */, bool& success /* @out */) = 0;

            // @text getTerritory
            // @brief Gets the configured system territory and region.
            // @param territory: territory name
            // @param region: region name
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetTerritory(string& territory /* @out */, string& region /* @out */, bool& success /* @out */) = 0;

            // @text getTimeZones
            // @brief Returns the friendly name set by setFriendlyName API or default value.
            // @param timeZones: A list of available timezones from the system
            // @param zoneinfo: A timezone area
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetTimeZones(IStringIterator* const& timeZones, string& zoneinfo /* @out @opaque */, bool& success /* @out */) = 0;

            // @text getTimeZoneDST
            // @brief Gets the available timezones from the system’s time zone database.
            // @param timeZone: The timezone
            // @param accuracy: The timezone accuracy (must be one of the following: INITIAL, INTERIM, FINAL)
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetTimeZoneDST(string& timeZone /* @out */, string& accuracy /* @out */, bool& success /* @out */) = 0;

            // @text getWakeupReason
            // @brief Returns the reason for the device coming out of deep sleep.
            // @param WakeupReason: The reason 
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetWakeupReason(string& wakeupReason /* @out */, bool& success /* @out */) = 0;

            // @text isOptOutTelemetry
            // @brief Checks the telemetry opt-out status.
            // @param OptOut: true for opt-out, otherwise false
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult IsOptOutTelemetry(bool& OptOut /* @out @text Opt-Out*/, bool& success /* @out */) = 0;

            // @text reboot
            // @brief Requests that the system performs a reboot of the set-top box.
            // @param rebootReason: The reboot reason
            // @param IARM_Bus_Call_STATUS: IARM BUS status
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult Reboot(const string& rebootReason, int& IARM_Bus_Call_STATUS /* @out */, bool& success /* @out */) = 0;

            // @text setDeepSleepTimer
            // @brief Sets the deep sleep timeout period.
            // @param seconds: The deep sleep timeout in seconds
            // @param SysSrv_Status: System service status error code if failure occurs
            // @param errorMessage: Error message if failure occurs
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetDeepSleepTimer(const int seconds, uint32_t& SysSrv_Status /* @out */, string& errorMessage /* @out */, bool& success /* @out */) = 0;

            // @text setFirmwareAutoReboot
            // @brief Enables or disables the AutoReboot Feature.
            // @param enable: true to enable Autoreboot or false to disable
            // @param SystemResult: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetFirmwareAutoReboot(const bool enable, SystemResult& result /* @out */) = 0;

            // @text setNetworkStandbyMode
            // @brief Enables or disables the AutoReboot Feature.
            // @param nwStandby: Whether WakeOnLAN and WakeOnWLAN is Supported (true); otherwise, false
            // @param SystemResult: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetNetworkStandbyMode(const bool nwStandby, SystemResult& result /* @out */) = 0;

            // @text setOptOutTelemetry
            // @brief Sets the telemetry opt-out status.
            // @param OptOut: true for opt-out, otherwise false
            // @param SystemResult: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetOptOutTelemetry(const bool OptOut /* @text Opt-Out */, SystemResult& result /* @out */) = 0;

            // @text setPowerState
            // @brief Sets the power state of the device.
            // @param powerState: The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON)
            // @param standbyReason: The reason for a standby state
            // @param SysSrv_Status: System service status error code if failure occurs
            // @param errorMessage: Error message if failure occurs
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetPowerState(const string &powerState, const string &standbyReason, uint32_t& SysSrv_Status /* @out */, string& errorMessage /* @out */, bool& success /* @out */) = 0;

            // @text setFriendlyName
            // @brief Sets the friendly name of device.
            // @param friendlyName: The friendly name of the device which used to display on the client device list
            // @param SystemResult: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetFriendlyName(const string& friendlyName, SystemResult& result /* @out */) = 0;

            // @text setBootLoaderSplashScreen
            // @brief Install or update the BootLoader Splash Screens.
            // @param path: Path to the pre-downloaded splash screen file location. Full path with file name
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetBootLoaderSplashScreen(const string& path, ErrorInfo& error /* @out */, bool& success /* @out */) = 0;

            // @text setTerritory
            // @brief Sets the system territory and region.
            // @param territory: territory name
            // @param region: region name
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetTerritory(const string& territory, const string& region, SystemError& error /* @out */, bool& success /* @out */) = 0;

            // @text setTimeZoneDST
            // @brief Sets the system time zone.
            // @param timeZone: The timezone
            // @param accuracy: The timezone accuracy (must be one of the following: INITIAL, INTERIM, FINAL)
            // @param SysSrv_Status: System service status error code if failure occurs
            // @param errorMessage: Error message if failure occurs
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetTimeZoneDST(const string& timeZone, const string& accuracy, uint32_t& SysSrv_Status /* @out */, string& errorMessage /* @out */, bool& success /* @out */) = 0;

            // @text updateFirmware
            // @brief Initiates a firmware update.
            // @param SystemResult: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult UpdateFirmware(SystemResult& result /* @out */) = 0;

            // @text getBootTypeInfo
            // @brief Get the FSR flag from the emmc raw area.
            // @param BootType: BOOT Type Info
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetBootTypeInfo(BootType &bootType /* @out */) = 0;

            // @text setMigrationStatus
            // @brief set the Migration Status of the device.
            // @param status: Migration Status
            // @param success: Whether the request succeeded
            virtual Core::hresult SetMigrationStatus(const string& status, bool& success /* @out */) = 0;

            // @text getMigrationStatus
            // @brief get the Migration Status of the device
            // @param MigrationStatus: Migration Status
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetMigrationStatus(MigrationStatus &migrationStatus /* @out */) = 0;

            // @text getMacAddresses
            // @brief Gets the MAC address of the device.
            // @param GUID: A unique identifier
            // @param asyncResponse: Whether the event notification succeeded
            // @param SysSrv_Status: System service status error code if failure occurs
            // @param errorMessage: Error message if failure occurs
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetMacAddresses(const string& GUID, bool &asyncResponse /* @out */, uint32_t& SysSrv_Status /* @out */, string& errorMessage /* @out */, bool& success /* @out */) = 0;

            // @text getPlatformConfiguration
            // @brief Returns the Supported features and device/account info
            // @param query: Query for support of a particular feature, e.g. AccountInfo.accountId
            // @param platformConfig: Platform Configuration Details
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetPlatformConfiguration (const string &query, PlatformConfig& platformConfig /* @out */) = 0;

            // @text setWakeupSrcConfiguration
            // @brief Sets the wakeup source configuration for the input powerState.
            // @param powerState: The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON)
            // @param wakeupSources: Array of Key value pair with wake up sources and its configurations
            // @param SystemResult: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetWakeupSrcConfiguration(const string& powerState, ISystemServicesWakeupSourcesIterator* const& wakeupSources, SystemResult& result /* @out */) = 0;

            // @text getSystemVersions
            // @brief Returns system version details.
            // @param SystemVersionsInfo: system version details
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetSystemVersions(SystemVersionsInfo& systemVersionsInfo /* @out */) = 0;

            // @text requestSystemUptime
            // @brief Returns the device uptime.
            // @param systemUptime: The uptime, in seconds, of the device
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult RequestSystemUptime(string& systemUptime /* @out */, bool& success /* @out */) = 0;

            // @text setMode
            // @brief Sets the mode of the set-top box for a specific duration before returning to normal mode.
            // @param ModeInfo: The mode information
            // @param SysSrv_Status: System service status error code if failure occurs
            // @param errorMessage: Error message if failure occurs
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetMode(const ModeInfo& modeInfo, uint32_t& SysSrv_Status /* @out */, string& errorMessage /* @out */, bool& success /* @out */) = 0;

            // @text uploadLogsAsync
            // @brief Starts background process to upload logs.
            // @param SystemResult: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult UploadLogsAsync(SystemResult& result /* @out */) = 0;

            // @text abortLogUpload
            // @brief Stops background process to upload logs.
            // @param SystemResult: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult AbortLogUpload(SystemResult& result /* @out */) = 0;

            // @text setFSRFlag
            // @brief Set the FSR flag into the emmc raw area.
            // @param fsrFlag: FSR flag
            // @param SystemResult: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetFSRFlag(const bool fsrFlag, SystemResult& result /* @out */) = 0;

            // @text getFSRFlag
            // @brief Get the FSR flag from the emmc raw area.
            // @param fsrFlag: FSR flag
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetFSRFlag(bool &fsrFlag /* @out */, bool& success /* @out */) = 0;

            // @text setBlocklistFlag
            // @brief To update Blocklist flag.
            // @param blocklist: Blocklist flag
            // @param BlocklistResult: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetBlocklistFlag(const bool blocklist, SetBlocklistResult& result /* @out */) = 0;

            // @text getBlocklistFlag
            // @brief Get block list flag.
            // @param BlocklistResult: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetBlocklistFlag(BlocklistResult& result /* @out */) = 0;

            // @text getBuildType
            // @brief Returns build type of the image flashed on the device.
            // @param build_type: Image build type
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetBuildType(string& buildType /* @out @text build_type */, bool& success /* @out */) = 0;

            // @text getTimeStatus
            // @brief Get the time status on the device.
            // @param TimeQuality: Time Quality
            // @param TimeSrc: Time Source
            // @param Time: Current Time
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetTimeStatus(string& TimeQuality /* @out */, string& TimeSrc /* @out */, string& Time /* @out */, bool& success /* @out */) = 0;
        };
    }
}
