/**
 * @file IRemoteControlStructs.h
 * @brief Data structures for Remote Control JSONRPC interface
 * 
 * If not stated otherwise in this file or this component's LICENSE
 * file the following copyright and licenses apply:
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
**/

#pragma once

#include <core/JSON.h>

namespace WPEFramework {
namespace Exchange {
namespace RemoteControlData {

    // @json 1.0.0
    struct PairingState {
        // @brief Pairing state values
        // @text INITIALISING, IDLE, SEARCHING, PAIRING, COMPLETE, FAILED
        enum State : uint8_t {
            INITIALISING,
            IDLE,
            SEARCHING,
            PAIRING,
            COMPLETE,
            FAILED
        };
    };

    // @json 1.0.0
    struct IRProgState {
        // @brief IR programming state values
        // @text IDLE, WAITING, COMPLETE, FAILED
        enum State : uint8_t {
            IDLE,
            WAITING,
            COMPLETE,
            FAILED
        };
    };

    // @json 1.0.0
    struct RemoteData : public Core::JSON::Container {
        RemoteData(const RemoteData&) = delete;
        RemoteData& operator=(const RemoteData&) = delete;

        RemoteData()
            : Core::JSON::Container()
            , MacAddress()
            , Connected(false)
            , Name()
            , RemoteId(0)
            , DeviceId()
            , Make()
            , Model()
            , HwVersion()
            , SwVersion()
            , BtlVersion()
            , SerialNumber()
            , BatteryPercent()
            , TvIRCode()
            , AmpIRCode()
            , WakeupKeyCode()
            , WakeupConfig()
            , WakeupCustomList()
            , UpgradeSessionId()
        {
            Add(_T("macAddress"), &MacAddress);
            Add(_T("connected"), &Connected);
            Add(_T("name"), &Name);
            Add(_T("remoteId"), &RemoteId);
            Add(_T("deviceId"), &DeviceId);
            Add(_T("make"), &Make);
            Add(_T("model"), &Model);
            Add(_T("hwVersion"), &HwVersion);
            Add(_T("swVersion"), &SwVersion);
            Add(_T("btlVersion"), &BtlVersion);
            Add(_T("serialNumber"), &SerialNumber);
            Add(_T("batteryPercent"), &BatteryPercent);
            Add(_T("tvIRCode"), &TvIRCode);
            Add(_T("ampIRCode"), &AmpIRCode);
            Add(_T("wakeupKeyCode"), &WakeupKeyCode);
            Add(_T("wakeupConfig"), &WakeupConfig);
            Add(_T("wakeupCustomList"), &WakeupCustomList);
            Add(_T("upgradeSessionId"), &UpgradeSessionId);
        }

        ~RemoteData() override = default;

        // @brief The MAC address of the remote in hex-colon format
        Core::JSON::String MacAddress;
        // @brief True if the remote is connected, otherwise false
        Core::JSON::Boolean Connected;
        // @brief The remote name
        Core::JSON::String Name;
        // @brief This integer is the remote ID number, assigned by the network
        Core::JSON::DecUInt32 RemoteId;
        // @brief The device ID number that is assigned by the network
        Core::JSON::DecUInt32 DeviceId;
        // @brief The manufacturer name of the remote
        Core::JSON::String Make;
        // @brief The remote model name
        Core::JSON::String Model;
        // @brief The remote hardware revision
        Core::JSON::String HwVersion;
        // @brief The remote software revision
        Core::JSON::String SwVersion;
        // @brief The remote bootloader revision
        Core::JSON::String BtlVersion;
        // @brief The remote serial number
        Core::JSON::String SerialNumber;
        // @brief The current remote battery level as a percentage (0 to 100)
        Core::JSON::DecUInt8 BatteryPercent;
        // @brief The current TV IR code that the remote is programmed with
        Core::JSON::String TvIRCode;
        // @brief The current AVR/AMP IR code that the remote is programmed with
        Core::JSON::String AmpIRCode;
        // @brief The Linux key code of the last button to be pressed on the remote before wakeup from deepsleep
        Core::JSON::DecUInt32 WakeupKeyCode;
        // @brief The current deepsleep wakeup key configuration of the remote (all, none, custom)
        Core::JSON::String WakeupConfig;
        // @brief List of linux keycodes that can wake the target from deepsleep (only present if wakeupConfig is custom)
        Core::JSON::String WakeupCustomList;
        // @brief The unique identifier for the firmware update session
        Core::JSON::String UpgradeSessionId;
    };

