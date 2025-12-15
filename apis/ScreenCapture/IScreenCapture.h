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
        struct EXTERNAL IScreenCapture : virtual public Core::IUnknown 
        {
            enum { ID = ID_SCREEN_CAPTURE };

            struct EXTERNAL Result {
                bool success /* @text success */;
            };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown 
            {
                enum { ID = ID_SCREEN_CAPTURE_NOTIFICATION };

                // @text uploadComplete
                // @brief Triggered after uploading a screen capture
                // @param status - in - boolean
                // @param message - in - string
                // @param call_guid - in - string
                virtual void UploadComplete(const bool& status, const string& message, const string& call_guid ) {};
            };

            virtual Core::hresult Register(IScreenCapture::INotification* notification ) = 0;
            virtual Core::hresult Unregister(IScreenCapture::INotification* notification ) = 0;


            /**********************uploadScreenCapture() - start*******************************/
            // @text uploadScreenCapture
            // @brief Takes a screenshot and uploads it to the specified URL
            // @param url - in - string
            // @param callGUID - in - string
            // @returns Core::hresult
            virtual Core::hresult UploadScreenCapture(const string& url , const string& callGUID , Result &result /* @out  */ ) = 0;
            /**********************uploadScreenCapture() - end*********************************/

            /**********************sendScreenshot() - start*******************************/
            // @text sendScreenshot
            // @brief Takes a screenshot and uploads it to the specified URL
            // @param callGUID -  A unique identifier of a call. The identifier is used to find a corresponding uploadComplete event
            // @returns Core::hresult
            virtual Core::hresult SendScreenshot(const string& callGUID , Result &result /* @out  */ ) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
