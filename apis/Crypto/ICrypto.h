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

#include <vector>

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

struct EXTERNAL ICrypto : virtual public Core::IUnknown {
    enum { ID = ID_CRYPTO };

    ~ICrypto() override = default;

    enum GenerateKeyAlgorithm : uint8_t {
        GENERATE_KEY_ALGORITHM_UNSPECIFIED = 0,
        GENERATE_KEY_ALGORITHM_AES128 = 1,
        GENERATE_KEY_ALGORITHM_AES256 = 2,
        GENERATE_KEY_ALGORITHM_HMAC128 = 3,
        GENERATE_KEY_ALGORITHM_HMAC160 = 4,
        GENERATE_KEY_ALGORITHM_HMAC256 = 5
    };

    enum KeyUsage : uint8_t {
        KEY_USAGE_UNSPECIFIED = 0,
        KEY_USAGE_ENCRYPT = 1,
        KEY_USAGE_DECRYPT = 2,
        KEY_USAGE_SIGN = 3,
        KEY_USAGE_VERIFY = 4,
        KEY_USAGE_DERIVE = 5,
        KEY_USAGE_WRAP = 6,
        KEY_USAGE_UNWRAP = 7
    };

    enum KeyPairAlgorithm : uint8_t {
        KEY_PAIR_ALGORITHM_UNSPECIFIED = 0,
        KEY_PAIR_ALGORITHM_AUTH_DH = 1
    };

    enum ProvisionType : uint8_t {
        PROVISION_TYPE_UNSPECIFIED = 0,
        PROVISION_TYPE_PRE_PROVISIONED_GLOBAL = 1
    };

    enum KeyType : uint8_t {
        KEY_TYPE_UNSPECIFIED = 0,
        KEY_TYPE_PUBLIC = 1,
        KEY_TYPE_PRIVATE = 2,
        KEY_TYPE_SYMMETRIC = 3
    };

    enum KeyAlgorithm : uint8_t {
        KEY_ALGORITHM_UNSPECIFIED = 0,
        KEY_ALGORITHM_AES_CBC = 1,
        KEY_ALGORITHM_AES_CTR = 2,
        KEY_ALGORITHM_SHA256 = 3,
        KEY_ALGORITHM_SHA384 = 4,
        KEY_ALGORITHM_SHA512 = 5,
        KEY_ALGORITHM_NFLXDH = 6,
        KEY_ALGORITHM_DH = 7
    };

    enum ImportExportType : uint8_t {
        IMPORT_EXPORT_TYPE_UNSPECIFIED = 0,
        IMPORT_EXPORT_TYPE_PROTECTED = 1,
        IMPORT_EXPORT_TYPE_CLEAR = 2
    };

    enum SignatureAlgorithm : uint8_t {
        SIGN_ALGORITHM_UNSPECIFIED = 0,
        SIGN_ALGORITHM_HMAC = 1
    };

    enum DigestAlgorithm : uint8_t {
        DIGEST_ALGORITHM_UNSPECIFIED = 0,
        DIGEST_ALGORITHM_SHA256 = 1
    };

    enum CipherAlgorithm : uint8_t {
        CIPHER_ALGORITHM_UNSPECIFIED = 0,
        CIPHER_ALGORITHM_AES_CBC = 1
    };

    enum AppConnectionState : uint8_t {
        APP_CONNECTION_STATE_UNSPECIFIED = 0,
        APP_CONNECTION_STATE_CONNECTED = 1,
        APP_CONNECTION_STATE_DISCONNECTED = 2
    };

    enum CryptoError : uint8_t {
        CRYPTO_ERROR_NONE = 0,
        CRYPTO_ERROR_AUTHENTICATION_FAILED = 1,
        CRYPTO_ERROR_INVALID_PARAMETERS = 2,
        CRYPTO_ERROR_OPERATION_FAILED = 3,
        CRYPTO_ERROR_LOCATOR_NOT_AVAILABLE = 4,
        CRYPTO_ERROR_INVALID_KEY_NAME = 5,
        CRYPTO_ERROR_INVALID_KEY_TYPE = 6,
        CRYPTO_ERROR_INVALID_KEY_ID = 7,
        CRYPTO_ERROR_INVALID_SESSION_STATE = 8,
        CRYPTO_ERROR_INVALID_INIT_DATA = 9,
        CRYPTO_ERROR_OVERSIZED_INPUT_DATA = 10,
        CRYPTO_ERROR_BUFFER_OVERFLOW = 11,
        CRYPTO_ERROR_KEY_PROVISION_ERROR = 12,
        CRYPTO_ERROR_SEALED_KEY_EXPORT_ERROR = 13
    };

    struct ApplicationContext {
        // @brief Authenticated application identifier.
        string appId;
        // @brief Caller-assigned session identifier for the application.
        string sessionId;
    };

    struct SharedBuffer {
        // @brief Host path of the shared-memory object owned by caller.
        // Implementation shall safely open the object, determine its actual
        // size, validate all buffer regions against that size, and map it only
        // for the duration of the synchronous operation. All acquired resources
        // shall be released before returning, and no buffer state shall be
        // retained.
        string name;
    };

