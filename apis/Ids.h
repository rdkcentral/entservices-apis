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

// This file holds all the identifiers (uint32_t) used to identify an interface. From this
// identifier, the comrpc framework can find the proper proxy/stub in case of communicating
// over a process boundary.
// Some users do not "fully" rebuild the system in case of changes. If this means that the
// Proxy/Stub code is not always rebuild in case of new releases, the identifier associated
// with an interface becomes as important as the interface syntax and as interfaces are not
// allowed to be changed, the ID associated with the interface should also not be changed
// and thus should be "fixed".

// So if you extend this file by defining a new interface ID make sure it is defined (has
// an actual value) and once the enum label has a value, never change it again.

// As some interfaces might be grouped, the first ID of the group is assigned a value, the
// other interfaces belonging to this group use the enum value of label that has an assigned
// value and just increment that label by the proper amount.

// Using this system, all interfaces will have an assigned number. If numbers overlap, the
// compiler, your best friend, will start complaining. Time to reassign the value, before we
// deploy.

// NOTE: Default the gap between each group of interface is 16. If you need more and the new
//       addition is add the end, write a comment with your interface that you might need more
//       than 16 interface in that group so that the next ID is indeed elevated (and rounded
//       up to a multiple of 16) if the next entry is made in the future.

namespace WPEFramework {

namespace Exchange {

    enum IDS : uint32_t {
        ID_ENTOS_OFFSET				     = RPC::IDS::ID_EXTERNAL_CC_INTERFACE_OFFSET,
        ID_BROWSER                                   = ID_ENTOS_OFFSET,
        ID_WEB_BROWSER                               = ID_BROWSER + 1,
        ID_BROWSER_NOTIFICATION                      = ID_BROWSER + 2,
        ID_BROWSER_RESOURCES                         = ID_BROWSER + 3,
        ID_BROWSER_SECURITY                          = ID_BROWSER + 4,
        ID_WEBKITBROWSER_NOTIFICATION                = ID_BROWSER + 5,
        ID_BROWSER_SCRIPTING                         = ID_BROWSER + 6,
        ID_BROWSER_COOKIEJAR                         = ID_BROWSER + 7,
        ID_BROWSER_COOKIEJAR_NOTIFICATION            = ID_BROWSER + 8,
        ID_MEMORY                                    = ID_BROWSER + 9,
        ID_PROCESSMEMORY                             = ID_BROWSER + 10,
        ID_MEMORYEXTENDED                            = ID_BROWSER + 11,
	ID_APPLICATION				     = ID_BROWSER + 12,
	ID_APPLICATION_NOTIFICATION		     = ID_BROWSER + 13,

	ID_DICTIONARY                                = ID_ENTOS_OFFSET + 0x010,
        ID_DICTIONARY_NOTIFICATION                   = ID_DICTIONARY + 1,
        ID_DICTIONARY_ITERATOR                       = ID_DICTIONARY + 2,

        ID_NETFLIX                                   = ID_ENTOS_OFFSET + 0x020,
        ID_NETFLIX_NOTIFICATION                      = ID_NETFLIX + 1,

        ID_CONTENTDECRYPTION                         = ID_ENTOS_OFFSET + 0x030,
        ID_CONTENTDECRYPTION_NOTIFICATION            = ID_CONTENTDECRYPTION + 1,

        ID_PROVISIONING                              = ID_ENTOS_OFFSET + 0x040,
        ID_PROVISIONING_NOTIFICATION                 = ID_PROVISIONING + 1,

        ID_CAPTURE                                   = ID_ENTOS_OFFSET + 0x050,

        ID_PACKAGER                                  = ID_ENTOS_OFFSET + 0x060,
        ID_PACKAGER_INSTALLATIONINFO                 = ID_PACKAGER + 1,
        ID_PACKAGER_PACKAGEINFO                      = ID_PACKAGER + 2,
        ID_PACKAGER_NOTIFICATION                     = ID_PACKAGER + 3,

	ID_COMPOSITION                               = ID_ENTOS_OFFSET + 0x070,
        ID_COMPOSITION_CLIENT                        = ID_COMPOSITION + 1,
        ID_COMPOSITION_RENDER                        = ID_COMPOSITION + 2,
        ID_COMPOSITION_NOTIFICATION                  = ID_COMPOSITION + 3,
        ID_COMPOSITION_DISPLAY                       = ID_COMPOSITION + 4,
        ID_COMPOSITION_CLIENTPROPERTIES              = ID_COMPOSITION + 5,
	ID_BRIGHTNESS                                = ID_COMPOSITION + 6,