    // @json 1.0.0
    struct NetworkStatus : public Core::JSON::Container {
        NetworkStatus(const NetworkStatus&) = delete;
        NetworkStatus& operator=(const NetworkStatus&) = delete;

        NetworkStatus()
            : Core::JSON::Container()
            , NetType(0)
            , NetTypeSupported()
            , PairingState()
            , IrProgState()
            , RemoteDataList()
        {
            Add(_T("netType"), &NetType);
            Add(_T("netTypeSupported"), &NetTypeSupported);
            Add(_T("pairingState"), &PairingState);
            Add(_T("irProgState"), &IrProgState);
            Add(_T("remoteData"), &RemoteDataList);
        }

        ~NetworkStatus() override = default;

        // @brief The type of network
        Core::JSON::DecUInt32 NetType;
        // @brief A list of the network types that the STB supports
        Core::JSON::ArrayType<Core::JSON::DecUInt32> NetTypeSupported;
        // @brief The current overall pairing state of the specified network
        Core::JSON::String PairingState;
        // @brief The current state of the IR code programming request to the remote
        Core::JSON::String IrProgState;
        // @brief Remote information for each paired remote control
        Core::JSON::ArrayType<RemoteData> RemoteDataList;
    };

    // ============== Request/Response Structures ==============

    // @json 1.0.0
    struct GetApiVersionNumberResponse : public Core::JSON::Container {
        GetApiVersionNumberResponse(const GetApiVersionNumberResponse&) = delete;
        GetApiVersionNumberResponse& operator=(const GetApiVersionNumberResponse&) = delete;

        GetApiVersionNumberResponse()
            : Core::JSON::Container()
            , Version(0)
        {
            Add(_T("version"), &Version);
        }

        ~GetApiVersionNumberResponse() override = default;

        // @brief The API version number
        Core::JSON::DecUInt32 Version;
    };

    // @json 1.0.0
    struct StartPairingRequest : public Core::JSON::Container {
        StartPairingRequest(const StartPairingRequest&) = delete;
        StartPairingRequest& operator=(const StartPairingRequest&) = delete;

        StartPairingRequest()
            : Core::JSON::Container()
            , NetType(0)
            , Timeout()
            , MacAddressList()
            , ScreenBindEnable()
            , ScanEnable()
        {
            Add(_T("netType"), &NetType);
            Add(_T("timeout"), &Timeout);
            Add(_T("macAddressList"), &MacAddressList);
            Add(_T("screenBindEnable"), &ScreenBindEnable);
            Add(_T("scanEnable"), &ScanEnable);
        }

        ~StartPairingRequest() override = default;

        // @brief The type of network
        Core::JSON::DecUInt32 NetType;
        // @brief The amount of time, in seconds, to attempt pairing before timing out (0 indicates no timeout)
        Core::JSON::DecUInt32 Timeout;
        // @brief A list of MAC addresses (optional)
        Core::JSON::ArrayType<Core::JSON::String> MacAddressList;
        // @brief Whether to enable screen bind mode (default: true)
        Core::JSON::Boolean ScreenBindEnable;
        // @brief Whether to enable scanning for remotes (default: true)
        Core::JSON::Boolean ScanEnable;
    };

