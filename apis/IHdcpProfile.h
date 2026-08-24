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
 
 namespace WPEFramework
 {
     namespace Exchange
     {
         /* @json 1.0.0 @text:keep */
         struct EXTERNAL IHdcpProfile : virtual public Core::IUnknown 
         {
            enum { ID = ID_HDCPPROFILE };

            struct EXTERNAL HDCPStatus
            {
                bool isConnected /* @text isConnected */ /* @brief Indicates whether a display is connected */;
                bool isHDCPCompliant  /* @text isHDCPCompliant */ /* @brief Indicates whether the display is HDCP compliant */;
                bool isHDCPEnabled  /* @text isHDCPEnabled *//* @brief Indicates whether content is protected */;
                uint32_t hdcpReason  /* @text hdcpReason *//* @brief The HDCP status reason */;
                string supportedHDCPVersion  /* @text supportedHDCPVersion */ /* @brief Supported HDCP protocol version by the host device */;
                string receiverHDCPVersion  /* @text receiverHDCPVersion */ /* @brief Supported HDCP protocol version by the receiver device (display) */;
                string currentHDCPVersion  /* @text currentHDCPVersion */ /* @brief Currently used HDCP protocol version */;
            };
 
            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown 
            {
                enum { ID = ID_HDCPPROFILE_NOTIFICATION };
                 
                // @text onDisplayConnectionChanged
                // @brief Triggered if HDMI was connected or disconnected upon receiving onHdmiOutputHotPlug
                // @details This notification is raised when an HDMI display is connected or disconnected after an HDMI output hot-plug event. The notification provides the current HDCP status.
                // @param[in] hdcpStatus HDCP-related data for the connected display.
                // @example hdcpStatus.isConnected: true
                // @example hdcpStatus.isHDCPCompliant: true
                // @example hdcpStatus.currentHDCPVersion: "2.2"
                // @retval Core::ERROR_NONE The display connection status was reported successfully.
                // @retval Core::ERROR_GENERAL The display connection status could not be reported.
                virtual void OnDisplayConnectionChanged(const HDCPStatus hdcpStatus/* @text HDCPStatus*/) {};
            };
            virtual Core::hresult Register(IHdcpProfile::INotification* notification) = 0;
            virtual Core::hresult Unregister(IHdcpProfile::INotification* notification ) = 0;
             
            /**********************getHDCPStatus() - start****************************/
            // @text getHDCPStatus
            // @brief Returns HDCP-related data.
            // @details This method returns HDCP-related information for the connected display, including connection status, compliance, enabled state, status reason, and supported and active HDCP versions.
            // @param[out] hdcpStatus Current HDCP status information.
            // @param[out] success Indicates whether the operation was successful.
            // @example hdcpStatus.isConnected: true
            // @example hdcpStatus.isHDCPEnabled: true
            // @example success: true
            // @param success: Indicates whether the operation was successful
            // @retval Core::ERROR_NONE The current HDCP status was retrieved successfully.
            // @retval Core::ERROR_GENERAL The current HDCP status could not be retrieved.
            virtual Core::hresult GetHDCPStatus(HDCPStatus& hdcpStatus /* @out @text HDCPStatus*/,bool& success  /* @out */) = 0;
            /**********************getHDCPStatus() - end******************************/
             
            /**********************getSettopHDCPSupport() - start*********************************/
            // @text getSettopHDCPSupport
            // @brief Returns which version of HDCP is supported by the STB.
            // @details This method returns the HDCP protocol version supported by the host device and indicates whether HDCP is supported by the set-top box.
            // @param[out] supportedHDCPVersion: HDCP protocol version supported by the host device.
            // @param[out] isHDCPSupported: Indicates whether HDCP is supported by the set-top box.
            // @param[out] success: Indicates whether the operation was successful.
            // @example supportedHDCPVersion: "2.2"
            // @example isHDCPSupported: true
            // @example success: true
            // @retval Core::ERROR_NONE The HDCP support information was retrieved successfully.
            // @retval Core::ERROR_GENERAL The HDCP support information could not be retrieved.
            // @param success: Indicates whether the operation was successful
            virtual Core::hresult GetSettopHDCPSupport(string& supportedHDCPVersion/* @out */,bool& isHDCPSupported/* @out */,bool& success /* @out */) = 0;
            /**********************getSettopHDCPSupport() - end***********************************/ 
         };
     } // namespace Exchange
 } // namespace WPEFramework
