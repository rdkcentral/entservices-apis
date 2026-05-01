/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 RDK Management
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
// @json 1.0.0 @text:keep
struct EXTERNAL IPlaybackSync : virtual public Core::IUnknown {
  enum { ID = ID_PLAYBACK_SYNC };

  struct EXTERNAL Success {
    bool success;
  };

  // @event 
  struct EXTERNAL INotification : virtual public Core::IUnknown {
    enum { ID = ID_PLAYBACK_SYNC_NOTIFICATION };
 
    // @brief Triggered when session participants device details change
    // @text onDeviceDetails
    // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
    // @param numberTimestamp: Reference timestamp of the request
    virtual void OnDeviceDetails(const string& jsonDeviceDetails /* @opaque */, const uint64_t numberTimestamp) { }

    // @brief Triggered when new participants join the room
    // @text onDeviceJoined
    // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
    // @param numberTimestamp: Reference timestamp of the request
    virtual void OnDeviceJoined(const string& jsonDeviceDetails /* @opaque */, const uint64_t numberTimestamp) { }

    // @brief Triggered when a room participant exits
    // @text onDeviceLeft
    // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
    // @param numberTimestamp: Reference timestamp of the request
    virtual void OnDeviceLeft(const string& jsonDeviceDetails /* @opaque */, const uint64_t numberTimestamp) { }

    // @brief Triggered when connection to the service is lost
    // @text onDisconnect
    virtual void OnDisconnect() { }

    // @brief Triggered on error
    // @text onError
    // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
    // @param numberErrorCode: An application defined error number
    // @param numberTimestamp: Reference timestamp of the request
    virtual void OnError(const string& jsonDeviceDetails /* @opaque */, const uint32_t numberErrorCode, const uint64_t numberTimestamp) { }

    // @brief Triggered when the session leadership solicitation action is invoked
    // @text onLeaderRequest
    // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
    // @param booleanRoomLeader: Room leadership status to be solicited
    // @param numberTimestamp: Reference timestamp of the request
    virtual void OnLeaderRequest(const string& jsonDeviceDetails /* @opaque */, const bool booleanRoomLeader, const uint64_t numberTimestamp) { }

    // @brief Triggered when the chat message action is invoked
    // @text onMessage
    // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
    // @param stringMessage: The chat message string
    // @param numberTimestamp: Reference timestamp of the request
    virtual void OnMessage(const string& jsonDeviceDetails /* @opaque */, const string& stringMessage, const uint64_t numberTimestamp) { }

    // @brief Triggered when the content playback pause action is invoked
    // @text onPause
    // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
    // @param numberPosition: Playback position of the content to be shared with room participants
    // @param numberTimestamp: Reference timestamp of the request
    virtual void OnPlaybackPaused(const string& jsonDeviceDetails /* @opaque */, const uint64_t numberPosition, const uint64_t numberTimestamp) { }

    // @brief Triggered when the content playback action is invoked
    // @text onPlay
    // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
    // @param numberPosition: Playback position of the content to be shared with room participants
    // @param numberTimestamp: Reference timestamp of the request
    virtual void OnPlaybackStarted(const string& jsonDeviceDetails /* @opaque */, const uint64_t numberPosition, const uint64_t numberTimestamp) { }

    // @brief Triggered when the service key of shared playback content is specified
    // @text onPlaybackServiceKey
    // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
    // @param stringServiceKey: The service key of the shared playback content
    // @param numberTimestamp: Reference timestamp of the request
    virtual void OnPlaybackServiceKey(const string& jsonDeviceDetails /* @opaque */, const string& stringServiceKey, const uint64_t numberTimestamp) { }

    // @brief Triggered when the URL of shared playback content is specified
    // @text onPlaybackURL
    // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
    // @param stringURL: The URL of the shared playback content
    // @param numberTimestamp: Reference timestamp of the request
    virtual void OnPlaybackURL(const string& jsonDeviceDetails /* @opaque */, const string& stringURL, const uint64_t numberTimestamp) { }