    // @json 1.0.0
    struct StopPairingRequest : public Core::JSON::Container {
        StopPairingRequest(const StopPairingRequest&) = delete;
        StopPairingRequest& operator=(const StopPairingRequest&) = delete;

        StopPairingRequest()
            : Core::JSON::Container()
            , ScreenBindDisable()
            , ScanDisable()
        {
            Add(_T("screenBindDisable"), &ScreenBindDisable);
            Add(_T("scanDisable"), &ScanDisable);
        }

        ~StopPairingRequest() override = default;

        // @brief Whether to disable screen bind mode (default: true)
        Core::JSON::Boolean ScreenBindDisable;
        // @brief Whether to disable scanning for remotes (default: true)
        Core::JSON::Boolean ScanDisable;
    };

    // @json 1.0.0
    struct GetNetStatusRequest : public Core::JSON::Container {
        GetNetStatusRequest(const GetNetStatusRequest&) = delete;
        GetNetStatusRequest& operator=(const GetNetStatusRequest&) = delete;

        GetNetStatusRequest()
            : Core::JSON::Container()
            , NetType(0)
        {
            Add(_T("netType"), &NetType);
        }

        ~GetNetStatusRequest() override = default;

        // @brief The type of network
        Core::JSON::DecUInt32 NetType;
    };

    // @json 1.0.0
    struct GetNetStatusResponse : public Core::JSON::Container {
        GetNetStatusResponse(const GetNetStatusResponse&) = delete;
        GetNetStatusResponse& operator=(const GetNetStatusResponse&) = delete;

        GetNetStatusResponse()
            : Core::JSON::Container()
            , Status()
        {
            Add(_T("status"), &Status);
        }

        ~GetNetStatusResponse() override = default;

        // @brief The network status information
        NetworkStatus Status;
    };

    // @json 1.0.0
    struct InitializeIRDBRequest : public Core::JSON::Container {
        InitializeIRDBRequest(const InitializeIRDBRequest&) = delete;
        InitializeIRDBRequest& operator=(const InitializeIRDBRequest&) = delete;

        InitializeIRDBRequest()
            : Core::JSON::Container()
            , NetType(0)
        {
            Add(_T("netType"), &NetType);
        }

        ~InitializeIRDBRequest() override = default;

        // @brief The type of network
        Core::JSON::DecUInt32 NetType;
    };

    // @json 1.0.0
    struct ClearIRCodesRequest : public Core::JSON::Container {
        ClearIRCodesRequest(const ClearIRCodesRequest&) = delete;
        ClearIRCodesRequest& operator=(const ClearIRCodesRequest&) = delete;

        ClearIRCodesRequest()
            : Core::JSON::Container()
            , RemoteId(0)
            , NetType(0)
        {
            Add(_T("remoteId"), &RemoteId);
            Add(_T("netType"), &NetType);
        }

        ~ClearIRCodesRequest() override = default;

        // @brief The remote ID of the target remote on the specified network
        Core::JSON::DecUInt32 RemoteId;
        // @brief The type of network
        Core::JSON::DecUInt32 NetType;
    };

    // @json 1.0.0
    struct SetIRCodeRequest : public Core::JSON::Container {
        SetIRCodeRequest(const SetIRCodeRequest&) = delete;
        SetIRCodeRequest& operator=(const SetIRCodeRequest&) = delete;

        SetIRCodeRequest()
            : Core::JSON::Container()
            , RemoteId(0)
            , NetType(0)
            , AvDevType()
            , Code()
        {
            Add(_T("remoteId"), &RemoteId);
            Add(_T("netType"), &NetType);
            Add(_T("avDevType"), &AvDevType);
            Add(_T("code"), &Code);
        }

        ~SetIRCodeRequest() override = default;

        // @brief The remote ID of the target remote on the specified network
        Core::JSON::DecUInt32 RemoteId;
        // @brief The type of network
        Core::JSON::DecUInt32 NetType;
        // @brief Whether the device is a video (TV) or audio (AMP) device
        Core::JSON::String AvDevType;
        // @brief The IR code being programmed into the remote
        Core::JSON::String Code;
    };

