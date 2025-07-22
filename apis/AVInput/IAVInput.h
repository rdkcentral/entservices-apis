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

struct InputDevice
{
    uint8_t id;
    string locator;
    bool connected;
};

struct MixerLevels
{
    uint8_t primaryVolume;
    uint8_t playerVolume;
};

enum VideoPlaneType
{
    PRIMARY = 0,
    SECONDARY = 1
};

struct InputSignalInfo
{
    uint8_t id;
    string locator;
    string status;
};

struct InputVideoMode
{
    uint8_t id;
    string locator;
    uint32_t width;
    uint32_t height;
    bool progressive;
    uint32_t frameRateN;
    uint32_t frameRateD;
};

struct GameFeatureStatus
{
    uint8_t id;
    string gameFeature;
    bool allmMode;
};

namespace WPEFramework
{
    namespace Exchange
    {
        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IAVInput : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_AV_INPUT
            };

            using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
            using IInputDeviceIterator = RPC::IIteratorType<InputDevice, ID_AV_INPUT_DEVICE_LIST_ITERATOR>;

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown
            {
                enum
                {
                    ID = ID_AV_INPUT_NOTIFICATION
                };

                // @text onSignalChanged
                // @brief Triggered when the signal status of an input device changes
                // @param info - in - The new signal information of the input device
                virtual void OnSignalChanged(const InputSignalInfo &info) {};

                // @text onInputStatusChanged
                // @brief Triggered when the input status of an input device changes
                // @param info - in - The new input status information of the input device
                virtual void OnInputStatusChanged(const InputSignalInfo &info) {};

                // @text videoStreamInfoUpdate
                // @brief Triggered when the video mode of an input device changes
                // @param videoMode - in - The new video mode information of the input device
                virtual void videoStreamInfoUpdate(const InputVideoMode &videoMode) {};

                // @text gameFeatureStatusUpdate
                // @brief Triggered when the game feature status of an input device changes
                // @param status - in - The new game feature status of the input device
                virtual void gameFeatureStatusUpdate(const GameFeatureStatus &status) {};

                // @text aviContentTypeUpdate
                // @brief Triggered when the AVI content type of an input device changes
                // @param contentType - in - The new AVI content type of the input device
                virtual void aviContentTypeUpdate(int contentType) {};
            };

            virtual Core::hresult Register(IAVInput::INotification *notification /* @in */) = 0;
            virtual Core::hresult Unregister(IAVInput::INotification *notification /* @in */) = 0;

            // @text numberOfInputs
            // @brief Returns an integer that specifies the number of available inputs
            // @param inputCount - out - An integer representing number of inputs
            virtual Core::hresult numberOfInputs(uint32_t &inputCount /* @out */) = 0;

            // @text getInputDevices
            // @brief Returns a list of input devices of the specified type
            // @param type - in - The type of input devices to retrieve
            // @param devices - out - An iterator to the list of input devices
            virtual Core::hresult getInputDevices(int type /* @in */, IInputDeviceIterator *&devices /* @out */) = 0;

            // @text writeEDID
            // @brief Returns a list of input devices of the specified type
            // @param id - in - The ID of the input device to write EDID to
            // @param edid - in - The EDID message to write
            virtual Core::hresult writeEDID(uint8_t id /* @in */, const string &edid /* @in */) = 0;

            // @text readEDID
            // @brief Reads the EDID from the specified input device
            // @param edid - out - The EDID message read from the device
            // @param id - in - The ID of the input device to write EDID to
            // @param edid - out - The EDID message to read
            virtual Core::hresult readEDID(uint8_t id /* @in */, string &edid /* @out */) = 0;

            // @text getRawSPD
            // @brief Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device as raw bits
            // @param spd - out - The SPD infoFrame packet information read from the device
            virtual Core::hresult getRawSPD(uint8_t id /* @in */, string &spd /* @out */) = 0;

            // @text getSPD
            // @brief Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device
            // @param spd - out - The SPD infoFrame packet information read from the device
            virtual Core::hresult getSPD(uint8_t id /* @in */, string &spd /* @out */) = 0;

            // @text setEdidVersion
            // @brief Sets an HDMI EDID version
            // @param id - in - The ID of the input device to set the EDID version for
            // @param version - in - The EDID version to set
            virtual Core::hresult setEdidVersion(uint8_t id /* @in */, const string &version /* @in */) = 0;

            // @text getEdidVersion
            // @brief Returns the EDID version
            // @param id - in - The ID of the input device to get the EDID version for
            // @param version - out - The EDID version
            virtual Core::hresult getEdidVersion(uint8_t id /* @in */, string &version /* @out */) = 0;

