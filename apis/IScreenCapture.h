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
                // @details This event is generated when the screen capture upload operation completes. The notification includes the upload status, status message, and the call identifier associated with the upload request.
                // @param status - in - boolean
                // @example status - true
                // @param message - in - string
                // @param call_guid - in - string
                // @example message: "Upload completed successfully"
                // @param call_guid - in - Unique identifier associated with the upload request.
                // @example call_guid: "123e4567-e89b-12d3-a456-426614174000"
                virtual void UploadComplete(const bool& status, const string& message, const string& call_guid ) {};
            };

            virtual Core::hresult Register(IScreenCapture::INotification* notification ) = 0;
            virtual Core::hresult Unregister(IScreenCapture::INotification* notification ) = 0;


            /**********************uploadScreenCapture() - start*******************************/
            // @text uploadScreenCapture
            // @brief Takes a screenshot and uploads it to the specified URL
            // @details Captures the current screen contents and uploads the generated image to the specified destination URL. The provided call GUID is included in the upload workflow and can be used to correlate the request with the corresponding uploadComplete notification.
            // @param url - in - string
            // @example url - "https://example.com/upload"
            // @param callGUID - in - string
            // @example callGUID: "123e4567-e89b-12d3-a456-426614174000"
            // @returns Core::hresult
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE - Screen capture request was accepted successfully.
            // @retval Core::ERROR_GENERAL - Failed to capture or upload the screenshot.
            virtual Core::hresult UploadScreenCapture(const string& url , const string& callGUID , Result &result /* @out  */ ) = 0;
            /**********************uploadScreenCapture() - end*********************************/

            /**********************sendScreenshot() - start*******************************/
            // @text sendScreenshot
            // @brief Takes a screenshot and uploads it to the specified URL
            // @details Captures the current screen and initiates an upload operation. The supplied call GUID can be used to identify the corresponding uploadComplete notification generated when the upload finishes.
            // @param: callGUID -  A unique identifier of a call. The identifier is used to find a corresponding uploadComplete event
            // @example callGUID: "123e4567-e89b-12d3-a456-426614174000"
            // @param: result - Whether the request succeeded
            // @returns Core::hresult
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE - Screenshot request was processed successfully.
            // @retval Core::ERROR_GENERAL - Failed to capture or upload the screenshot.
            virtual Core::hresult SendScreenshot(const string& callGUID , Result &result /* @out  */ ) = 0;
            /**********************sendScreenshot() - end*********************************/
        };
    } // namespace Exchange
} // namespace WPEFramework