    // @json 1.0.0
    struct GetIRCodesByAutoLookupRequest : public Core::JSON::Container {
        GetIRCodesByAutoLookupRequest(const GetIRCodesByAutoLookupRequest&) = delete;
        GetIRCodesByAutoLookupRequest& operator=(const GetIRCodesByAutoLookupRequest&) = delete;

        GetIRCodesByAutoLookupRequest()
            : Core::JSON::Container()
            , NetType(0)
        {
            Add(_T("netType"), &NetType);
        }

        ~GetIRCodesByAutoLookupRequest() override = default;

        // @brief The type of network
        Core::JSON::DecUInt32 NetType;
    };

    // @json 1.0.0
    struct GetIRCodesByAutoLookupResponse : public Core::JSON::Container {
        GetIRCodesByAutoLookupResponse(const GetIRCodesByAutoLookupResponse&) = delete;
        GetIRCodesByAutoLookupResponse& operator=(const GetIRCodesByAutoLookupResponse&) = delete;

        GetIRCodesByAutoLookupResponse()
            : Core::JSON::Container()
            , TvManufacturer()
            , TvModel()
            , TvCodes()
            , AvrManufacturer()
            , AvrModel()
            , AvrCodes()
        {
            Add(_T("tvManufacturer"), &TvManufacturer);
            Add(_T("tvModel"), &TvModel);
            Add(_T("tvCodes"), &TvCodes);
            Add(_T("avrManufacturer"), &AvrManufacturer);
            Add(_T("avrModel"), &AvrModel);
            Add(_T("avrCodes"), &AvrCodes);
        }

        ~GetIRCodesByAutoLookupResponse() override = default;

        // @brief The TV manufacturer for which codes are provided
        Core::JSON::String TvManufacturer;
        // @brief The TV model for which codes are provided
        Core::JSON::String TvModel;
        // @brief A list of TV IR codes
        Core::JSON::ArrayType<Core::JSON::String> TvCodes;
        // @brief The AVR manufacturer for which codes are provided
        Core::JSON::String AvrManufacturer;
        // @brief The AVR model for which codes are provided
        Core::JSON::String AvrModel;
        // @brief A list of AVR IR codes
        Core::JSON::ArrayType<Core::JSON::String> AvrCodes;
    };

    // @json 1.0.0
    struct GetIRCodesByNamesRequest : public Core::JSON::Container {
        GetIRCodesByNamesRequest(const GetIRCodesByNamesRequest&) = delete;
        GetIRCodesByNamesRequest& operator=(const GetIRCodesByNamesRequest&) = delete;

        GetIRCodesByNamesRequest()
            : Core::JSON::Container()
            , AvDevType()
            , Manufacturer()
            , Model()
        {
            Add(_T("avDevType"), &AvDevType);
            Add(_T("manufacturer"), &Manufacturer);
            Add(_T("model"), &Model);
        }

        ~GetIRCodesByNamesRequest() override = default;

        // @brief Whether the device is a video (TV) or audio (AMP) device
        Core::JSON::String AvDevType;
        // @brief The manufacturer name of the AV device
        Core::JSON::String Manufacturer;
        // @brief The model name of the AV device
        Core::JSON::String Model;
    };

    // @json 1.0.0
    struct GetIRCodesByNamesResponse : public Core::JSON::Container {
        GetIRCodesByNamesResponse(const GetIRCodesByNamesResponse&) = delete;
        GetIRCodesByNamesResponse& operator=(const GetIRCodesByNamesResponse&) = delete;

        GetIRCodesByNamesResponse()
            : Core::JSON::Container()
            , AvDevType()
            , Manufacturer()
            , Model()
            , Codes()
        {
            Add(_T("avDevType"), &AvDevType);
            Add(_T("manufacturer"), &Manufacturer);
            Add(_T("model"), &Model);
            Add(_T("codes"), &Codes);
        }

