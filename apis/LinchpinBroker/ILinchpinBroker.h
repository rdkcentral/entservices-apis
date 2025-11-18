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

/* @json @text:keep */
struct EXTERNAL ILinchpinBroker : virtual public Core::IUnknown {
    enum { ID = ID_LINCHPIN_BROKER };

    enum EXTERNAL SubscriptionStatus {
        SUBSCRIBED,
        PENDING
    };

    struct EXTERNAL TopicInfo {
        uint32_t topicId;
        SubscriptionStatus status;
    };

    using ITopicInfoIterator  = RPC::IIteratorType<TopicInfo, ID_LINCHPIN_BROKER_TOPIC_INFO_ITERATOR>;

    // @event
    struct EXTERNAL INotification : virtual public Core::IUnknown {
        enum { ID = ID_LINCHPIN_BROKER_NOTIFICATION };

        // @text onSubscriptionStatusChanged
        // @brief The subscription status of one or more topics previously registered by a particular client is now changed.
        // @param clientId Id of the client whose "subscription status" is changed.
        // @param topicList List of topics and their corresponding subscription status.
        virtual void OnSubscriptionStatusChanged(const string& clientId /* @index */, const ITopicInfoIterator*& topicList){};

        // @text onTopicMessageReceived
        // @brief The specified topic has changed.
        // @param topicId Topic id of the topic associated with the notification
        // @param payloadType The type of the payload
        // @param payload Updated topic data
        // @param headers Headers associated with the topic
        virtual void OnTopicMessageReceived(const uint32_t topicId /* @index */, const string& payloadType, const string& payload /* @opaque */, const string& headers /* @opaque */){};    
    };

    virtual uint32_t Register(const string& clientId, const uint32_t topicId, ILinchpinBroker::INotification* notification) = 0;
    virtual uint32_t Unregister(const string& clientId, const uint32_t topicId, ILinchpinBroker::INotification* notification) = 0;

    // @text getTopicId
    // @brief Generates a topicId for the given unique topic name. If a topicId already generated for a given topic name, returns it.
    // @param topicName Name of the topic
    // @param topicId The associated (generated) topic Id.
    virtual uint32_t GetTopicId(const string& topicName, uint32_t &topicId /* @out */) = 0;

    // @text publish
    // @brief Publishes the specified data to the given topic.
    // @param topicId Topic Id of the topic to publish to
    // @param payloadType The type of the payload
    // @param payload The payload data
    virtual uint32_t Publish(const uint32_t topicId, const string& payloadType, const string& payload) = 0;

    // @text getTopicsSubscriptionStatus
    // @brief Retrieves the list of topics subscribed to by the client.
    // @param clientId Id of the client for which topic info is sought.
    // @param topicList List of topics and their corresponding subscription status.
    virtual uint32_t GetTopicsSubscriptionStatus(const string& clientId, ITopicInfoIterator*& topicList /* @out */) = 0;
};

} // namespace Exchange
} // namespace WPEFramework
