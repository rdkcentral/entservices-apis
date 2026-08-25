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
 
 namespace WPEFramework
 {
     namespace Exchange
     {
         /* @json 1.0.0 @text:keep */
         struct EXTERNAL IHdmiCecSink : virtual public Core::IUnknown {
             enum { ID = ID_HDMI_CEC_SINK };

             struct EXTERNAL HdmiCecSinkActivePath
            {
                uint8_t logicalAddress;
                string physicalAddress;
                string deviceType;
                string vendorID;
                string osdName;
            };

            struct EXTERNAL HdmiCecSinkDevices
            {
                uint8_t logicalAddress;
                string physicalAddress;
                string deviceType;
                string cecVersion;
                string osdName;
                string vendorID;
                string powerStatus;
                string portNumber;
            };

            struct EXTERNAL HdmiCecSinkSuccess {
                bool success;
            };

            using IHdmiCecSinkActivePathIterator = RPC::IIteratorType<HdmiCecSinkActivePath, ID_HDMI_CEC_SINK_ACTIVE_PATH_ITERATOR>;
            using IHdmiCecSinkDeviceListIterator = RPC::IIteratorType<HdmiCecSinkDevices, ID_HDMI_CEC_SINK_DEVICE_LIST_ITERATOR>;

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown
            {
                enum { ID = ID_HDMI_CEC_SINK_NOTIFICATION };


                // @brief Triggered when routing though the HDMI ARC port is successfully established.
                // @text arcInitiationEvent
                // @details Triggered when routing though the HDMI ARC port is successfully established.
                // @param status: Is the operation successful or not
                virtual void ArcInitiationEvent(const string status) {};

                // @brief Triggered when routing though the HDMI ARC port terminates.
                // @text arcTerminationEvent
                // @details Triggered when routing though the HDMI ARC port terminates.
                // @param status: Is the operation successful or not
                // @example status: "ARC_TERMINATED"
                virtual void ArcTerminationEvent(const string status) {};

                // @brief Triggered when the active source device changes.
                // @text onActiveSourceChange
                // @details Triggered when the active source device changes.
                // @param logicalAddress: Logical address of the active source
                // @example logicalAddress: 4
                // @param physicalAddress: Physical address of the active source
                // @example physicalAddress: "1.0.0.0"
                virtual void OnActiveSourceChange(const int logicalAddress, const string physicalAddress) {};

                // @brief Triggered when a new device is added to the CEC network.
                // @text onDeviceAdded
                // @details Triggered when a new device is added to the CEC network.
                // @param logicalAddress: Logical address of the added device
                // @example logicalAddress: 5
                virtual void OnDeviceAdded(const int logicalAddress) {};

                // @brief Triggered when device information changes.
                // @text onDeviceInfoUpdated
                // @details Triggered when device information changes.
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress: 5
                virtual void OnDeviceInfoUpdated(const int logicalAddress) {};

                // @brief Triggered when a device is removed from the CEC network.
                // @text onDeviceRemoved
                // @details Triggered when a device is removed from the CEC network.
                // @param logicalAddress: Logical address of the removed device
                // @example logicalAddress: 5
                virtual void OnDeviceRemoved(const int logicalAddress) {};

                // @brief Triggered when an <Image View ON> CEC message is received from the source device.
                // @text onImageViewOnMsg
                // @details Triggered when an <Image View ON> CEC message is received from the source device.
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress: 4
                virtual void OnImageViewOnMsg(const int logicalAddress) {};

                // @brief Triggered when the source is no longer active.
                // @text onInActiveSource
                // @details Triggered when the source is no longer active.
                // @param logicalAddress: Logical address of the source
                // @example logicalAddress: 4
                // @param physicalAddress: Physical address of the source
                // @example physicalAddress: "1.0.0.0"
                virtual void OnInActiveSource(const int logicalAddress, const string physicalAddress) {};

                // @brief Triggered when a <Text View ON> CEC message is received from the source device.
                // @text onTextViewOnMsg
                // @details Triggered when a <Text View ON> CEC message is received from the source device.
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress: 4
                virtual void OnTextViewOnMsg(const int logicalAddress) {};

                // @brief Triggered when the TV is in standby mode and it receives <Image View ON>/ <Text View ON>/ <Active Source> CEC message from the connected source device.
                // @text onWakeupFromStandby
                // @details Triggered when the TV is in standby mode and it receives <Image View ON>/ <Text View ON>/ <Active Source> CEC message from the connected source device.
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress: 4
                virtual void OnWakeupFromStandby(const int logicalAddress) {};

                // @brief Triggered when an audio device is added or removed.
                // @text reportAudioDeviceConnectedStatus
                // @details Triggered when an audio device is added or removed.
                // @param status: Status of the audio device
                // @example status: "AUDIO_DEVICE_CONNECTED"
                // @param audioDeviceConnected: Audio device connected or not
                // @example audioDeviceConnected: "true"
                virtual void ReportAudioDeviceConnectedStatus(const string status, const string audioDeviceConnected) {};

                // @brief Triggered when CEC <Report Audio Status> message of device is received.
                // @text reportAudioStatusEvent
                // @details Triggered when CEC <Report Audio Status> message of device is received.
                // @param muteStatus: Mute status of the device
                // @example muteStatus: 0
                // @param volumeLevel: Volume level of the device
                // @example volumeLevel: 50
                virtual void ReportAudioStatusEvent(const int muteStatus, const int volumeLevel) {};

                // @brief Triggered when CEC <Feature Abort> message of device is received.
                // @text reportFeatureAbortEvent
                // @details Triggered when CEC <Feature Abort> message of device is received.
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress: 4
                // @param opcode: Opcode of the message
                // @example opcode: 0x44
                // @param FeatureAbortReason: Reason for the feature abort
                // @example FeatureAbortReason: 0x01
                virtual void ReportFeatureAbortEvent(const int logicalAddress, const int opcode, const int FeatureAbortReason) {};

                // @brief Triggered when the HDMI-CEC is enabled.
                // @text reportCecEnabledEvent
                // @details Triggered when the HDMI-CEC is enabled.
                // @param cecEnable: HDMI-CEC enabled or not
                // @example cecEnable: "true"
                virtual void ReportCecEnabledEvent(const string cecEnable) {};

                // @brief Triggered when CEC <Set System Audio Mode> message of device is received.
                // @text setSystemAudioModeEvent
                // @details Triggered when CEC <Set System Audio Mode> message of device is received.
                // @param audioMode: Audio mode of the device
                // @example audioMode: "AUDIO_MODE_ON"
                virtual void SetSystemAudioModeEvent(const string audioMode) {};

                // @brief Triggered when SAD is received from the connected audio device. See requestShortAudioDescriptor.
                // @text shortAudiodescriptorEvent
                // @details Triggered when SAD is received from the connected audio device. See requestShortAudioDescriptor.
                // @param shortAudioDescriptor: JSON response containing the Short Audio Descriptor (SAD) information
                // @example shortAudioDescriptor: { "shortAudioDescriptor": "0x09, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00" }
                virtual void ShortAudiodescriptorEvent(const string& shortAudioDescriptor) {};

                // @brief Triggered when the source device changes status to STANDBY.
                // @text standbyMessageReceived
                // @details Triggered when the source device changes status to STANDBY.
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress: 4
                virtual void StandbyMessageReceived(const int logicalAddress) {};

                // @brief Triggered when the source device changes.
                // @text reportAudioDevicePowerStatus
                // @details Triggered when the source device changes.
                // @param powerStatus: Power status of the device
                // @example powerStatus: 0
                virtual void ReportAudioDevicePowerStatus(const int powerStatus) {};

                // @brief Notifies when a key release CEC message is received from other CEC device
                // @text onKeyReleaseEvent
                // @details Notifies when a key release CEC message is received from other CEC device
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress: 4
                virtual void OnKeyReleaseEvent(const int logicalAddress) {};

                // @brief Notifies when a key press CEC message is received from other CEC device
                // @text onKeyPressEvent
                // @details Notifies when a key press CEC message is received from other CEC device
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress: 4
                // @param keyCode: Key code of the key press event
                // @example keyCode: 0x44
                virtual void OnKeyPressEvent(const int logicalAddress, const int keyCode) {};

            };

            // @json:omit
            virtual Core::hresult Register(Exchange::IHdmiCecSink::INotification *notification) = 0;
            // @json:omit
            virtual Core::hresult Unregister(Exchange::IHdmiCecSink::INotification *notification) = 0;
            // @json:omit
            virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

            // @brief Gets the Active Route(s) of the HDMI CEC Sink
            // @text getActiveRoute
            // @details Gets the Active Route(s) of the HDMI CEC Sink
            // @param available: Is the active route available or not
            // @example available: true
            // @param length: Length of the active route
            // @example length: 2
            // @param pathList: List of active path
            // @example pathList: [{logicalAddress: 4, physicalAddress: "1.0.0.0"}]
            // @param ActiveRoute: Active route of the device
            // @example ActiveRoute: "1.0.0.0"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The active HDMI-CEC route was retrieved successfully.
            // @retval Core::ERROR_GENERAL The active HDMI-CEC route could not be retrieved.
            virtual Core::hresult GetActiveRoute(bool &available /* @out */, uint8_t &length /* @out */, IHdmiCecSinkActivePathIterator*& pathList /* @out */, string &ActiveRoute /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the status of the current active source
            // @text getActiveSource
            // @details Gets the status of the current active source
            // @param available: Is the active source available or not
            // @example available: true
            // @param logicalAddress: Logical address of the active source
            // @example logicalAddress: 4
            // @param physicalAddress: Physical address of the active source
            // @example physicalAddress: "1.0.0.0"
            // @param deviceType: Device type of the active source
            // @example deviceType: "Playback Device"
            // @param cecVersion: CEC version of the active source
            // @example cecVersion: "1.4"
            // @param osdName: OSD name of the active source
            // @example osdName: "STB"
            // @param vendorID: Vendor ID of the active source
            // @example vendorID: "0x0000"
            // @param powerStatus: Power status of the active source
            // @example powerStatus: "On"
            // @param port: Port number of the active source
            // @example port: "HDMI0"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The active source was retrieved successfully.
            // @retval Core::ERROR_GENERAL The active source could not be retrieved.
            virtual Core::hresult GetActiveSource(bool &available /* @out */, uint8_t &logicalAddress /* @out */, string &physicalAddress /* @out */, string &deviceType /* @out */, string &cecVersion /* @out */, string &osdName /* @out */, string &vendorID /* @out*/, string &powerStatus /* @out */, string &port /* @out */, bool &success /* @out */) = 0;

            // @brief Gets audio device connected status
            // @text getAudioDeviceConnectedStatus
            // @details Gets the connected status of the audio device
            // @param connected: Is the audio device connected or not
            // @example connected: true
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The audio device connected status was retrieved successfully.
            // @retval Core::ERROR_GENERAL The audio device connected status could not be retrieved.
            virtual Core::hresult GetAudioDeviceConnectedStatus(bool &connected /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the list of devices connected to the HDMI CEC sink
            // @text getDeviceList
            // @details Gets the list of devices connected to the HDMI CEC sink
            // @param numberofdevices: Number of devices connected to the HDMI CEC sink
            // @example numberofdevices: 2
            // @param deviceList: List of devices connected to the HDMI CEC sink
            // @example deviceList: [{logicalAddress: 4, physicalAddress: "1.0.0.0", deviceType: "Playback Device", cecVersion: "1.4", osdName: "STB", vendorID: "0x0000", powerStatus: "On", port: "HDMI0"}]
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The device list was retrieved successfully.
            // @retval Core::ERROR_GENERAL The device list could not be retrieved.
            virtual Core::hresult GetDeviceList(uint32_t &numberofdevices /* @out */, IHdmiCecSinkDeviceListIterator*& deviceList /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the status of the HDMI CEC Sink
            // @text getEnabled
            // @details Gets the status of the HDMI CEC Sink
            // @param enabled: Is the HDMI CEC Sink enabled or not
            // @example enabled: true
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The HDMI CEC Sink status was retrieved successfully.
            // @retval Core::ERROR_GENERAL The HDMI CEC Sink status could not be retrieved.
            virtual Core::hresult GetEnabled(bool &enabled /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the OSD name of the HDMI CEC Sink
            // @text getOSDName
            // @details Gets the OSD name of the HDMI CEC Sink
            // @param name: OSD name of the HDMI CEC Sink
            // @example name: "TV"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The OSD name was retrieved successfully.
            // @retval Core::ERROR_GENERAL The OSD name could not be retrieved.
            virtual Core::hresult GetOSDName(string &name /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the vendor ID of the HDMI CEC Sink
            // @text getVendorId
            // @details Gets the vendor ID of the HDMI CEC Sink
            // @param vendorid: Vendor ID of the HDMI CEC Sink
            // @example vendorid: "0x0000"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The vendor ID was retrieved successfully.
            // @retval Core::ERROR_GENERAL The vendor ID could not be retrieved.
            virtual Core::hresult GetVendorId(string &vendorid /* @out */, bool &success /* @out */) = 0;

            // @brief This is a helper debug command for developers. It prints the list of connected devices and properties of connected devices 
            // @text printDeviceList
            // @details This is a helper debug command for developers. It prints the list of connected devices and properties of connected devices
            // @param printed: Is the device list printed or not
            // @example printed: true
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The device list was printed successfully.
            // @retval Core::ERROR_GENERAL The device list could not be printed.
            virtual Core::hresult PrintDeviceList(bool &printed /* @out */, bool &success /* @out */) = 0;

            // @brief Request the active source in the network
            // @text requestActiveSource
            // @details Request the active source in the network
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The active source was requested successfully.
            // @retval Core::ERROR_GENERAL The active source could not be requested.
            virtual Core::hresult RequestActiveSource(HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Sends the CEC Request Short Audio Descriptor (SAD) message as an
            // @text requestShortAudioDescriptor
            // @details Sends the CEC Request Short Audio Descriptor (SAD) message as an inquiry to the audio device.
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The SAD request was sent successfully.
            // @retval Core::ERROR_GENERAL The SAD request could not be sent.
            virtual Core::hresult RequestShortAudioDescriptor(HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief This message is used to power on the connected audio device. Usually sent by the TV when it comes out of standby and detects audio device connected in the network.
            // @text sendAudioDevicePowerOnMessage
            // @details This message is used to power on the connected audio device. Usually sent by the TV when it comes out of standby and detects audio device connected in the network.
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The audio device power on message was sent successfully.
            // @retval Core::ERROR_GENERAL The audio device power on message could not be sent.
            virtual Core::hresult SendAudioDevicePowerOnMessage(HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Sends the CEC <Give Audio Status> message to request the audio status.
            // @text sendGetAudioStatusMessage
            // @details Sends the CEC <Give Audio Status> message to request the audio status.
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The audio status request message was sent successfully.
            // @retval Core::ERROR_GENERAL The audio status request message could not be sent.
            virtual Core::hresult SendGetAudioStatusMessage(HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Sends the CEC <User Control Pressed> message when TV remote key is pressed.
            // @text sendKeyPressEvent  
            // @details Sends the CEC <User Control Pressed> message when TV remote key is pressed.
            // @param logicalAddress: Logical address of the device
            // @example logicalAddress: 4
            // @param keyCode: Key code of the key press event
            // @example keyCode: 0x44
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The key press event message was sent successfully.
            // @retval Core::ERROR_GENERAL The key press event message could not be sent.
            virtual Core::hresult SendKeyPressEvent(const uint32_t &logicalAddress , const uint32_t &keyCode , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Sends the CEC <User Control Pressed> message when TV remote key is pressed.
            // @text sendUserControlPressed
            // @details Sends the CEC <User Control Pressed> message when TV remote key is pressed.
            // @param logicalAddress: Logical address of the device
            // @example logicalAddress: 4
            // @param keyCode: Key code of the key press event
            // @example keyCode: 0x44
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The user control pressed message was sent successfully.
            // @retval Core::ERROR_GENERAL The user control pressed message could not be sent.
            virtual Core::hresult SendUserControlPressed(const uint32_t &logicalAddress , const uint32_t &keyCode , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Sends the CEC <User Control Released> message when TV remote key is released.
            // @text sendUserControlReleased
            // @details Sends the CEC <User Control Released> message when TV remote key is released.
            // @param logicalAddress: Logical address of the device
            // @example logicalAddress: 4
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The user control released message was sent successfully.
            // @retval Core::ERROR_GENERAL The user control released message could not be sent.
            virtual Core::hresult SendUserControlReleased(const uint32_t &logicalAddress , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Sends the CEC <Standby> message to another CEC device
            // @text sendStandbyMessage
            // @details Sends the CEC <Standby> message to another CEC device
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The standby message was sent successfully.
            // @retval Core::ERROR_GENERAL The standby message could not be sent.
            virtual Core::hresult SendStandbyMessage(HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Sets the source device to active (setStreamPath). The source wakes from standby if it’s in the standby state.
            // @text setActivePath
            // @details Sets the source device to active (setStreamPath). The source wakes from standby if it’s in the standby state.
            // @param activePath: Active path of the device
            // @example activePath: "1.0.0.0"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The active path was set successfully.
            // @retval Core::ERROR_GENERAL The active path could not be set.
            virtual Core::hresult SetActivePath(const string &activePath , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Sets the current active source as TV (physical address 0.0.0.0). This call needs to be made when the TV switches to internal tuner or any apps.
            // @text setActiveSource
            // @details Sets the current active source as TV (physical address 0.0.0.0). This call needs to be made when the TV switches to internal tuner or any apps.
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The active source was set successfully.
            // @retval Core::ERROR_GENERAL The active source could not be set.
            virtual Core::hresult SetActiveSource(HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Sets the status of the HDMI CEC Sink
            // @text setEnabled
            // @details Sets the status of the HDMI CEC Sink
            // @param enabled: Is the HDMI CEC Sink enabled or not
            // @example enabled: true
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The HDMI CEC Sink status was set successfully.
            // @retval Core::ERROR_GENERAL The HDMI CEC Sink status could not be set.
            virtual Core::hresult SetEnabled(const bool &enabled , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Updates the internal data structure with the new menu Language and also broadcasts the <Set Menu Language> CEC message.
            // @text setMenuLanguage
            // @details Updates the internal data structure with the new menu Language and also broadcasts the <Set Menu Language> CEC message.
            // @param language: Menu language to be set
            // @example language: "eng"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The menu language was set successfully.
            // @retval Core::ERROR_GENERAL The menu language could not be set.
            virtual Core::hresult SetMenuLanguage(const string &language , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Sets the OSD name of the HDMI CEC Sink
            // @text setOSDName
            // @details Sets the OSD name of the HDMI CEC Sink
            // @param osdName: OSD name of the HDMI CEC Sink
            // @example osdName: "My TV"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The OSD name was set successfully.
            // @retval Core::ERROR_GENERAL The OSD name could not be set.
            virtual Core::hresult SetOSDName(const string &name , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Changes routing while switching between HDMI inputs and TV.
            // @text setRoutingChange
            // @details Changes routing while switching between HDMI inputs and TV.
            // @param oldPort: Old port number
            // @example oldPort: "HDMI1"
            // @param newPort: New port number
            // @example newPort: "HDMI2"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The routing change was set successfully.
            // @retval Core::ERROR_GENERAL The routing change could not be set.
            virtual Core::hresult SetRoutingChange(const string &oldPort , const string &newPort , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Enable (or disable) HDMI-CEC Audio Return Channel (ARC) routing. Upon enabling, triggers arcInitiationEvent and upon disabling, triggers arcTerminationEvent.
            // @text setupARCRouting
            // @details Enable (or disable) HDMI-CEC Audio Return Channel (ARC) routing. Upon enabling, triggers arcInitiationEvent and upon disabling, triggers arcTerminationEvent.
            // @param enabled: Is the HDMI-CEC ARC routing enabled or 
            // @example enabled: true
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The HDMI-CEC ARC routing was set successfully.
            // @retval Core::ERROR_GENERAL The HDMI-CEC ARC routing could not be set.
            virtual Core::hresult SetupARCRouting(const bool &enabled , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Sets the vendor ID of the HDMI CEC Sink
            // @text setVendorId
            // @details Sets the vendor ID of the HDMI CEC Sink
            // @param vendorId: Vendor ID of the HDMI CEC Sink
            // @example vendorId: "0x0000"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The vendor ID was set successfully.
            // @retval Core::ERROR_GENERAL The vendor ID could not be set.
            virtual Core::hresult SetVendorId(const string &vendorid , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Sets the Current Latency Values such as Video Latency, Latency Flags,Audio Output Compensated value and Audio Output Delay by sending <Report Current Latency> message for Dynamic Auto LipSync Feature.
            // @text setLatencyInfo
            // @details Sets the Current Latency Values such as Video Latency, Latency Flags,Audio Output Compensated value and Audio Output Delay by sending <Report Current Latency> message for Dynamic Auto LipSync Feature.
            // @param videoLatency: Video Latency value
            // @example videoLatency: "0"
            // @param lowLatencyMode: Low Latency Mode value
            // @example lowLatencyMode: "0"
            // @param audioOutputCompensated: Audio Output Compensated value
            // @example audioOutputCompensated: "0"
            // @param audioOutputDelay: Audio Output Delay value
            // @example audioOutputDelay: "0"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The latency info was set successfully.
            // @retval Core::ERROR_GENERAL The latency info could not be set.
            virtual Core::hresult SetLatencyInfo(const string &videoLatency , const string &lowLatencyMode , const string &audioOutputCompensated , const string &audioOutputDelay , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Requests the audio device power status.
            // @text requestAudioDevicePowerStatus
            // @details Requests the audio device power status.
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE The audio device power status was requested successfully.
            // @retval Core::ERROR_GENERAL The audio device power status could not be requested.
            virtual Core::hresult RequestAudioDevicePowerStatus(HdmiCecSinkSuccess &successResult /* @out */) = 0;

         };
 } // namespace Exchange
 } // namespace WPEFramework
 