        ~GetIRCodesByNamesResponse() override = default;

        // @brief Whether the device is a video (TV) or audio (AMP) device
        Core::JSON::String AvDevType;
        // @brief The manufacturer name of the AV device
        Core::JSON::String Manufacturer;
        // @brief The model name of the AV device
        Core::JSON::String Model;
        // @brief A list of IR codes
        Core::JSON::ArrayType<Core::JSON::String> Codes;
    };

    // @json 1.0.0
    struct GetIRDBManufacturersRequest : public Core::JSON::Container {
        GetIRDBManufacturersRequest(const GetIRDBManufacturersRequest&) = delete;
        GetIRDBManufacturersRequest& operator=(const GetIRDBManufacturersRequest&) = delete;

        GetIRDBManufacturersRequest()
            : Core::JSON::Container()
            , AvDevType()
            , Manufacturer()
        {
            Add(_T("avDevType"), &AvDevType);
            Add(_T("manufacturer"), &Manufacturer);
        }

        ~GetIRDBManufacturersRequest() override = default;

        // @brief Whether the device is a video (TV) or audio (AMP) device
        Core::JSON::String AvDevType;
        // @brief A part of the name of the manufacturer of the AV device
        Core::JSON::String Manufacturer;
    };

    // @json 1.0.0
    struct GetIRDBManufacturersResponse : public Core::JSON::Container {
        GetIRDBManufacturersResponse(const GetIRDBManufacturersResponse&) = delete;
        GetIRDBManufacturersResponse& operator=(const GetIRDBManufacturersResponse&) = delete;

        GetIRDBManufacturersResponse()
            : Core::JSON::Container()
            , AvDevType()
            , Manufacturers()
        {
            Add(_T("avDevType"), &AvDevType);
            Add(_T("manufacturers"), &Manufacturers);
        }

        ~GetIRDBManufacturersResponse() override = default;

        // @brief Whether the device is a video (TV) or audio (AMP) device
        Core::JSON::String AvDevType;
        // @brief A list of manufacturer names
        Core::JSON::ArrayType<Core::JSON::String> Manufacturers;
    };

    // @json 1.0.0
    struct GetIRDBModelsRequest : public Core::JSON::Container {
        GetIRDBModelsRequest(const GetIRDBModelsRequest&) = delete;
        GetIRDBModelsRequest& operator=(const GetIRDBModelsRequest&) = delete;

        GetIRDBModelsRequest()
            : Core::JSON::Container()
            , AvDevType()
            , Manufacturer()
            , Model()
        {
            Add(_T("avDevType"), &AvDevType);
            Add(_T("manufacturer"), &Manufacturer);
            Add(_T("model"), &Model);
        }

        ~GetIRDBModelsRequest() override = default;

        // @brief Whether the device is a video (TV) or audio (AMP) device
        Core::JSON::String AvDevType;
        // @brief The manufacturer name of the AV device
        Core::JSON::String Manufacturer;
        // @brief A part (minimum of 3 characters) of the model name of the AV device
        Core::JSON::String Model;
    };

    // @json 1.0.0
    struct GetIRDBModelsResponse : public Core::JSON::Container {
        GetIRDBModelsResponse(const GetIRDBModelsResponse&) = delete;
        GetIRDBModelsResponse& operator=(const GetIRDBModelsResponse&) = delete;

        GetIRDBModelsResponse()
            : Core::JSON::Container()
            , AvDevType()
            , Manufacturer()
            , Models()
        {
            Add(_T("avDevType"), &AvDevType);
            Add(_T("manufacturer"), &Manufacturer);
            Add(_T("models"), &Models);
        }

        ~GetIRDBModelsResponse() override = default;

