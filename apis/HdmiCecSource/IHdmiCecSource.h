/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 Synamedia Ltd.
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
                string vendorId;
                string osdName;
            };

            using IHdmiCecSourceDeviceListIterator = RPC::IIteratorType<HdmiCecSourceDevices, ID_HDMI_CEC_SOURCE_DEVICE_LIST_ITERATOR>;


            struct EXTERNAL INotification : virtual public Core::IUnknown
            {
                enum { ID = ID_HDMI_CEC_SOURCE_NOTIFICATION };
    
                // @brief Device added event
                // @text onDeviceAdded
                virtual void OnDeviceAdded() = 0;
    
                // @brief Device removed event
                // @text onDeviceRemoved
                // @param logicalAddress: Logical address of the removed device
                virtual void OnDeviceRemoved(const uint8_t logicalAddress /* @in */) = 0;
    
                // @brief Device info updated event
                // @text onDeviceInfoUpdated
                // @param deviceInfo: Device info of the updated device
                virtual void OnDeviceInfoUpdated(const int logicalAddress/* @in */) = 0;
    
                // @brief Active source status updated event
                // @text onActiveSourceStatusUpdated
                // @param isActiveSource: Is the active source active or not
                virtual void OnActiveSourceStatusUpdated(const bool isActiveSource /* @in */) = 0;
    
                // @brief Triggered when a device enters standby
                // @text standbyMessageReceived
                // @param logicalAddress: Logical address of the device
                virtual void standbyMessageReceived(const int8_t logicalAddress /* @in */) = 0;

                // @brief Triggered when a key release message is received
                // @text SendKeyReleaseMsgEvent
                // @param logicalAddress: Logical address of the device
                virtual void SendKeyReleaseMsgEvent(const int logicalAddress /* @in */) = 0;


                // @brief Triggered when a key press message is received
                // @text SendKeyPressMsgEvent
                // @param logicalAddress: Logical address of the device
                // @param keyCode: Key code of the key press event
                virtual void SendKeyPressMsgEvent(const int logicalAddress /* @in */, const int keyCode /* @in */) = 0;
            };

            // @json:omit
            virtual uint32_t Register(Exchange::IHdmiCecSource::INotification *notification) = 0;
            // @json:omit
            virtual uint32_t Unregister(Exchange::IHdmiCecSource::INotification *notification) = 0;

            /** Gets the status of the active source. */
            // @text getActiveSourceStatus
            // @brief Gets the status of the active source
            // @param isActiveSource: Is the active source active or not
            virtual uint32_t GetActiveSourceStatus(bool &isActiveSource /* @out */) const = 0;

            // @brief Gets the status of the HDMI CEC source
            // @text getEnabled
            // @param enabled: Is the HDMI CEC source enabled or not
            virtual uint32_t GetEnabled(bool &enabled /* @out */) const = 0;

            // @brief Gets the OSD name of the HDMI CEC source
            // @text getOSDName
            // @param osdName: OSD name of the HDMI CEC source
            virtual uint32_t GetOSDName(string &osdName /* @out */) const = 0;

            // @brief Gets the OTP enabled status of the HDMI CEC source
            // @text getOTPEnabled
            // @param otpEnabled: Is the OTP enabled or not
            virtual uint32_t GetOTPEnabled(bool &otpEnabled /* @out */) const = 0;

            // @brief Gets the vendor ID of the HDMI CEC source
            // @text getVendorId
            // @param vendorId: Vendor ID of the HDMI CEC source
            virtual uint32_t GetVendorId(string &vendorId /* @out */) const = 0;

            // @brief Performs the OTP action
            // @text performOTPAction
            virtual uint32_t PerformOTPAction() = 0;

            // @brief Sends a key press event to the HDMI CEC source
            // @text sendKeyPressEvent
            // @param logicalAddress: Logical address of the device
            // @param keyCode: Key code of the key press event
            virtual uint32_t SendKeyPressEvent(const uint32_t logicalAddress, const uint32_t keyCode /* @in */) = 0;

            // @brief Sends a standby message to the HDMI CEC source
            // @text sendStandbyMessage
            virtual uint32_t SendStandbyMessage() = 0;

            // @brief Sets the status of the HDMI CEC source
            // @text setEnabled
            // @param enabled: Is the HDMI CEC source enabled or not
            virtual uint32_t SetEnabled(const bool enabled /* @in */) = 0;

            // @brief Sets the OSD name of the HDMI CEC source
            // @text setOSDName
            // @param osdName: OSD name of the HDMI CEC source
            virtual uint32_t SetOSDName(const string osdName /* @in */) = 0;

            // @brief Sets the OTP enabled status of the HDMI CEC source
            // @text setOTPEnabled
            // @param enabled: Is the OTP enabled or not
            virtual uint32_t SetOTPEnabled(const bool enabled /* @in */) = 0;

            // @brief Sets the vendor ID of the HDMI CEC source
            // @text setVendorId
            // @param vendorId: Vendor ID of the HDMI CEC source
            virtual uint32_t SetVendorId(const string vendorId /* @in */) = 0;

            virtual uint32_t GetDeviceList(IHdmiCecSourceDeviceListIterator*& deviceList /* @out */) const = 0;
        };
} // namespace Exchange
} // namespace WPEFramework
