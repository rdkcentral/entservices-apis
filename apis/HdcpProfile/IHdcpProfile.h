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
			
	 		struct HDCPStatus
			{
				bool isConnected /* Indicates whether a display is connected*/;
				bool isHDCPCompliant /* Indicates whether the display is HDCP compliant*/;
				bool isHDCPEnabled /* Indicates whether content is protected*/;
				uint32_t hdcpReason /* The HDCP status reason*/;
				string supportedHDCPVersion /* Supported HDCP protocol version by the host device*/;
				string receiverHDCPVersion /* Supported HDCP protocol version by the receiver device (display)*/;
				string currentHDCPVersion /* Currently used HDCP protocol version*/;
			};
			struct SupportedHdcpInfo
			{
				string supportedHDCPVersion /* Supported HDCP protocol version by the host device */;
				bool isHDCPSupported /* Indicates whether HDCP is supported by the STB*/;	
			};

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown 
            {
                enum { ID = ID_HDCPPROFILE_NOTIFICATION };
				
				// @text onDisplayConnectionChanged
				// @brief Triggered if HDMI was connected or disconnected upon receiving onHdmiOutputHotPlug
				// @param HDCPStatus - in - string
				virtual void OnDisplayConnectionChanged(const string& HDCPStatus) {};
            };
	    	virtual Core::hresult Register(IHdcpProfile::INotification* notification /* @in */) = 0;
            virtual Core::hresult Unregister(IHdcpProfile::INotification* notification /* @in */) = 0;
			
			/**********************getHDCPStatus() - start****************************/
            // @text getHDCPStatus
            // @brief Returns HDCP-related data.
			// @param HDCPStatus: Contains HDCP-related data as separate properties
            virtual Core::hresult GetHDCPStatus(HDCPStatus &hdcpstatus /* @out */) = 0;
			
			/**********************getSettopHDCPSupport() - start****************************/
            // @text getSettopHDCPSupport
            // @brief Returns which version of HDCP is supported by the STB.
	    	// @param SupportedHdcpInfo: settop supported Hdcp information
            virtual Core::hresult GetHDCPStatus(SupportedHdcpInfo &hdcpinfo /* @out */) = 0;
			
        };
    } // namespace Exchange
} // namespace WPEFramework
