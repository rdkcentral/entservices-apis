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
struct EXTERNAL ILinchpinClientProxy : virtual public Core::IUnknown {
    enum { ID = ID_LINCHPIN_CLIENT_PROXY };

    enum EXTERNAL SubscriptionStatus : uint8_t {
        SUBSCRIBED,
        PENDING
    };

    struct EXTERNAL TopicInfo {
        string topic;
        SubscriptionStatus status;
    };

    using ITopicInfoIterator = RPC::IIteratorType<TopicInfo, WPEFramework::Exchange::ID_LINCHPIN_CLIENT_PROXY_TOPIC_INFO_ITERATOR>;

    // @event
    struct EXTERNAL INotification : virtual public Core::IUnknown {
        enum { ID = ID_LINCHPIN_CLIENT_PROXY_NOTIFICATION };

        // @text onSubscriptionStatusChanged
        // @brief The subscription status of one or more topics previously registered by a particular client is now changed.
        // @param clientId Id of the client whose "subscription status" is changed.
        // @param topicList: List of topics and their corresponding subscription status./opt/ha
        virtual void OnSubscriptionStatusChanged(const string& clientId, const string &topicList){}; // TODO: Add index tag to clientId, change topicList to ITopicInfoIterator* const topicList

        // @text onMessageReceived
        // @brief The subscribed topic has changed
        // @param topic: Topic associated with the notification
        // @param payloadType: The type of the payload
        // @param payload: The payload data
        // @param headers: Headers associated with the topic
        virtual void OnMessageReceived(const string& topic, const string& payloadType, const string& payload /* @opaque */, const string& headers /* @opaque */) {}; // TODO: Add index tag to topicName
    };

    // @json:omit
    virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

    virtual Core::hresult Register(ILinchpinClientProxy::INotification* notification) = 0;
    virtual Core::hresult Unregister(ILinchpinClientProxy::INotification* notification) = 0;

    // @json:omit
    virtual Core::hresult RegistrationCallbackOnSubscriptionStatusChanged(const string& clientId) = 0;

    // @json:omit
    virtual Core::hresult RegistrationCallbackOnMessageReceived(const string& clientId) = 0;

    // @text publish
    // @brief Publishes the specified data to the given topic
    // @param topic: Topic to publish to
    // @param payloadType: The type of the payload
    // @param payload: The payload data
    virtual Core::hresult Publish(const string& topic, const string& payloadType, const string& payload) = 0;

    // @text getSubscriptionStatus
    // @brief Retrieves the list of topics subscribed to by the client
    // @param clientId: Id of the client for which topic info is sought
    // @param topicList: List of topics and their corresponding subscription status
    virtual Core::hresult GetSubscriptionStatus(const string& clientId, ITopicInfoIterator*& topicList /* @out */) = 0;

    // @text subscribe
    // @brief Subscribes the client to the specified topic.
    // @param clientId: Id of the client
    // @param topic: name of topic
    virtual Core::hresult Subscribe(const string& clientId, const string& topic) = 0;

    // @text unsubscribe
    // @brief Unsubscribes the client from the specified topic.
    // @param clientId: Id of the client
    // @param topic: name of topic
    virtual Core::hresult Unsubscribe(const string& clientId, const string& topic) = 0;
};

} // namespace Exchange
} // namespace WPEFramework

