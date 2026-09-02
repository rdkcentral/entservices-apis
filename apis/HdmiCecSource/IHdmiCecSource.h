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
        struct EXTERNAL IHdmiCecSource : virtual public Core::IUnknown {
            enum { ID = ID_HDMI_CEC_SOURCE };

            struct HdmiCecSourceDevices
            {
                uint8_t logicalAddress;
                string vendorID;
                string osdName;
            };

            struct EXTERNAL HdmiCecSourceSuccess {
                bool success;
            };


            using IHdmiCecSourceDeviceListIterator = RPC::IIteratorType<HdmiCecSourceDevices, ID_HDMI_CEC_SOURCE_DEVICE_LIST_ITERATOR>;

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown
            {
                enum { ID = ID_HDMI_CEC_SOURCE_NOTIFICATION };
    
                // @brief Notifies when CEC device added to CEC network
                // @text onDeviceAdded
                // @details Provides the logical address of the added device when it is added to the CEC network.
                // @param logicalAddress: Logical address of the added device
                // @example logicalAddress: 1
                virtual void OnDeviceAdded(const int logicalAddress) {};
    
                // @brief Notifies when CEC device removed from CEC network
                // @text onDeviceRemoved
                // @details Provides the logical address of the removed device when it is removed from the CEC network.
                // @param logicalAddress: Logical address of the removed device
                // @example logicalAddress: 1
                virtual void OnDeviceRemoved(const int logicalAddress ) {};
    
                // @brief Notifies when CEC device info updated
                // @text onDeviceInfoUpdated
                // @details Provides the logical address of the updated device when its information is updated.
                // @param logicalAddress: Logical address of the updated device
                // @example logicalAddress: 1
                virtual void OnDeviceInfoUpdated(const int logicalAddress) {};
    
                // @brief Notifies when the active source status is updated
                // @text onActiveSourceStatusUpdated
                // @details This event is triggered when the active source status changes
                // @param status Indicates whether the active source is active.
                // @example status: true
                virtual void OnActiveSourceStatusUpdated(const bool status ) {};
    
                // @brief Notifies when CEC standby message received from the other CEC device
                // @text standbyMessageReceived
                // @details This event is triggered when a standby message is received from another CEC device
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress: 1
                virtual void StandbyMessageReceived(const int logicalAddress ) {};

                // @brief Notifies when a key release CEC message is received from other CEC device
                // @text onKeyReleaseEvent
                // @details This event is triggered when a key release event is detected from a remote CEC device
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress: 1
                virtual void OnKeyReleaseEvent(const int logicalAddress ) {};


                // @brief Notifies when a key press CEC message is received from other CEC device
                // @text onKeyPressEvent
                // @details This event is triggered when a key press event is detected from a remote CEC device
                // @param logicalAddress: Logical address of the device
                // @example logicalAddress: 1
                // @param keyCode: Key code of the key press event
                // @example keyCode: 123
                virtual void OnKeyPressEvent(const int logicalAddress , const int keyCode ) {};
            };

            // @json:omit
            virtual Core::hresult Register(Exchange::IHdmiCecSource::INotification *notification) = 0;
            // @json:omit
            virtual Core::hresult Unregister(Exchange::IHdmiCecSource::INotification *notification) = 0;
            // @json:omit
            virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

            // @brief Gets the status if the device is the current active source
            // @text getActiveSourceStatus
            // @details Retrieves the current active source status of the HDMI CEC source device
            // @param status: Is the active source active or not
            // @example status: true
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult GetActiveSourceStatus(bool &status /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the status of the HDMI CEC source
            // @text getEnabled
            // @details Retrieves whether the HDMI CEC source is currently enabled or disabled
            // @param enabled: Is the HDMI CEC source enabled or not
            // @example enabled: true
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult GetEnabled(bool &enabled /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the OSD name of the HDMI CEC source
            // @text getOSDName
            // @details Retrieves the On-Screen Display (OSD) name configured for the HDMI CEC source device
            // @param name: OSD name of the HDMI CEC source
            // @example name: "My CEC Source"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult GetOSDName(string &name /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the OTP enabled status of the HDMI CEC source
            // @text getOTPEnabled
            // @details Retrieves whether One-Touch Play (OTP) is enabled for the HDMI CEC source
            // @param otpEnabled: Is the OTP enabled or not
            // @example otpEnabled: true
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult GetOTPEnabled(bool &otpEnabled /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the vendor ID of the HDMI CEC source
            // @text getVendorId
            // @details Retrieves the vendor ID assigned to the HDMI CEC source device
            // @param vendorid: ID of the HDMI CEC source
            // @example vendorid: "123456"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult GetVendorId(string &vendorid /* @out */, bool &success /* @out */) = 0;

            // @brief Performs the OTP action
            // @text performOTPAction
            // @details Triggers the One-Touch Play (OTP) action on the HDMI CEC source device
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult PerformOTPAction(HdmiCecSourceSuccess &success /* @out */) = 0;

            // @brief Sends a key press event to the HDMI CEC device.
            // @text sendKeyPressEvent
            // @details Transmits a key press event to the specified HDMI CEC device with the given key code
            // @param logicalAddress: Logical address of the device
            // @example logicalAddress: 1
            // @param keyCode: Key code of the key press event
            // @example keyCode: 123
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult SendKeyPressEvent(const uint32_t &logicalAddress , const uint32_t &keyCode , HdmiCecSourceSuccess &success /* @out */) = 0;

            // @brief Sends a standby message to another CEC device
            // @text sendStandbyMessage
            // @details Transmits a standby request to all devices on the CEC network
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult SendStandbyMessage(HdmiCecSourceSuccess &success /* @out */) = 0;

            // @brief Sets the status of the HDMI CEC source
            // @text setEnabled
            // @details Enables or disables the HDMI CEC source functionality
            // @param enabled: Is the HDMI CEC source enabled or not
            // @example enabled: true
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult SetEnabled(const bool &enabled , HdmiCecSourceSuccess &success /* @out */) = 0;

            // @brief Sets the OSD name of the HDMI CEC source
            // @text setOSDName
            // @details Configures the On-Screen Display (OSD) name for the HDMI CEC source device
            // @param name: OSD name of the HDMI CEC source
            // @example name: "My CEC Source"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult SetOSDName(const string &name , HdmiCecSourceSuccess &success /* @out */) = 0;

            // @brief Sets the OTP enabled status of the HDMI CEC source
            // @text setOTPEnabled
            // @details Enables or disables One-Touch Play (OTP) functionality for the HDMI CEC source
            // @param enabled: Is the OTP enabled or not
            // @example enabled: true
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult SetOTPEnabled(const bool &enabled , HdmiCecSourceSuccess &success /* @out */) = 0;

            // @brief Sets the vendor ID of the HDMI CEC source
            // @text setVendorId
            // @details Configures the vendor ID for the HDMI CEC source device
            // @param vendorid: Vendor ID of the HDMI CEC source
            // @example vendorid: "123456"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult SetVendorId(const string &vendorid , HdmiCecSourceSuccess &success /* @out */) = 0;

            // @brief Gets the list of devices connected to the HDMI CEC source
            // @text getDeviceList
            // @details Retrieves information about all devices currently connected to the HDMI CEC network
            // @param numberofdevices: Number of devices connected to the HDMI CEC source
            // @example numberofdevices: 2
            // @param deviceList: List of devices connected to the HDMI CEC source
            // @example deviceList: [{ logicalAddress: 1, vendorID: "123456", osdName: "Device1" }, { logicalAddress: 2, vendorID: "654321", osdName: "Device2" }]
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult GetDeviceList(uint32_t &numberofdevices /* @out */, IHdmiCecSourceDeviceListIterator*& deviceList /* @out */, bool &success /* @out */) = 0;
        };
} // namespace Exchange
} // namespace WPEFramework
