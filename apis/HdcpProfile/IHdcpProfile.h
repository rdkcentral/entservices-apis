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
                // @param HDCPStatus: Contains HDCP-related data as separate properties
                virtual void OnDisplayConnectionChanged(const HDCPStatus hdcpStatus) {};
            };
            virtual Core::hresult Register(IHdcpProfile::INotification* notification /* @in */) = 0;
            virtual Core::hresult Unregister(IHdcpProfile::INotification* notification /* @in */) = 0;
             
            /**********************getHDCPStatus() - start****************************/
            // @text getHDCPStatus
            // @brief Returns HDCP-related data.
            // @param HDCPStatus: Contains HDCP-related data as separate properties
            // @param success: Indicates whether the operation was successful
            virtual Core::hresult GetHDCPStatus(HDCPStatus& hdcpStatus /* @out @text HDCPStatus*/,bool& success  /* @out */) = 0;
            /**********************getHDCPStatus() - end******************************/
             
            /**********************getSettopHDCPSupport() - start*********************************/
            // @text getSettopHDCPSupport
            // @brief Returns which version of HDCP is supported by the STB.
            // @param supportedHDCPVersion: Supported HDCP protocol version by the host device
            // @param isHDCPSupported: Indicates whether HDCP is supported by the STB
            // @param success: Indicates whether the operation was successful
            virtual Core::hresult GetSettopHDCPSupport(string& supportedHDCPVersion/* @out */,bool& isHDCPSupported/* @out */,bool& success /* @out */) = 0;
            /**********************getSettopHDCPSupport() - end***********************************/ 
         };
     } // namespace Exchange
 } // namespace WPEFramework