    // @brief Triggered when the content playback position is being published
    // @text onPosition
    // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
    // @param numberPosition: Playback position of the content to be shared with room participants
    // @param numberTimestamp: Reference timestamp of the request
    virtual void OnPlaybackPositionUpdated(const string& jsonDeviceDetails /* @opaque */, const uint64_t numberPosition, const uint64_t numberTimestamp) { }

    // @brief Triggered when the content playback speed action is invoked
    // @text onSpeed
    // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
    // @param numberSpeed: Content playback speed (positive for forward, negative for rewind)
    // @param numberTimestamp: Reference timestamp of the request
    virtual void OnPlaybackSpeedChanged(const string& jsonDeviceDetails /* @opaque */, const int32_t numberSpeed, const uint64_t numberTimestamp) { }

    // @brief Triggered when the content playback stop action is invoked
    // @text onStopped
    // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
    // @param numberTimestamp: Reference timestamp of the request
    virtual void OnPlaybackStopped(const string& jsonDeviceDetails /* @opaque */, const uint64_t numberTimestamp) { }
  };

  /** Register notification interface */
  // @brief Register notification interface
  // @param notification: Notification sink to register for playback synchronization events
  // @retval Core::ERROR_NONE: Notification interface registered successfully
  // @retval Core::ERROR_GENERAL: Failed to register the notification interface
  virtual Core::hresult Register(INotification *notification) = 0;
  /** Unregister notification interface */
  // @brief Unregister notification interface
  // @param notification: Notification sink to unregister from playback synchronization events
  // @retval Core::ERROR_NONE: Notification interface unregistered successfully
  // @retval Core::ERROR_GENERAL: Failed to unregister the notification interface
  virtual Core::hresult Unregister(INotification *notification) = 0;

  /** Allow the plugin to initialize to use service object */
  // @json:omit
  // @brief Initialize the playback synchronization plugin with the given service shell
  // @param service: Service shell instance used to access plugin host facilities
  // @retval Core::ERROR_NONE: Plugin initialized successfully
  // @retval Core::ERROR_GENERAL: Plugin initialization failed
  virtual Core::hresult Initialize(PluginHost::IShell* service) = 0;

  /** Allow the plugin to deinitialize to use service object */
  // @json:omit
  // @brief Deinitialize the playback synchronization plugin and release the service shell
  // @param service: Service shell instance previously provided during initialization
  // @retval Core::ERROR_NONE: Plugin deinitialized successfully
  // @retval Core::ERROR_GENERAL: Plugin deinitialization failed
  virtual Core::hresult Deinitialize(PluginHost::IShell* service) = 0;

  /** Connects a client to a pub/sub Linchpin service */
  // @text connect
  // @brief Connects a client to a pub/sub Linchpin service
  // @param stringEndpoint: A fully qualified domain name (FQDN) of a Linchpin server
  // @param stringClientName: A Linchpin server client name
  // @param numberClientType: The Linchpin server client payload type
  // @param stringToken: A secure access token (SAT) for Linchpin client authorization
  // @param result: The result of the operation
  // @retval Core::ERROR_NONE: Client connected to the Linchpin service successfully
  // @retval Core::ERROR_GENERAL: Failed to connect the client to the Linchpin service
  virtual Core::hresult Connect(const string& stringEndpoint, const string& stringClientName, const uint32_t numberClientType, const string& stringToken, Success& result /* @out */) = 0;

  /** Creates and joins a room */
  // @text setRoom
  // @brief Creates and joins a room that provides participants a synchronization session
  // @param stringRoomCode: A room code that identifies the room
  // @param result: The result of the operation
  // @retval Core::ERROR_NONE: Room created/joined successfully
  // @retval Core::ERROR_GENERAL: Failed to create or join the specified room
  virtual Core::hresult SetRoom(const string& stringRoomCode, Success& result /* @out */) = 0;

