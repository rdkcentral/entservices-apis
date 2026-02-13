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
                string bluetooth_mac /* @brief Bluetooth MAC Address */;
                string boxIP /* @brief STB IP Address */;
                string build_type /* @brief Image build type */;
                string device_type /* @brief Device type */;
                string estb_mac /* @brief STB MAC Address */;
                string eth_mac /* @brief Ethernet MAC Address */;
                string friendly_id /* @brief friendly device model name */;
                string imageVersion /* @brief Image version */;
                string version /* @brief Version Info */;
                string software_version /* @brief Software version */;
                string model_number /* @brief Device model number */;
                string wifi_mac /* @brief WIFI Mac Address */;
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL DownloadedFirmwareInfo {
                string currentFWVersion /* @brief The current firmware version */;
                string downloadedFWVersion /* @brief The downloaded firmware version */;
                string downloadedFWLocation /* @brief The location of the downloaded firmware */;
                bool isRebootDeferred /* @brief Whether the device should be rebooted */;
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL SystemError {
                string message /* @brief Error Message */;
            };

            struct EXTERNAL ErrorInfo {
                string message /* @brief Error Message */;
                string code /* @brief Error Code */;
            };

            struct EXTERNAL BlocklistResult {
                ErrorInfo error /* @brief Error Information */;
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL SystemServicesSuccess {
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL AmericaInfo {
                string New_York /* @brief Error Information */;
                string Los_Angeles /* @brief Error Information */;
            };

            struct EXTERNAL EuropeInfo {
                string London /* @brief Error Information */;
            };

            struct EXTERNAL Zoneinfo {
                AmericaInfo America /* @brief Error Information */;
                EuropeInfo Europe /* @brief Error Information */;
            };

            struct EXTERNAL TimeZoneInfo {
                Zoneinfo zoneinfo /* @brief Error Information */;
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

            struct EXTERNAL SystemModeInfo {
                ModeInfo modeinfo /* @brief The mode information */;
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL AccountInfoDetails {
                string accountId /* @brief Account Id */;
                string x1DeviceId /* @brief X1 Device Id */;
                bool XCALSessionTokenAvailable /* @brief XCAL Session Token Available */;
                string experience /* @brief Experience*/;
                string deviceMACAddress /* @brief Device MAC Address */;
                bool firmwareUpdateDisabled /* @brief Whether the firmwareUpdate Disabled */;
            };

            struct EXTERNAL WebBrowserInfo {
                string browserType /* @brief Browser Type*/;
                string version /* @brief Version */;
                string userAgent /* @brief User Agent*/;
            };

            struct EXTERNAL MIMETypeExclusions {
            };

            struct EXTERNAL Features {
            };

            struct EXTERNAL DeviceInfoDetails {
                string quirks /* @brief The list of installed “quirks” */;
                MIMETypeExclusions mimeTypeExclusions /* @brief mime Type Exclusions */;
                Features features /* @brief features */;
                string mimeTypes /* @brief mime Types*/;
                string model /* @brief */;
                string deviceType /* @brief */;
                bool supportsTrueSD /* @brief */;
                WebBrowserInfo webBrowser /* @brief */;
                string HdrCapability /* @brief e.g. HDR10,Dolby Vision,Technicolor Prime */;
                bool canMixPCMWithSurround /* @brief */;
                string publicIP /* @brief Public IP */;
            };

            struct EXTERNAL PlatformConfig {
                AccountInfoDetails AccountInfo /* @brief AccountInfo Details */;
                DeviceInfoDetails DeviceInfo /* @brief DeviceInfo Details */;
                bool success /* @brief Whether the request succeeded */;
            };

            struct EXTERNAL MacAddressesInfo {
                string ecm_mac /* @brief The embedded cable modem MAC address */;
                string estb_mac /* @brief The embedded set-top box MAC address */;
                string moca_mac /* @brief The MOCA MAC address */;
                string eth_mac /* @brief The Ethernet MAC address */;
                string wifi_mac /* @brief The Wifi MAC address */;
                string bluetooth_mac /* @brief The Bluetooth MAC address */;
                string rf4ce_mac /* @brief The Rf4ce MAC address */;
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
                bool WAKEUPSRC_VOICE;
                bool WAKEUPSRC_PRESENCE_DETECTION;
                bool WAKEUPSRC_BLUETOOTH;
                bool WAKEUPSRC_WIFI;
                bool WAKEUPSRC_IR;
                bool WAKEUPSRC_POWER_KEY;
                bool WAKEUPSRC_CEC;
                bool WAKEUPSRC_LAN;
                bool WAKEUPSRC_TIMER;
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

                // @text OnMacAddressesRetreived
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

            };

            virtual Core::hresult Register(ISystemServices::INotification* notification) = 0;
            virtual Core::hresult Unregister(ISystemServices::INotification* notification) = 0;

            // @text getDeviceInfo
            // @brief Collects device details
            // @param params: A list of supported device keys
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
            virtual Core::hresult GetFirmwareDownloadPercent(uint32_t & downloadPercent /* @out */, bool& success /* @out */) = 0;

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
            virtual Core::hresult GetLastWakeupKeyCode(string& wakeupKeyCode /* @out */, bool& success /* @out */) = 0;

            // @text getMfgSerialNumber
            // @brief Gets the Manufacturing Serial Number.
            // @param mfgSerialNumber: Manufacturing Serial Number
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetMfgSerialNumber(string& mfgSerialNumber /* @out */, bool& success /* @out */) = 0;

            // @text getNetworkStandbyMode
            // @brief Returns the network standby mode of the device.
            // @param nwStandby: Whether WakeOnLAN and WakeOnWLAN is supported (true); otherwise, false
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
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetRFCConfig(IStringIterator* const& rfcList, IStringIterator*& RFCConfig /* @out */, bool& success /* @out */) = 0;

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
            // @param TimeZoneInfo: A timezone area
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetTimeZones(TimeZoneInfo& timeZoneInfo /* @out */) = 0;

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
            virtual Core::hresult GetWakeupReason(string& WakeupReason /* @out */, bool& success /* @out */) = 0;

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
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetDeepSleepTimer(const int seconds, SystemServicesSuccess& success /* @out */) = 0;

            // @text setFirmwareAutoReboot
            // @brief Enables or disables the AutoReboot Feature.
            // @param enable: true to enable Autoreboot or false to disable
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetFirmwareAutoReboot(const bool enable, SystemServicesSuccess& success /* @out */) = 0;

            // @text setNetworkStandbyMode
            // @brief Enables or disables the AutoReboot Feature.
            // @param nwStandby: Whether WakeOnLAN and WakeOnWLAN is supported (true); otherwise, false
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult setNetworkStandbyMode(const bool nwStandby, SystemServicesSuccess& success /* @out */) = 0;

            // @text setOptOutTelemetry
            // @brief Sets the telemetry opt-out status.
            // @param OptOut: true for opt-out, otherwise false
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetOptOutTelemetry(const bool OptOut /* @text Opt-Out */, SystemServicesSuccess& success /* @out */) = 0;

            // @text setPowerState
            // @brief Sets the power state of the device.
            // @param powerState: The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON)
            // @param standbyReason: The reason for a standby state
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetPowerState(const string &powerState, const string &standbyReason, SystemServicesSuccess& success /* @out */) = 0;

            // @text setFriendlyName
            // @brief Sets the friendly name of device.
            // @param friendlyName: The friendly name of the device which used to display on the client device list
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetFriendlyName(const string& friendlyName, SystemServicesSuccess& success /* @out */) = 0;

            // @text setBootLoaderSplashScreen
            // @brief Install or update the BootLoader Splash Screens.
            // @param path: Path to the pre-downloaded splash screen file location. Full path with file name
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetBootLoaderSplashScreen(const string& path, ErrorInfo& error /* @out */, bool& success /* @out */) = 0;

            // @text setTerritory
            // @brief Sets the system territory and region.
            // @param territory: territory name
            // @param region: region name
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetTerritory(const string& territory, const string& region, SystemError& error /* @out */, bool& success /* @out */) = 0;

            // @text setTimeZoneDST
            // @brief Sets the system time zone.
            // @param timeZone: The timezone
            // @param accuracy: The timezone accuracy (must be one of the following: INITIAL, INTERIM, FINAL)
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetTimeZoneDST(const string& timeZone, const string& accuracy, SystemServicesSuccess& success /* @out */) = 0;

            // @text updateFirmware
            // @brief Initiates a firmware update.
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult UpdateFirmware(SystemServicesSuccess& success /* @out */) = 0;

            // @text getBootTypeInfo
            // @brief Get the FSR flag from the emmc raw area.
            // @param bootType: BOOT Type Info
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetBootTypeInfo(string &bootType /* @out */, bool& success /* @out */) = 0;

            // @text setMigrationStatus
            // @brief set the Migration Status of the device.
            // @param status: Migration Status
            // @param success: Whether the request succeeded
            virtual Core::hresult SetMigrationStatus(const bool status, bool& success /* @out */) = 0;

            // @text getMigrationStatus
            // @brief set the Migration Status of the device
            // @param MigrationStatus: Migration Status
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetMigrationStatus(string &MigrationStatus /* @out */, bool& success /* @out */) = 0;

            // @text getMacAddresses
            // @brief Gets the MAC address of the device.
            // @param GUID: A unique identifier
            // @param asyncResponse: Whether the event notification succeeded
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetMacAddresses(const string& GUID, bool &asyncResponse /* @out */, bool& success /* @out */) = 0;

            // @text getPlatformConfiguration
            // @brief Returns the supported features and device/account info
            // @param platformConfig: Platform Configuration Details
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetPlatformConfiguration (PlatformConfig& platformConfig /* @out */) = 0;

            // @text setWakeupSrcConfiguration
            // @brief Sets the wakeup source configuration for the input powerState.
            // @param powerState: The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON)
            // @param wakeupSources: Array of Key value pair with wake up sources and its configurations
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetWakeupSrcConfiguration(const string& powerState, ISystemServicesWakeupSourcesIterator* const& wakeupSources, SystemServicesSuccess& success /* @out */) = 0;

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
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetMode(const ModeInfo& modeinfo, SystemServicesSuccess& success /* @out */) = 0;

            // @text uploadLogsAsync
            // @brief Starts background process to upload logs.
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult UploadLogsAsync(SystemServicesSuccess& success /* @out */) = 0;

            // @text abortLogUpload
            // @brief Stops background process to upload logs.
            // @param SystemServicesSuccess: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult AbortLogUpload(SystemServicesSuccess& success /* @out */) = 0;

            // @text setFSRFlag
            // @brief Set the FSR flag into the emmc raw area.
            // @param fsrFlag: FSR flag
            // @param success: Whether the request succeeded
            // @retval ErrorCode::ERROR_NONE: Indicates success
            // @retval ErrorCode::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetFSRFlag(const bool fsrFlag, bool& success /* @out */) = 0;

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
            virtual Core::hresult SetBlocklistFlag(const bool blocklist, BlocklistResult& result /* @out */) = 0;

            // @text getBlocklistFlag
            // @brief Get block list falg.
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

        };
    }
}
