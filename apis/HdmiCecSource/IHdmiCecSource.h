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

            using IHdmiCecSourceDeviceListIterator = RPC::IIteratorType<HdmiCecSourceDevices, ID_HDMI_CEC_SOURCE_DEVICE_LIST_ITERATOR>;


            struct EXTERNAL INotification : virtual public Core::IUnknown
            {
                enum { ID = ID_HDMI_CEC_SOURCE_NOTIFICATION };
    
                // @brief Notifies when CEC device added to CEC network
                // @text onDeviceAdded
                // @param logicalAddress: Logical address of the added device
                virtual void OnDeviceAdded(const int logicalAddress) {};
    
                // @brief Notifies when CEC device removed from CEC network
                // @text onDeviceRemoved
                // @param logicalAddress: Logical address of the removed device
                virtual void OnDeviceRemoved(const int logicalAddress /* @in */) {};
    
                // @brief Notifies when CEC device info updated
                // @text onDeviceInfoUpdated
                // @param deviceInfo: Device info of the updated device
                virtual void OnDeviceInfoUpdated(const int logicalAddress/* @in */) {};
    
                // @brief Notifies when the active source status is updated
                // @text onActiveSourceStatusUpdated
                // @param isActiveSource: Is the active source active or not
                virtual void OnActiveSourceStatusUpdated(const bool status /* @in */) {};
    
                // @brief Notifies when CEC standby message received from the other CEC device
                // @text standbyMessageReceived
                // @param logicalAddress: Logical address of the device
                virtual void StandbyMessageReceived(const int logicalAddress /* @in */) {};

                // @brief Notifies when a key release CEC message is received from other CEC device
                // @text sendKeyReleaseMsgEvent
                // @param logicalAddress: Logical address of the device
                virtual void SendKeyReleaseMsgEvent(const int logicalAddress /* @in */) {};


                // @brief Notifies when a key press CEC message is received from other CEC device
                // @text sendKeyPressMsgEvent
                // @param logicalAddress: Logical address of the device
                // @param keyCode: Key code of the key press event
                virtual void SendKeyPressMsgEvent(const int logicalAddress /* @in */, const int keyCode /* @in */) {};
            };

            // @json:omit
            virtual Core::hresult Register(Exchange::IHdmiCecSource::INotification *notification) = 0;
            // @json:omit
            virtual Core::hresult Unregister(Exchange::IHdmiCecSource::INotification *notification) = 0;
            // @json:omit
            virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

            // @brief Gets the status if the device is the current active source
            // @text getActiveSourceStatus
            // @param status: Is the active source active or not
            // @param success: Is the operation successful or not
            virtual Core::hresult GetActiveSourceStatus(bool &status /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the status of the HDMI CEC source
            // @text getEnabled
            // @param enabled: Is the HDMI CEC source enabled or not
            // @param success: Is the operation successful or not
            virtual Core::hresult GetEnabled(bool &enabled /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the OSD name of the HDMI CEC source
            // @text getOSDName
            // @param name: OSD name of the HDMI CEC source
            // @param success: Is the operation successful or not
            virtual Core::hresult GetOSDName(string &name /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the OTP enabled status of the HDMI CEC source
            // @text getOTPEnabled
            // @param otpEnabled: Is the OTP enabled or not
            // @param success: Is the operation successful or not
            virtual Core::hresult GetOTPEnabled(bool &enabled /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the vendor ID of the HDMI CEC source
            // @text getVendorId
            // @param vendorId: Vendor ID of the HDMI CEC source
            // @param success: Is the operation successful or not
            virtual Core::hresult GetVendorId(string &vendorid /* @out */, bool &success /* @out */) = 0;

            // @brief Performs the OTP action
            // @text performOTPAction
            // @param success: Is the operation successful or not
            virtual Core::hresult PerformOTPAction(bool &success /* @out */) = 0;

            // @brief Sends a key press event to the HDMI CEC device.
            // @text sendKeyPressEvent
            // @param logicalAddress: Logical address of the device
            // @param keyCode: Key code of the key press event
            // @param success: Is the operation successful or not
            virtual Core::hresult SendKeyPressEvent(const uint32_t &logicalAddress /* @in */, const uint32_t &keyCode /* @in */, bool &success /* @out */) = 0;

            // @brief Sends a standby message to the HDMI CEC source
            // @text sendStandbyMessage
            // @param success: Is the operation successful or not
            virtual Core::hresult SendStandbyMessage(bool &success /* @out */) = 0;

            // @brief Sets the status of the HDMI CEC source
            // @text setEnabled
            // @param enabled: Is the HDMI CEC source enabled or not
            // @param success: Is the operation successful or not
            virtual Core::hresult SetEnabled(const bool &enabled /* @in */, bool &success /* @out */) = 0;

            // @brief Sets the OSD name of the HDMI CEC source
            // @text setOSDName
            // @param osdName: OSD name of the HDMI CEC source
            // @param success: Is the operation successful or not
            virtual Core::hresult SetOSDName(const string &name /* @in */, bool &success /* @out */) = 0;

            // @brief Sets the OTP enabled status of the HDMI CEC source
            // @text setOTPEnabled
            // @param enabled: Is the OTP enabled or not
            // @param success: Is the operation successful or not
            virtual Core::hresult SetOTPEnabled(const bool &enabled /* @in */, bool &success /* @out */) = 0;

            // @brief Sets the vendor ID of the HDMI CEC source
            // @text setVendorId
            // @param vendorId: Vendor ID of the HDMI CEC source
            // @param success: Is the operation successful or not
            virtual Core::hresult SetVendorId(const string &vendorid /* @in */, bool &success /* @out */) = 0;

            // @brief Gets the list of devices connected to the HDMI CEC source
            // @text getDeviceList
            // @param deviceList: List of devices connected to the HDMI CEC source
            // @param success: Is the operation successful or not
            virtual Core::hresult GetDeviceList(IHdmiCecSourceDeviceListIterator*& deviceList /* @out */, bool &success /* @out */) = 0;
        };
} // namespace Exchange
} // namespace WPEFramework