  /** Retrieves the current room code */
  // @text getRoom
  // @brief Retrieves the current room code
  // @param stringRoomCode: Returns the room code that identifies the room
  // @param success: Indicates whether the operation succeeded
  // @retval Core::ERROR_NONE: Room code retrieved successfully
  virtual Core::hresult GetRoom(string& stringRoomCode /* @out */, bool& success /* @out */) const = 0;

  /** Sets device-related information */
  // @text setDevice
  // @brief Sets device-related information for sharing with session participants
  // @param jsonDeviceDetails: A valid JSON object string with application defined device detail(s)
  // @param result: The result of the operation
  // @retval Core::ERROR_NONE: Device details set successfully
  // @retval Core::ERROR_GENERAL: Failed to set device details
  virtual Core::hresult SetDevice(const string& jsonDeviceDetails /* @opaque */, Success& result /* @out */) = 0;

  /** Retrieves device related information */
  // @text getDevice
  // @brief Retrieves device related information
  // @param jsonDeviceDetails: Returns the device details as a JSON object string
  // @param success: Indicates whether the operation succeeded
  // @retval Core::ERROR_NONE: Device details retrieved successfully
  virtual Core::hresult GetDevice(string& jsonDeviceDetails /* @out @opaque */, bool& success /* @out */) const = 0;

  /** Negotiates room leadership status */
  // @text requestLeadership
  // @brief Negotiates room leadership status
  // @param booleanRoomLeader: Room leadership status to be solicited
  // @param result: The result of the operation
  // @retval Core::ERROR_NONE: Leadership request published successfully
  // @retval Core::ERROR_GENERAL: Failed to publish leadership request
  virtual Core::hresult RequestLeadership(const bool booleanRoomLeader, Success& result /* @out */) = 0;

  /** Sets the playback content URL */
  // @text setPlaybackURL
  // @brief Sets the playback content URL for room participants
  // @param stringURL: The URL of the shared playback content
  // @param result: The result of the operation
  // @retval Core::ERROR_NONE: Playback URL set successfully
  // @retval Core::ERROR_GENERAL: Failed to set playback URL
  virtual Core::hresult SetPlaybackURL(const string& stringURL, Success& result /* @out */) = 0;

  /** Retrieves the currently shared content's URL */
  // @text getPlaybackURL
  // @brief Retrieves the currently shared content's URL
  // @param stringURL: Returns the URL of the shared playback content
  // @param success: Indicates whether the operation succeeded
  // @retval Core::ERROR_NONE: Playback URL retrieved successfully
  virtual Core::hresult GetPlaybackURL(string& stringURL /* @out */, bool& success /* @out */) const = 0;

  /** Sets and shares the playback content's service key */
  // @text setPlaybackServiceKey
  // @brief Sets and shares the playback content's service key
  // @param stringServiceKey: The service key of the shared playback content
  // @param result: The result of the operation
  // @retval Core::ERROR_NONE: Playback service key set successfully
  // @retval Core::ERROR_GENERAL: Failed to set playback service key
  virtual Core::hresult SetPlaybackServiceKey(const string& stringServiceKey, Success& result /* @out */) = 0;

  /** Retrieves the currently shared content's service key */
  // @text getPlaybackServiceKey
  // @brief Retrieves the currently shared content's service key
  // @param stringServiceKey: Returns the service key of the shared playback content
  // @param success: Indicates whether the operation succeeded
  // @retval Core::ERROR_NONE: Playback service key retrieved successfully
  virtual Core::hresult GetPlaybackServiceKey(string& stringServiceKey /* @out */, bool& success /* @out */) const = 0;