/* Mermaid Sequence Diagram - Starts in the next line

sequenceDiagram
    participant C1 as CLIENT 1
    participant C2 as CLIENT 2
    participant LB as LINCHPIN CLIENT PROXY

    rect rgb(200, 220, 240)
        Note over C1,LB: CLIENT 1 REGISTERS
        C1->>+LB: Register("CLIENT 1", "Topic 1")
        LB-->>-C1: returns()
        LB->>+C1: OnSubscriptionStatusChanged("CLIENT 1", [{"Topic 1", SUBSCRIBED}])
        C1-->>-LB: returns()
        
        opt Optional Step
            C1->>+LB: getSubscriptionStatus("CLIENT 1")
            LB-->>-C1: returns([{"Topic 1", SUBSCRIBED}])
        end
    end

    rect rgb(200, 240, 220)
        Note over C2,LB: CLIENT 2 REGISTERS
        C2->>+LB: Register("CLIENT 2", "Topic 1")
        LB-->>-C2: returns()
        LB->>+C2: OnSubscriptionStatusChanged("CLIENT 2", [{"Topic 1", SUBSCRIBED}])
        C2-->>-LB: returns()
        
        opt Optional Step
            C2->>+LB: getSubscriptionStatus("CLIENT 2")
            LB-->>-C2: returns([{"Topic 1", SUBSCRIBED}])
        end

        C2->>+LB: Register("CLIENT 2", "Topic 2")
        LB-->>-C2: returns()
        LB->>+C2: OnSubscriptionStatusChanged("CLIENT 2", [{"Topic 2", SUBSCRIBED}])
        C2-->>-LB: returns()
        
        opt Optional Step
            C2->>+LB: getSubscriptionStatus("CLIENT 2")
            LB-->>-C2: returns([{"Topic 1", SUBSCRIBED}, {"Topic 2", SUBSCRIBED}])
        end
    end

    rect rgb(240, 220, 200)
        Note over C1,LB: Topic 1 Value Changed
        LB->>+C1: onTopicUpdated("Topic 1", "payload type", ...)
        C1-->>-LB: returns()
        LB->>+C2: onTopicUpdated("Topic 1", "payload type", ...)
        C2-->>-LB: returns()
    end

    rect rgb(240, 220, 200)
        Note over C2,LB: Topic 2 Value Changed
        LB->>+C2: onTopicUpdated("Topic 2", "payload type", ...)
        C2-->>-LB: returns()
    end

    rect rgb(255, 200, 200)
        Note over C1,LB: CONNECTION LOST
        Note right of LB: Flip all subscription status to PENDING<br/>Send one notification per client
        LB->>+C1: OnSubscriptionStatusChanged("CLIENT 1", [{"Topic 1", PENDING}])
        C1-->>-LB: returns()
        
        opt Optional Step
            C1->>+LB: getSubscriptionStatus("CLIENT 1")
            LB-->>-C1: returns([{"Topic 1", PENDING}])
        end

        LB->>+C2: OnSubscriptionStatusChanged("CLIENT 2", [{"Topic 1", PENDING}, {"Topic 2", PENDING}])
        C2-->>-LB: returns()
        
        opt Optional Step
            C2->>+LB: getSubscriptionStatus("CLIENT 2")
            LB-->>-C2: returns([{"Topic 1", PENDING}, {"Topic 2", PENDING}])
        end
    end

    rect rgb(200, 255, 200)
        Note over C1,LB: CONNECTION RESTORED
        Note right of LB: Re-establish connection with server<br/>Attempt (re)subscription for each topic<br/>Topic 2 resubscription fails for illustration
        
        LB->>+C1: OnSubscriptionStatusChanged("CLIENT 1", [{"Topic 1", SUBSCRIBED}])
        C1-->>-LB: returns()
        
        opt Optional Step
            C1->>+LB: getSubscriptionStatus("CLIENT 1")
            LB-->>-C1: returns([{"Topic 1", SUBSCRIBED}])
        end

        LB->>+C2: OnSubscriptionStatusChanged("CLIENT 2", [{"Topic 1", SUBSCRIBED}, {"Topic 2", PENDING}])
        C2-->>-LB: returns()
        
        opt Optional Step
            C2->>+LB: getSubscriptionStatus("CLIENT 2")
            LB-->>-C2: returns([{"Topic 1", SUBSCRIBED}, {"Topic 2", PENDING}])
        end
    end

Mermaid Sequence Diagram - Ends in the previous line */