            // @text setEdid2AllmSupport
            // @brief Sets an HDMI ALLM bit in EDID
            // @param id - in - The ID of the input device to set the ALLM bit for
            // @param allm - in - The ALLM bit value to set
            virtual Core::hresult setEdid2AllmSupport(uint8_t id /* @in */, const bool &allm /* @in */) = 0;

            // @text getEdid2AllmSupport
            // @brief Returns the ALLM bit in EDID
            // @param id - in - The ID of the input device to get the ALLM
            // @param allm - out - The ALLM bit value
            virtual Core::hresult getEdid2AllmSupport(uint8_t id /* @in */, bool &allm /* @out */) = 0;

            // @text setVRRSupport
            // @brief Sets an HDMI VRR support bit in EDID
            // @param id - in - The ID of the input device to set the VRR
            // @param vrrSupport - in - The VRR support bit value to set
            virtual Core::hresult setVRRSupport(uint8_t id /* @in */, bool vrrSupport /* @in */) = 0;

            // @text getVRRSupport
            // @brief Returns the VRR support bit in EDID
            // @param id - in - The ID of the input device to get the VRR
            // @param vrrSupport - out - The VRR support bit value
            virtual Core::hresult getVRRSupport(uint8_t id /* @in */, bool &vrrSupport /* @out */) = 0;

            // @text getVRRFrameRate
            // @brief Returns the VRR frame rate for the specified HDMI Input device
            // @param id - in - The ID of the input device to get the VRR
            // @param vrrFrameRate - out - The VRR frame rate
            virtual Core::hresult getVRRFrameRate(uint8_t id /* @in */, double &vrrFrameRate /* @out */) = 0;

            // @text getHdmiVersion
            // @brief Returns the HDMI compatibility version for the specified input device
            // @param id - in - The ID of the input device to get the HDMI version
            // @param hdmiVersion - out - The HDMI compatibility version
            virtual Core::hresult getHdmiVersion(uint8_t id /* @in */, string &hdmiVersion /* @out */) = 0;

            // @text setMixerLevels
            // @brief Sets the mixer levels for the specified input device
            // @param id - in - The ID of the input device to set the mixer levels for
            // @param levels - in - The mixer levels to set
            virtual Core::hresult setMixerLevels(uint8_t id /* @in */, const MixerLevels &levels /* @in */) = 0;

            // @text startInput
            // @brief Starts the specified input device
            // @param id - in - The ID of the input device to start
            virtual Core::hresult startInput(uint8_t id /* @in */, int type /* @in */, bool audioMix /* @in */, const VideoPlaneType &planeType /* @in */, bool topMostPlane /* @in */) = 0;

            // @text stopInput
            // @brief Stops the specified input device
            // @param type - in - The type of input device to stop
            virtual Core::hresult stopInput(int type /* @in */) = 0;

            // @text setVideoRectangle
            // @brief Sets the video rectangle for the specified input device
            // @param x - in - The x-coordinate of the video rectangle
            // @param y - in - The y-coordinate of the video rectangle
            // @param width - in - The width of the video rectangle
            // @param height - in - The height of the video rectangle
            // @param type - in - The type of input device to set the video rectangle for
            virtual Core::hresult setVideoRectangle(uint16_t x /* @in */, uint16_t y /* @in */, uint16_t width /* @in */, uint16_t height /* @in */, uint16_t type /* @in */) = 0;

            // @text currentVideoMode
            // @brief Returns the current video mode for the specified input device
            // @param currentVideoMode - out - The current video mode
            // @param message - out - A message indicating the status of the operation
            virtual Core::hresult currentVideoMode(string &currentVideoMode /* @out */, string &message /* @out */) = 0;

            // @text contentProtected
            // @brief Returns whether the content is protected for the specified input device
            // @param isContentProtected - out - A boolean indicating if the content is protected
            virtual Core::hresult contentProtected(bool &isContentProtected /* @out */) = 0;

            // @text getSupportedGameFeatures
            // @brief Returns the supported game features for the specified input device
            // @param features - out - A list of supported game features
            virtual Core::hresult getSupportedGameFeatures(IStringIterator *&features /* @out */) = 0;

            // @text getGameFeatureStatus
            // @brief Returns the status of a specific game feature for the specified input device
            // @param feature - in - The game feature to check the status of
            // @param status - out - The status of the game feature
            virtual Core::hresult getGameFeatureStatus(uint8_t id /* @in */, const string &feature /* @in */, bool &mode /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