        // @brief Whether the device is a video (TV) or audio (AMP) device
        Core::JSON::String AvDevType;
        // @brief The manufacturer name of the AV device
        Core::JSON::String Manufacturer;
        // @brief A list of model names
        Core::JSON::ArrayType<Core::JSON::String> Models;
    };

    // @json 1.0.0
    struct GetLastKeypressSourceResponse : public Core::JSON::Container {
        GetLastKeypressSourceResponse(const GetLastKeypressSourceResponse&) = delete;
        GetLastKeypressSourceResponse& operator=(const GetLastKeypressSourceResponse&) = delete;

        GetLastKeypressSourceResponse()
            : Core::JSON::Container()
            , ControllerId(0)
            , Timestamp(0)
            , SourceName()
            , SourceType()
            , SourceKeyCode(0)
            , IsScreenBindMode(false)
            , RemoteKeypadConfig(0)
        {
            Add(_T("controllerId"), &ControllerId);
            Add(_T("timestamp"), &Timestamp);
            Add(_T("sourceName"), &SourceName);
            Add(_T("sourceType"), &SourceType);
            Add(_T("sourceKeyCode"), &SourceKeyCode);
            Add(_T("bIsScreenBindMode"), &IsScreenBindMode);
            Add(_T("remoteKeypadConfig"), &RemoteKeypadConfig);
        }

        ~GetLastKeypressSourceResponse() override = default;

        // @brief The controller ID of the target remote on the specified network
        Core::JSON::DecUInt32 ControllerId;
        // @brief The time of the last key press
        Core::JSON::DecUInt64 Timestamp;
        // @brief The source of the last key press
        Core::JSON::String SourceName;
        // @brief The source type of the last key press
        Core::JSON::String SourceType;
        // @brief The source key code
        Core::JSON::DecUInt32 SourceKeyCode;
        // @brief true if in screen bind mode, otherwise false
        Core::JSON::Boolean IsScreenBindMode;
        // @brief The configuration of the remote keypad
        Core::JSON::DecUInt32 RemoteKeypadConfig;
    };

    // @json 1.0.0
    struct ConfigureWakeupKeysRequest : public Core::JSON::Container {
        ConfigureWakeupKeysRequest(const ConfigureWakeupKeysRequest&) = delete;
        ConfigureWakeupKeysRequest& operator=(const ConfigureWakeupKeysRequest&) = delete;

        ConfigureWakeupKeysRequest()
            : Core::JSON::Container()
            , WakeupConfig()
            , CustomKeys()
        {
            Add(_T("wakeupConfig"), &WakeupConfig);
            Add(_T("customKeys"), &CustomKeys);
        }

        ~ConfigureWakeupKeysRequest() override = default;

        // @brief The deepsleep wakeup key configuration of the remote (all, none, custom)
        Core::JSON::String WakeupConfig;
        // @brief List of Linux key codes that can wake the target from deepsleep (mandatory if wakeupConfig is custom)
        Core::JSON::String CustomKeys;
    };

    // @json 1.0.0
    struct FindMyRemoteRequest : public Core::JSON::Container {
        FindMyRemoteRequest(const FindMyRemoteRequest&) = delete;
        FindMyRemoteRequest& operator=(const FindMyRemoteRequest&) = delete;

        FindMyRemoteRequest()
            : Core::JSON::Container()
            , Level()
        {
            Add(_T("level"), &Level);
        }

        ~FindMyRemoteRequest() override = default;

        // @brief The level at which the remote will beep (off, mid, high)
        Core::JSON::String Level;
    };

    // @json 1.0.0
    struct UnpairRequest : public Core::JSON::Container {
        UnpairRequest(const UnpairRequest&) = delete;
        UnpairRequest& operator=(const UnpairRequest&) = delete;

        UnpairRequest()
            : Core::JSON::Container()
            , MacAddressList()
        {
            Add(_T("macAddressList"), &MacAddressList);
        }

