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
         // @json @text:keep
         struct EXTERNAL IHdmiCecSink : virtual public Core::IUnknown {
             enum { ID = ID_HDMI_CEC_SINK };

             struct HdmiCecSinkActivePath
            {
                uint8_t logicalAddress; /* @text logical address*/
                string physicalAddress; /* @text physical address*/
                string deviceType; /* @text device type*/
                string vendorID;    /* @text vendor id*/
                string osdName; /* @text osd name*/
            };

            struct HdmiCecSinkDevices
            {
                uint8_t logicalAddress; /* @text logical address*/
                string physicalAddress; /* @text physical address*/
                string deviceType; /* @text device type*/
                string cecVersion; /* @text cec version*/
                string osdName; /* @text osd name*/
                string vendorID; /* @text vendor id*/
                string powerStatus; /* @text power status*/
                string portNumber; /* @text port number*/
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
                // @param success: Is the operation successful or not
                virtual void ArcInitiationEvent(const string success /* @in */) {};

                // @brief Triggered when routing though the HDMI ARC port terminates.
                // @text arcTerminationEvent
                // @param success: Is the operation successful or not
                virtual void ArcTerminationEvent(const string success /* @in */) {};

                // @brief Triggered when the active source device changes.
                // @text onActiveSourceChange
                // @param logicalAddress: Logical address of the active source
                // @param physicalAddress: Physical address of the active source
                virtual void OnActiveSourceChange(const int logicalAddress /* @in */, const string physicalAddress /* @in */) {};

                // @brief Triggered when a new device is added to the CEC network.
                // @text onDeviceAdded
                // @param logicalAddress: Logical address of the added device
                virtual void OnDeviceAdded(const int logicalAddress /* @in */) {};

                // @brief Triggered when device information changes.
                // @text onDeviceInfoUpdated
                // @param logicalAddress: Logical address of the device
                virtual void OnDeviceInfoUpdated(const int logicalAddress /* @in */) {};

                // @brief Triggered when a device is removed from the CEC network.
                // @text onDeviceRemoved
                // @param logicalAddress: Logical address of the removed device
                virtual void OnDeviceRemoved(const int logicalAddress /* @in */) {};

                // @brief Triggered when an <Image View ON> CEC message is received from the source device.
                // @text onImageViewOnMsg
                // @param logicalAddress: Logical address of the device
                virtual void OnImageViewOnMsg(const int logicalAddress /* @in */) {};

                // @brief Triggered when the source is no longer active.
                // @text onInActiveSource
                // @param logicalAddress: Logical address of the source
                // @param physicalAddress: Physical address of the source
                virtual void OnInActiveSource(const int logicalAddress /* @in */, const string physicalAddress /* @in */) {};

                // @brief Triggered when a <Text View ON> CEC message is received from the source device.
                // @text onTextViewOnMsg
                // @param logicalAddress: Logical address of the device
                virtual void OnTextViewOnMsg(const int logicalAddress /* @in */) {};

                // @brief Triggered when the TV is in standby mode and it receives <Image View ON>/ <Text View ON>/ <Active Source> CEC message from the connected source device.
                // @text onWakeupFromStandby
                // @param logicalAddress: Logical address of the device
                virtual void OnWakeupFromStandby(const int logicalAddress /* @in */) {};

                // @brief Triggered when an audio device is added or removed.
                // @text reportAudioDeviceConnectedStatus
                // @param status: Status of the audio device
                // @param audioDeviceConnected: Audio device connected or not
                virtual void ReportAudioDeviceConnectedStatus(const string status /* @in */, const string audioDeviceConnected /* @in */) {};

                // @brief Triggered when CEC <Report Audio Status> message of device is received.
                // @text reportAudioStatusEvent
                // @param muteStatus: Mute status of the device
                // @param volumeLevel: Volume level of the device
                virtual void ReportAudioStatusEvent(const int muteStatus /* @in */, const int volumeLevel /* @in */) {};

                // @brief Triggered when CEC <Feature Abort> message of device is received.
                // @text reportFeatureAbortEvent
                // @param logicalAddress: Logical address of the device
                // @param opcode: Opcode of the message
                // @param FeatureAbortReason: Reason for the feature abort
                virtual void ReportFeatureAbortEvent(const int logicalAddress /* @in */, const int opcode /* @in */, const int FeatureAbortReason /* @in */) {};

                // @brief Triggered when the HDMI-CEC is enabled.
                // @text reportCecEnabledEvent
                // @param cecEnable: HDMI-CEC enabled or not
                virtual void ReportCecEnabledEvent(const string cecEnable /* @in */) {};

                // @brief Triggered when CEC <Set System Audio Mode> message of device is received.
                // @text setSystemAudioModeEvent
                // @param audioMode: Audio mode of the device
                virtual void SetSystemAudioModeEvent(const string audioMode /* @in */) {};

                // @brief Triggered when SAD is received from the connected audio device. See requestShortAudioDescriptor.
                // @text shortAudiodescriptorEvent
                // @param jsonresponse: JSON response containing the Short Audio Descriptor (SAD) information
                virtual void ShortAudiodescriptorEvent(const string& jsonresponse) {};

                // @brief Triggered when the source device changes status to STANDBY.
                // @text standbyMessageReceived
                // @param logicalAddress: Logical address of the device
                virtual void StandbyMessageReceived(const int logicalAddress /* @in */) {};

                // @brief Triggered when the source device changes.
                // @text reportAudioDevicePowerStatus
                // @param powerStatus: Power status of the device
                virtual void ReportAudioDevicePowerStatus(const int powerStatus /* @in */) {};


            };

            // @json:omit
            virtual Core::hresult Register(Exchange::IHdmiCecSink::INotification *notification) = 0;
            // @json:omit
            virtual Core::hresult Unregister(Exchange::IHdmiCecSink::INotification *notification) = 0;
            // @json:omit
            virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

            // @brief Gets the Active Route(s) of the HDMI CEC Sink
            // @text getActiveRoute
            // @param available: Is the active route available or not
            // @param length: Length of the active route
            // @param pathList: List of active path
            // @param ActiveRoute: Active route of the device
            // @param success: Is the operation successful or not
            virtual Core::hresult GetActiveRoute(bool &available /* @out */, uint8_t &length /* @out */, IHdmiCecSinkActivePathIterator*& pathList /* @out */, string &ActiveRoute /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the status of the current active source
            // @text getActiveSource
            // @param available: Is the active source available or not
            // @param logicalAddress: Logical address of the active source
            // @param physicalAddress: Physical address of the active source
            // @param deviceType: Device type of the active source
            // @param cecVersion: CEC version of the active source
            // @param osdName: OSD name of the active source
            // @param vendorID: Vendor ID of the active source
            // @param powerStatus: Power status of the active source
            // @param success: Is the operation successful or not
            virtual Core::hresult GetActiveSource(bool &available /* @out */, uint8_t &logicalAddress /* @out */, string &physicalAddress /* @out */, string &deviceType /* @out */, string &cecVersion /* @out */, string &osdName /* @out */, string &vendorID /* @out*/, string &powerStatus /* @out */, string &port /* @out */, bool &success /* @out */) = 0;

            // @brief Gets audio device connected status
            // @text getAudioDeviceConnectedStatus
            // @param connected: Is the audio device connected or not
            // @param success: Is the operation successful or not
            virtual Core::hresult GetAudioDeviceConnectedStatus(bool &connected /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the list of devices connected to the HDMI CEC sink
            // @text getDeviceList
            // @param numberofdevices: Number of devices connected to the HDMI CEC sink
            // @param deviceList: List of devices connected to the HDMI CEC sink
            // @param success: Is the operation successful or not
            virtual Core::hresult GetDeviceList(uint32_t &numberofdevices /* @out */, IHdmiCecSinkDeviceListIterator*& deviceList /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the status of the HDMI CEC Sink
            // @text getEnabled
            // @param enabled: Is the HDMI CEC Sink enabled or not
            // @param success: Is the operation successful or not
            virtual Core::hresult GetEnabled(bool &enabled /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the OSD name of the HDMI CEC Sink
            // @text getOSDName
            // @param name: OSD name of the HDMI CEC Sink
            // @param success: Is the operation successful or not
            virtual Core::hresult GetOSDName(string &name /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the vendor ID of the HDMI CEC Sink
            // @text getVendorId
            // @param vendorid: Vendor ID of the HDMI CEC Sink
            // @param success: Is the operation successful or not
            virtual Core::hresult GetVendorId(string &vendorid /* @out */, bool &success /* @out */) = 0;

            // @brief This is a helper debug command for developers. It prints the list of connected devices and properties of connected devices 
            // @text printDeviceList
            // @param printed: Is the device list printed or not
            // @param success: Is the operation successful or not
            virtual Core::hresult PrintDeviceList(bool &printed /* @out */, bool &success /* @out */) = 0;

            // @brief Request the active source in the network
            // @text requestActiveSource
            // @param success: Is the operation successful or not
            virtual Core::hresult RequestActiveSource(HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Sends the CEC Request Short Audio Descriptor (SAD) message as an
            // @text requestShortAudioDescriptor
            // @param success: Is the operation successful or not
            virtual Core::hresult RequestShortAudioDescriptor(HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief This message is used to power on the connected audio device. Usually sent by the TV when it comes out of standby and detects audio device connected in the network.
            // @text sendAudioDevicePowerOnMessage
            // @param success: Is the operation successful or not
            virtual Core::hresult SendAudioDevicePowerOnMessage(HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Sends the CEC <Give Audio Status> message to request the audio status.
            // @text sendGetAudioStatusMessage
            // @param success: Is the operation successful or not
            virtual Core::hresult SendGetAudioStatusMessage(HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Sends the CEC <User Control Pressed> message when TV remote key is pressed.
            // @text sendKeyPressEvent
            // @param logicalAddress: Logical address of the device
            // @param keyCode: Key code of the key press event
            // @param success: Is the operation successful or not
            virtual Core::hresult SendKeyPressEvent(const uint32_t &logicalAddress /* @in */, const uint32_t &keyCode /* @in */, HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Sends the CEC <User Control Pressed> message when TV remote key is pressed.
            // @text sendUserControlPressed
            // @param logicalAddress: Logical address of the device
            // @param keyCode: Key code of the key press event
            // @param success: Is the operation successful or not
            virtual Core::hresult SendUserControlPressed(const uint32_t &logicalAddress /* @in */, const uint32_t &keyCode /* @in */, HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Sends the CEC <User Control Released> message when TV remote key is released.
            // @text sendUserControlReleased
            // @param logicalAddress: Logical address of the device
            // @param success: Is the operation successful or not
            virtual Core::hresult SendUserControlReleased(const uint32_t &logicalAddress /* @in */, HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Sends the CEC <Standby> message to another CEC device
            // @text sendStandbyMessage
            // @param success: Is the operation successful or not
            virtual Core::hresult SendStandbyMessage(HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Sets the source device to active (setStreamPath). The source wakes from standby if it’s in the standby state.
            // @text setActivePath
            // @param activePath: Active path of the device
            // @param success: Is the operation successful or not
            virtual Core::hresult SetActivePath(const string &activePath /* @in */, HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Sets the current active source as TV (physical address 0.0.0.0). This call needs to be made when the TV switches to internal tuner or any apps.
            // @text setActiveSource
            // @param success: Is the operation successful or not
            virtual Core::hresult SetActiveSource(HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Sets the status of the HDMI CEC Sink
            // @text setEnabled
            // @param enabled: Is the HDMI CEC Sink enabled or not
            // @param success: Is the operation successful or not
            virtual Core::hresult SetEnabled(const bool &enabled /* @in */, HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Updates the internal data structure with the new menu Language and also broadcasts the <Set Menu Language> CEC message.
            // @text setMenuLanguage
            // @param language: Menu language to be set
            // @param success: Is the operation successful or not
            virtual Core::hresult SetMenuLanguage(const string &language /* @in */, HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Sets the OSD name of the HDMI CEC Sink
            // @text setOSDName
            // @param osdName: OSD name of the HDMI CEC Sink
            // @param success: Is the operation successful or not
            virtual Core::hresult SetOSDName(const string &name /* @in */, HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Changes routing while switching between HDMI inputs and TV.
            // @text setRoutingChange
            // @param oldPort: Old port number
            // @param newPort: New port number
            // @param success: Is the operation successful or not
            virtual Core::hresult SetRoutingChange(const string &oldPort /* @in */, const string &newPort /* @in */, HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Enable (or disable) HDMI-CEC Audio Return Channel (ARC) routing. Upon enabling, triggers arcInitiationEvent and upon disabling, triggers arcTerminationEvent.
            // @text setupARCRouting
            // @param enabled: Is the HDMI-CEC ARC routing enabled or not
            // @param success: Is the operation successful or not
            virtual Core::hresult SetupARCRouting(const bool &enabled /* @in */, HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Sets the vendor ID of the HDMI CEC Sink
            // @text setVendorId
            // @param vendorId: Vendor ID of the HDMI CEC Sink
            // @param success: Is the operation successful or not
            virtual Core::hresult SetVendorId(const string &vendorid /* @in */, HdmiCecSinkSuccess &success /* @out */) = 0;

            // @brief Sets the Current Latency Values such as Video Latency, Latency Flags,Audio Output Compensated value and Audio Output Delay by sending <Report Current Latency> message for Dynamic Auto LipSync Feature.
            // @text setLatencyInfo
            // @param videoLatency: Video Latency value
            // @param lowLatencyMode: Low Latency Mode value
            // @param audioOutputCompensated: Audio Output Compensated value
            // @param audioOutputDelay: Audio Output Delay value
            // @param success: Is the operation successful or not
            virtual Core::hresult SetLatencyInfo(const string &videoLatency /* @in */, const string &lowLatencyMode /* @in */, const string &audioOutputCompensated /* @in */, const string &audioOutputDelay /* @in */, HdmiCecSinkSuccess &success /* @out */) = 0;

         };

 } // namespace Exchange
 } // namespace WPEFramework
 