    struct BufferRegion {
        // @brief Byte offset in the shared buffer from which the data starts.
        uint32_t offset;
        // @brief Number of valid bytes in the region.
        uint32_t length;
    };

    struct AuthDhKeyPairParameters {
        // @brief Prime modulus P encoded as an unsigned big-endian byte sequence.
        std::vector<uint8_t> primeP;
        // @brief Generator G used for the Diffie-Hellman key pair.
        uint32_t generatorG;
    };

    struct KeyPairParameters {
        /*
         * Currently, only DH is supported.
         * In the future, additional algorithms (e.g., RSA) may be added.
         * When new algorithms are introduced, this field may become optional,
         * and additional optional parameters may be added as required.
         */
        AuthDhKeyPairParameters authDh;
    };

    // @brief Generates a key with the requested algorithm and usages.
    // @param context: Application and session identifiers.
    // @param algorithm: Algorithm used to generate the key.
    // @param usage: Operations for which the generated key may be used.
    // @param keyId: Generated transient key identifier.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult GenerateKey(const ApplicationContext& context,
        const GenerateKeyAlgorithm algorithm, const std::vector<KeyUsage>& usage,
        uint32_t& keyId /* @out */, CryptoError& error /* @out */) = 0;

    // @brief Generates a key pair using the specified algorithm and parameters.
    // @param context: Application and session identifiers.
    // @param algorithm: Algorithm used to generate the key pair.
    // @param parameters: Algorithm-specific key-pair parameters.
    // @param privateKeyId: Generated transient private-key identifier.
    // @param publicKeyId: Generated transient public-key identifier.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult GenerateKeyPair(const ApplicationContext& context,
        const KeyPairAlgorithm algorithm, const KeyPairParameters& parameters,
        uint32_t& privateKeyId /* @out */, uint32_t& publicKeyId /* @out */,
        CryptoError& error /* @out */) = 0;

    // @brief Loads a pre-provisioned key and returns its transient identifier.
    // @param context: Application and session identifiers.
    // @param locator: Locator of the pre-provisioned key.
    // @param provisionType: Provisioning source of the key.
    // @param keyId: Transient identifier of the loaded key.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult LoadKey(const ApplicationContext& context,
        const string& locator, const ProvisionType provisionType, uint32_t& keyId /* @out */,
        CryptoError& error /* @out */) = 0;

    // @brief Releases a transient key owned by the application session.
    // @param context: Application and session identifiers.
    // @param keyId: Identifier of the transient key to release.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult UnloadKey(const ApplicationContext& context, const uint32_t keyId,
        CryptoError& error /* @out */) = 0;

    // @brief Checks whether a named key is available.
    // @param context: Application and session identifiers.
    // @param locator: Locator of the key.
    // @param exists: Indicates whether the key is available.
    // @param keyId: Transient key identifier when the key is available.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult KeyExists(const ApplicationContext& context,
        const string& locator, bool& exists /* @out */, uint32_t& keyId /* @out */,
        CryptoError& error /* @out */) const = 0;

    // @brief Returns metadata for a transient key.
    // @param context: Application and session identifiers.
    // @param keyId: Identifier of the transient key.
    // @param keyType: Type of the key.
    // @param keyUsage: Operations for which the key may be used.
    // @param keyAlgorithm: Algorithm associated with the key.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult GetKeyInfo(const ApplicationContext& context,
        const uint32_t keyId, KeyType& keyType /* @out */,
        std::vector<KeyUsage>& keyUsage /* @out */,
        KeyAlgorithm& keyAlgorithm /* @out */, CryptoError& error /* @out */) const = 0;

    // @brief Releases all transient keys owned by the application session.
    // @param context: Application and session identifiers.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult FlushKeys(const ApplicationContext& context,
        CryptoError& error /* @out */) = 0;

    // @brief Imports a key blob and returns its transient identifier.
    // @param context: Application and session identifiers.
    // @param keyType: Type of the key being imported.
    // @param importExportType: Optional protection format of the key blob.
    // @param keyBlob: Key data to import.
    // @param keyId: Transient identifier of the imported key.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult ImportKey(const ApplicationContext& context, const KeyType keyType,
        const Core::OptionalType<ImportExportType>& importExportType,
        const std::vector<uint8_t>& keyBlob,
        uint32_t& keyId /* @out */, CryptoError& error /* @out */) = 0;

    // @brief Exports a transient key as a key blob.
    // @param context: Application and session identifiers.
    // @param keyId: Identifier of the transient key to export.
    // @param importExportType: Optional protection format of the exported key blob.
    // @param keyBlob: Exported key data.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult ExportKey(const ApplicationContext& context, const uint32_t keyId,
        const Core::OptionalType<ImportExportType>& importExportType,
        std::vector<uint8_t>& keyBlob /* @out */,
        CryptoError& error /* @out */) const = 0;

    // @brief Signs input held in shared memory and returns the signature location.
    // @param context: Application and session identifiers.
    // @param buffer: Shared-memory object containing the input and output.
    // @param algorithm: Signature algorithm.
    // @param keyId: Identifier of the signing key.
    // @param digestAlgorithm: Digest algorithm applied to the input.
    // @param inputData: Region containing the input data.
    // @param signature: Plugin-selected region containing the generated signature.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult Sign(const ApplicationContext& context,
        const SharedBuffer& buffer, const SignatureAlgorithm algorithm,
        const uint32_t keyId, const DigestAlgorithm digestAlgorithm,
        const BufferRegion& inputData, BufferRegion& signature /* @out */,
        CryptoError& error /* @out */) = 0;

    // @brief Verifies input against an expected signature held in shared memory.
    // @param context: Application and session identifiers.
    // @param buffer: Shared-memory object containing the input and signature.
    // @param algorithm: Signature algorithm.
    // @param keyId: Identifier of the verification key.
    // @param digestAlgorithm: Digest algorithm applied to the input.
    // @param inputData: Region containing the input data.
    // @param expectedSignature: Region containing the expected signature.
    // @param verificationStatus: Indicates whether the signature is valid.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult Verify(const ApplicationContext& context,
        const SharedBuffer& buffer, const SignatureAlgorithm algorithm,
        const uint32_t keyId, const DigestAlgorithm digestAlgorithm,
        const BufferRegion& inputData, const BufferRegion& expectedSignature,
        bool& verificationStatus /* @out */,
        CryptoError& error /* @out */) = 0;

    // @brief Encrypts input held in shared memory and returns the ciphertext location.
    // @param context: Application and session identifiers.
    // @param buffer: Shared-memory object containing the input and output.
    // @param algorithm: Cipher algorithm.
    // @param keyId: Identifier of the encryption key.
    // @param initData: Region containing the initialization data.
    // @param inputData: Region containing the plaintext.
    // @param encryptedData: Plugin-selected region containing the generated ciphertext.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult Encrypt(const ApplicationContext& context,
        const SharedBuffer& buffer, const CipherAlgorithm algorithm,
        const uint32_t keyId, const BufferRegion& initData,
        const BufferRegion& inputData, BufferRegion& encryptedData /* @out */,
        CryptoError& error /* @out */) = 0;

    // @brief Decrypts ciphertext held in shared memory and returns the plaintext location.
    // @param context: Application and session identifiers.
    // @param buffer: Shared-memory object containing the input and output.
    // @param algorithm: Cipher algorithm.
    // @param keyId: Identifier of the decryption key.
    // @param initData: Region containing the initialization data.
    // @param encryptedData: Region containing the ciphertext.
    // @param outputData: Plugin-selected region containing the generated plaintext.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult Decrypt(const ApplicationContext& context,
        const SharedBuffer& buffer, const CipherAlgorithm algorithm,
        const uint32_t keyId, const BufferRegion& initData,
        const BufferRegion& encryptedData, BufferRegion& outputData /* @out */,
        CryptoError& error /* @out */) = 0;
    
    // @brief Derives encryption, HMAC, and wrapping keys from an existing key pair.
    // @param context: Application and session identifiers.
    // @param algorithm: Key-pair algorithm used for derivation.
    // @param privateKeyId: Identifier of the local private key.
    // @param publicKeyId: Identifier of the peer public key.
    // @param derivationKeyId: Identifier of the key used for derivation.
    // @param encryptionKeyId: Identifier of the derived encryption key.
    // @param hmacKeyId: Identifier of the derived HMAC key.
    // @param wrappingKeyId: Identifier of the derived wrapping key.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult DeriveSessionKeys(const ApplicationContext& context,
        const KeyPairAlgorithm algorithm, const uint32_t privateKeyId,
        const uint32_t publicKeyId,
        const uint32_t derivationKeyId, uint32_t& encryptionKeyId /* @out */,
        uint32_t& hmacKeyId /* @out */, uint32_t& wrappingKeyId /* @out */,
        CryptoError& error /* @out */) = 0;

    // @brief Generates cryptographically secure random data.
    // @param context: Application and session identifiers.
    // @param numberOfBytes: Number of random bytes to generate.
    // @param randomValue: Generated random data.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult GenerateRandom(const ApplicationContext& context,
        const uint32_t numberOfBytes,
        std::vector<uint8_t>& randomValue /* @out */,
        CryptoError& error /* @out */) = 0;

    // @brief Updates the lower-level crypto session lifecycle for an application session.
    // @param context: Application and session identifiers.
    // @param state: Current connection state of the application session.
    // @param error: Crypto operation result.
    // @retval Core::ERROR_NONE: Indicates successful invocation of the method;
    // the result of the requested functionality is returned in error output param.
    // @retval Core::ERROR_*: Standard Core error indicating that invocation failed.
    virtual Core::hresult NotifyAppState(const ApplicationContext& context,
        const AppConnectionState state, CryptoError& error /* @out */) = 0;
};

} // namespace Exchange
} // namespace WPEFramework