        ID_GRAPHICS_PROPERTIES                       = ID_ENTOS_OFFSET + 0x080,
        ID_CONNECTION_PROPERTIES                     = ID_GRAPHICS_PROPERTIES + 1,
        ID_DISPLAY_PROPERTIES                        = ID_GRAPHICS_PROPERTIES + 2,
        ID_COLORIMETRY_ITERATOR                      = ID_GRAPHICS_PROPERTIES + 3,
        ID_CONNECTION_PROPERTIES_NOTIFICATION        = ID_GRAPHICS_PROPERTIES + 4,

        ID_HDR_PROPERTIES                            = ID_ENTOS_OFFSET + 0x090,
        ID_HDR_ITERATOR                              = ID_HDR_PROPERTIES + 1,

        ID_PLAYER_PROPERTIES                         = ID_ENTOS_OFFSET + 0x0A0,
        ID_PLAYER_PROPERTIES_AUDIO                   = ID_PLAYER_PROPERTIES + 1,
        ID_PLAYER_PROPERTIES_VIDEO                   = ID_PLAYER_PROPERTIES + 2,

        ID_DOLBY_OUTPUT                              = ID_ENTOS_OFFSET + 0x0B0,
        ID_DOLBY_OUTPUT_NOTIFICATION                 = ID_DOLBY_OUTPUT + 1,

        ID_CONFIGURATION                             = ID_ENTOS_OFFSET + 0x0C0,

        ID_DEVICE_INFO                               = ID_ENTOS_OFFSET + 0x0D0,
        ID_DEVICE_CAPABILITIES_AUDIO                 = ID_DEVICE_INFO + 1,
        ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT          = ID_DEVICE_INFO + 2,
        ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY      = ID_DEVICE_INFO + 3,
        ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY = ID_DEVICE_INFO + 4,
        ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE    = ID_DEVICE_INFO + 5,
        ID_DEVICE_CAPABILITIES_VIDEO                 = ID_DEVICE_INFO + 6,
        ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT          = ID_DEVICE_INFO + 7,
        ID_DEVICE_CAPABILITIES_RESOLUTION            = ID_DEVICE_INFO + 8,
        ID_FIRMWARE_VERSION                          = ID_DEVICE_INFO + 9,

        ID_FOCUS                                     = ID_ENTOS_OFFSET + 0x0E0,

        ID_ACCESSOROCDM                              = ID_ENTOS_OFFSET + 0x0F0,
        ID_SESSION                                   = ID_ACCESSOROCDM + 1,
        ID_SESSION_CALLBACK                          = ID_ACCESSOROCDM + 2,
        ID_SESSION_EXTENSION                         = ID_ACCESSOROCDM + 3,

        ID_MESSAGE_CONTROL                           = ID_ENTOS_OFFSET + 0x100,
        ID_MESSAGE_CONTROL_ITERATOR                  = ID_MESSAGE_CONTROL + 1,

        ID_STORE                                     = ID_ENTOS_OFFSET + 0x110,
        ID_STORE_NOTIFICATION                        = ID_STORE + 1,
        ID_STORE_CACHE                               = ID_STORE + 2,
        ID_STORE2                                    = ID_STORE + 3,
        ID_STORE2_NOTIFICATION                       = ID_STORE + 4,
        ID_STORE_INSPECTOR                           = ID_STORE + 5,
        ID_STORE_INSPECTOR_NAMESPACE_SIZE_ITERATOR   = ID_STORE + 6,
        ID_STORE_LIMIT                               = ID_STORE + 7,

        ID_PACKAGEMANAGER                            = ID_ENTOS_OFFSET + 0x120,
        ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR         = ID_PACKAGEMANAGER + 1,
        ID_PACKAGEMANAGER_NOTIFICATION               = ID_PACKAGEMANAGER + 2,
        ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR       = ID_PACKAGEMANAGER + 3,
        ID_PACKAGEMANAGER_BROKER                     = ID_PACKAGEMANAGER + 4,
        ID_PACKAGEMANAGER_CALLBACK                   = ID_PACKAGEMANAGER + 5,

        ID_TEXT_TO_SPEECH                            = ID_ENTOS_OFFSET + 0x130,
        ID_TEXT_TO_SPEECH_NOTIFICATION               = ID_TEXT_TO_SPEECH + 1,

        ID_HOMEKITTV                                 = ID_ENTOS_OFFSET + 0x140,
        ID_HOMEKITTV_NOTIFICATION                    = ID_HOMEKITTV + 1,