        ~UnpairRequest() override = default;

        // @brief A list of MAC addresses to unpair
        Core::JSON::ArrayType<Core::JSON::String> MacAddressList;
    };

    // @json 1.0.0
    struct StartFirmwareUpdateRequest : public Core::JSON::Container {
        StartFirmwareUpdateRequest(const StartFirmwareUpdateRequest&) = delete;
        StartFirmwareUpdateRequest& operator=(const StartFirmwareUpdateRequest&) = delete;

        StartFirmwareUpdateRequest()
            : Core::JSON::Container()
            , MacAddress()
            , FileName()
            , FileType()
            , PercentIncrement(0)
        {
            Add(_T("macAddress"), &MacAddress);
            Add(_T("fileName"), &FileName);
            Add(_T("fileType"), &FileType);
            Add(_T("percentIncrement"), &PercentIncrement);
        }

        ~StartFirmwareUpdateRequest() override = default;

        // @brief The MAC address of the target remote
        Core::JSON::String MacAddress;
        // @brief The full path and filename for the firmware image
        Core::JSON::String FileName;
        // @brief The type of firmware image file
        Core::JSON::String FileType;
        // @brief The increment change of a firmware update to notify (1-100 percent)
        Core::JSON::DecUInt32 PercentIncrement;
    };

    // @json 1.0.0
    struct StartFirmwareUpdateResponse : public Core::JSON::Container {
        StartFirmwareUpdateResponse(const StartFirmwareUpdateResponse&) = delete;
        StartFirmwareUpdateResponse& operator=(const StartFirmwareUpdateResponse&) = delete;

        StartFirmwareUpdateResponse()
            : Core::JSON::Container()
            , SessionIdList()
        {
            Add(_T("sessionIdList"), &SessionIdList);
        }

        ~StartFirmwareUpdateResponse() override = default;

        // @brief A list of session identifiers
        Core::JSON::ArrayType<Core::JSON::DecUInt32> SessionIdList;
    };

    // @json 1.0.0
    struct CancelFirmwareUpdateRequest : public Core::JSON::Container {
        CancelFirmwareUpdateRequest(const CancelFirmwareUpdateRequest&) = delete;
        CancelFirmwareUpdateRequest& operator=(const CancelFirmwareUpdateRequest&) = delete;

        CancelFirmwareUpdateRequest()
            : Core::JSON::Container()
            , SessionId(0)
        {
            Add(_T("sessionId"), &SessionId);
        }

        ~CancelFirmwareUpdateRequest() override = default;

        // @brief The session identifier
        Core::JSON::DecUInt32 SessionId;
    };

    // @json 1.0.0
    struct StatusFirmwareUpdateRequest : public Core::JSON::Container {
        StatusFirmwareUpdateRequest(const StatusFirmwareUpdateRequest&) = delete;
        StatusFirmwareUpdateRequest& operator=(const StatusFirmwareUpdateRequest&) = delete;

        StatusFirmwareUpdateRequest()
            : Core::JSON::Container()
            , SessionId(0)
        {
            Add(_T("sessionId"), &SessionId);
        }

        ~StatusFirmwareUpdateRequest() override = default;

        // @brief The session identifier
        Core::JSON::DecUInt32 SessionId;
    };

    // @json 1.0.0
    struct FirmwareUpdateStatus : public Core::JSON::Container {
        FirmwareUpdateStatus(const FirmwareUpdateStatus&) = delete;
        FirmwareUpdateStatus& operator=(const FirmwareUpdateStatus&) = delete;

        FirmwareUpdateStatus()
            : Core::JSON::Container()
            , State()
            , PercentComplete(0)
        {
            Add(_T("state"), &State);
            Add(_T("percentComplete"), &PercentComplete);
        }

        ~FirmwareUpdateStatus() override = default;

