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
 
    enum CryptographyVault : uint8_t {
        CRYPTOGRAPHY_VAULT_DEFAULT = 0,
        CRYPTOGRAPHY_VAULT_PLATFORM = 1,
        CRYPTOGRAPHY_VAULT_PROVISIONING = 0x10,
        CRYPTOGRAPHY_VAULT_NETFLIX = 0x11
    };

    enum IDs : uint32_t {
        ID_HASH = 0x00001100,
        ID_VAULT,
        ID_CIPHER,
        ID_DIFFIE_HELLMAN,
        ID_CRYPTOGRAPHY,
        ID_PERSISTENT
    };

    enum aesmode : uint8_t {
        ECB,
        CBC,
        OFB,
        CFB1,
        CFB8,
        CFB128,
        CTR
    };

    enum hashtype : uint8_t {
        SHA1 = 20,
        SHA224 = 28,
        SHA256 = 32,
        SHA384 = 48,
        SHA512 = 64
    };

    struct EXTERNAL IHash : virtual public Core::IUnknown {

        enum { ID = ID_HASH };

        ~IHash() override = default;

        // @brief Add data to the hash calculation.
        // @details Data may be ingested over multiple calls before calculating the hash.
        // @param length: Number of bytes in data.
        // @example length: 4
        // @param data: Bytes to add to the hash calculation.
        // @example data: [0x64, 0x61, 0x74, 0x61]
        // @retval bytesIngested: Number of bytes accepted by the hash calculator.
        virtual uint32_t Ingest(const uint32_t length, const uint8_t data[] /* @length:length */) = 0;

        // @brief Calculate the hash of the ingested data.
        // @details Writes the calculated hash into the caller-provided output buffer.
        // @param maxLength: Maximum number of hash bytes that fit in data.
        // @example maxLength: 32
        // @param data: Output buffer receiving the calculated hash.
        // @example data: [output buffer]
        // @retval hashLength: Number of hash bytes written to data.
        virtual uint8_t Calculate(const uint8_t maxLength, uint8_t data[] /* @out @maxlength:maxLength */) = 0;
    };

    struct EXTERNAL ICipher : virtual public Core::IUnknown {

        enum { ID = ID_CIPHER };

        ~ICipher()  override = default;

        // Encryption and decryption, might require more bytes of data to complete succefully (like padding) to indicate the
        // the encryption or decryption failed due to a lack of storage space, a negative length is returned. The abs(length)
        // indicates the number of bytes required in the output buffer to succefully complete.

        // @brief Encrypt input data.
        // @details Encryption may require additional output space for padding. If the output buffer is too small, a negative return value indicates the required buffer size.
        // @param ivLength: Number of bytes in the initialization vector.
        // @example ivLength: 16
        // @param iv: Initialization vector used for encryption.
        // @example iv: [initialization vector]
        // @param inputLength: Number of bytes in input.
        // @example inputLength: 4
        // @param input: Plaintext bytes to encrypt.
        // @example input: [0x64, 0x61, 0x74, 0x61]
        // @param maxOutputLength: Maximum number of encrypted bytes that fit in output.
        // @example maxOutputLength: 32
        // @param output: Output buffer receiving the encrypted data.
        // @example output: [output buffer]
        // @retval outputLength: Positive byte count on success; negative required output-buffer size if the buffer is too small.
        virtual int32_t Encrypt(const uint8_t ivLength, const uint8_t iv[] /* @length:ivLength */,
                                const uint32_t inputLength, const uint8_t input[] /* @length:inputLength */,
                                const uint32_t maxOutputLength, uint8_t output[] /* @out @maxlength:maxOutputLength */) const = 0;

        // @brief Decrypt encrypted data.
        // @details Decryption may require additional output space for padding. If the output buffer is too small, a negative return value indicates the required buffer size.
        // @param ivLength: Number of bytes in the initialization vector.
        // @example ivLength: 16
        // @param iv: Initialization vector used for decryption.
        // @example iv: [initialization vector]
        // @param inputLength: Number of bytes in input.
        // @example inputLength: 4
        // @param input: Encrypted bytes to decrypt.
        // @example input: [0x64, 0x61, 0x74, 0x61]
        // @param maxOutputLength: Maximum number of decrypted bytes that fit in output.
        // @example maxOutputLength: 32
        // @param output: Output buffer receiving the decrypted data.
        // @example output: [output buffer]
        // @retval outputLength: Positive byte count on success; negative required output-buffer size if the buffer is too small.
        virtual int32_t Decrypt(const uint8_t ivLength, const uint8_t iv[] /* @length:ivLength */,
                                const uint32_t inputLength, const uint8_t input[] /* @length:inputLength */,
                                const uint32_t maxOutputLength, uint8_t output[] /* @out @maxlength:maxOutputLength */) const = 0;
    };

    struct EXTERNAL IDiffieHellman : virtual public Core::IUnknown {

        enum { ID = ID_DIFFIE_HELLMAN };

        ~IDiffieHellman() override = default;

        // @brief Generate a Diffie-Hellman key pair.
        // @details Creates private and public keys using the supplied generator and modulus, and returns identifiers for both keys.
        // @param generator: Generator value used for key generation.
        // @example generator: 2
        // @param modulusSize: Number of bytes in modulus.
        // @example modulusSize: 256
        // @param modulus: Modulus bytes used for key generation.
        // @example modulus: [modulus bytes]
        // @param privKeyId: Receives the generated private key identifier.
        // @example privKeyId: 1
        // @param pubKeyId: Receives the generated public key identifier.
        // @example pubKeyId: 2
        // @retval result: Status value returned by the key-generation operation.
        virtual uint32_t Generate(const uint8_t generator, const uint16_t modulusSize, const uint8_t modulus[]/* @length:modulusSize */ ,
                                  uint32_t& privKeyId /* @out */, uint32_t& pubKeyId /* @out */) = 0;

        // @brief Derive a Diffie-Hellman shared secret.
        // @details Uses the private key and peer public key to create a shared secret in the key store.
        // @param privateKey: Identifier of the local private key.
        // @example privateKey: 1
        // @param peerPublicKeyId: Identifier of the peer public key.
        // @example peerPublicKeyId: 2
        // @param secretId: Receives the identifier of the derived shared secret.
        // @example secretId: 3
        // @retval result: Status value returned by the derivation operation.
        virtual uint32_t Derive(const uint32_t privateKey, const uint32_t peerPublicKeyId, uint32_t& secretId /* @out */) = 0;
    };

    struct IPersistent : virtual public Core::IUnknown {

    enum { ID = ID_PERSISTENT };

    enum keytype {
        AES128,
        AES256,
        HMAC128,
        HMAC160,
        HMAC256
    };

    virtual ~IPersistent() { }

    // @brief Check whether a persistent key exists.
    // @details Looks up a key using its locator without loading it into a vault.
    // @param locator: Name or location identifying the persistent key.
    // @example locator: "device-key"
    // @param result: Receives true if the key exists; otherwise false.
    // @example result: true
    // @retval status: Status value returned by the lookup operation.
    virtual uint32_t Exists(const string& locator, bool& result /* @out */) const =0;

    // @brief Load a persistent key into a vault.
    // @details Resolves the key locator and returns the identifier assigned to the loaded key.
    // @param locator: Name or location identifying the persistent key.
    // @example locator: "device-key"
    // @param id: Receives the loaded key identifier.
    // @example id: 1
    // @retval status: Status value returned by the load operation.
    virtual uint32_t Load(const string& locator, uint32_t&  id /* @out */) = 0;

    // @brief Create a persistent key.
    // @details Creates a key of the requested type and returns its identifier.
    // @param locator: Name or location under which to store the key.
    // @example locator: "device-key"
    // @param keyType: Type of key to create.
    // @example keyType: AES256
    // @param id: Receives the created key identifier.
    // @example id: 1
    // @retval status: Status value returned by the creation operation.
    virtual uint32_t Create(const string& locator, const keytype keyType, uint32_t& id /* @out */) = 0 ;

    // @brief Flush persistent-key backend resources.
    // @details Requests that the backend explicitly flush any resources associated with persistent keys.
    // @retval status: Status value returned by the flush operation.
    virtual uint32_t Flush() = 0;

    };


    struct EXTERNAL IVault : virtual public Core::IUnknown {

        enum { ID = ID_VAULT };

        ~IVault()  override = default;

        // Operations manipulating items in the vault
        // ---------------------------------------------------

        // @brief Get the size of a vault data blob.
        // @details Returns zero when the identifier does not exist; a non-extractable blob is reported with the uint16_t representation of -1.
        // @param id: Identifier of the data blob.
        // @example id: 1
        // @retval size: Blob size in bytes, zero if the identifier does not exist, or uint16_t(-1) if it exists but is not extractable.
        virtual uint16_t Size(const uint32_t id) const = 0;

        // @brief Import an unencrypted data blob into the vault.
        // @details Returns an identifier for the imported blob. User identifiers are greater than 0x80000000; lower values are reserved for implementation-specific internal blobs.
        // @param length: Number of bytes in blob.
        // @example length: 4
        // @param blob: Unencrypted data to import.
        // @example blob: [0x64, 0x61, 0x74, 0x61]
        // @retval id: Identifier assigned to the imported blob.
        virtual uint32_t Import(const uint16_t length, const uint8_t blob[] /* @length:length */) = 0;

        // @brief Export an unencrypted data blob from the vault.
        // @details Only public blobs can be exported; the method writes the data into the caller-provided buffer.
        // @param id: Identifier of the blob to export.
        // @example id: 1
        // @param maxLength: Maximum number of bytes that fit in blob.
        // @example maxLength: 256
        // @param blob: Output buffer receiving the exported data.
        // @example blob: [output buffer]
        // @retval length: Number of bytes exported to blob.
        virtual uint16_t Export(const uint32_t id, const uint16_t maxLength, uint8_t blob[] /* @out @maxlength:maxLength */) const = 0;

        // @brief Store an encrypted data blob in the vault.
        // @details Stores the supplied encrypted blob and returns its identifier.
        // @param length: Number of bytes in blob.
        // @example length: 4
        // @param blob: Encrypted data to store.
        // @example blob: [0x01, 0x02, 0x03, 0x04]
        // @retval id: Identifier assigned to the stored blob.
        virtual uint32_t Set(const uint16_t length, const uint8_t blob[] /* @length:length */) = 0;

        // @brief Retrieve an encrypted data blob from the vault.
        // @details Writes the blob identified by id into the caller-provided buffer.
        // @param id: Identifier of the blob to retrieve.
        // @example id: 1
        // @param maxLength: Maximum number of bytes that fit in blob.
        // @example maxLength: 256
        // @param blob: Output buffer receiving the encrypted data.
        // @example blob: [output buffer]
        // @retval length: Number of bytes retrieved into blob.
        virtual uint16_t Get(const uint32_t id, const uint16_t maxLength, uint8_t blob[] /* @out @maxlength:maxLength */) const = 0;

        // @brief Delete a data blob from the vault.
        // @details Removes the blob identified by id.
        // @param id: Identifier of the blob to delete.
        // @example id: 1
        // @retval deleted: True if the blob was deleted; otherwise false.
        virtual bool Delete(const uint32_t id) = 0;


        // Crypto operations using the vault for key storage
        // -----------------------------------------------------

        // @brief Create a HMAC calculator.
        // @details Returns a calculator configured for the requested hash type and vault key.
        // @param hashType: Hash algorithm to use for HMAC calculation.
        // @example hashType: SHA256
        // @param keyId: Identifier of the key to use for HMAC calculation.
        // @example keyId: 1
        // @retval calculator: HMAC calculator, or nullptr if one cannot be created.
        virtual IHash* HMAC(const hashtype hashType, const uint32_t keyId) = 0;

        // @brief Create an AES cipher.
        // @details Returns an encryptor and decryptor configured for the requested AES mode and vault key.
        // @param aesMode: AES mode to use for encryption and decryption.
        // @example aesMode: CBC
        // @param keyId: Identifier of the key to use for encryption and decryption.
        // @example keyId: 1
        // @retval cipher: AES cipher, or nullptr if one cannot be created.
        virtual ICipher* AES(const aesmode aesMode, const uint32_t keyId) = 0;

        // @brief Get a Diffie-Hellman key generator.
        // @details Returns the vault's Diffie-Hellman interface for key generation and shared-secret derivation.
        // @retval diffieHellman: Diffie-Hellman interface, or nullptr if unavailable.
        virtual IDiffieHellman* DiffieHellman() = 0;
    };

    struct EXTERNAL ICryptography : virtual public Core::IUnknown {
        enum { ID = ID_CRYPTOGRAPHY };

        ~ICryptography()  override = default;

        static ICryptography* Instance(const std::string& connectionPoint);

        // @brief Create a hash calculator.
        // @details Returns a calculator configured to compute the requested hash algorithm.
        // @param hashType: Hash algorithm to use.
        // @example hashType: SHA256
        // @retval calculator: Hash calculator, or nullptr if one cannot be created.
        virtual IHash* Hash(const hashtype hashType) = 0;

        // @brief Retrieve a cryptography vault.
        // @details Selects the vault identified by id, such as the default, platform, provisioning, or Netflix vault.
        // @param id: Identifier of the vault to retrieve.
        // @example id: CRYPTOGRAPHY_VAULT_DEFAULT
        // @retval vault: Requested vault interface, or nullptr if unavailable.
        virtual IVault* Vault(const CryptographyVault id) = 0;
    };

}
}