  /** Publishes chat/text message to room participants */
  // @text publishMessage
  // @brief Publishes chat/text message to room participants
  // @param stringMessage: The chat message string
  // @param numberTimestamp: Reference timestamp of the request
  // @param result: The result of the operation
  // @retval Core::ERROR_NONE: Message published successfully
  // @retval Core::ERROR_GENERAL: Failed to publish message
  virtual Core::hresult PublishMessage(const string& stringMessage, const uint64_t numberTimestamp, Success& result /* @out */) = 0;

  /** Publishes content's playback pause action */
  // @text publishPause
  // @brief Publishes content's playback pause action with the room participants
  // @param numberPosition: Playback position of the content to be shared with room participants
  // @param numberTimestamp: Reference timestamp of the request
  // @param result: The result of the operation
  // @retval Core::ERROR_NONE: Pause action published successfully
  // @retval Core::ERROR_GENERAL: Failed to publish pause action
  virtual Core::hresult PublishPause(const uint64_t numberPosition, const uint64_t numberTimestamp, Success& result /* @out */) = 0;

  /** Publishes the content's playback speed action */
  // @text publishSpeed
  // @brief Publishes the content's playback speed action with the room participants
  // @param numberSpeed: Content playback speed (positive for forward, negative for rewind)
  // @param numberTimestamp: Reference timestamp of the request
  // @param result: The result of the operation
  // @retval Core::ERROR_NONE: Speed action published successfully
  // @retval Core::ERROR_GENERAL: Failed to publish speed action
  virtual Core::hresult PublishSpeed(const int32_t numberSpeed, const uint64_t numberTimestamp, Success& result /* @out */) = 0;

  /** Publishes the content's playback stop action */
  // @text publishStop
  // @brief Publishes the content's playback stop action with the room participants
  // @param numberTimestamp: Reference timestamp of the request
  // @param result: The result of the operation
  // @retval Core::ERROR_NONE: Stop action published successfully
  // @retval Core::ERROR_GENERAL: Failed to publish stop action
  virtual Core::hresult PublishStop(const uint64_t numberTimestamp, Success& result /* @out */) = 0;

  /** Publishes the content's playback position */
  // @text publishPlaybackPosition
  // @brief Publishes the content's playback position with the room participants
  // @param numberPosition: Playback position of the content to be shared with room participants
  // @param numberTimestamp: Reference timestamp of the request
  // @param result: The result of the operation
  // @retval Core::ERROR_NONE: Playback position published successfully
  // @retval Core::ERROR_GENERAL: Failed to publish playback position
  virtual Core::hresult PublishPlaybackPosition(const uint64_t numberPosition, const uint64_t numberTimestamp, Success& result /* @out */) = 0;

  /** Publishes the content's playback action */
  // @text publishPlaybackStarted
  // @brief Publishes the content's playback action with the room participants
  // @param numberPosition: Playback position of the content to be shared with room participants
  // @param numberTimestamp: Reference timestamp of the request
  // @param numberSetupOverhead: The total amount of time in milliseconds from receiving position to starting play
  // @param result: The result of the operation
  // @retval Core::ERROR_NONE: Playback started action published successfully
  // @retval Core::ERROR_GENERAL: Failed to publish playback started action
  virtual Core::hresult PublishPlaybackStarted(const uint64_t numberPosition, const uint64_t numberTimestamp, const uint64_t numberSetupOverhead, Success& result /* @out */) = 0;

  /** Publishes any session errors with room participants */
  // @text publishPlaybackError
  // @brief Publishes any session errors with room participants
  // @param numberErrorCode: An application defined error number
  // @param numberTimestamp: Reference timestamp of the request
  // @param result: The result of the operation
  // @retval Core::ERROR_NONE: Playback error published successfully
  // @retval Core::ERROR_GENERAL: Failed to publish playback error
  virtual Core::hresult PublishPlaybackError(const uint32_t numberErrorCode, const uint64_t numberTimestamp, Success& result /* @out */) = 0;
};
} // namespace Exchange
} // namespace WPEFramework
