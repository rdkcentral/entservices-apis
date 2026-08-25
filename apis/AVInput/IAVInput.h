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

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
    namespace Exchange {
        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IAVInput : virtual public Core::IUnknown {
            enum {
                ID = ID_AV_INPUT
            };

            struct InputDevice {
                int id          /* @brief id */;
                string locator  /* @brief locator */;
                bool connected  /* @brief connected */;
            };

            struct SuccessResult {
                bool success /* @brief success */;
            };

            using IStringIterator       = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
            using IInputDeviceIterator  = RPC::IIteratorType<InputDevice, ID_AV_INPUT_DEVICE_LIST_ITERATOR>;

            // @json:omit
            virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

            struct EXTERNAL IDevicesChangedNotification : virtual public Core::IUnknown {
                enum {
                    ID = ID_AV_INPUT_NOTIFICATION_DEVICES_CHANGED
                };

                // @text onDevicesChanged
                // @brief Triggered whenever a new HDMI/Composite device is connected to an HDMI/Composite Input
                virtual void OnDevicesChanged(IInputDeviceIterator* const devices) {}
            };

            // @json:omit
            virtual Core::hresult RegisterDevicesChangedNotification(IDevicesChangedNotification* notification) = 0;

            // @json:omit
            virtual Core::hresult UnregisterDevicesChangedNotification(IDevicesChangedNotification* notification) = 0;

            // @event
            struct EXTERNAL ISignalChangedNotification : virtual public Core::IUnknown {
                enum {
                    ID = ID_AV_INPUT_NOTIFICATION_SIGNAL_CHANGED
                };

                // @text onSignalChanged
                // @brief Triggered whenever the signal status changes for an HDMI/Composite Input
                // @param id - in - The port identifier for the HDMI/Composite Input
                // @param locator - in - A URL corresponding to the HDMI/Composite Input port
                // @param signalStatus - in - Signal Status of the HDMI/Composite Input. Valid values are noSignal, unstableSignal, notSupportedSignal, stableSignal
                virtual void OnSignalChanged(const int id, const string& locator, const string& signalStatus) { };
            };

            virtual Core::hresult RegisterSignalChangedNotification(ISignalChangedNotification* notification) = 0;
            virtual Core::hresult UnregisterSignalChangedNotification(ISignalChangedNotification* notification) = 0;

            // @event
            struct EXTERNAL IInputStatusChangedNotification : virtual public Core::IUnknown {
                enum {
                    ID = ID_AV_INPUT_NOTIFICATION_INPUT_STATUS_CHANGED
                };

                // @text onInputStatusChanged
                // @brief Triggered whenever the status changes for an HDMI/Composite Input
                // @param id - in - The port identifier for the HDMI/Composite Input
                // @param locator - in - A URL corresponding to the HDMI/Composite Input port
                // @param status - in - Status of the HDMI/Composite Input. Valid values are started or stopped
                // @param plane - in - Defines whether the video plane type, 0 - Primary video plane, 1 - Secondary Video Plane, Other values - Invalid
                virtual void OnInputStatusChanged(const int id, const string& locator, const string& status, const int plane) { };
            };

            virtual Core::hresult RegisterInputStatusChangedNotification(IInputStatusChangedNotification* notification) = 0;
            virtual Core::hresult UnregisterInputStatusChangedNotification(IInputStatusChangedNotification* notification) = 0;

            // @event
            struct EXTERNAL IVideoStreamInfoUpdateNotification : virtual public Core::IUnknown {
                enum {
                    ID = ID_AV_INPUT_NOTIFICATION_VIDEO_STREAM_INFO_UPDATE
                };

                // @text videoStreamInfoUpdate
                // @brief Triggered whenever there is an update in HDMI/Composite Input video stream info
                // @param id - in - The port identifier for the HDMI/Composite Input
                // @param locator - in - A URL corresponding to the HDMI/Composite Input port
                // @param width - in - Width of the Video Stream
                // @param height - in - Height of the Video Stream
                // @param progressive - in - Whether the Video Stream is progressive or not
                // @param frameRateN - in - FrameRate Numerator
                // @param frameRateD - in - FrameRate Denominator
                virtual void VideoStreamInfoUpdate(const int id, const string& locator, const int width, const int height, const bool progressive, const int frameRateN, const int frameRateD) { };
            };

            virtual Core::hresult RegisterVideoStreamInfoUpdateNotification(IVideoStreamInfoUpdateNotification* notification) = 0;
            virtual Core::hresult UnregisterVideoStreamInfoUpdateNotification(IVideoStreamInfoUpdateNotification* notification) = 0;

            // @event
            struct EXTERNAL IGameFeatureStatusUpdateNotification : virtual public Core::IUnknown {
                enum {
                    ID = ID_AV_INPUT_NOTIFICATION_GAME_FEATURE_STATUS_UPDATE
                };

                // @text gameFeatureStatusUpdate
                // @brief Triggered whenever game feature(ALLM) status changes for an HDMI Input
                // @param id - in - The port identifier for the HDMI Input
                // @param gameFeature - in - Game Feature to which current status requested
                // @param mode - in - The current game feature status. Mode is required only for ALLM. Need to add support for future game features
                // @example id: 1
                // @example gameFeature: "ALLM"
                // @example mode: true
                virtual void GameFeatureStatusUpdate(const int id, const string& gameFeature, const bool mode) { };
            };

            virtual Core::hresult RegisterGameFeatureStatusUpdateNotification(IGameFeatureStatusUpdateNotification* notification) = 0;
            virtual Core::hresult UnregisterGameFeatureStatusUpdateNotification(IGameFeatureStatusUpdateNotification* notification) = 0;

            // @event
            struct EXTERNAL IAviContentTypeUpdateNotification : virtual public Core::IUnknown {
                enum {
                    ID = ID_AV_INPUT_NOTIFICATION_AVI_CONTENT_TYPE_UPDATE
                };

                // @text aviContentTypeUpdate
                // @brief Triggered whenever AV Infoframe content type changes for an HDMI Input
                // @details This notification is generated when the HDMI source reports a change
                // in the AVI InfoFrame Content Type field for an active HDMI input port.
                // The event provides the HDMI input port identifier and the newly detected content type.
                // Applications may use this information to optimize display processing or adjust picture settings based on the reported content type.
                // @param id - in - Hdmi Input port ID for which content type change event received and possible values are port id 0, 1 and 2 for three Hdmi Input ports
                // @param aviContentType - in - new Content type received for the active hdmi input port and the possible integer values indicates following accordingly 0 - Graphics, 1 - Photo, 2 - Cinema, 3 - Game, 4 - Invalid data
                // @example id: 0
                // @example aviContentType: 3
                virtual void AviContentTypeUpdate(const int id, const int aviContentType) { };
            };

            virtual Core::hresult RegisterAviContentTypeUpdateNotification(IAviContentTypeUpdateNotification* notification) = 0;
            virtual Core::hresult UnregisterAviContentTypeUpdateNotification(IAviContentTypeUpdateNotification* notification) = 0;

            // @text numberOfInputs
            // @brief Returns an integer that specifies the number of available inputs
            // @details Retrieves the total count of hardware or streaming input ports currently available on the device.
            // @param numberOfInputs - out - The number of inputs that are available for selection
            // @param success - out - Whether the request succeeded
            // @example numberOfInputs: 4
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            // @retval Core::ERROR_GENERAL: Indicates failure
            virtual Core::hresult NumberOfInputs(uint32_t& numberOfInputs /* @out */, bool& success /* @out */) = 0;

            // @text writeEDID
            // @brief Changes a current EDID value.
            // @details Updates the EDID data exposed by the specified HDMI input.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param message - in - A new EDID value
            // @param success - out - Whether the request succeeded
            // @example portId: "HDMI0"
            // @example message: "00FFFFFFFFFFFF0010AC44A04C5A5530"
            // @example success: true
            // @retval Core::ERROR_NONE - EDID was updated successfully.
            // @retval Core::ERROR_GENERAL - EDID update failed.
            virtual Core::hresult WriteEDID(const string& portId, const string& message, SuccessResult& successResult /* @out */) = 0;

            // @text readEDID
            // @brief Returns the current EDID value.
            // @details Retrieves the detailed EDID raw data block currently exposed by the specified active HDMI input port.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param EDID - out - The EDID Value
            // @param success - out - Whether the request succeeded
            // @example portId: "HDMI0"
            // @example EDID: "00FFFFFFFFFFFF0010AC44A04C5A5530"
            // @example success: true
            // @retval Core::ERROR_NONE - EDID was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve EDID.
            virtual Core::hresult ReadEDID(const string& portId, string& EDID /* @out */, bool& success /* @out */) = 0;

            // @text getRawSPD
            // @brief Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device as raw bits
            // @details Retrieves the raw binary payload of the Source Product Descriptor infoFrame transmitted from the source device connected to the specified input port.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param HDMISPD - out - The SPD information as raw bits
            // @param success - out - Whether the request succeeded
            // @example portId: "HDMI0"
            // @example HDMISPD: "0102030405060708090A0B0C0D0E0F10"
            // @example success: true
            // @retval Core::ERROR_NONE - SPD information was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve SPD information.
            virtual Core::hresult GetRawSPD(const string& portId, string& HDMISPD /* @out */, bool& success /* @out */) = 0;

            // @text getSPD
            // @brief Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device
            // @details Retrieves the structured Source Product Descriptor infoFrame data transmitted from the device connected to the specified input port.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param HDMISPD - out - The SPD information
            // @param success - out - Whether the request succeeded
            // @example portId: "HDMI0"
            // @example HDMISPD: "Vendor:Comcast,Product:Xi6,Source:1"
            // @example success: true
            // @retval Core::ERROR_NONE - SPD information was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve SPD information.
            virtual Core::hresult GetSPD(const string& portId, string& HDMISPD /* @out */, bool& success /* @out */) = 0;

            // @text setEdidVersion
            // @brief Sets an HDMI EDID version
            // @details Configures the active EDID structural standard version profile exposed to source transmitters on the specified HDMI port interface.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param edidVersion - in - The EDID version
            // @param success - out - Whether the request succeeded
            // @example portId: "HDMI0"
            // @example edidVersion: "HDMI_VERSION_2.0"
            // @example successResult: {"success": true}
            // @retval Core::ERROR_NONE - EDID version profile was updated successfully.
            // @retval Core::ERROR_GENERAL - Failed to update the EDID version profile.
            virtual Core::hresult SetEdidVersion(const string& portId, const string& edidVersion, SuccessResult& successResult /* @out */) = 0;

            // @text getEdidVersion
            // @brief Returns the EDID version
            // @details Retrieves the active EDID structural standard version profile currently exposed on the specified HDMI port interface.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param edidVersion - out - The EDID version
            // @param success - out - Whether the request succeeded
            // @example portId: "HDMI0"
            // @example edidVersion: "HDMI_VERSION_2.0"
            // @example success: true
            // @retval Core::ERROR_NONE - EDID version profile was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve the EDID version profile.
            virtual Core::hresult GetEdidVersion(const string& portId, string& edidVersion /* @out */, bool& success /* @out */) = 0;

            // @text setEdid2AllmSupport
            // @brief Sets an HDMI ALLM bit in EDID.
            // @details Configures the Auto Low Latency Mode (ALLM) support bit within the EDID structure for the specified HDMI input port.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param allmSupport - in - The ALLM support in EDID
            // @param success - out - Whether the request succeeded
            // @example portId: "HDMI0"
            // @example allmSupport: true
            // @example successResult: {"success": true}
            // @retval Core::ERROR_NONE - HDMI ALLM bit in EDID was updated successfully.
            // @retval Core::ERROR_GENERAL - Failed to update the HDMI ALLM bit in EDID.
            virtual Core::hresult SetEdid2AllmSupport(const string& portId, const bool allmSupport, SuccessResult& successResult /* @out */) = 0;

            // @text getEdid2AllmSupport
            // @brief Returns the ALLM bit in EDID
            // @details Retrieves the Auto Low Latency Mode (ALLM) support bit from the EDID structure for the specified HDMI input port.
            // @param portId - in - The ID of the input device to get the ALLM
            // @param allmSupport - out - The ALLM bit value in edid
            // @param success - out - Whether the request succeeded
            // @example portId: "HDMI0"
            // @example allmSupport: true
            // @example success: true
            // @retval Core::ERROR_NONE - HDMI ALLM bit in EDID was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve the HDMI ALLM bit in EDID.
            virtual Core::hresult GetEdid2AllmSupport(const string& portId, bool& allmSupport /* @out */, bool& success /* @out */) = 0;

            // @text setVRRSupport
            // @brief Sets an HDMI VRR support bit in EDID
            // @details Configures the Variable Refresh Rate (VRR) support bit within the EDID structure for the specified HDMI input port.
            // @param id - in - The ID of the input device to set the VRR
            // @param vrrSupport - in - The VRR support bit value to set
            // @example portId: "HDMI0"
            // @example vrrSupport: true
            // @example successResult: {"success": true}
            // @retval Core::ERROR_NONE - HDMI VRR bit in EDID was updated successfully.
            // @retval Core::ERROR_GENERAL - Failed to update the HDMI VRR bit in EDID.
            virtual Core::hresult SetVRRSupport(const string& portId, const bool vrrSupport, SuccessResult& successResult /* @out */) = 0;

            // @text getVRRSupport
            // @brief Returns the VRR support bit in EDID
            // @details Configures the Variable Refresh Rate (VRR) support bit within the EDID structure for the specified HDMI input port.
            // @param id - in - The ID of the input device to get the VRR
            // @param vrrSupport - out - The VRR support bit value
            // @param success: [Type: Boolean] Whether the request succeeded
            // @retval Core::ERROR_NONE - HDMI VRR bit in EDID was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve the HDMI VRR bit in EDID.
            // @example portId: "HDMI0"
            // @example vrrSupport: true
            // @example success: true
            virtual Core::hresult GetVRRSupport(const string& portId, bool& vrrSupport /* @out */, bool& success /* @out */) = 0;

            // @text getARCPortId
            // @brief Returns the Arc portID of the panel
            // @details Retrieves the unique hardware identifier of the active Audio Return Channel (ARC) port available on the display panel.
            // @param portId - out - The arc port Id
            // @param success - out - Whether the request succeeded
            // @example portId: "HDMI1"
            // @example success: true
            // @retval Core::ERROR_NONE - ARC port ID was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve the ARC port ID.
            virtual Core::hresult GetARCPortId(string& portId /* @out */, bool& success /* @out */) = 0;

            // @text getHdmiVersion
            // @brief Gets the maximum hdmi compatibility version supported for the given port.
            // @details Retrieves the highest HDMI version that the specified HDMI input port can support.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param HdmiCapabilityVersion - out - The Maximum Hdmi compatibility version supported by the given port
            // @param success - out - Whether the request succeeded
            // @example portId: "HDMI0"
            // @example HdmiCapabilityVersion: "HDMI_VERSION_2.1"
            // @example success: true
            // @retval Core::ERROR_NONE - HDMI version was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve the HDMI version.
            virtual Core::hresult GetHdmiVersion(const string& portId, string& HdmiCapabilityVersion /* @out */, bool& success /* @out */) = 0;

            // @text setMixerLevels
            // @brief Sets the audio mixer level for given audio input.
            // @details Configures the dual-stream relative volume mixing levels across the main primary channel and secondary input source.
            // @param primaryVolume - in - Primary audio input volume
            // @param inputVolume - in - System audio input volume
            // @param success - out - Whether the request succeeded
            // @example primaryVolume: 80
            // @example inputVolume: 40
            // @example successResult: {"success": true}
            // @retval Core::ERROR_NONE - Audio mixer levels were updated successfully.
            // @retval Core::ERROR_GENERAL - Failed to update the audio mixer levels.
            virtual Core::hresult SetMixerLevels(const int primaryVolume, const int inputVolume, SuccessResult& successResult /* @out */) = 0;

            // @text startInput
            // @brief Activates the specified HDMI/Composite Input port as the primary video source.
            // @details Initializes and displays the video stream from the designated input port onto the specified display plane layer with optional audio mixing options.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param typeOfInput - in - The type of Input - HDMI/COMPOSITE
            // @param requestAudioMix - in - Defines whether the Audio mixing is true or false, This is an optional argument
            // @param plane - in - Defines whether the video plane type, 0 - Primary video plane, 1 - Secondary Video Plane, Other values - Invalid - This is an optional argument
            // @param topMost - in - Defines whether the Hdmi Input should be over or under the other video plane
            // @param success - out - Whether the request succeeded
            // @example portId: "HDMI0"
            // @example typeOfInput: "HDMI"
            // @example requestAudioMix: true
            // @example plane: 0
            // @example topMost: true
            // @example successResult: {"success": true}
            // @retval Core::ERROR_NONE - Input source was successfully started.
            // @retval Core::ERROR_GENERAL - Failed to activate the specified input port.
            virtual Core::hresult StartInput(const string& portId, const string& typeOfInput, const bool requestAudioMix, const int plane, const bool topMost, SuccessResult& successResult /* @out */) = 0;

            // @text stopInput
            // @brief Deactivates the HDMI/Composite Input port currently selected as the primary video source.
            // @details Tears down the active rendering stream pipelines for the specified input type and frees the associated display plane resources.
            // @param typeOfInput - in - The type of Input - HDMI/COMPOSITE
            // @param success - out - Whether the request succeeded
            // @example typeOfInput: "HDMI"
            // @example successResult: {"success": true}
            // @retval Core::ERROR_NONE - Input source was successfully stopped.
            // @retval Core::ERROR_GENERAL - Failed to deactivate the specified input port.
            virtual Core::hresult StopInput(const string& typeOfInput, SuccessResult& successResult /* @out */) = 0;

            // @text setVideoRectangle
            // @brief Sets an HDMI/Composite Input video window.
            // @details Sets the geometric display boundaries (x, y coordinates alongside width and height) for the active input video stream.
            // @param x - in - The x-coordinate of the video rectangle
            // @param y - in - The y-coordinate of the video rectangle
            // @param w - in - The width of the video rectangle
            // @param h - in - The height of the video rectangle
            // @param typeOfInput - in - The type of Input - HDMI/COMPOSITE
            // @param success - out - Whether the request succeeded
            // @example x: 0
            // @example y: 0
            // @example w: 1920
            // @example h: 1080
            // @example typeOfInput: "HDMI"
            // @example successResult: {"success": true}
            // @retval Core::ERROR_NONE - Video window coordinates were configured successfully.
            // @retval Core::ERROR_GENERAL - Failed to update video window coordinates.
            virtual Core::hresult SetVideoRectangle(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const string& typeOfInput, SuccessResult& successResult /* @out */) = 0;

            // @text currentVideoMode
            // @brief Returns the current video mode for the specified input device
            // @details Retrieves the active video resolution and refresh rate profile currently running on the specified input device pipeline.
            // @param currentVideoMode - out - The current video mode
            // @param success - out - Whether the request succeeded
            // @example currentVideoMode: "1920x1080p60"
            // @example success: true
            // @retval Core::ERROR_NONE - Video mode profile was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve the active video mode.
            virtual Core::hresult CurrentVideoMode(string& currentVideoMode /* @out */, bool& success /* @out */) = 0;

            // @text contentProtected
            // @brief Returns whether the content is protected for the specified input device
            // @details Queries the AV Input subsystem to determine whether the currently active HDMI or Composite input is carrying protected content. Content protection is typically enforced using HDCP or other content protection mechanisms and can be used by applications to determine whether restricted playback or recording policies should be applied.
            // @param isContentProtected - out - Whether the HDMI input is protected
            // @param success - out - Whether the request succeeded
            // @example isContentProtected: true
            // @example success: true
            // @retval Core::ERROR_NONE - The content protection status was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve the content protection status.
            virtual Core::hresult ContentProtected(bool& isContentProtected /* @out */, bool& success /* @out */) = 0;

            // @text getSupportedGameFeatures
            // @brief Returns the list of supported game features.
            // @details Retrieves the array list of advanced gaming optimization features natively supported by the hardware interface layout.
            // @param supportedGameFeatures - out - The supported game Features
            // @param success - out - Whether the request succeeded
            // @example supportedGameFeatures: ["ALLM", "VRR", "QFT"]
            // @example success: true
            // @retval Core::ERROR_NONE - Game features list was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve supported game features.
            virtual Core::hresult GetSupportedGameFeatures(WPEFramework::Exchange::IAVInput::IStringIterator*& supportedGameFeatures /* @out */, bool& success /* @out */) = 0;

            // @text getGameFeatureStatus
            // @brief Returns the Game Feature Status. For example: ALLM.
            // @details Queries the activation runtime toggle state of a specific gaming enhancement capability mapped to the active interface.
            // @param portId - in - An ID of an HDMI Input port as returned by the getInputDevices method
            // @param gameFeature - in - Game Feature to which current status requested
            // @param mode - out - The current game feature status. Mode is required only for ALLM. Need to add support for future game features
            // @param success - out - Whether the request succeeded
            // @example portId: "HDMI0"
            // @example gameFeature: "ALLM"
            // @example mode: true
            // @example success: true
            // @retval Core::ERROR_NONE - Specific game feature state was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve the designated game feature state.
            virtual Core::hresult GetGameFeatureStatus(const string& portId, const string& gameFeature, bool& mode /* @out */, bool& success /* @out */) = 0;

            // @text getVRRFrameRate
            // @brief Returns the current VRR frame rate for the specified input device
            // @details Retrieves the active real-time rendering frame rate frequency operating on the variable refresh rate pipeline.
            // @param portId - in - An ID of an HDMI Input port as returned by the getInputDevices method
            // @param currentVRRVideoFrameRate - out - The current VRR frame rate
            // @param success - out - Whether the request succeeded
            // @example portId: "HDMI0"
            // @example currentVRRVideoFrameRate: 59.94
            // @example success: true
            // @retval Core::ERROR_NONE - The VRR frame rate was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve the VRR frame rate.
            virtual Core::hresult GetVRRFrameRate(const string& portId, double& currentVRRVideoFrameRate /* @out */, bool& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
