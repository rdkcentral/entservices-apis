/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 Metrological
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

namespace WPEFramework {
namespace Exchange {

    // @json @uncompliant:collapsed
    struct EXTERNAL IApplication : virtual public Core::IUnknown {

        enum { ID = ID_APPLICATION };

        ~IApplication() override = default;

        // @event @uncompliant:collapsed
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_APPLICATION_NOTIFICATION };

            ~INotification() override = default;

            /* @brief Application visibility changes */
            /* @details Notifies subscribers when the application's hidden state changes. */
            /* @param hidden Denotes if application is currently hidden */
            /* @example hidden: true */
            virtual void VisibilityChange(const bool hidden) = 0;
        };

        enum resettype : uint8_t {
            FACTORY,
            CACHE,
            CREDENTIALS,
            RECORDINGS
        };

        enum launchpointtype : uint8_t {
            UNDEFINED,
            DIAL,
            DEDICATED_BUTTON,
            DEDICATED_ICON,
            APPLICATION_LIST,
            INTEGRATED_TILE,
            SEARCH_RESULT,
            SEARCH_CONTINUATION,
            VOICE_CONTROL,
            VOICE_SEARCH_RESULT,
            VISUAL_GESTURE,
            TOUCH_GESTURE,
            EPG_GRID,
            CHANNEL_NUMBER,
            CHANNEL_ZAP,
            CHANNEL_BAR,
            WEB_BROWSER,
            POWER_ON,
            POWER_ON_FROM_DEDICATED_BUTTON,
            SUSPENDED_POWER_ON,
            RESTART,
            SUSPENDED_RESTART,
            RESUMED_FROM_SCREEN_SAVER,
            RESUMED_FROM_STANDBY,
            BANNER_AD,
            TITLE_RECOMMENDATION,
            APPLICATION_PROMOTION
        };

        virtual void Register(INotification* sink) = 0;
        virtual void Unregister(INotification* sink) = 0;

        // @brief Resets application data
        // @details Clears the selected category of application data.
        // @param type: Type of reset to perform
        // @example type: FACTORY
        // @retval Core::ERROR_NONE: Application data reset successfully
        virtual uint32_t Reset(const resettype type) = 0;

        // @property
        // @brief Application-specific identification string
        // @details Retrieves the identifier associated with this application.
        // @param id: Identifier string
        // @example id: "com.example.application"
        // @retval Core::ERROR_NONE: Application identifier retrieved successfully
        virtual uint32_t Identifier(string& id /* @out */) const = 0;

        // @property
        // @brief URI of the associated application-specific content
        // @details Sets the URI that identifies the content associated with this application.
        // @param link: Content URI (e.g. https://youtube.com)
        // @example link: "https://youtube.com"
        // @retval Core::ERROR_NONE: Content URI set successfully
        virtual uint32_t ContentLink(const string& link) = 0;

        // @property
        // @brief Application launching point
        // @details Retrieves the launch point that identifies how the application was started.
        // @param point: Receives the application's launch point
        // @example point: DIAL
        // @retval Core::ERROR_NONE: Launch point retrieved successfully
        virtual uint32_t LaunchPoint(launchpointtype& point /* @out */) const = 0;

        // @property
        // @brief Sets the application launching point
        // @details Updates the launch point associated with the application.
        // @param point: Launch point to set
        // @example point: DIAL
        // @retval Core::ERROR_NONE: Launch point set successfully
        virtual uint32_t LaunchPoint(const launchpointtype& point) = 0;

        // @property
        // @brief Current application visibility
        // @details Retrieves whether the application is currently hidden.
        // @param visiblity: Receives true when the application is hidden
        // @example visiblity: false
        // @retval Core::ERROR_NONE: Application visibility retrieved successfully
        virtual uint32_t Visible(bool& visiblity /* @out */) const = 0;

        // @property
        // @brief Sets the current application visibility
        // @details Sets whether the application is hidden.
        // @param visibility: True to hide the application; false to show it
        // @example visibility: true
        // @retval Core::ERROR_NONE: Application visibility set successfully
        virtual uint32_t Visible(const bool visibility) = 0;

        // @property
        // @brief Current application user interface language
        // @details Retrieves the application's user interface language using an RFC 5646 language tag.
        // @param language: Language string as per RFC5646 (e.g. en)
        // @example language: "en-US"
        // @retval Core::ERROR_NONE: Application language retrieved successfully
        virtual uint32_t Language(string& language /* @out */) const = 0;

        // @property
        // @brief Sets the current application user interface language
        // @details Sets the application's user interface language using an RFC 5646 language tag.
        // @param language: Language tag to set (e.g. en-US)
        // @example language: "en-US"
        // @retval Core::ERROR_NONE: Application language set successfully
        virtual uint32_t Language(const string& language) = 0;
    };
}
}
