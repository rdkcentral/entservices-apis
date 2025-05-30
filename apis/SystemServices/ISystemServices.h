/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2025 RDK Management
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

            struct EXTERNAL SystemServicesSuccess {
                bool success;
            };

            struct EXTERNAL ModeInfo {
                string mode;
                int duration;
            };

            struct EXTERNAL SystemModeInfo {
                ModeInfo modeinfo;
                bool success;
            };

            struct EXTERNAL PreviousRebootInfo {
                string timestamp;
                string reason;
                string source;
                string customReason;
                string otherReason;
                bool success;
            };

            struct EXTERNAL RebootInfo {
                string timestamp;
                string reason;
                string source;
                string customReason;
                string otherReason;
                string lastHardPowerReset;
                bool success;
            };

            struct EXTERNAL SystemVersionsInfo {
                string stbVersion;
                string receiverVersion;
                string stbTimestamp;
                bool success;            
            };

            struct EXTERNAL DownloadedFirmwareInfo {
                string currentFWVersion;
                string downloadedFWVersion;
                string downloadedFWLocation;
                bool isRebootDeferred;
                bool success;
            };

            struct EXTERNAL FirmwareUpdateInfo {
                int status;
                string responseString;
                string firmwareUpdateVersion;
                bool rebootImmediately;
                bool updateAvailable;
                int updateAvailableEnum;
                bool success;
            };

            struct EXTERNAL MacAddressesInfo {
                string ecm_mac;
                string estb_mac;
                string moca_mac;
                string eth_mac;
                string wifi_mac;
                string rf4ce_mac;
                string info;
                bool success;
            };

            struct EXTERNAL TerritoryChangedInfo {
                string oldTerritory;
                string newTerritory;
                string oldRegion;
                string newRegion;
            };

            struct EXTERNAL TimeZoneDSTChangedInfo {
                string oldTimeZone;
                string newTimeZone;
                string oldAccuracy;
                string newAccuracy;
            };

            struct EXTERNAL TemperatureThresholds {
                string WARN;
                string MAX;
                string temperature;
            };

            struct EXTERNAL TemperatureThresholdsInfo {
                TemperatureThresholds temperatureThresholds;
                bool success;
            };

            struct EXTERNAL ErrorInfo {
                string message;
                string code;
            };

            struct EXTERNAL BlocklistResult {
                ErrorInfo error;
                bool success;
            };

            struct EXTERNAL AmericaInfo {
                string New_York;
                string Los_Angeles;
            };

            struct EXTERNAL EuropeInfo {
                string London;
            };

            struct EXTERNAL Zoneinfo {
                AmericaInfo America;
                EuropeInfo Europe;
            };

            struct EXTERNAL TimeZoneInfo {
                Zoneinfo zoneinfo;
                bool success;
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

            struct EXTERNAL XconfParams {
                string env;
        	string eStbMac;
		string model;
        	string firmwareVersion;
	    };

	    struct EXTERNAL XconfParamsResult {
                XconfParams xconfParams;
		bool success;
            };

            struct EXTERNAL TemperatureThresholdsSet {
  		string WARN;
        	string MAX;
	    };

            using ISystemServicesWakeupSourcesIterator = RPC::IIteratorType<WakeupSources, ID_SYSTEMSERVICES_WAKEUPSOURCES_ITERATOR>;

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown 
            {
                enum { ID = ID_SYSTEMSERVICES_NOTIFICATION };

                // @text OnFirmwarePendingReboot
                // @brief Triggered when the fireFirmwarePendingReboot method is invoked.
                // @param fireFirmwarePendingReboot - in - int
                // @param success - in - bool
                virtual void OnFirmwarePendingReboot (const int fireFirmwarePendingReboot, const bool success) {};

                // @text onFirmwareUpdateInfoReceived
                // @brief Triggered when the getFirmwareUpdateInfo asynchronous method is invoked.
                // @param FirmwareUpdateInfo - in - struct
                virtual void OnFirmwareUpdateInfoReceived (const FirmwareUpdateInfo &firmwareUpdateInfo) {};

                // @text onFirmwareUpdateStateChange
                // @brief Triggered when the state of a firmware update changes.
                // @param firmwareUpdateStateChange - in - int
                virtual void OnFirmwareUpdateStateChange (const int firmwareUpdateStateChange) {};

                // @text onMacAddressesRetreived
                // @brief Triggered when the getMacAddresses asynchronous method is invoked.
                // @param MacAddressesInfo - in - struct
                virtual void OnMacAddressesRetreived (const MacAddressesInfo &macAddressesInfo) {};

                // @text onNetworkStandbyModeChanged
                // @brief Triggered when the network standby mode setting changes.
                // @param nwStandby - in - bool
                virtual void OnNetworkStandbyModeChanged (const bool nwStandby) {};
                
                // @text onRebootRequest
                // @brief Triggered when an application invokes the reboot
                // @param requestedApp - in - string
                // @param rebootReason - in - string
                virtual void OnRebootRequest (const string& requestedApp, const string& rebootReason) {};
                
                // @text onSystemClockSet
                // @brief Triggered when the clock on the set-top device is updated.
                virtual void OnSystemClockSet () {};
                
                // @text onSystemModeChanged
                // @brief Triggered when the device operating mode changes.
                // @param mode - in - string
                virtual void OnSystemModeChanged (const string& mode) {};
                
                // @text onSystemPowerStateChanged
                // @brief Triggered when the power manager detects a device power state change.
                // @param powerState - in - string
                // @param currentPowerState - in - string
                virtual void OnSystemPowerStateChanged (const string& powerState, const string& currentPowerState) {};
                
                // @text onFriendlyNameChanged
                // @brief Triggered when the device friendly name change.
                // @param friendlyName - in - string
                virtual void OnFriendlyNameChanged (const string& friendlyName) {};
                
                // @text onTemperatureThresholdChanged
                // @brief Triggered when the device temperature changes beyond the WARN or MAX limits.
                // @param thresholdType - in - string
                // @param exceeded - in - bool
                // @param temperature - in - string
                virtual void OnTemperatureThresholdChanged (const string& thresholdType, const bool exceeded, const string& temperature) {};
                
                // @text onTerritoryChanged
                // @brief Triggered when the device territory changed.
                // @param TerritoryChangedInfo - in - struct
                virtual void OnTerritoryChanged (const TerritoryChangedInfo &territoryChangedInfo) {};
                
                // @text onDeviceMgtUpdateReceived
                // @brief Triggered when the device management update completes.
                // @param source - in - string
                // @param type - in - string
                // @param success - in - bool
                virtual void OnDeviceMgtUpdateReceived (const string& source, const string& type, const bool success) {};
                
                // @text onTimeZoneDSTChanged
                // @brief Triggered when device time zone changed.
                // @param TimeZoneDSTChangedInfo - in - struct
                virtual void OnTimeZoneDSTChanged (const TimeZoneDSTChangedInfo &timeZoneDSTChangedInfo) {};
                
                // @text onLogUpload
                // @brief Triggered when logs upload process is done or stopped.
                // @param logUploadStatus - in - string
                virtual void OnLogUpload (const string& logUploadStatus) {};
                
                // @text onBlocklistChanged
                // @brief Triggers when the blocklist flag is modified.
                // @param oldBlocklistFlag - in - bool
                // @param newBlocklistFlag - in - bool
                virtual void OnBlocklistChanged (const bool oldBlocklistFlag, const bool newBlocklistFlag) {};
            };

            virtual Core::hresult Register(ISystemServices::INotification* notification) = 0;
            virtual Core::hresult Unregister(ISystemServices::INotification* notification) = 0;
            
            // @text clearLastDeepSleepReason
            // @brief Clears the last deep sleep reason
            // @param SystemServicesSuccess - out
            virtual Core::hresult ClearLastDeepSleepReason(SystemServicesSuccess& success /* @out */) = 0;
            
            // @text deletePersistentPath
            // @brief Deletes persistent path associated with a callsign.
            // @param callsign - in - string
            // @param type - in - string
            // @param SystemServicesSuccess - out
            virtual Core::hresult DeletePersistentPath(const string& callsign, const string& type, SystemServicesSuccess& success /* @out */) = 0;
            
            // @text enableMoca
            // @brief Enables (or disables) Moca support for the platform.
            // @param value - in - bool
            // @param SystemServicesSuccess - out
            virtual Core::hresult EnableMoca(const bool value, SystemServicesSuccess& success /* @out */) = 0;
            
            // @text enableXREConnectionRetention
            // @brief Enables (or disables) XRE Connection Retention option.
            // @param enable - in - bool
            // @param SystemServicesSuccess - out
            virtual Core::hresult EnableXREConnectionRetention(const bool enable, SystemServicesSuccess& success /* @out */) = 0;
            
            // @text fireFirmwarePendingReboot
            // @brief Notifies the device about a pending reboot.
            // @param SystemServicesSuccess - out
            virtual Core::hresult FireFirmwarePendingReboot(SystemServicesSuccess& success /* @out */) = 0;
            
            // @text getAvailableStandbyModes
            // @brief Queries the available standby modes.
            // @param supportedStandbyModes - out - array of supported standby modes
            // @param success - out - bool
            virtual Core::hresult GetAvailableStandbyModes(IStringIterator*& supportedStandbyModes /* @out */, bool& success /* @out */) = 0;
            
            // @text getCoreTemperature
            // @brief Returns the core temperature of the device.
            // @param temperature - out - string
            // @param success - out - bool
            virtual Core::hresult GetCoreTemperature(string& temperature /* @out */, bool& success /* @out */) = 0;
            
            // @text getDeviceInfo
            // @brief Collects device details
            // @param params - in - A list of supported device keys
            // @param estb_mac - out - string
            // @param success - out - bool
            virtual Core::hresult GetDeviceInfo(IStringIterator* const& params, string& estb_mac /* @out */, bool& success /* @out */) = 0;
            
            // @text getDownloadedFirmwareInfo
            // @brief Returns information about firmware downloads.
            // @param DownloadedFirmwareInfo - out - struct
            virtual Core::hresult GetDownloadedFirmwareInfo(DownloadedFirmwareInfo& downloadedFirmwareInfo /* @out */) = 0;
            
            // @text getFirmwareDownloadPercent
            // @brief Gets the current download percentage.
            // @param downloadPercent - out - int
            // @param success - out - bool
            virtual Core::hresult GetFirmwareDownloadPercent(int& downloadPercent /* @out */, bool& success /* @out */) = 0;
            
            // @text getFirmwareUpdateInfo
            // @brief Checks the firmware update information.
            // @param GUID - in - string
            // @param asyncResponse - out - bool
            // @param success - out - bool
            virtual Core::hresult GetFirmwareUpdateInfo(const string& GUID, bool &asyncResponse /* @out */, bool& success /* @out */) = 0;
            
            // @text getFirmwareUpdateState
            // @brief Checks the state of the firmware update.
            // @param firmwareUpdateState - out - int
            // @param success - out - bool
            virtual Core::hresult GetFirmwareUpdateState(int& firmwareUpdateState /* @out */, bool& success /* @out */) = 0;
            
            // @text getLastDeepSleepReason
            // @brief Retrieves the last deep sleep reason.
            // @param reason - out - string
            // @param success - out - bool
            virtual Core::hresult GetLastDeepSleepReason(string& reason /* @out */, bool& success /* @out */) = 0;
            
            // @text getLastFirmwareFailureReason
            // @brief Retrieves the last firmware failure reason.
            // @param failReason - out - string
            // @param success - out - bool
            virtual Core::hresult GetLastFirmwareFailureReason(string& failReason /* @out */, bool& success /* @out */) = 0;
            
            // @text getLastWakeupKeyCode
            // @brief Returns the last wakeup keycode.
            // @param wakeupKeyCode - out - string
            // @param success - out - bool
            virtual Core::hresult GetLastWakeupKeyCode(string& wakeupKeyCode /* @out */, bool& success /* @out */) = 0;
            
            // @text getMacAddresses
            // @brief Gets the MAC address of the device.
            // @param GUID - in - string
            // @param asyncResponse - out - bool
            // @param success - out - bool
            virtual Core::hresult GetMacAddresses(const string& GUID, bool &asyncResponse /* @out */, bool& success /* @out */) = 0;
            
            // @text getMfgSerialNumber
            // @brief Gets the Manufacturing Serial Number.
            // @param mfgSerialNumber - out - string
            // @param success - out - bool
            virtual Core::hresult GetMfgSerialNumber(string& mfgSerialNumber /* @out */, bool& success /* @out */) = 0;
            
            // @text getMode
            // @brief Returns the currently set mode information.
            // @param SystemModeInfo - out - struct
            virtual Core::hresult GetMode(SystemModeInfo& systemMode /* @out */) = 0;
            
            // @text getNetworkStandbyMode
            // @brief Returns the network standby mode of the device.
            // @param nwStandby - out - bool
            // @param success - out - bool
            virtual Core::hresult GetNetworkStandbyMode(bool& nwStandby /* @out */, bool& success /* @out */) = 0;
            
            // @text getOvertempGraceInterval
            // @brief Returns the over-temperature grace interval value.
            // @param graceInterval - out - string
            // @param success - out - bool
            virtual Core::hresult GetOvertempGraceInterval(string& graceInterval /* @out */, bool& success /* @out */) = 0;
            
            // getPlatformConfiguration // need to do
            
            // @text getPowerState
            // @brief Returns the power state of the device.
            // @param powerState - out - string
            // @param success - out - bool
            virtual Core::hresult GetPowerState(string& powerState /* @out */, bool& success /* @out */) = 0;
            
            // @text getPowerStateBeforeReboot
            // @brief Returns the power state before reboot.
            // @param state - out - string
            // @param success - out - bool
            virtual Core::hresult GetPowerStateBeforeReboot(string& state /* @out */, bool& success /* @out */) = 0;
            
            // @text getPowerStateIsManagedByDevice
            // @brief Checks whether the power state is managed by the device.
            // @param powerStateManagedByDevice - out - bool
            // @param success - out - bool
            virtual Core::hresult GetPowerStateIsManagedByDevice(bool& powerStateManagedByDevice /* @out */, bool& success /* @out */) = 0;
            
            // @text getPreferredStandbyMode
            // @brief Returns the preferred standby mode.
            // @param preferredStandbyMode - out - string
            // @param success - out - bool
            virtual Core::hresult GetPreferredStandbyMode(string& preferredStandbyMode /* @out */, bool& success /* @out */) = 0;
            
            // @text getPreviousRebootInfo
            // @brief Returns the preferred standby mode.
            // @param PreviousRebootInfo - out - struct
            virtual Core::hresult GetPreviousRebootInfo(PreviousRebootInfo& previousRebootInfo /* @out */) = 0;
            
            // @text getPreviousRebootInfo2
            // @brief Returns detailed information about a reboot.
            // @param RebootInfo - out - struct
            virtual Core::hresult GetPreviousRebootInfo2(RebootInfo& rebootInfo /* @out */) = 0;
            
            // @text getPreviousRebootReason
            // @brief Returns the last reboot reason.
            // @param reason - out - string
            // @param success - out - bool
            virtual Core::hresult GetPreviousRebootReason(string& reason /* @out */, bool& success /* @out */) = 0;
            
            // @text getRFCConfig
            // @brief Returns information that is related to RDK Feature Control (RFC) configurations.
            // @param rfcList - in - A list of RFC properties to query
            // @param RFCConfig - out - A list of specified RFC properties
            // @param success - out - bool
            virtual Core::hresult GetRFCConfig(IStringIterator* const& rfcList, IStringIterator*& RFCConfig /* @out */, bool& success /* @out */) = 0;
            
            // @text getSerialNumber
            // @brief Returns the device serial number.
            // @param serialNumber - out - string
            // @param success - out - bool
            virtual Core::hresult GetSerialNumber(string& serialNumber /* @out */, bool& success /* @out */) = 0;
            
            // @text getStateInfo
            // @brief Queries device state information of various properties.
            // @param param - in - string
            // @param paramValue - out - int
            // @param success - out - bool
            virtual Core::hresult GetStateInfo(const string& param, int& paramValue /* @out @opaque */, bool& success /* @out */) = 0;
            
            // @text getStoreDemoLink
            // @brief Returns the store demo video link.
            // @param fileURL - out - string
            // @param success - out - bool
            virtual Core::hresult GetStoreDemoLink(string& fileURL /* @out */, bool& success /* @out */) = 0;
            
            // @text getSystemVersions
            // @brief Returns system version details.
            // @param SystemVersionsInfo - out - struct
            virtual Core::hresult GetSystemVersions(SystemVersionsInfo& systemVersionsInfo /* @out */) = 0;
            
            // @text getTemperatureThresholds
            // @brief Returns temperature threshold values.
            // @param TemperatureThresholdsInfo - out - struct
            virtual Core::hresult GetTemperatureThresholds(TemperatureThresholdsInfo& temperatureThresholdsInfo /* @out */) = 0;
            
            // @text getFriendlyName
            // @brief Returns the friendly name set by setFriendlyName API or default value.
            // @param friendlyName - out - string
            // @param success - out - bool
            virtual Core::hresult GetFriendlyName(string& friendlyName /* @out */, bool& success /* @out */) = 0;
            
            // @text getTerritory
            // @brief Gets the configured system territory and region.
            // @param territory - out - string
            // @param region - out - string
            // @param success - out - bool
            virtual Core::hresult GetTerritory(string& territory /* @out */, string& region /* @out */, bool& success /* @out */) = 0;

            // @text getTimeZones
            // @brief Returns the friendly name set by setFriendlyName API or default value.
            // @param TimeZoneInfo - out - struct
            virtual Core::hresult GetTimeZones(TimeZoneInfo& timeZoneInfo /* @out */) = 0;
            
            // @text getTimeZoneDST
            // @brief Gets the available timezones from the system’s time zone database.
            // @param timeZone - out - string
            // @param accuracy - out - string
            // @param success - out - bool
            virtual Core::hresult GetTimeZoneDST(string& timeZone /* @out */, string& accuracy /* @out */, bool& success /* @out */) = 0;
            
            // @text setFSRFlag
            // @brief Set the FSR flag into the emmc raw area.
            // @param fsrFlag - in - bool
            // @param success - out - bool
            virtual Core::hresult SetFSRFlag(const bool fsrFlag, bool& success /* @out */) = 0;
            
            // @text getFSRFlag
            // @brief Get the FSR flag from the emmc raw area.
            // @param fsrFlag - out - bool
            // @param success - out - bool
            virtual Core::hresult GetFSRFlag(bool &fsrFlag /* @out */, bool& success /* @out */) = 0;
            
            // @text getBootTypeInfo
            // @brief Get the FSR flag from the emmc raw area.
            // @param bootType - out - string
            // @param success - out - bool
            virtual Core::hresult GetBootTypeInfo(string &bootType /* @out */, bool& success /* @out */) = 0;
            
            // @text setBlocklistFlag
            // @brief To update Blocklist flag.
            // @param blocklist - in - bool
            // @param BlocklistResult - out - struct
            virtual Core::hresult SetBlocklistFlag(const bool blocklist, BlocklistResult& result /* @out */) = 0;
            
            // @text getBlocklistFlag
            // @brief Get block list falg.
            // @param BlocklistResult - out - struct
            virtual Core::hresult GetBlocklistFlag(BlocklistResult& result /* @out */) = 0;
            
            // @text setMigrationStatus
            // @brief set the Migration Status of the device.
            // @param status - in - string
            // @param success - out - bool
            virtual Core::hresult SetMigrationStatus(const bool status, bool& success /* @out */) = 0;
            
            // @text getMigrationStatus
            // @brief set the Migration Status of the device
            // @param MigrationStatus - out - string
            // @param success - out - bool
            virtual Core::hresult GetMigrationStatus(string &MigrationStatus /* @out */, bool& success /* @out */) = 0;
            
            // @text getWakeupReason
            // @brief Returns the reason for the device coming out of deep sleep.
            // @param WakeupReason - out - string
            // @param success - out - boolean
            virtual Core::hresult GetWakeupReason(string& WakeupReason /* @out */, bool& success /* @out */) = 0;

            // @text getXconfParams
            // @brief Returns XCONF configuration parameters for the device.
            // @param XconfParamsResult - out - struct
            virtual Core::hresult GetXconfParams(XconfParamsResult& xconfParamsResult /* @out */ ) = 0;

	    // @text isOptOutTelemetry
            // @brief Checks the telemetry opt-out status.
            // @param OptOut  - out - boolean
            // @param success - out - boolean
            virtual Core::hresult IsOptOutTelemetry(bool& OptOut /* @out @text Opt-Out*/, bool& success /* @out */) = 0;

	    // @text queryMocaStatus
            // @brief Checks whether MOCA is enabled.
            // @param mocaEnabled  - out - boolean
            // @param success - out - boolean
            virtual Core::hresult QueryMocaStatus(bool& mocaEnabled /* @out */, bool& success /* @out */) = 0;

	    // @text reboot
            // @brief Requests that the system performs a reboot of the set-top box.
            // @param rebootReason  - in - string
	    // @param IARM_Bus_Call_STATUS - out - int
            // @param success - out - boolean
            virtual Core::hresult Reboot(const string& rebootReason, int& IARM_Bus_Call_STATUS /* @out */, bool& success /* @out */) = 0;

	    // @text requestSystemUptime
            // @brief Returns the device uptime.
            // @param systemUptime  - out - string
            // @param success - out - boolean
            virtual Core::hresult RequestSystemUptime(string& systemUptime /* @out */, bool& success /* @out */) = 0;

	    // @text setBootLoaderPattern
            // @brief Sets the boot loader pattern mode in MFR.
            // @param pattern  - in - string
            // @param success - out - boolean
            virtual Core::hresult SetBootLoaderPattern(const string& pattern, bool& success /* @out */) = 0;

	    // @text setDeepSleepTimer
            // @brief Sets the deep sleep timeout period.
            // @param seconds  - in - int
            // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetDeepSleepTimer(const int seconds, SystemServicesSuccess& success /* @out */) = 0;

	    // @text setFirmwareAutoReboot
            // @brief Enables or disables the AutoReboot Feature.
            // @param enable  - in - boolean
            // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetFirmwareAutoReboot(const bool enable, SystemServicesSuccess& success /* @out */) = 0;
	    
 	    // @text setFirmwareRebootDelay
            // @brief Delays the firmware reboot.
            // @param delaySeconds  - in - int
            // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetFirmwareRebootDelay(const int delaySeconds, SystemServicesSuccess& success /* @out */) = 0;

	    // @text setMode
            // @brief Sets the mode of the set-top box for a specific duration before returning to normal mode.
            // @param ModeInfo - in - struct
	    // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetMode(const ModeInfo& modeinfo, SystemServicesSuccess& success /* @out */) = 0;
	
	    // @text setOptOutTelemetry
            // @brief Sets the telemetry opt-out status.
            // @param OptOut  - in - boolean
            // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetOptOutTelemetry(const bool OptOut /* @text Opt-Out */, SystemServicesSuccess& success /* @out */) = 0;

	    // @text setOvertempGraceInterval
            // @brief Sets the over-temperature grace interval value. Not supported on all devices.
            // @param graceInterval - in - string
            // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetOvertempGraceInterval(const string& graceInterval, SystemServicesSuccess& success /* @out */) = 0;

	    // @text setPowerState
            // @brief Sets the power state of the device.
            // @param powerState - in - string
	    // @param standbyReason - in - string
	    // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetPowerState(const string &powerState, const string &standbyReason, SystemServicesSuccess& success /* @out */) = 0;

 	    // @text setPreferredStandbyMode
            // @brief Sets and persists the preferred standby mode.
            // @param standbyMode - in - string
	    // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetPreferredStandbyMode(const string& standbyMode, SystemServicesSuccess& success /* @out */) = 0;
	 
	    // @text setTemperatureThresholds
            // @brief Sets the temperature threshold values.
            // @param TemperatureThresholdsSet - in - struct
	    // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetTemperatureThresholds(const TemperatureThresholdsSet& thresholds, SystemServicesSuccess& success /* @out */) = 0;

 	    // @text setFriendlyName
            // @brief Sets the friendly name of device.
            // @param friendlyName - in - string
	    // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetFriendlyName(const string& friendlyName, SystemServicesSuccess& success /* @out */) = 0;

	    // @text setBootLoaderSplashScreen
            // @brief Install or update the BootLoader Splash Screens.
            // @param path - in - string
	    // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetBootLoaderSplashScreen(const string& path, SystemServicesSuccess& success /* @out */) = 0;

	    // @text getBuildType
            // @brief Returns build type of the image flashed on the device.
            // @param build_type  - out - string
            // @param success - out - boolean
            virtual Core::hresult GetBuildType(string& build_type /* @out */, bool& success /* @out */) = 0;

	    // @text setTerritory
            // @brief Sets the system territory and region.
            // @param territory - in - string
	    // @param region - in - string
	    // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetTerritory(const string& territory, const string& region, SystemServicesSuccess& success /* @out */) = 0;

	    // @text setTimeZoneDST
            // @brief Sets the system time zone.
            // @param timeZone - in - string
	    // @param accuracy - in - string
	    // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetTimeZoneDST(const string& timeZone, const string& accuracy, SystemServicesSuccess& success /* @out */) = 0;

	    // @text setWakeupSrcConfiguration
            // @brief Sets the wakeup source configuration for the input powerState.
	    // @param powerState - in - string	
            // @param wakeupSources - in - Boolean Array of Key value pair with wake up sources and its configurations
            // @param SystemServicesSuccess - out - struct
            virtual Core::hresult SetWakeupSrcConfiguration(const string& powerState, ISystemServicesWakeupSourcesIterator* const& wakeupSources, SystemServicesSuccess& success /* @out */) = 0;

	    // @text getWakeupSrcConfiguration
            // @brief Returns all the supported wakeup configurations and powerState.
	    // @param powerState - out - string	
            // @param wakeupSources - out - Boolean Array of Key value pair with wake up sources and its configurations
            // @param success - out - boolean
            virtual Core::hresult GetWakeupSrcConfiguration(string& powerState /* @out */, ISystemServicesWakeupSourcesIterator*& wakeupSources /* @out */, bool& success /* @out */) = 0;

	    // @text updateFirmware
            // @brief Initiates a firmware update.
            // @param SystemServicesSuccess - out - struct
            virtual Core::hresult UpdateFirmware(SystemServicesSuccess& success /* @out */) = 0;

  	    // @text uploadLogsAsync
            // @brief Starts background process to upload logs.
            // @param SystemServicesSuccess - out - struct
            virtual Core::hresult UploadLogsAsync(SystemServicesSuccess& success /* @out */) = 0;

  	    // @text abortLogUpload
            // @brief Stops background process to upload logs.
            // @param SystemServicesSuccess - out - struct
            virtual Core::hresult AbortLogUpload(SystemServicesSuccess& success /* @out */) = 0;
 
	    // @text getThunderStartReason
            // @brief Returns the Thunder start reason.
            // @param startReason  - out - string
            // @param success - out - boolean
            virtual Core::hresult GetThunderStartReason(string& startReason /* @out */, bool& success /* @out */) = 0;

   	    // @text setPrivacyMode
            // @brief Setting Privacy Mode.
            // @param privacyMode  - in - string
            // @param success - out - boolean
            virtual Core::hresult SetPrivacyMode(const string& privacyMode, bool& success /* @out */) = 0;

 	    // @text getPrivacyMode
            // @brief Getting Privacy Mode.
            // @param privacyMode - out - string
            // @param success - out - string
            virtual Core::hresult GetPrivacyMode(string& privacyMode /* @out */, bool& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
