/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026
 *
 * Licensed under the Apache License, Version 2.0
 */

#pragma once

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL IGStreamerPlayer : virtual public Core::IUnknown {
        enum { ID = ID_GSTREAMERPLAYER };

        struct INotification : virtual public Core::IUnknown {
            enum { ID = ID_GSTREAMERPLAYER_NOTIFICATION };

            virtual ~INotification() {}

            // @text onPipelineCreated
            // @brief Notification when pipeline is created successfully
            // @param data: pipeline information
            virtual void OnPipelineCreated(const string& data) {}

            // @text onPlaybackStateChanged
            // @brief Notification when playback state changes
            // @param data: state information
            virtual void OnPlaybackStateChanged(const string& data) {}
        };

        virtual ~IGStreamerPlayer() {}

        // @json:omit
        // @text configure
        // @brief Configure plugin
        // @param service: interface instance
        // @retval Core::NONE: Indicates successful configuration
        virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

        // @json:omit
        // @text register
        // @brief Register notification sink
        // @param sink: notification interface pointer
        virtual Core::hresult Register(INotification* sink) = 0;

        // @json:omit
        // @text unregister
        // @brief Unregister notification sink
        // @param sink: notification interface pointer
        virtual Core::hresult Unregister(INotification* sink) = 0;

        // @text createPipeline
        // @brief Create GStreamer pipeline
        // @param input: pipeline description
        // @param output: response message
        virtual Core::hresult CreatePipeline(const string& input, string& output /* @out */) = 0;

        // @text play
        // @brief Start pipeline playback
        // @param input: player information
        // @param output: response message
        virtual Core::hresult Play(const string& input, string& output /* @out */) = 0;

        // @text pause
        // @brief Pause pipeline playback
        // @param input: player information
        // @param output: response message
        virtual Core::hresult Pause(const string& input, string& output /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework //System Audio Player as Reference
