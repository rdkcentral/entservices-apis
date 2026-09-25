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

    // This interface gives direct access to a Browser to change
    // Browser specific properties like displayed URL.
    struct EXTERNAL IDictionary : virtual public Core::IUnknown {
        enum { ID = ID_DICTIONARY };

        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_DICTIONARY_NOTIFICATION };

            ~INotification() override = default;

            // Signal changes on the subscribed namespace..
            // @brief Notifies that a value in the specified namespace has been modified.
            // @details This method is called whenever a value in the specified namespace has been modified.
            // @param nameSpace: string Namespace where the modification occurred.
            // @example nameSpace: "com.example.myapp"
            // @param key: string Key that was modified.
            // @example key: "exampleKey"
            // @param value: string New value associated with the key.
            // @example value: "exampleValue"
            virtual void Modified(const string& nameSpace, const string& key, const string& value) = 0;
        };

        struct EXTERNAL IIterator : virtual public Core::IUnknown {
            enum { ID = ID_DICTIONARY_ITERATOR };

            ~IIterator() override = default;
            // @brief Resets the iterator to the first entry.
            // @details Positions the iterator at the beginning of the collection.
            virtual void Reset() = 0;
            
            // @brief Checks if the iterator is currently pointing to a valid entry.
            // @details Returns true if the iterator is positioned at a valid entry, false otherwise.
            virtual bool IsValid() const = 0;
            
            // @brief Advances the iterator to the next entry.
            // @details Moves the iterator forward and reports whether the new position is valid.

            // Signal changes on the subscribed namespace..
            // @brief Retrieves the key of the current entry.
            // @details Returns the key at the iterator's current position.
            virtual const string Key() const = 0;
            
            // @brief Retrieves the value of the current entry.
            // @details Returns the value at the iterator's current position.
            virtual const string Value() const = 0;
        };

        ~IDictionary() override = default;

        // Allow to observe values in the dictionary. If they are changed, the sink gets notified.
        virtual void Register(const string& nameSpace, struct IDictionary::INotification* sink) = 0;
        virtual void Unregister(const string& nameSpace, struct IDictionary::INotification* sink) = 0;

        // Getters and Setters for the dictionary.
        // @brief Retrieves a value from the dictionary.
        // @details Looks up a key within the specified namespace.
        // @param nameSpace: Namespace containing the key.
        // @example nameSpace: "com.example.myapp"
        // @param key: Key whose value is requested.
        // @example key: "exampleKey"
        // @param value: Output parameter receiving the associated value.
        // @example value: "exampleValue"
        // @retval core::ERROR_NONE if the operation was successful
        virtual bool Get(const string& nameSpace, const string& key, string& value /* @out */) const = 0;
       
        // @brief Stores a key-value pair in the dictionary.
        // @details Creates a new entry or updates an existing one within the namespace.
        // @param nameSpace: Namespace where the key belongs.
        // @example nameSpace: "com.example.myapp"
        // @param key: Key to create or update.
        // @example key: "exampleKey"
        // @param value: Value associated with the key.
        // @example value: "exampleValue"
        // @retval core::ERROR_NONE if the operation was successful
        virtual bool Set(const string& nameSpace, const string& key, const string& value) = 0;
       
        // @brief Retrieves an iterator for a namespace.
        // @details Returns an iterator that can be used to enumerate all key-value pairs within the namespace.
        // @param nameSpace: Namespace to enumerate.
        // @example nameSpace: "com.example.myapp"  
        // @retval core::ERROR_NONE if the operation was successful
        virtual IIterator* Get(const string& nameSpace) const = 0;
    };
}
}

