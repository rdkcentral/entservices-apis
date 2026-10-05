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

    // @brief Retrieve the ESN.
    // @details Returns the device ESN value used by the Netflix security context for identification and entitlement validation.
    // @param esn: Output ESN value.
    // @example esn: "NFANDROID1-1234567890"
    // @retval Core::ERROR_NONE: ESN retrieved successfully.
    virtual Core::hresult GetESN(std::string& esn /* @out */) const = 0;

    // @brief Retrieve the pre-shared encryption key.
    // @details Returns the key handle associated with the encryption key used for protected content operations.
    // @param encryptionKeyId: Output encryption key handle.
    // @example encryptionKeyId: 1
    // @retval Core::ERROR_NONE: Encryption key retrieved successfully.
    virtual Core::hresult GetEncryptionKey(uint32_t& encryptionKeyId /* @out */) const = 0;

    // @brief Retrieve the pre-shared HMAC key.
    // @details Returns the key handle associated with the HMAC validation key used for authentication and integrity checks.
    // @param hmacKeyId: Output HMAC key handle.
    // @example hmacKeyId: 1
    // @retval Core::ERROR_NONE: HMAC key retrieved successfully.
    virtual Core::hresult GetHMACKey(uint32_t& hmacKeyId /* @out */) const = 0;

    // @brief Retrieve the pre-shared wrapping key.
    // @details Returns the key handle associated with the wrapping key used to protect key material during exchange operations.
    // @param wrappingKeyId: Output wrapping key handle.
    // @example wrappingKeyId: 1
    // @retval Core::ERROR_NONE: Wrapping key retrieved successfully.
    virtual Core::hresult GetWrappingKey(uint32_t& wrappingKeyId /* @out */) const = 0;

    // @brief Derive the encryption, HMAC, and wrapping keys using an authenticated Diffie-Hellman exchange.
    // @details This method derives the required key material from the supplied private and peer public key handles and the derivation key identifier, returning the resulting cryptographic key handles.
    // @param privateDhKeyId: Identifier for the local private Diffie-Hellman key.
    // @example privateDhKeyId: 1
    // @param peerPublicDhKeyId: Identifier for the peer public Diffie-Hellman key.
    // @example peerPublicDhKeyId: 1
    // @param derivationKeyId: Identifier for the derivation key used in the key-generation process.
    // @example derivationKeyId: 1
    // @param encryptionKeyId: Output key handle for the derived encryption key.
    // @example encryptionKeyId: 1
    // @param hmacKeyId: Output key handle for the derived HMAC key.
    // @example hmacKeyId: 1
    // @param wrappingKeyId: Output key handle for the derived wrapping key.
    // @example wrappingKeyId: 1
    // @retval Core::ERROR_NONE: Keys were derived successfully.
    virtual uint32_t DeriveKeys(const uint32_t privateDhKeyId, const uint32_t peerPublicDhKeyId, const uint32_t derivationKeyId,
                                uint32_t& encryptionKeyId /* @out */, uint32_t& hmacKeyId /* @out */, uint32_t& wrappingKeyId /* @out */) = 0;

    static INetflixSecurity* Instance();
};

}
}