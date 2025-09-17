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

            struct EXTERNAL IDevicesChangedNotification : virtual public Core::IUnknown {
                enum {
                    ID = ID_AV_INPUT_NOTIFICATION_DEVICES_CHANGED
                };

                // @text onDevicesChanged
                // @brief Triggered whenever a new HDMI/Composite device is connected to an HDMI/Composite Input
                virtual void OnDevicesChanged(IInputDeviceIterator* const devices) {}
            };

            // @json:omit
            virtual Core::hresult Register(IDevicesChangedNotification* notification) = 0;

            // @json:omit
            virtual Core::hresult Unregister(IDevicesChangedNotification* notification) = 0;

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

            virtual Core::hresult Register(ISignalChangedNotification* notification) = 0;
            virtual Core::hresult Unregister(ISignalChangedNotification* notification) = 0;

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

            virtual Core::hresult Register(IInputStatusChangedNotification* notification) = 0;
            virtual Core::hresult Unregister(IInputStatusChangedNotification* notification) = 0;

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

            virtual Core::hresult Register(IVideoStreamInfoUpdateNotification* notification) = 0;
            virtual Core::hresult Unregister(IVideoStreamInfoUpdateNotification* notification) = 0;

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
                virtual void GameFeatureStatusUpdate(const int id, const string& gameFeature, const bool mode) { };
            };

            virtual Core::hresult Register(IGameFeatureStatusUpdateNotification* notification) = 0;
            virtual Core::hresult Unregister(IGameFeatureStatusUpdateNotification* notification) = 0;

            // @event
            struct EXTERNAL IHdmiContentTypeUpdateNotification : virtual public Core::IUnknown {
                enum {
                    ID = ID_AV_INPUT_NOTIFICATION_HDMI_CONTENT_TYPE_UPDATE
                };

                // @text hdmiContentTypeUpdate
                // @brief Triggered whenever AV Infoframe content type changes for an HDMI Input
                // @param id - in - Hdmi Input port ID for which content type change event received and possible values are port id 0, 1 and 2 for three Hdmi Input ports
                // @param aviContentType - in - new Content type received for the active hdmi input port and the possible integer values indicates following accordingly 0 - Graphics, 1 - Photo, 2 - Cinema, 3 - Game, 4 - Invalid data
                virtual void HdmiContentTypeUpdate(const int id, const int aviContentType) { };
            };

            virtual Core::hresult Register(IHdmiContentTypeUpdateNotification* notification) = 0;
            virtual Core::hresult Unregister(IHdmiContentTypeUpdateNotification* notification) = 0;

            // @text numberOfInputs
            // @brief Returns an integer that specifies the number of available inputs
            // @param numberOfInputs - out - The number of inputs that are available for selection
            // @param success - out - Whether the request succeeded
            virtual Core::hresult NumberOfInputs(uint32_t& numberOfInputs /* @out */, bool& success /* @out */) = 0;

            // <pca> Removed GetInputDevices </pca>

            // @text writeEDID
            // @brief Changes a current EDID value.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param message - in - A new EDID value
            // @param success - out - Whether the request succeeded
            virtual Core::hresult WriteEDID(const int portId, const string& message, SuccessResult& successResult /* @out */) = 0;

            // @text readEDID
            // @brief Returns the current EDID value.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param EDID - out - The EDID Value
            // @param success - out - Whether the request succeeded
            virtual Core::hresult ReadEDID(const int portId, string& EDID /* @out */, bool& success /* @out */) = 0;

            // @text getRawSPD
            // @brief Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device as raw bits
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param HDMISPD - out - The SPD information as raw bits
            // @param success - out - Whether the request succeeded
            virtual Core::hresult GetRawSPD(const int portId, string& HDMISPD /* @out */, bool& success /* @out */) = 0;

            // @text getSPD
            // @brief Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param HDMISPD - out - The SPD information
            // @param success - out - Whether the request succeeded
            virtual Core::hresult GetSPD(const int portId, string& HDMISPD /* @out */, bool& success /* @out */) = 0;

            // @text setEdidVersion
            // @brief Sets an HDMI EDID version
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param edidVersion - in - The EDID version
            // @param success - out - Whether the request succeeded
            virtual Core::hresult SetEdidVersion(const int portId, const string& edidVersion, SuccessResult& successResult /* @out */) = 0;

            // @text getEdidVersion
            // @brief Returns the EDID version
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param edidVersion - out - The EDID version
            // @param success - out - Whether the request succeeded
            virtual Core::hresult GetEdidVersion(const int portId, string& edidVersion /* @out */, bool& success /* @out */) = 0;

            // @text setEdid2AllmSupport
            // @brief Sets an HDMI ALLM bit in EDID.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param allmSupport - in - The ALLM support in EDID
            // @param success - out - Whether the request succeeded
            virtual Core::hresult SetEdid2AllmSupport(const int portId, const bool allmSupport, SuccessResult& successResult /* @out */) = 0;

            // @text getEdid2AllmSupport
            // @brief Returns the ALLM bit in EDID
            // @param portId - in - The ID of the input device to get the ALLM
            // @param allmSupport - out - The ALLM bit value in edid
            // @param success - out - Whether the request succeeded
            virtual Core::hresult GetEdid2AllmSupport(const int portId, bool& allmSupport /* @out */, bool& success /* @out */) = 0;

            // @text setVRRSupport
            // @brief Sets an HDMI VRR support bit in EDID
            // @param id - in - The ID of the input device to set the VRR
            // @param vrrSupport - in - The VRR support bit value to set
            virtual Core::hresult SetVRRSupport(const int portId, const bool vrrSupport) = 0;

            // @text getVRRSupport
            // @brief Returns the VRR support bit in EDID
            // @param id - in - The ID of the input device to get the VRR
            // @param vrrSupport - out - The VRR support bit value
            virtual Core::hresult GetVRRSupport(const int portId, bool& vrrSupport /* @out */) = 0;

            // @text getHdmiVersion
            // @brief Gets the maximum hdmi compatibility version supported for the given port.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param HdmiCapabilityVersion - out - The Maximum Hdmi compatibility version supported by the given port
            // @param success - out - Whether the request succeeded
            virtual Core::hresult GetHdmiVersion(const int portId, string& HdmiCapabilityVersion /* @out */, bool& success /* @out */) = 0;

            // @text setMixerLevels
            // @brief Sets the audio mixer level for given audio input.
            // @param primaryVolume - in - Primary audio input volume
            // @param inputVolume - in - System audio input volume
            // @param success - out - Whether the request succeeded
            virtual Core::hresult SetMixerLevels(const int primaryVolume, const int inputVolume, SuccessResult& successResult /* @out */) = 0;

            // @text startInput
            // @brief Activates the specified HDMI/Composite Input port as the primary video source.
            // @param portId - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method
            // @param typeOfInput - in - The type of Input - HDMI/COMPOSITE
            // @param audioMix - in - Defines whether the Audio mixing is true or false, This is an optional argument
            // @param planeType - in - Defines whether the video plane type, 0 - Primary video plane, 1 - Secondary Video Plane, Other values - Invalid - This is an optional argument
            // @param topMost - in - Defines whether the Hdmi Input should be over or under the other video plane
            // @param success - out - Whether the request succeeded
            virtual Core::hresult StartInput(const int portId, const int typeOfInput, const bool audioMix, const int planeType, const bool topMost, SuccessResult& successResult /* @out */) = 0;

            // @text stopInput
            // @brief Deactivates the HDMI/Composite Input port currently selected as the primary video source.
            // @param typeOfInput - in - The type of Input - HDMI/COMPOSITE
            // @param success - out - Whether the request succeeded
            virtual Core::hresult StopInput(const int typeOfInput, SuccessResult& successResult /* @out */) = 0;

            // @text setVideoRectangle
            // @brief Sets an HDMI/Composite Input video window.
            // @param x - in - The x-coordinate of the video rectangle
            // @param y - in - The y-coordinate of the video rectangle
            // @param w - in - The width of the video rectangle
            // @param h - in - The height of the video rectangle
            // @param typeOfInput - in - The type of Input - HDMI/COMPOSITE
            // @param success - out - Whether the request succeeded
            virtual Core::hresult SetVideoRectangle(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint16_t typeOfInput, SuccessResult& successResult /* @out */) = 0;

            // @text currentVideoMode
            // @brief Returns the current video mode for the specified input device
            // @param currentVideoMode - out - The current video mode
            // @param success - out - Whether the request succeeded
            virtual Core::hresult CurrentVideoMode(string& currentVideoMode /* @out */, bool& success /* @out */) = 0;

            // @text contentProtected
            // @brief Returns whether the content is protected for the specified input device
            // @param isContentProtected - out - Whether the HDMI input is protected
            // @param success - out - Whether the request succeeded
            virtual Core::hresult ContentProtected(bool& isContentProtected /* @out */, bool& success /* @out */) = 0;

            // @text getSupportedGameFeatures
            // @brief Returns the list of supported game features.
            // @param supportedGameFeatures - out - The supported game Features
            // @param success - out - Whether the request succeeded
            virtual Core::hresult GetSupportedGameFeatures(Exchange::IAVInput::IStringIterator*& supportedGameFeatures /* @out */, bool& success /* @out */) = 0;

            // @text getGameFeatureStatus
            // @brief Returns the Game Feature Status. For example: ALLM.
            // @param portId - in - An ID of an HDMI Input port as returned by the getInputDevices method
            // @param gameFeature - in - Game Feature to which current status requested
            // @param mode - out - The current game feature status. Mode is required only for ALLM. Need to add support for future game features
            // @param success - out - Whether the request succeeded
            virtual Core::hresult GetGameFeatureStatus(const int portId, const string& gameFeature, bool& mode /* @out */, bool& success /* @out */) = 0;

            // @text getVRRFrameRate
            // @brief Returns the current VRR frame rate for the specified input device
            // @param portId - in - An ID of an HDMI Input port as returned by the getInputDevices method
            // @param currentVRRVideoFrameRate - out - The current VRR frame rate
            // @param success - out - Whether the request succeeded
            virtual Core::hresult GetVRRFrameRate(const int portId, double& currentVRRVideoFrameRate /* @out */, bool& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