        ID_USER_SETTINGS                             = ID_ENTOS_OFFSET + 0x150,
        ID_USER_SETTINGS_NOTIFICATION                = ID_USER_SETTINGS + 1,
        ID_USER_SETTINGS_INSPECTOR                   = ID_USER_SETTINGS + 2,
        ID_USER_SETTINGS_MIGRATION_STATE_ITERATOR    = ID_USER_SETTINGS + 3,

	ID_ANALYTICS                                 = ID_ENTOS_OFFSET + 0x160,

	ID_XCAST                                     = ID_ENTOS_OFFSET + 0x170,
	ID_XCAST_NOTIFICATION                        = ID_XCAST + 1,
	ID_XCAST_APPLICATION_INFO_ITERATOR           = ID_XCAST + 2,

        ID_POWER_MANAGER                                           = ID_ENTOS_OFFSET + 0x180,
        ID_POWER_MANAGER_NOTIFICATION_REBOOT                       = ID_POWER_MANAGER + 1,
        ID_POWER_MANAGER_NOTIFICATION_MODE_PRECHANGE               = ID_POWER_MANAGER + 2,
        ID_POWER_MANAGER_NOTIFICATION_MODE_CHANGED                 = ID_POWER_MANAGER + 3,
        ID_POWER_MANAGER_NOTIFICATION_DEEP_SLEEP_TIMEOUT           = ID_POWER_MANAGER + 4,
        ID_POWER_MANAGER_NOTIFICATION_NETWORK_STANDBY_MODE_CHANGED = ID_POWER_MANAGER + 5,
        ID_POWER_MANAGER_NOTIFICATION_THERMAL_MODE_CHANGED         = ID_POWER_MANAGER + 6,

	ID_TEXT_TRACK                                = ID_ENTOS_OFFSET + 0x190,
	ID_TEXT_TRACK_CLOSED_CAPTIONS_STYLE          = ID_TEXT_TRACK + 1,
	ID_TEXT_TRACK_CLOSED_CAPTIONS_STYLE_NOTIFICATION = ID_TEXT_TRACK + 2,

	ID_USB_DEVICE                                = ID_ENTOS_OFFSET + 0x1A0,
	ID_USB_PRODUCT_INFO_ITERATOR                 = ID_USB_DEVICE + 1,
	ID_USB_DEVICE_INFO_ITERATOR                  = ID_USB_DEVICE + 2,
	ID_USB_DEVICE_NOTIFICATION                   = ID_USB_DEVICE + 3,
	ID_USB_DEVICE_ITERATOR                       = ID_USB_DEVICE + 4,

	ID_USB_MASS_STORAGE                          = ID_ENTOS_OFFSET + 0x1B0,
	ID_USB_MASS_STORAGE_DEVICE_INFO_ITERATOR     = ID_USB_MASS_STORAGE + 1,
	ID_USB_MASS_STORAGE_MOUNT_INFO_ITERATOR      = ID_USB_MASS_STORAGE + 2,
	ID_USB_MASS_STORAGE_NOTIFICATION             = ID_USB_MASS_STORAGE + 3,

	ID_RDK_WINDOW_MANAGER                        = ID_ENTOS_OFFSET +0x1C0,
	ID_RDK_WINDOW_MANAGER_NOTIFICATION           = ID_RDK_WINDOW_MANAGER + 1,

    	ID_FIRMWARE_UPDATE                           = ID_ENTOS_OFFSET + 0x1D0,
    	ID_FIRMWARE_UPDATE_NOTIFICATION              = ID_FIRMWARE_UPDATE + 1,

        ID_LIFECYCLE_MANAGER                         = ID_ENTOS_OFFSET + 0x1E0,
        ID_LIFECYCLE_MANAGER_NOTIFICATION            = ID_LIFECYCLE_MANAGER + 1,
        ID_LIFECYCLE_MANAGER_STATE                   = ID_LIFECYCLE_MANAGER + 2,
        ID_LIFECYCLE_MANAGER_STATE_NOTIFICATION      = ID_LIFECYCLE_MANAGER + 3,

	ID_APPMANAGER                                = ID_ENTOS_OFFSET + 0x1F0,
        ID_APPMANAGER_NOTIFICATION                   = ID_APPMANAGER + 1,