        // @brief The firmware update state
        Core::JSON::String State;
        // @brief The percentage complete (0-100)
        Core::JSON::DecUInt32 PercentComplete;
    };

    // @json 1.0.0
    struct StatusFirmwareUpdateResponse : public Core::JSON::Container {
        StatusFirmwareUpdateResponse(const StatusFirmwareUpdateResponse&) = delete;
        StatusFirmwareUpdateResponse& operator=(const StatusFirmwareUpdateResponse&) = delete;

        StatusFirmwareUpdateResponse()
            : Core::JSON::Container()
            , Result()
        {
            Add(_T("result"), &Result);
        }

        ~StatusFirmwareUpdateResponse() override = default;

        // @brief The firmware update status
        FirmwareUpdateStatus Result;
    };

    // Event Structures

    // @json 1.0.0
    struct StatusEventData : public Core::JSON::Container {
        StatusEventData(const StatusEventData&) = delete;
        StatusEventData& operator=(const StatusEventData&) = delete;

        StatusEventData()
            : Core::JSON::Container()
            , NetType(0)
            , NetTypeSupported(false)
            , PairingState()
            , IrProgState()
            , RemoteData()
        {
            Add(_T("netType"), &NetType);
            Add(_T("netTypeSupported"), &NetTypeSupported);
            Add(_T("pairingState"), &PairingState);
            Add(_T("irProgState"), &IrProgState);
            Add(_T("remoteData"), &RemoteData);
        }

        ~StatusEventData() override = default;

        // @brief The type of remote control network
        Core::JSON::DecUInt32 NetType;
        // @brief Whether the network type is supported
        Core::JSON::Boolean NetTypeSupported;
        // @brief The pairing state
        Core::JSON::EnumType<PairingState> PairingState;
        // @brief The IR programming state
        Core::JSON::EnumType<IRProgState> IrProgState;
        // @brief Array of remote data for all remotes on the network
        Core::JSON::ArrayType<RemoteControlData::RemoteData> RemoteData;
    };

    // @json 1.0.0
    struct ValidationStatusObject : public Core::JSON::Container {
        ValidationStatusObject(const ValidationStatusObject&) = delete;
        ValidationStatusObject& operator=(const ValidationStatusObject&) = delete;

        ValidationStatusObject()
            : Core::JSON::Container()
            , NetType(0)
            , ValidationDigit1(0)
            , ValidationDigit2(0)
            , ValidationDigit3(0)
        {
            Add(_T("netType"), &NetType);
            Add(_T("validationDigit1"), &ValidationDigit1);
            Add(_T("validationDigit2"), &ValidationDigit2);
            Add(_T("validationDigit3"), &ValidationDigit3);
        }

        ~ValidationStatusObject() override = default;

        // @brief The type of remote control network
        Core::JSON::DecUInt32 NetType;
        // @brief The first validation digit
        Core::JSON::DecUInt32 ValidationDigit1;
        // @brief The second validation digit
        Core::JSON::DecUInt32 ValidationDigit2;
        // @brief The third validation digit
        Core::JSON::DecUInt32 ValidationDigit3;
    };

    // @json 1.0.0
    struct FirmwareUpdateProgressEvent : public Core::JSON::Container {
        FirmwareUpdateProgressEvent(const FirmwareUpdateProgressEvent&) = delete;
        FirmwareUpdateProgressEvent& operator=(const FirmwareUpdateProgressEvent&) = delete;

        FirmwareUpdateProgressEvent()
            : Core::JSON::Container()
            , SessionId(0)
            , Status()
        {
            Add(_T("sessionId"), &SessionId);
            Add(_T("status"), &Status);
        }

        ~FirmwareUpdateProgressEvent() override = default;

        // @brief The session identifier
        Core::JSON::DecUInt32 SessionId;
        // @brief The firmware update status
        FirmwareUpdateStatus Status;
    };

} // namespace RemoteControlData
} // namespace Exchange
} // namespace WPEFramework
