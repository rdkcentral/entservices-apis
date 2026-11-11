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

struct EXTERNAL INetflixSecurity : public Core::IUnknown
{
    enum { ID = 0x00001200 };

    virtual ~INetflixSecurity() { }

    // @brief Retrieve the ESN
    // @details This API retrieves the ESN of the device.
    // @param esn: Output ESN value
    // @example esn: "1234567890"
    // @retval Core::ERROR_NONE: ESN retrieved successfully
    // @retval Core::ERROR_UNAVAILABLE: ESN is unavailable
    virtual Core::hresult GetESN(std::string& esn /* @out */) const = 0;

    // @brief Retrieve the pre-shared encryption key
    // @details This API retrieves the pre-shared encryption key of the device.
    // @param encryptionKeyId: Output encryption key handle
    // @example encryptionKeyId: 1
    // @retval Core::ERROR_NONE: Encryption key retrieved successfully
    // @retval Core::ERROR_UNAVAILABLE: Encryption key is unavailable
    virtual Core::hresult GetEncryptionKey(uint32_t& encryptionKeyId /* @out */) const = 0;

    // @brief Retrieve the pre-shared HMAC key
    // @details This API retrieves the pre-shared HMAC key of the device.
    // @param hmacKeyId: Output HMAC key handle
    // @example hmacKeyId: 1
    // @retval Core::ERROR_NONE: HMAC key retrieved successfully
    // @retval Core::ERROR_UNAVAILABLE: HMAC key is unavailable
    virtual Core::hresult GetHMACKey(uint32_t& hmacKeyId /* @out */) const = 0;

    // @brief Retrieve the pre-shared wrapping key
    // @details This API retrieves the pre-shared wrapping key of the device.
    // @param wrappingKeyId: Output wrapping key handle
    // @example wrappingKeyId: 1
    // @retval Core::ERROR_NONE: Wrapping key retrieved successfully
    // @retval Core::ERROR_UNAVAILABLE: Wrapping key is unavailable
    virtual Core::hresult GetWrappingKey(uint32_t& wrappingKeyId /* @out */) const = 0;

    // @brief Derive encryption keys based on an authenticated Diffie-Hellman procedure.
    // @details This API derives encryption, HMAC, and wrapping keys using the specified Diffie-Hellman key IDs.
    // @param privateDhKeyId The ID of the private Diffie-Hellman key.
    // @example privateDhKeyId: 1
    // @param peerPublicDhKeyId The ID of the peer's public Diffie-Hellman key.
    // @example peerPublicDhKeyId: 1
    // @param derivationKeyId The ID of the derivation key.
    // @example derivationKeyId: 1
    // @param encryptionKeyId Output encryption key handle.
    // @example encryptionKeyId: 1
    // @param hmacKeyId Output HMAC key handle.
    // @example hmacKeyId: 1
    // @param wrappingKeyId Output wrapping key handle.
    // @example wrappingKeyId: 1
    virtual uint32_t DeriveKeys(const uint32_t privateDhKeyId, const uint32_t peerPublicDhKeyId, const uint32_t derivationKeyId,
                                uint32_t& encryptionKeyId /* @out */, uint32_t& hmacKeyId /* @out */, uint32_t& wrappingKeyId /* @out */) = 0;

    static INetflixSecurity* Instance();
};

}
}