        ID_LISA                                      = ID_ENTOS_OFFSET + 0x200,
        ID_LISA_NOTIFICATION                         = ID_LISA + 1,
        ID_LISA_APP_VERSION                          = ID_LISA + 2,
        ID_LISA_APP_VERSION_ITERATOR                 = ID_LISA + 3,
        ID_LISA_APP                                  = ID_LISA + 4,
        ID_LISA_APP_ITERATOR                         = ID_LISA + 5,
        ID_LISA_APPS_PAYLOAD                         = ID_LISA + 6,
        ID_LISA_STORAGE                              = ID_LISA + 7,
        ID_LISA_STORAGE_PAYLOAD                      = ID_LISA + 8,
        ID_LISA_PROGRESS                             = ID_LISA + 9,
        ID_LISA_KEY_VALUE                            = ID_LISA + 10,
        ID_LISA_KEY_VALUE_ITERATOR                   = ID_LISA + 11,
        ID_LISA_METADATA_PAYLOAD                     = ID_LISA + 12,
        ID_LISA_LOCK_INFO                            = ID_LISA + 13,
        ID_LISA_HANDLE_RESULT                        = ID_LISA + 14,

        ID_SYSTEMAUDIOPLAYER                         = ID_ENTOS_OFFSET + 0x210,
        ID_SYSTEMAUDIOPLAYER_NOTIFICATION            = ID_SYSTEMAUDIOPLAYER + 1,

        ID_RUNTIME_MANAGER                           = ID_ENTOS_OFFSET + 0x220,
        ID_RUNTIME_MANAGER_NOTIFICATION              = ID_RUNTIME_MANAGER + 1,

        ID_DEVICE_OPTIMIZE_STATE_ACTIVATOR           = ID_ENTOS_OFFSET + 0x230,

        ID_SYSTEM_MODE                               = ID_ENTOS_OFFSET + 0x240,
        ID_SYSTEM_MODE_NOTIFICATION                  = ID_SYSTEM_MODE + 1,

        ID_OCICONTAINER                              = ID_ENTOS_OFFSET + 0x250,
        ID_OCICONTAINER_NOTIFICATION                 = ID_OCICONTAINER + 1,

        ID_TELEMETRY                                 = ID_ENTOS_OFFSET + 0x260,
        ID_TELEMETRY_NOTIFICATION                    = ID_TELEMETRY + 1,

        ID_APP_PACKAGE_MANAGER                       = ID_ENTOS_OFFSET + 0x300,
        ID_PACKAGE_DOWNLOADER                        = ID_APP_PACKAGE_MANAGER + 1,
        ID_PACKAGE_DOWNLOADER_NOTIFICATION           = ID_APP_PACKAGE_MANAGER + 2,
        ID_PACKAGE_INSTALLER                         = ID_APP_PACKAGE_MANAGER + 3,
        ID_PACKAGE_INSTALLER_NOTIFICATION            = ID_APP_PACKAGE_MANAGER + 4,
        ID_PACKAGE_HANDLER                           = ID_APP_PACKAGE_MANAGER + 5,
        ID_PACKAGE_INFO_ITERATOR                     = ID_APP_PACKAGE_MANAGER + 7,
        ID_PACKAGE_ITERATOR                          = ID_APP_PACKAGE_MANAGER + 8,
        ID_PACKAGE_KEY_VALUE_ITERATOR                = ID_APP_PACKAGE_MANAGER + 9,
	
	ID_STORAGEMANAGER                            = ID_ENTOS_OFFSET + 0x310,

        ID_AUTHSERVICE                               = ID_ENTOS_OFFSET + 0x320,
        ID_AUTHSERVICE_NOTIFICATION                  = ID_AUTHSERVICE + 1,

	ID_NATIVEJS				     = ID_ENTOS_OFFSET + 0x330,

    ID_HDMI_CEC_SOURCE                               = ID_ENTOS_OFFSET + 0x340,
        ID_HDMI_CEC_SOURCE_DEVICE_LIST_ITERATOR          = ID_HDMI_CEC_SOURCE + 1,
        ID_HDMI_CEC_SOURCE_NOTIFICATION                  = ID_HDMI_CEC_SOURCE + 2,

        ID_AMAZONPRIME                               = ID_ENTOS_OFFSET + 0x350,
        ID_AMAZONPRIME_NOTIFICATION                  = ID_AMAZONPRIME + 1,

        ID_SCREEN_CAPTURE                            = ID_ENTOS_OFFSET + 0x360,
        ID_SCREEN_CAPTURE_NOTIFICATION               = ID_SCREEN_CAPTURE + 1,
      
        ID_DEVICE_DIAGNOSTICS                        = ID_ENTOS_OFFSET + 0x370,
        ID_DEVICE_DIAGNOSTICS_PARAM_LIST_ITERATOR    = ID_DEVICE_DIAGNOSTICS + 1,
        ID_DEVICE_DIAGNOSTICS_NOTIFICATION           = ID_DEVICE_DIAGNOSTICS + 2,

        ID_FRAMERATE                                 = ID_ENTOS_OFFSET + 0x380,
        ID_FRAMERATE_NOTIFICATION                    = ID_FRAMERATE + 1
    };
}
}
