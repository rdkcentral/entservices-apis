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

                // @text arcInitiationEvent
                // @brief Triggered when routing though the HDMI ARC port is successfully established.
                // @details This event is generated when Audio Return Channel (ARC) routing has been successfully established between the TV and a connected audio device, such as a soundbar or AV receiver.
                // @param status - in - Indicates the result of the ARC initiation operation.
                // @example status - "success"
                virtual void ArcInitiationEvent(const string status) {};

                // @text arcTerminationEvent
                // @brief Triggered when routing though the HDMI ARC port terminates.
                // @details This event is generated when an existing ARC connection is terminated between the TV and the connected audio device.
                // @param status - in - Indicates the result of the ARC termination operation.
                // @example status - "success"
                virtual void ArcTerminationEvent(const string status) {};

                // @text onActiveSourceChange
                // @brief Triggered when the active source device changes.
                // @details This event is generated whenever a different HDMI-CEC source becomes the active source on the HDMI network.
                // @param logicalAddress: Logical address of the active source
                // @example logicalAddress - 4
                // @param physicalAddress: Physical address of the active source
                // @example physicalAddress - "2.0.0.0"
                virtual void OnActiveSourceChange(const int logicalAddress, const string physicalAddress) {};

                // @text onDeviceAdded
                // @brief Triggered when a new device is added to the CEC network.
                // @details This event is generated when a newly discovered HDMI-CEC device becomes available on the CEC network.
                // @param logicalAddress: Logical address of the added device
                // @example logicalAddress - 5
                virtual void OnDeviceAdded(const int logicalAddress) {};

                // @text onDeviceInfoUpdated
                // @brief Triggered when device information changes.
                // @details This event is generated when information associated with an HDMI-CEC device is updated on the network.
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress - 5
                virtual void OnDeviceInfoUpdated(const int logicalAddress) {};

                // @text onDeviceRemoved
                // @brief Triggered when a device is removed from the CEC network.
                // @details This event is generated when an HDMI-CEC device is no longer available or is disconnected from the CEC network.
                // @param logicalAddress: Logical address of the removed device
                // @example logicalAddress - 5
                virtual void OnDeviceRemoved(const int logicalAddress) {};

                // @text onImageViewOnMsg
                // @brief Triggered when an <Image View ON> CEC message is received from the source device.
                // @details This event is generated when a connected source device sends an HDMI-CEC <Image View On> command requesting the TV to display its content.
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress - 4
                virtual void OnImageViewOnMsg(const int logicalAddress) {};

                // @text onInActiveSource
                // @brief Triggered when the source is no longer active.
                // @details This event is generated when an HDMI-CEC source device reports that it is no longer the active source on the HDMI network.
                // @param logicalAddress: Logical address of the source
                // @example logicalAddress - 4
                // @param physicalAddress: Physical address of the source
                // @example physicalAddress - "2.0.0.0"
                virtual void OnInActiveSource(const int logicalAddress, const string physicalAddress) {};

                // @text onTextViewOnMsg
                // @brief Triggered when a <Text View ON> CEC message is received from the source device.
                // @details This event is generated when a connected source device sends an HDMI-CEC <Text View On> command requesting activation of the display.
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress - 4
                virtual void OnTextViewOnMsg(const int logicalAddress) {};

                // @text onWakeupFromStandby
                // @brief Triggered when the TV is in standby mode and it receives <Image View ON>/ <Text View ON>/ <Active Source> CEC message from the connected source device.
                // @details This event is generated when HDMI-CEC activity from a connected source device causes the TV to wake from standby mode.
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress - 4
                virtual void OnWakeupFromStandby(const int logicalAddress) {};

                // @text reportAudioDeviceConnectedStatus
                // @brief Triggered when an audio device is added or removed.
                // @details This event reports changes in the connection status of an HDMI-CEC audio device such as a soundbar or AV receiver.
                // @param status: Status of the audio device
                // @example status - "connected"
                // @param audioDeviceConnected: Audio device connected or not
                // @example audioDeviceConnected - "true"
                virtual void ReportAudioDeviceConnectedStatus(const string status, const string audioDeviceConnected) {};

                // @text reportAudioStatusEvent
                // @brief Triggered when CEC <Report Audio Status> message of device is received.
                // @details This event provides the current volume level and mute status reported by the connected HDMI-CEC audio device.
                // @param muteStatus: Mute status of the device
                // @example muteStatus - 0
                // @param volumeLevel: Volume level of the device
                // @example volumeLevel - 25
                virtual void ReportAudioStatusEvent(const int muteStatus, const int volumeLevel) {};

                // @text reportFeatureAbortEvent
                // @brief Triggered when CEC <Feature Abort> message of device is received.
                // @details This event is generated when a connected HDMI-CEC device rejects a command and returns a <Feature Abort> message.
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress - 5
                // @param opcode: Opcode of the message
                // @example opcode - 130
                // @param FeatureAbortReason: Reason for the feature abort
                // @example FeatureAbortReason - 0
                virtual void ReportFeatureAbortEvent(const int logicalAddress, const int opcode, const int FeatureAbortReason) {};

                // @text reportCecEnabledEvent
                // @brief Triggered when the HDMI-CEC is enabled.
                // @details This event is generated when the HDMI-CEC functionality is enabled on the device. Applications can use this notification to update their UI or initiate CEC-related operations that require HDMI-CEC support.
                // @param cecEnable: HDMI-CEC enabled or not
                // @example cecEnable - "true"
                virtual void ReportCecEnabledEvent(const string cecEnable) {};

                // @text setSystemAudioModeEvent
                // @brief Triggered when CEC <Set System Audio Mode> message of device is received.
                // @details This event is generated when a connected HDMI-CEC device sends a <Set System Audio Mode> command. It indicates a change in the system audio mode state and allows the TV and audio devices to synchronize audio routing.
                // @param audioMode: Audio mode of the device
                // @example audioMode - "on"
                virtual void SetSystemAudioModeEvent(const string audioMode) {};

                // @text shortAudiodescriptorEvent
                // @brief Triggered when SAD is received from the connected audio device. See requestShortAudioDescriptor.
                // @details This event is generated when Short Audio Descriptor (SAD) information is received from a connected HDMI-CEC audio device. The SAD data describes audio formats and capabilities supported by the device.
                // @param shortAudioDescriptor: JSON response containing the Short Audio Descriptor (SAD) information
                // @example shortAudioDescriptor - "{\"audioFormatCode\":1,\"channels\":2}"
                virtual void ShortAudiodescriptorEvent(const string& shortAudioDescriptor) {};

                // @text standbyMessageReceived
                // @brief Triggered when the source device changes status to STANDBY.
                // @details This event is generated when a connected HDMI-CEC source device sends a <Standby> message indicating that it is entering standby mode.
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress - 4
                virtual void StandbyMessageReceived(const int logicalAddress) {};

                // @text reportAudioDevicePowerStatus
                // @brief Triggered when the source device changes.
                // @details This event is generated when the power status of a connected HDMI-CEC audio device is reported. The notification can be used to track whether the audio device is powered on, in standby, or transitioning between power states.
                // @param powerStatus: Power status of the device
                // @example powerStatus - 0
                virtual void ReportAudioDevicePowerStatus(const int powerStatus) {};

                // @text onKeyReleaseEvent                
                // @brief Notifies when a key release CEC message is received from other CEC device
                // @details This event is generated when a connected HDMI-CEC device sends a key release message, indicating that a previously pressed remote-control key has been released.
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress - 5
                virtual void OnKeyReleaseEvent(const int logicalAddress) {};

                // @text onKeyPressEvent
                // @brief Notifies when a key press CEC message is received from other CEC device
                // @details This event is generated when a connected HDMI-CEC device sends a key press message. It provides both the originating device address and the key code associated with the remote-control action.
                // @param logicalAddress: Logical address of the device
                // @param keyCode: Key code of the key press event
                // @example keyCode - 68
                virtual void OnKeyPressEvent(const int logicalAddress, const int keyCode) {};

            };

            // @json:omit
            virtual Core::hresult Register(Exchange::IHdmiCecSink::INotification *notification) = 0;
            // @json:omit
            virtual Core::hresult Unregister(Exchange::IHdmiCecSink::INotification *notification) = 0;
            // @json:omit
            virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

            // @text getActiveRoute
            // @brief Gets the Active Route(s) of the HDMI CEC Sink
            // @details Retrieves the currently active HDMI-CEC route, including the active path list and the physical route of the active device.
            // @param[out] available Indicates whether an active route is available.
            // @param[out] length Number of active paths in the route.
            // @param[out] pathList Iterator containing the active HDMI-CEC paths.
            // @param[out] ActiveRoute Physical route of the active device.
            // @param[out] success Indicates whether the operation was successful.
            // @example available: true
            // @example length: 1
            // @example ActiveRoute: "1.0.0.0"
            // @example success: true
            // @retval Core::ERROR_NONE The active HDMI-CEC route was retrieved successfully.
            // @retval Core::ERROR_GENERAL The active HDMI-CEC route could not be retrieved.
            virtual Core::hresult GetActiveRoute(bool &available /* @out */, uint8_t &length /* @out */, IHdmiCecSinkActivePathIterator*& pathList /* @out */, string &ActiveRoute /* @out */, bool &success /* @out */) = 0;

            // @text getActiveSource
            // @brief Gets the status of the current active source
            // @details Retrieves the active source and its HDMI-CEC properties.
            // @param available: Is the active source available or not
            // @param logicalAddress: Logical address of the active source
            // @param physicalAddress: Physical address of the active source
            // @param deviceType: Device type of the active source
            // @param cecVersion: CEC version of the active source
            // @param osdName: OSD name of the active source
            // @param vendorID: Vendor ID of the active source
            // @param powerStatus: Power status of the active source
            // @param success: Is the operation successful or not
            // @example available: true
            // @example logicalAddress: 4
            // @example physicalAddress: "1.0.0.0"
            // @example deviceType: "Playback Device"
            // @example success: true
            // @retval Core::ERROR_NONE The active source was retrieved successfully.
            // @retval Core::ERROR_GENERAL The active source could not be retrieved.
            virtual Core::hresult GetActiveSource(bool &available /* @out */, uint8_t &logicalAddress /* @out */, string &physicalAddress /* @out */, string &deviceType /* @out */, string &cecVersion /* @out */, string &osdName /* @out */, string &vendorID /* @out*/, string &powerStatus /* @out */, string &port /* @out */, bool &success /* @out */) = 0;

            // @text getAudioDeviceConnectedStatus
            // @brief Gets audio device connected status
            // @details Retrieves whether an HDMI-CEC audio device is connected.
            // @param connected: Is the audio device connected or not
            // @param success: Is the operation successful or not
            // @example connected: true
            // @example success: true
            // @retval Core::ERROR_NONE The audio-device status was retrieved successfully.
            // @retval Core::ERROR_GENERAL The audio-device status could not be retrieved.
            virtual Core::hresult GetAudioDeviceConnectedStatus(bool &connected /* @out */, bool &success /* @out */) = 0;

            // @text getDeviceList
            // @brief Gets the list of devices connected to the HDMI CEC sink
            // @details Retrieves the list of devices connected to the HDMI-CEC sink.
            // @param numberofdevices: Number of devices connected to the HDMI CEC sink
            // @param deviceList: List of devices connected to the HDMI CEC sink
            // @param success: Is the operation successful or not
            // @example numberofdevices: 2
            // @example success: true
            // @retval Core::ERROR_NONE The device list was retrieved successfully.
            // @retval Core::ERROR_GENERAL The device list could not be retrieved.
            virtual Core::hresult GetDeviceList(uint32_t &numberofdevices /* @out */, IHdmiCecSinkDeviceListIterator*& deviceList /* @out */, bool &success /* @out */) = 0;

            // @text getEnabled
            // @brief Gets the status of the HDMI CEC Sink
            // @details Retrieves the HDMI-CEC sink enable state.
            // @param enabled: Is the HDMI CEC Sink enabled or not
            // @param success: Is the operation successful or not
            // @example enabled: true
            // @example success: true
            // @retval Core::ERROR_NONE The HDMI-CEC enable state was retrieved successfully.
            // @retval Core::ERROR_GENERAL The HDMI-CEC enable state could not be retrieved.
            virtual Core::hresult GetEnabled(bool &enabled /* @out */, bool &success /* @out */) = 0;

            // @text getOSDName
            // @brief Gets the OSD name of the HDMI CEC Sink
            // @details Retrieves the OSD name of the HDMI-CEC sink.
            // @param name: OSD name of the HDMI CEC Sink
            // @param success: Is the operation successful or not
            // @example name: "Living Room TV"
            // @example success: true
            // @retval Core::ERROR_NONE The OSD name was retrieved successfully.
            // @retval Core::ERROR_GENERAL The OSD name could not be retrieved.
            virtual Core::hresult GetOSDName(string &name /* @out */, bool &success /* @out */) = 0;

            // @text getVendorId
            // @brief Gets the vendor ID of the HDMI CEC Sink
            // @details Retrieves the vendor ID of the HDMI-CEC sink.
            // @param vendorid: Vendor ID of the HDMI CEC Sink
            // @param success: Is the operation successful or not
            // @example vendorid: "000C03"
            // @example success: true
            // @retval Core::ERROR_NONE The vendor ID was retrieved successfully.
            // @retval Core::ERROR_GENERAL The vendor ID could not be retrieved.
            virtual Core::hresult GetVendorId(string &vendorid /* @out */, bool &success /* @out */) = 0;

            // @text printDeviceList
            // @brief This is a helper debug command for developers. It prints the list of connected devices and properties of connected devices 
            // @details Prints the connected-device list for debugging.
            // @param printed: Is the device list printed or not
            // @param success: Is the operation successful or not
            // @example printed: true
            // @example success: true
            // @retval Core::ERROR_NONE The device list was printed successfully.
            // @retval Core::ERROR_GENERAL The device list could not be printed.
            virtual Core::hresult PrintDeviceList(bool &printed /* @out */, bool &success /* @out */) = 0;

            // @text requestActiveSource
            // @brief Request the active source in the network
            // @details Sends the corresponding HDMI-CEC request or command.
            // @param success: Is the operation successful or not
            // @example successResult.success: true
            // @retval Core::ERROR_NONE The HDMI-CEC command was sent successfully.
            // @retval Core::ERROR_GENERAL The HDMI-CEC command could not be sent.
            virtual Core::hresult RequestActiveSource(HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text requestShortAudioDescriptor
            // @brief Sends the CEC Request Short Audio Descriptor (SAD) message as an
            // @details Sends the corresponding HDMI-CEC request or command.
            // @param success: Is the operation successful or not
            // @example successResult.success: true
            // @retval Core::ERROR_NONE The HDMI-CEC command was sent successfully.
            // @retval Core::ERROR_GENERAL The HDMI-CEC command could not be sent.
            virtual Core::hresult RequestShortAudioDescriptor(HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text sendAudioDevicePowerOnMessage
            // @brief This message is used to power on the connected audio device. Usually sent by the TV when it comes out of standby and detects audio device connected in the network.
            // @details Sends an HDMI-CEC command to a connected audio device, such as an AV Receiver (AVR) or soundbar, requesting it to transition to the On state. This message is typically sent by the TV when it exits standby mode and detects an audio device on the HDMI-CEC network, enabling coordinated power management across connected devices.
            // @param successResult - out - Indicates whether the operation was successful.
            // @example successResult.success - true
            // @retval Core::ERROR_NONE - The power-on message was sent successfully.
            // @retval Core::ERROR_GENERAL - Failed to send the power-on message due to an internal error or HDMI-CEC communication failure.
            virtual Core::hresult SendAudioDevicePowerOnMessage(HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text sendGetAudioStatusMessage
            // @brief Sends the CEC <Give Audio Status> message to request the audio status.
            // @details Transmits an HDMI-CEC <Give Audio Status> command to the connected audio device.audio system and requests its current audio status. The receiving audio device responds with audio-related information such as volume level and mute state through the appropriate HDMI-CEC messages, allowing the host device to synchronize its audio controls with the external audio system.
            // @param successResult - out - Indicates whether the operation was successful.
            // @example successResult.success: true
            // @retval Core::ERROR_NONE - The audio status request message was sent successfully.
            // @retval Core::ERROR_GENERAL - Failed to send the audio status request due to an internal error or HDMI-CEC communication failure.
            virtual Core::hresult SendGetAudioStatusMessage(HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @brief Sends the CEC <User Control Pressed> message when TV remote key is pressed.
            // @text sendKeyPressEvent
            // @details Sends a CEC User Control Pressed message.
            // @param logicalAddress: Logical address of the device
            // @param keyCode: Key code of the key press event
            // @param success: Is the operation successful or not
            // @example logicalAddress: 4
            // @example keyCode: 13
            // @example successResult.success: true
            // @retval Core::ERROR_NONE The key-press command was sent successfully.
            // @retval Core::ERROR_GENERAL The key-press command could not be sent.
            virtual Core::hresult SendKeyPressEvent(const uint32_t &logicalAddress , const uint32_t &keyCode , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text sendUserControlPressed
            // @brief Sends the CEC <User Control Pressed> message when TV remote key is pressed.
            // @details Sends a CEC User Control Pressed message.
            // @param logicalAddress: Logical address of the device
            // @param keyCode: Key code of the key press event
            // @param success: Is the operation successful or not
            // @example logicalAddress: 4
            // @example keyCode: 13
            // @example successResult.success: true
            // @retval Core::ERROR_NONE The key-press command was sent successfully.
            // @retval Core::ERROR_GENERAL The key-press command could not be sent.
            virtual Core::hresult SendUserControlPressed(const uint32_t &logicalAddress , const uint32_t &keyCode , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text sendUserControlReleased
            // @brief Sends the CEC <User Control Released> message when TV remote key is released.
            // @details Sends a CEC User Control Released message.
            // @param logicalAddress: Logical address of the device
            // @param success: Is the operation successful or not
            // @example logicalAddress: 4
            // @example successResult.success: true
            // @retval Core::ERROR_NONE The key-release command was sent successfully.
            // @retval Core::ERROR_GENERAL The key-release command could not be sent.
            virtual Core::hresult SendUserControlReleased(const uint32_t &logicalAddress , HdmiCecSinkSuccess &successResult /* @out */) = 0;
          
            // @text sendStandbyMessage
            // @brief Sends the CEC <Standby> message to another CEC device
            // @details Transmits an HDMI-CEC Standby command to connected CEC-enabled devices. The Standby message requests the target device to enter standby mode, allowing power-state synchronization between the host device and other devices connected through the HDMI network.
            // @param success: Is the operation successful or not
            // @param successResult - out - Indicates whether the operation was successful.
            // @example successResult.success - true
            // @retval Core::ERROR_NONE - The Standby message was sent successfully.
            // @retval Core::ERROR_GENERAL - Failed to send the Standby message due to an internal error or communication failure with the CEC adapter.
            virtual Core::hresult SendStandbyMessage(HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text setActivePath
            // @brief Sets the source device to active (setStreamPath). The source wakes from standby if it’s in the standby state.
            // @details Sets the specified source device as the active HDMI-CEC source.
            // @param activePath: Active path of the device
            // @param success: Is the operation successful or not
            // @example activePath: "1.0.0.0"
            // @example successResult.success: true
            // @retval Core::ERROR_NONE The active path was set successfully.
            // @retval Core::ERROR_GENERAL The active path could not be set.
            virtual Core::hresult SetActivePath(const string &activePath , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text setActiveSource
            // @brief Sets the current active source as TV (physical address 0.0.0.0). This call needs to be made when the TV switches to internal tuner or any apps.
            // @details Broadcasts an HDMI-CEC <Active Source> message with the TV's physical address (0.0.0.0), informing other CEC-enabled devices that the TV is now the active source on the HDMI network. This is typically invoked when switching from an external HDMI source to an internal source such as a tuner, streaming application, or other built-in functionality.
            // @param successResult - out - Indicates whether the operation was successful.
            // @example successResult.success: true
            // @retval Core::ERROR_NONE The Active Source message was sent successfully.
            // @retval Core::ERROR_GENERAL Failed to send the Active Source message due to an internal error or HDMI-CEC communication failure.
            virtual Core::hresult SetActiveSource(HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text setEnabled
            // @brief Sets the status of the HDMI CEC Sink
            // @details Enables or disables HDMI-CEC on the sink.
            // @param enabled: Is the HDMI CEC Sink enabled or not
            // @param success: Is the operation successful or not
            // @example enabled: true
            // @example successResult.success: true
            // @retval Core::ERROR_NONE HDMI-CEC was configured successfully.
            // @retval Core::ERROR_GENERAL HDMI-CEC could not be configured.
            virtual Core::hresult SetEnabled(const bool &enabled , HdmiCecSinkSuccess &successResult /* @out */) = 0;
          
            // @text setMenuLanguage
            // @brief Updates the internal data structure with the new menu Language and also broadcasts the <Set Menu Language> CEC message.
            // @details Sets the menu language and broadcasts a Set Menu Language message.
            // @param language: Menu language to be set
            // @param success: Is the operation successful or not
            // @example language: "eng"
            // @example successResult.success: true
            // @retval Core::ERROR_NONE The menu language was set successfully.
            // @retval Core::ERROR_GENERAL The menu language could not be set.
            virtual Core::hresult SetMenuLanguage(const string &language , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text setOSDName
            // @brief Sets the OSD name of the HDMI CEC Sink
            // @details Sets the OSD name of the HDMI-CEC sink.
            // @param osdName: OSD name of the HDMI CEC Sink
            // @param success: Is the operation successful or not
            // @example name: "Living Room TV"
            // @example successResult.success: true
            // @retval Core::ERROR_NONE The OSD name was set successfully.
            // @retval Core::ERROR_GENERAL The OSD name could not be set.
            virtual Core::hresult SetOSDName(const string &name , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text setRoutingChange
            // @brief Changes routing while switching between HDMI inputs and TV.
            // @details Changes HDMI-CEC routing when switching between HDMI inputs.
            // @param oldPort: Old port number
            // @param newPort: New port number
            // @param success: Is the operation successful or not
            // @example oldPort: "1"
            // @example newPort: "2"
            // @example successResult.success: true
            // @retval Core::ERROR_NONE The routing change was sent successfully.
            // @retval Core::ERROR_GENERAL The routing change could not be sent.
            virtual Core::hresult SetRoutingChange(const string &oldPort , const string &newPort , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text setupARCRouting
            // @brief Enable (or disable) HDMI-CEC Audio Return Channel (ARC) routing. Upon enabling, triggers arcInitiationEvent and upon disabling, triggers arcTerminationEvent.
            // @details Enables or disables HDMI-CEC ARC routing.
            // @param enabled: Is the HDMI-CEC ARC routing enabled or not
            // @example enabled: true
            // @example successResult.success: true
            // @param success: Is the operation successful or not
            // @retval Core::ERROR_NONE ARC routing was configured successfully.
            // @retval Core::ERROR_GENERAL ARC routing could not be configured.
            virtual Core::hresult SetupARCRouting(const bool &enabled , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text setVendorId
            // @brief Sets the vendor ID of the HDMI CEC Sink
            // @details Sets the vendor ID of the HDMI-CEC sink.
            // @param vendorId: Vendor ID of the HDMI CEC Sink
            // @param success: Is the operation successful or not
            // @example vendorid: "000C03"
            // @example successResult.success: true
            // @retval Core::ERROR_NONE The vendor ID was set successfully.
            // @retval Core::ERROR_GENERAL The vendor ID could not be set.
            virtual Core::hresult SetVendorId(const string &vendorid , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text setLatencyInfo
            // @brief Sets the Current Latency Values such as Video Latency, Latency Flags,Audio Output Compensated value and Audio Output Delay by sending <Report Current Latency> message for Dynamic Auto LipSync Feature.
            // @details Sends current latency information for the Dynamic Auto LipSync feature.
            // @param videoLatency: Video Latency value
            // @param lowLatencyMode: Low Latency Mode value
            // @param audioOutputCompensated: Audio Output Compensated value
            // @param audioOutputDelay: Audio Output Delay value
            // @param success: Is the operation successful or not
            // @example videoLatency: "50"
            // @example lowLatencyMode: "1"
            // @example audioOutputCompensated: "0"
            // @example audioOutputDelay: "0"
            // @example successResult.success: true
            // @retval Core::ERROR_NONE The latency information was sent successfully.
            // @retval Core::ERROR_GENERAL The latency information could not be sent.
            virtual Core::hresult SetLatencyInfo(const string &videoLatency , const string &lowLatencyMode , const string &audioOutputCompensated , const string &audioOutputDelay , HdmiCecSinkSuccess &successResult /* @out */) = 0;

            // @text requestAudioDevicePowerStatus
            // @brief Requests the audio device power status.
            // @details Sends an HDMI-CEC power status request to the connected audio device and retrieves its current power state. This API can be used to determine whether the audio device, such as an AVR or soundbar, is in an On, Standby, or transitioning state before performing audio-related CEC operations.
            // @param successResult - out - Indicates whether the operation was successful.
            // @example successResult.success - true
            // @retval Core::ERROR_NONE - The power status request was sent successfully.
            // @retval Core::ERROR_GENERAL - Failed to send the power status request due to an internal error or HDMI-CEC communication failure.
            virtual Core::hresult RequestAudioDevicePowerStatus(HdmiCecSinkSuccess &successResult /* @out */) = 0;

         };
 } // namespace Exchange
 } // namespace WPEFramework
 
