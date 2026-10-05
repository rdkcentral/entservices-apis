/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2021 Metrological
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
/*
 * Metrological has done changes to the original interface definition
 * from Fraunhofer FOKUS
 */
/*
 * Copyright 2014 Fraunhofer FOKUS
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

// @stubgen:skip

// For the support of portable data types such as uint8_t.
#include <stdint.h>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <list>
#include <vector>

#include <interfaces/Portability.h>

class BufferReader {
private:
    BufferReader() = delete;
    BufferReader(const BufferReader&) = delete;
    BufferReader& operator=(const BufferReader&) = delete;

    // Internal implementation of multi-byte reads
    template <typename T>
    bool Read(T* v)
    {
        if ((v != nullptr) && (HasBytes(sizeof(T)) == true)) {
            T tmp = 0;
            for (size_t i = 0; i < sizeof(T); i++) {
                tmp <<= 8;
                tmp += buf_[pos_++];
            }
            *v = tmp;
            return true;
        }
        return false;
    }

public:
    inline BufferReader(const uint8_t* buf, size_t size)
        : buf_(buf)
        , size_(buf != NULL ? size : 0)
        , pos_(0)
    {
    }
    inline ~BufferReader() = default;

public:
    inline bool HasBytes(size_t count) const { return pos_ + count <= size_; }
    inline bool IsEOF() const { return pos_ >= size_; }
    inline const uint8_t* data() const { return buf_; }
    inline size_t size() const { return size_; }
    inline size_t pos() const { return pos_; }

    // Read a value from the stream, performing endian correction,
    // and advance the stream pointer.
    inline bool Read1(uint8_t* v) WARNING_RESULT_NOT_USED { return Read(v); }
    inline bool Read2(uint16_t* v) WARNING_RESULT_NOT_USED { return Read(v); }
    inline bool Read2s(int16_t* v) WARNING_RESULT_NOT_USED { return Read(v); }
    inline bool Read4(uint32_t* v) WARNING_RESULT_NOT_USED { return Read(v); }
    inline bool Read4s(int32_t* v) WARNING_RESULT_NOT_USED { return Read(v); }
    inline bool Read8(uint64_t* v) WARNING_RESULT_NOT_USED { return Read(v); }
    inline bool Read8s(int64_t* v) WARNING_RESULT_NOT_USED { return Read(v); }

    inline bool ReadString(std::string* str, size_t count) WARNING_RESULT_NOT_USED
    {
        if ((str != nullptr) && (HasBytes(count) == true)) {
            str->assign(buf_ + pos_, buf_ + pos_ + count);
            pos_ += count;
            return true;
        }
        return false;
    }
    inline bool ReadVec(std::vector<uint8_t>* vec, size_t count) WARNING_RESULT_NOT_USED
    {
        if ((vec != nullptr) && (HasBytes(count) == true)) {
            vec->clear();
            vec->insert(vec->end(), buf_ + pos_, buf_ + pos_ + count);
            pos_ += count;
            return true;
        }
        return false;
    }

    // These variants read a 4-byte integer of the corresponding signedness and
    // store it in the 8-byte return type.
    inline bool Read4Into8(uint64_t* v) WARNING_RESULT_NOT_USED
    {
        uint32_t tmp;
        if ((v != nullptr) && (Read4(&tmp) == true)) {
            *v = tmp;
            return true;
        }
        return false;
    }
    inline bool Read4sInto8s(int64_t* v) WARNING_RESULT_NOT_USED
    {
        int32_t tmp;
        if ((v != nullptr) && (Read4s(&tmp) == true)) {
            *v = tmp;
            return true;
        }
        return false;
    }

    // Advance the stream by this many bytes.
    inline bool SkipBytes(size_t bytes) WARNING_RESULT_NOT_USED
    {
        if (HasBytes(bytes) == true) {
            pos_ += bytes;
            return true;
        }
        return false;
    }

private:
    const uint8_t* buf_;
    size_t size_;
    size_t pos_;
};

namespace WPEFramework
{
   namespace PluginHost
   {
      struct IShell;
   }
}

namespace CDMi {

// EME error code to which CDMi errors are mapped. Please
// refer to the EME spec for details of the errors
// https://dvcs.w3.org/hg/html-media/raw-file/tip/encrypted-media/encrypted-media.html
#define MEDIA_KEYERR_UNKNOWN 1
#define MEDIA_KEYERR_CLIENT 2
#define MEDIA_KEYERR_SERVICE 3
#define MEDIA_KEYERR_OUTPUT 4
#define MEDIA_KEYERR_HARDWARECHANGE 5
#define MEDIA_KEYERR_DOMAIN 6

// More CDMi status codes can be defined. In general
// CDMi status codes should use the same PK error codes.

#define CDMi_FAILED(Status) ((CDMi_RESULT)(Status) < 0)
#define CDMi_SUCCEEDED(Status) ((CDMi_RESULT)(Status) >= 0)

/* Media Key status required by EME */
#define MEDIA_KEY_STATUS_USABLE 0
#define MEDIA_KEY_STATUS_INTERNAL_ERROR 1
#define MEDIA_KEY_STATUS_EXPIRED 2
#define MEDIA_KEY_STATUS_OUTPUT_NOT_ALLOWED 3
#define MEDIA_KEY_STATUS_OUTPUT_DOWNSCALED 4
#define MEDIA_KEY_STATUS_KEY_STATUS_PENDING 5
#define MEDIA_KEY_STATUS_KEY_STATUS_MAX KEY_STATUS_PENDING

typedef enum {
    CDMi_SUCCESS = 0,
    CDMi_S_FALSE = 1,
    CDMi_MORE_DATA_AVAILABLE = 2,
    CDMi_INTERFACE_NOT_IMPLEMENTED = 3,
    CDMi_BUFFER_TOO_SMALL = 4,
    CDMi_INVALID_ACCESSOR = 0x80000001,
    CDMi_KEYSYSTEM_NOT_SUPPORTED = 0x80000002,
    CDMi_INVALID_SESSION = 0x80000003,
    CDMi_INVALID_DECRYPT_BUFFER = 0x80000004,
    CDMi_OUT_OF_MEMORY = 0x80000005,
    CDMi_METHOD_NOT_IMPLEMENTED = 0x80000006,
    CDMi_FAIL = 0x80004005,
    CDMi_INVALID_ARG = 0x80070057,
    CDMi_SERVER_INTERNAL_ERROR = 0x8004C600,
    CDMi_SERVER_INVALID_MESSAGE = 0x8004C601,
    CDMi_SERVER_SERVICE_SPECIFIC = 0x8004C604,
    CDMi_BUSY_CANNOT_INITIALIZE = 0x8004DD00,
} CDMi_RESULT;

typedef enum {
    Temporary,
    PersistentUsageRecord,
    PersistentLicense
} LicenseType;

typedef enum {
    Invalid = 0,
    LimitedDuration,
    Standard
} LicenseTypeExt;

typedef enum {
    LicenseAcquisitionState = 0,
    InactiveDecryptionState,
    ActiveDecryptionState,
    InvalidState
} SessionStateExt;

typedef enum 
{
    Unknown = 0,
    Video,
    Audio,
    Data
} MediaType;

// ISO/IEC 23001-7 defines two Common Encryption Schemes with Full Sample and Subsample modes
typedef enum : uint8_t {
    Clear = 0,
    AesCtr_Cenc,    // AES-CTR mode and Sub-Sample encryption
    AesCbc_Cbc1,    // AES-CBC mode and Sub-Sample encryption
    AesCtr_Cens,    // AES-CTR mode and Sub-Sample + patterned encryption
    AesCbc_Cbcs     // AES-CBC mode and Sub-Sample + patterned encryption + Constant IV
} EncryptionScheme;

// CBCS & CENC3.0 pattern is a number of encrypted blocks followed a number of clear
// blocks after which the pattern repeats.
typedef struct {
    uint32_t clear_blocks;
    uint32_t encrypted_blocks;
} EncryptionPattern;

typedef struct {
    uint16_t clear_bytes;
    uint32_t encrypted_bytes;
} SubSampleInfo;

typedef struct {
    EncryptionScheme   scheme;          // Encryption scheme used in this sample
    EncryptionPattern pattern;          // Encryption Pattern used in this sample
    uint8_t*           iv;              // Initialization vector(IV) to decrypt this sample
    uint8_t            ivLength;        // Length of IV
    uint8_t*           keyId;           // ID of Key required to decrypt this sample
    uint8_t            keyIdLength;     // Length of KeyId
    uint8_t            subSampleCount;  // Number or Sub-Samples in this sample
    SubSampleInfo*     subSample;       // SubSample mapping - Repeating pair of Clear bytes and Encrypted Bytes representing each subsample.
} SampleInfo;

//FPS
typedef struct {
  uint32_t offset;
  uint32_t size;
} Cdmi_FPSSliceInfo;

// IStreamProperties to provide information about the current stream
class IStreamProperties {
public:
    virtual ~IStreamProperties (void) = default;

    // @brief Gets the height of the current video stream.
    // @details The value is reported in pixels by the stream properties provider.
    // @retval uint16_t: Stream height in pixels.
    virtual uint16_t GetHeight() const = 0;
    
    // @brief Gets the width of the current video stream.
    // @details The value is reported in pixels by the stream properties provider.
    // @retval uint16_t: Stream width in pixels.
    virtual uint16_t GetWidth() const = 0;

    // @brief Gets the media type of the current stream.
    // @details The media type identifies the stream as unknown, video, audio, or data.
    // @retval MediaType: Type of the current media stream.
    virtual MediaType GetMediaType() const = 0;

    // @brief Gets the legacy initialization-data length.
    // @details Deprecated; retained for backwards compatibility with older stream providers.
    // @retval uint8_t: Legacy initialization-data length.
    virtual uint8_t InitLength() const = 0;
};

// IMediaKeySessionCallback defines the callback interface to receive
// events originated from MediaKeySession.
class IMediaKeySessionCallback {
public:
    virtual ~IMediaKeySessionCallback(void) = default;

    // @brief Notifies that a key message was generated.
    // @details Called when a key message is successfully created and is ready for delivery to the license server.
    // @param f_pbKeyMessage:Buffer containing the generated key message.
    // @example f_pbKeyMessage: "keyMessageBuffer"
    // @param f_cbKeyMessage:Length of the key message buffer.
    // @example f_cbKeyMessage: 128
    // @param f_pszUrl:URL associated with the key message delivery.
    // @example f_pszUrl: "https://license.server.com"
    virtual void OnKeyMessage(
        const uint8_t* f_pbKeyMessage, //__in_bcount(f_cbKeyMessage)
        uint32_t f_cbKeyMessage, //__in
        const char* f_pszUrl)
        = 0; //__in_z_opt

    // @brief Notifies that the MediaKeySession encountered an error.
    // @details Signals the failure condition and includes the DRM-specific and system error codes along with an error message.
    // @param f_nError:Error code raised by the session.
    // @example f_nError: -1
    // @param f_crSysError:Underlying system error code.
    // @example f_crSysError: 0
    // @param errorMessage:Human-readable description of the failure.
    // @example errorMessage: "Session failed due to invalid key."
    virtual void OnError(
        int16_t f_nError,
        CDMi_RESULT f_crSysError,
        const char* errorMessage)
        = 0;

    // @brief Notifies that a key status update was received.
    // @details Reports the current status of one or more keys associated with the media session.
    // @param keyMessage:Key message or related metadata associated with the update.
    // @example keyMessage: "keyMessageBuffer"
    // @param buffer:Buffer containing the status update payload.
    // @example buffer: "statusUpdateBuffer"
    // @param length:Length of the status update payload.
    // @example length: 128
    virtual void OnKeyStatusUpdate(const char* keyMessage, const uint8_t* buffer, const uint8_t length) = 0;
   
    // @brief Notifies the client that key-status updates are complete.
    // @details Signals completion after one or more key-status changes have been delivered.
    virtual void OnKeyStatusesUpdated() const = 0;
};

// IMediaKeySession defines the MediaKeySession interface.
class IMediaKeySession {
public:
    IMediaKeySession(void) = default;
    virtual ~IMediaKeySession(void) = default;

    // @brief Retrieves key-system-specific metadata for the session.
    // @details The default implementation returns an empty string when metadata is not supplied.
    // @retval std::string: Session metadata for the active key system.
    virtual std::string GetMetadata() const { return std::string(); }

    // @brief Starts key acquisition for the session.
    // @details Kicks off the process of acquiring a key and provides a callback for receiving notifications during the process.
    // @param f_piMediaKeySessionCallback: Callback interface used to receive session progress notifications.
    // @example f_piMediaKeySessionCallback: "mediaKeySessionCallbackInstance"
    virtual void Run(
        const IMediaKeySessionCallback* f_piMediaKeySessionCallback)
        = 0; //__in

    // @brief Loads persisted data for this session into the CDM.
    // @details Used to restore stored session state before resuming session operations.
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, an error result describing the load failure.
    virtual CDMi_RESULT Load() = 0;

    // @brief Processes a key message response.
    // @details Updates the session with the license response data returned by the license server.
    // @param f_pbKeyMessageResponse: Buffer containing the key message response.
    // @example f_pbKeyMessageResponse: "keyMessageResponseBuffer"
    // @param f_cbKeyMessageResponse: Length of the key message response buffer.
    // @example f_cbKeyMessageResponse: 128
    virtual void Update(
        const uint8_t* f_pbKeyMessageResponse, //__in_bcount(f_cbKeyMessageResponse)
        uint32_t f_cbKeyMessageResponse)
        = 0; //__in

    // @brief Removes licenses and keys associated with the session.
    // @details Requests deletion of all license and key material held for this session.
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, an error result describing the removal failure.
    virtual CDMi_RESULT Remove() = 0;

    // @brief Closes the session and releases its resources.
    // @details Explicitly releases resources associated with this media-key session.
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, an error result describing the close failure.
    virtual CDMi_RESULT Close(void) = 0;

    // @brief Gets the identifier of this media-key session.
    // @details The returned string pointer remains valid only while the associated session exists.
    // @retval const char*: Session identifier, or an implementation-defined empty value when unavailable.
    virtual const char* GetSessionId(void) const = 0;

    // @brief Gets the key system associated with this media-key session.
    // @details Identifies the DRM key system that owns the session.
    // @retval const char*: Key-system identifier associated with the session.
    virtual const char* GetKeySystem(void) const = 0;

    // @brief Decrypts content using the provided session key and encryption metadata.
    // @details Deprecated API for decrypting content with explicit session key material and IV metadata.
    // @param f_pbSessionKey: Session key buffer.
    // @example f_pbSessionKey: "sessionKeyBuffer"
    // @param f_cbSessionKey: Length of the session key buffer.
    // @example f_cbSessionKey: 16
    // @param encryptionScheme: Encryption scheme used for the content.
    // @example encryptionScheme: "AES-CTR"
    // @param pattern: Encryption pattern used for the content.
    // @example pattern: {2, 1}
    // @param f_pbIV: Initialization vector buffer.
    // @example f_pbIV: "ivBuffer"
    // @param f_cbIV: Length of the IV buffer.
    // @example f_cbIV: 16
    // @param f_pbData: Encrypted data buffer.
    // @example f_pbData: "encryptedDataBuffer"
    // @param f_cbData: Length of the encrypted data buffer.
    // @example f_cbData: 256
    // @param f_pcbOpaqueClearContent: Pointer to output clear-content length.
    // @example f_pcbOpaqueClearContent: 256
    // @param f_ppbOpaqueClearContent: Pointer to output clear-content buffer.
    // @example f_ppbOpaqueClearContent: "clearContentBuffer"
    // @param keyIdLength: Length of the key identifier.
    // @example keyIdLength: 16
    // @param keyId: Key identifier used for decryption.
    // @example keyId: "keyIdentifier"
    // @param initWithLast15: Indicates whether the final 15 bytes should be used during decryption.
    // @example initWithLast15: true
    // @retval CDMi_RESULT: Status code indicating whether the deprecated decrypt operation succeeded.
    DEPRECATED virtual CDMi_RESULT Decrypt(
        const uint8_t* f_pbSessionKey VARIABLE_IS_NOT_USED,
        uint32_t f_cbSessionKey VARIABLE_IS_NOT_USED,
        const EncryptionScheme encryptionScheme VARIABLE_IS_NOT_USED,
        const EncryptionPattern& pattern VARIABLE_IS_NOT_USED,
        const uint8_t* f_pbIV VARIABLE_IS_NOT_USED,
        uint32_t f_cbIV VARIABLE_IS_NOT_USED,
        uint8_t* f_pbData VARIABLE_IS_NOT_USED,
        uint32_t f_cbData VARIABLE_IS_NOT_USED,
        uint32_t* f_pcbOpaqueClearContent VARIABLE_IS_NOT_USED,
        uint8_t** f_ppbOpaqueClearContent VARIABLE_IS_NOT_USED,
        const uint8_t keyIdLength VARIABLE_IS_NOT_USED,
        const uint8_t* keyId VARIABLE_IS_NOT_USED,
        bool initWithLast15 /*=0*/ VARIABLE_IS_NOT_USED) {

        return (CDMi_METHOD_NOT_IMPLEMENTED);
    }

    // @brief Decrypts encrypted sample data using its sample and stream metadata.
    // @details The output buffer and output length are supplied by the CDM implementation; sampleInfo provides key, IV, scheme and subsample metadata.
    // @param inData: Encrypted input data.
    // @example inData: "encryptedDataBuffer"
    // @param inDataLength: Number of bytes in inData.
    // @example inDataLength: 256
    // @param outData: Receives the decrypted output buffer.
    // @example outData: "decryptedDataBuffer"
    // @param outDataLength: Receives the number of bytes in outData.
    // @example outDataLength: 256
    // @param sampleInfo: Key, IV, encryption scheme, pattern and subsample information for the sample.
    // @example sampleInfo: &sampleMetadata
    // @param properties: Stream properties used by the decrypt operation.
    // @example properties: &streamProperties
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, a CDMi error result.
    virtual CDMi_RESULT Decrypt(
        uint8_t*                 inData,          // Incoming encrypted data
        const uint32_t           inDataLength,    // Incoming encrypted data length
        uint8_t**                outData,         // Outgoing decrypted data
        uint32_t*                outDataLength,   // Outgoing decrypted data length
        const SampleInfo*        sampleInfo,      // Information required to decrypt Sample
        const IStreamProperties* properties) {    // Stream Properties

PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        return (Decrypt(sampleInfo->keyId, sampleInfo->keyIdLength,
                sampleInfo->scheme, sampleInfo->pattern,
                sampleInfo->iv, sampleInfo->ivLength,
                inData, inDataLength,
                outDataLength, outData,
                sampleInfo->keyIdLength, sampleInfo->keyId,
                properties->InitLength()));
POP_WARNING()
    }

    // @brief Decrypts FairPlay-protected content using the specified cryptor and slice metadata.
    // @details Optional FairPlay overload; the default implementation reports CDMi_METHOD_NOT_IMPLEMENTED.
    // @param MovieId: Identifier of the FairPlay movie session.
    // @example MovieId: 1234567890
    // @param CryptorId: Identifier of the FairPlay cryptor.
    // @example CryptorId: 9876543210
    // @param ContentTyp: Content type associated with the encrypted data.
    // @example ContentTyp: 1
    // @param encryptedData: Encrypted content buffer to process.
    // @example encryptedData: {0x01, 0x02, 0x03, 0x04} represents the encrypted content bytes.
    // @param encryptedDataSize: Number of bytes in encryptedData.
    // @example encryptedDataSize: 4 indicates that encryptedData contains 4 bytes.
    // @param SliceInfoArray: Array describing encrypted content slices.
    // @example SliceInfoArray: [{offset: 0, size: 1024}, {offset: 1024, size: 1024}] represents the slices of the encrypted content.
    // @param SliceInfoArrayCount: Number of entries in SliceInfoArray.
    // @example SliceInfoArrayCount: 2 indicates that SliceInfoArray contains 2 entries.
    // @param iv: Initialization vector for the encrypted content.
    // @example iv: {0x01, 0x02, 0x03, 0x04} represents the initialization vector bytes.
    // @param svphan: Platform-specific secure-video-path handle or context.
    // @example svphan: "secureVideoPathHandle" represents the platform-specific secure-video-path handle or context.
    // @retval CDMi_RESULT: CDMi_METHOD_NOT_IMPLEMENTED by default; otherwise, the FairPlay decrypt result.
    virtual CDMi_RESULT Decrypt(uint64_t MovieId,uint64_t CryptorId, uint32_t ContentTyp, uint8_t *encryptedData, uint32_t encryptedDataSize, const Cdmi_FPSSliceInfo *SliceInfoArray,uint32_t SliceInfoArrayCount, uint8_t *iv, void *svphan)
    {
	    return (CDMi_METHOD_NOT_IMPLEMENTED);
    }

    // @brief Releases the clear content associated with the session.
    // @details Clears the decrypted content that was produced for a prior decrypt operation.
    // @param f_pbSessionKey:Session key buffer associated with the content.
    // @example f_pbSessionKey: "sessionKeyBuffer"
    // @param f_cbSessionKey: Length of the session key buffer.
    // @example f_cbSessionKey: 16
    // @param f_cbClearContentOpaque: Length of the opaque clear content.
    // @example f_cbClearContentOpaque: 256
    // @param f_pbClearContentOpaque: Opaque clear content buffer to release.
    // @example f_pbClearContentOpaque: "clearContentBuffer"
    // @retval CDMi_RESULT: Status indicating whether the content release succeeded.
    virtual CDMi_RESULT ReleaseClearContent(
        const uint8_t* f_pbSessionKey,
        uint32_t f_cbSessionKey,
        const uint32_t f_cbClearContentOpaque,
        uint8_t* f_pbClearContentOpaque)
        = 0;

    // @brief Resets the output-protection state for the session.
    // @details Optional operation; the default implementation reports CDMi_METHOD_NOT_IMPLEMENTED.
    // @retval CDMi_RESULT: CDMi_METHOD_NOT_IMPLEMENTED by default; otherwise, the reset result.
    virtual CDMi_RESULT ResetOutputProtection() { return (CDMi_METHOD_NOT_IMPLEMENTED); }
    
    // @brief Sets a named implementation-specific session parameter.
    // @details Optional operation; the default implementation reports CDMi_METHOD_NOT_IMPLEMENTED.
    // @param name: Name of the parameter to set.
    // @example name: "playbackMode"
    // @param value: String value to assign to the parameter.
    // @example value: "streaming"
    // @retval CDMi_RESULT: CDMi_METHOD_NOT_IMPLEMENTED by default; otherwise, the parameter-setting result.
    virtual CDMi_RESULT SetParameter(const std::string& name VARIABLE_IS_NOT_USED, const std::string& value VARIABLE_IS_NOT_USED) { return (CDMi_METHOD_NOT_IMPLEMENTED); }
};

// IMediaKeySession defines the MediaKeySession interface.
class IMediaKeySessionExt {
public:
    IMediaKeySessionExt(void) = default;
    virtual ~IMediaKeySessionExt(void) = default;

    // @brief Gets the numeric identifier of the extended session.
    // @details Returns the session identifier in the extension's integer representation.
    // @retval uint32_t: Numeric session identifier.
    virtual uint32_t GetSessionIdExt(void) const = 0;

    // @brief Sets the DRM header for the session.
    // @details Supplies a DRM header to the session for use in license acquisition or challenge exchange.
    // @param drmHeader:Buffer containing the DRM header.
    // @example drmHeader: "drmHeaderBuffer"
    // @param drmHeaderLength: Length of the DRM header buffer.
    // @example drmHeaderLength: 128
    // @retval CDMi_RESULT: Status of the DRM header update operation.
    virtual CDMi_RESULT SetDrmHeader(const uint8_t drmHeader[], uint32_t drmHeaderLength) = 0;

    // @brief Retrieves challenge data for the session.
    // @details Returns the challenge data needed to complete an extended DRM challenge flow.
    // @param challenge: Output buffer that receives the challenge data.
    // @example challenge: "challengeBuffer"
    // @param challengeSize: Length of the challenge data returned by the call.
    // @example challengeSize: 256
    // @param isLDL: Indicates whether the challenge is for a low-delay license flow.
    // @example isLDL: 1
    // @retval CDMi_RESULT: Status of the challenge retrieval operation.
    virtual CDMi_RESULT GetChallengeDataExt(uint8_t* challenge, uint32_t& challengeSize, uint32_t isLDL) = 0;

    // @brief Cancels pending extended challenge-data generation.
    // @details Allows the caller to cancel a challenge request that is no longer required.
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, a CDMi error result.
    virtual CDMi_RESULT CancelChallengeDataExt() = 0;

    // @brief Stores license data associated with the session.
    // @details Persists license metadata and optionally returns a secure stop identifier.
    // @param licenseData:Buffer containing the license data.
    // @example licenseData: "licenseDataBuffer"
    // @param licenseDataSize: Length of the license data buffer.
    // @example licenseDataSize: 512
    // @param secureStopId: Optional output buffer for a secure stop identifier.
    // @example secureStopId: "secureStopIdBuffer"
    // @retval CDMi_RESULT: Status of the license data storage operation.
    virtual CDMi_RESULT StoreLicenseData(const uint8_t licenseData[], uint32_t licenseDataSize, uint8_t* secureStopId) = 0;

    // @brief Selects a specific key identifier for use with the session.
    // @details Chooses the key ID that should be used for subsequent decryption operations.
    // @param keyLength: Length of the key identifier.
    // @example keyLength: 16
    // @param keyId: Buffer containing the key identifier.
    // @example keyId: "keyIdBuffer"
    // @retval CDMi_RESULT: Status of the key selection operation.
    virtual CDMi_RESULT SelectKeyId(const uint8_t keyLength, const uint8_t keyId[]) = 0;

    // @brief Clears the session's decrypt context.
    // @details Removes transient decrypt-context state maintained by the CDM.
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, a CDMi error result.
    virtual CDMi_RESULT CleanDecryptContext() = 0;
};

// IMediaKeys defines the MediaKeys interface.
class IMediaKeys {
public:
    IMediaKeys(void) = default;
    virtual ~IMediaKeys(void) = default;

    // @brief Retrieves key-system-specific metadata.
    // @details The default implementation returns an empty string when metadata is not supplied.
    // @retval std::string: Metadata for the key system.
    virtual std::string GetMetadata() const { return std::string(); }

    // @brief Creates a MediaKeySession using the supplied initialization data.
    // @details Creates a MediaKeySession for the requested key system using the provided init data and CDM data.
    // @param keySystem:Key system to create the session for.
    // @example keySystem: "com.example.drm"
    // @param licenseType: Type of license requested for the session.
    // @example licenseType: 1
    // @param f_pwszInitDataType: Type of initialization data.
    // @example f_pwszInitDataType: "cenc"
    // @param f_pbInitData: Initialization data buffer.
    // @example f_pbInitData: "initDataBuffer"
    // @param f_cbInitData: Length of the initialization data buffer.
    // @example f_cbInitData: 128
    // @param f_pbCDMData: CDM-specific data buffer.
    // @example f_pbCDMData: "cdmDataBuffer"
    // @param f_cbCDMData: Length of the CDM-specific data buffer.
    // @example f_cbCDMData: 256
    // @param f_ppiMediaKeySession:Output pointer to the created session.
    // @example f_ppiMediaKeySession: "mediaKeySessionPointer"
    // @retval CDMi_RESULT: Status of the session creation operation.
    virtual CDMi_RESULT CreateMediaKeySession(
        const std::string& keySystem,
        int32_t licenseType,
        const char* f_pwszInitDataType,
        const uint8_t* f_pbInitData,
        uint32_t f_cbInitData,
        const uint8_t* f_pbCDMData,
        uint32_t f_cbCDMData,
        IMediaKeySession** f_ppiMediaKeySession)
        = 0;

    // @brief Sets the server certificate.
    // @details Configures the server certificate used to communicate with the DRM license server.
    // @param f_pbServerCertificate: Buffer containing the server certificate.
    // @example f_pbServerCertificate: "serverCertificateBuffer"
    // @param f_cbServerCertificate: Length of the server certificate buffer.
    // @example f_cbServerCertificate: 512
    // @retval CDMi_RESULT: Status of the server certificate configuration operation.
    virtual CDMi_RESULT SetServerCertificate(
        const uint8_t* f_pbServerCertificate,
        uint32_t f_cbServerCertificate)
        = 0;

    // @brief Destroys an existing MediaKeySession.
    // @details Releases the resources associated with a previously created MediaKeySession.
    // @param f_piMediaKeySession:Session instance to destroy.
    // @example f_piMediaKeySession: "mediaKeySessionPointer"
    // @retval CDMi_RESULT: Status of the session destruction operation.
    virtual CDMi_RESULT DestroyMediaKeySession(
        IMediaKeySession* f_piMediaKeySession)
        = 0;

    // @brief Creates a FairPlay movie session.
    // @details Optional FairPlay operation; the default implementation reports CDMi_METHOD_NOT_IMPLEMENTED.
    // @param version: FairPlay interface version.
    // @example version: 1
    // @param cert: FairPlay certificate bytes.
    // @example cert: "certificateBuffer"
    // @param certificatesize: Number of bytes in cert.
    // @example certificatesize: 256
    // @param versionlist: Supported FairPlay version values.
    // @example versionlist: [1, 2, 3]
    // @param versionListSize: Number of entries in versionlist.
    // @example versionListSize: 3
    // @param movieIdOut: Receives the created movie-session identifier.
    // @example movieIdOut: &movieId
    // @retval CDMi_RESULT: CDMi_METHOD_NOT_IMPLEMENTED by default; otherwise, the movie-session creation result.
    virtual CDMi_RESULT CreateMovieSession(uint32_t version, const uint8_t* cert, uint32_t certificatesize,
        const uint32_t* versionlist, uint32_t versionListSize, uint64_t* movieIdOut)
    {
        return CDMi_METHOD_NOT_IMPLEMENTED;
    }
    // @brief Destroys a FairPlay movie session.
    // @details Optional FairPlay operation; the default implementation reports CDMi_METHOD_NOT_IMPLEMENTED.
    // @param version: FairPlay interface version.
    // @example version: 1
    // @param movieId: Identifier of the movie session to destroy.
    // @example movieId: 12345
    // @retval CDMi_RESULT: CDMi_METHOD_NOT_IMPLEMENTED by default; otherwise, the destruction result.
    virtual CDMi_RESULT DestroyMovieSession(uint32_t version, uint64_t movieId)
    {
        return CDMi_METHOD_NOT_IMPLEMENTED;
    }
    // @brief Generates a FairPlay license challenge using a version list.
    // @details Optional FairPlay operation; combines asset, streamer, version-list and cryptor data into the challenge and session outputs.
    // @param version: FairPlay interface version.
    // @example version: 1
    // @param movieId: Identifier of the movie session.
    // @example movieId: 12345
    // @param assetidData: Asset identifier bytes.
    // @example assetidData: "assetIdBuffer"
    // @param assetidSize: Number of bytes in assetidData.
    // @example assetidSize: 16
    // @param versionlist: Supported FairPlay version values.
    // @example versionlist: [1, 2, 3]
    // @param versionListSize: Number of entries in versionlist.
    // @example versionListSize: 3
    // @param streamerChallengeData: Streamer-provided challenge data.
    // @example streamerChallengeData: "streamerDataBuffer"
    // @param streamerChallengeSize: Number of bytes in streamerChallengeData.
    // @example streamerChallengeSize: 128
    // @param cryptorId: Identifier of the FairPlay cryptor.
    // @example cryptorId: 98765
    // @param licenseChallengeBuffer: Receives the generated license challenge.
    // @example licenseChallengeBuffer: "challengeBuffer"
    // @param licenseSize: Receives the generated challenge size.
    // @example licenseSize: 256
    // @param session: Receives session data for the server exchange.
    // @example session: "sessionBuffer"
    // @retval CDMi_RESULT: CDMi_METHOD_NOT_IMPLEMENTED by default; otherwise, the challenge-generation result.
    virtual CDMi_RESULT GenerateChallengeWithVersionList(uint32_t version, uint64_t movieId,
        const uint8_t* assetidData, uint32_t assetidSize, const uint32_t* versionlist, uint32_t versionListSize,
        const uint8_t* streamerChallengeData, uint32_t streamerChallengeSize,
        uint64_t cryptorId, uint8_t* licenseChallengeBuffer, uint8_t* licenseSize, uint8_t* session)
    {
        return CDMi_METHOD_NOT_IMPLEMENTED;
    }
    // @brief Destroys a FairPlay server exchange.
    // @details Optional FairPlay operation that releases state associated with a server-exchange session.
    // @param version: FairPlay interface version.
    // @example version: 1
    // @param session: Server-exchange session data to destroy.
    // @example session: "sessionBuffer"
    // @retval CDMi_RESULT: CDMi_METHOD_NOT_IMPLEMENTED by default; otherwise, the destruction result.
    virtual CDMi_RESULT DestroyServerExchange(uint32_t version, uint8_t* session)
    {
        return CDMi_METHOD_NOT_IMPLEMENTED;
    }
    // @brief Processes FairPlay license data for a server exchange.
    // @details Optional FairPlay operation that applies license data and returns the cryptor identifier.
    // @param version: FairPlay interface version.
    // @example version: 1
    // @param session: Server-exchange session data.
    // @example session: "sessionBuffer"
    // @param licenseData: License response bytes.
    // @example licenseData: "licenseBuffer"
    // @param licenseDataSize: Number of bytes in licenseData.
    // @example licenseDataSize: 256
    // @param cryptoId: Receives the identifier of the cryptor created for this license.
    // @example cryptoId: 98765
    // @retval CDMi_RESULT: CDMi_METHOD_NOT_IMPLEMENTED by default; otherwise, the license-processing result.
    virtual CDMi_RESULT ProcessLicense(uint32_t version, uint8_t* session,
        const uint8_t* licenseData, uint32_t licenseDataSize, uint8_t* cryptoId)
    {
        return CDMi_METHOD_NOT_IMPLEMENTED;
    }
    // @brief Initializes the FairPlay library.
    // @details Optional FairPlay operation; the default implementation reports CDMi_METHOD_NOT_IMPLEMENTED.
    // @retval CDMi_RESULT: CDMi_METHOD_NOT_IMPLEMENTED by default; otherwise, the initialization result.
    virtual CDMi_RESULT InitLibrary()
    {
        return CDMi_METHOD_NOT_IMPLEMENTED;
    }

    // @brief Destroys a FairPlay cryptor.
    // @details Optional FairPlay operation that releases the cryptor identified by cryptoId.
    // @param version: FairPlay interface version.
    // @example version: 1
    // @param cryptoId: Identifier of the cryptor to destroy.
    // @example cryptoId: 98765
    // @retval CDMi_RESULT: CDMi_METHOD_NOT_IMPLEMENTED by default; otherwise, the destruction result.
    virtual CDMi_RESULT DestroyCryptor(uint32_t version, uint64_t cryptoId)
     {
             return CDMi_METHOD_NOT_IMPLEMENTED;
     }
};

// IMediaKeySession defines the MediaKeySessionExt interface.
class IMediaKeysExt {
public:
    IMediaKeysExt(void) = default;
    virtual ~IMediaKeysExt(void) = default;

    // @brief Gets the DRM system's current time.
    // @details Returns the time value maintained by the DRM implementation.
    // @retval uint64_t: DRM system time.
    virtual uint64_t GetDrmSystemTime() const = 0;

    // @brief Gets the extended DRM implementation version.
    // @details Returns the version string exposed by the key-system extension.
    // @retval std::string: DRM implementation version.
    virtual std::string GetVersionExt() const = 0;

    // @brief Gets the maximum number of limited-duration-license sessions.
    // @details Reports the LDL session limit configured by the DRM implementation.
    // @retval uint32_t: Maximum supported LDL session count.
    virtual uint32_t GetLdlSessionLimit() const = 0;

    // @brief Checks whether secure-stop support is enabled.
    // @details Queries the current secure-stop setting for this DRM implementation.
    // @retval bool: True if secure stop is enabled; otherwise, false.
    virtual bool IsSecureStopEnabled() = 0;

    // @brief Enables or disables secure-stop support.
    // @details Applies the requested secure-stop setting to this DRM implementation.
    // @param enable: True to enable secure stop; false to disable it.
    // @example enable: true
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, a CDMi error result.
    virtual CDMi_RESULT EnableSecureStop(bool enable) = 0;

    // @brief Resets stored secure-stop records.
    // @details Requests the DRM implementation to clear its secure-stop state.
    // @retval uint32_t: Implementation-defined reset result code.
    virtual uint32_t ResetSecureStops() = 0;

    // @brief Retrieves identifiers for stored secure stops.
    // @details Writes identifiers into the caller-provided buffer and returns the number written through count.
    // @param ids: Destination buffer for secure-stop identifiers.
    // @example ids: [1, 2, 3, 4]
    // @param idsLength: Capacity of ids in bytes.
    // @example idsLength: 4
    // @param count: Receives the number of identifiers returned.
    // @example count: 4
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, a CDMi error result.
    virtual CDMi_RESULT GetSecureStopIds(
        uint8_t ids[],
        uint16_t idsLength,
        uint32_t& count)
        = 0;

    // @brief Retrieves the serialized data for a secure stop.
    // @details Looks up a secure stop by session ID and returns its raw data in the supplied buffer.
    // @param sessionID: Identifier of the secure stop to retrieve.
    // @example sessionID: [1, 2, 3, 4]
    // @param sessionIDLength: Number of bytes in sessionID.
    // @example sessionIDLength: 4
    // @param rawData: Destination buffer for the serialized secure-stop data.
    // @example rawData: [0, 1, 2, 3]
    // @param rawSize: Input buffer capacity and output size of the returned data.
    // @example rawSize: 4
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, a CDMi error result such as CDMi_BUFFER_TOO_SMALL.
    virtual CDMi_RESULT GetSecureStop(
        const uint8_t sessionID[],
        uint32_t sessionIDLength,
        uint8_t* rawData,
        uint16_t& rawSize)
        = 0;

    // @brief Commits a secure-stop record using the server response.
    // @details Associates the supplied server response with the secure-stop session identified by sessionID.
    // @param sessionID: Identifier of the secure stop being committed.
    // @example sessionID: [1, 2, 3, 4]
    // @param sessionIDLength: Number of bytes in sessionID.
    // @example sessionIDLength: 4
    // @param serverResponse: Secure-stop response received from the server.
    // @example serverResponse: [5, 6, 7, 8]
    // @param serverResponseLength: Number of bytes in serverResponse.
    // @example serverResponseLength: 4
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, a CDMi error result.
    virtual CDMi_RESULT CommitSecureStop(
        const uint8_t sessionID[],
        uint32_t sessionIDLength,
        const uint8_t serverResponse[],
        uint32_t serverResponseLength)
        = 0;

    // @brief Deletes the DRM key store.
    // @details Requests removal of the key store maintained by this DRM implementation.
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, a CDMi error result.
    virtual CDMi_RESULT DeleteKeyStore() = 0;

    // @brief Deletes the DRM secure store.
    // @details Requests removal of the secure store maintained by this DRM implementation.
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, a CDMi error result.
    virtual CDMi_RESULT DeleteSecureStore() = 0;

    // @brief Retrieves the key store hash.
    // @details Returns a hash identifying the key store contents.
    // @param secureStoreHash: Output buffer that receives the key-store hash.
    // @example secureStoreHash: "keyStoreHashBuffer"
    // @param secureStoreHashLength: Length of the output buffer.
    // @example secureStoreHashLength: 32
    // @retval CDMi_RESULT: Status of the key-store hash retrieval operation.
    virtual CDMi_RESULT GetKeyStoreHash(
        uint8_t secureStoreHash[],
        uint32_t secureStoreHashLength)
        = 0;

    // @brief Retrieves the secure store hash.
    // @details Returns a hash identifying the secure-store contents.
    // @param secureStoreHash: Output buffer that receives the secure-store hash.
    // @example secureStoreHash: "secureStoreHashBuffer"
    // @param secureStoreHashLength: Length of the output buffer.
    // @example secureStoreHashLength: 32
    // @retval CDMi_RESULT: Status of the secure-store hash retrieval operation.
    virtual CDMi_RESULT GetSecureStoreHash(
        uint8_t secureStoreHash[],
        uint32_t secureStoreHashLength)
        = 0;
};

struct IMediaSystemMetrics {
    virtual ~IMediaSystemMetrics() = default;

    // @brief Gathers media system metrics.
    // @details Returns system-level metrics for the current DRM implementation in the supplied buffer.
    // @param bufferLength: Length of the metrics buffer on input, and number of bytes written on output.
    // @example bufferLength: 256
    // @param buffer: Output buffer receiving the system metrics data.
    // @example buffer: "metricsBuffer"
    // @retval CDMi_RESULT: Status of the metrics collection operation.
    virtual CDMi_RESULT Metrics (uint32_t& bufferLength, uint8_t buffer[]) const = 0;
};

struct IMediaSessionMetrics {
    virtual ~IMediaSessionMetrics() = default;

    // @brief Gathers media session metrics.
    // @details Returns session-level metrics for the current DRM session in the supplied buffer.
    // @param bufferLength: Length of the metrics buffer on input, and number of bytes written on output.
    // @example bufferLength: 256
    // @param buffer: Output buffer receiving the session metrics data.
    // @example buffer: "sessionMetricsBuffer"
    // @retval CDMi_RESULT: Status of the metrics collection operation.
    virtual CDMi_RESULT Metrics (uint32_t& bufferLength, uint8_t buffer[]) const = 0;
};

struct IGoogleCastAuthExtension {
    virtual ~IGoogleCastAuthExtension() = default;
   
    // @brief Signs a hash using the wrapped device key.
    // @details Produces a signature for the supplied hash using the device key material.
    // @param wrappedDeviceKey:Wrapped device key used to sign the hash.
    // @example wrappedDeviceKey: "wrappedDeviceKeyBuffer"
    // @param hash: Hash value to sign.
    // @example hash: "hashBuffer"
    // @param signature: Output signature buffer.
    // @example signature: "signatureBuffer"
    // @retval CDMi_RESULT: Status of the signing operation.
    virtual CDMi_RESULT SignHash(const std::string& wrappedDeviceKey, const std::string& hash, std::string& signature /* @out */) = 0;
    
    // @brief Generates a device key and certificate.
    // @details Produces a device key and certificate pair for device authentication.
    // @param wrappedDeviceKey: Output wrapped device key.
    // @example wrappedDeviceKey: "wrappedDeviceKeyBuffer"
    // @param deviceCertificate: Output device certificate.
    // @example deviceCertificate: "deviceCertificateBuffer"
    // @retval CDMi_RESULT: Status of the device key generation operation.
    virtual CDMi_RESULT GenDeviceKeyAndCert(std::string& wrappedDeviceKey /* @out */, std::string& deviceCertificate /* @out */) = 0;
    
    // @brief Returns the model certificate chain.
    // @details Provides the certificate chain associated with the DRM model.
    // @param certChain: Output certificate chain data.
    // @example certChain: "certChainBuffer"
    // @retval CDMi_RESULT: Status of the certificate-chain retrieval operation.
    virtual CDMi_RESULT GetModelCertChain(std::string& certChain /* @out */) const = 0;

    // @brief Returns the DRM system identifier.
    // @details Returns the platform system identifier used for authentication or entitlement checks.
    // @param id: Output system identifier.
    // @example id: 12345
    // @retval CDMi_RESULT: Status of the system identifier retrieval operation.
    virtual CDMi_RESULT GetSystemId(uint32_t& id /* @out */) const = 0;
};

// Optional batch (multi-sample) decryption. A standalone extension interface
struct IMediaKeySessionBatch {
    virtual ~IMediaKeySessionBatch() = default;

    // @brief Decrypts a batch of samples.
    // @details Decrypts multiple samples in one call using the supplied per-sample metadata and stream properties.
    // @param inData:Incoming encrypted data buffer.
    // @example inData: "encryptedDataBuffer"
    // @param inDataLength: Length of the incoming encrypted data buffer.
    // @example inDataLength: 1024
    // @param outData: Output buffer for decrypted data.
    // @example outData: "decryptedDataBuffer"
    // @param outDataLength: Length of the decrypted data buffer.
    // @example outDataLength: 1024
    // @param sampleInfo: Array of per-sample decrypt information.
    // @example sampleInfo: "sampleInfoArray"
    // @param sampleCount: Number of sample entries in the sampleInfo array.
    // @example sampleCount: 4
    // @param properties: Stream properties associated with the sample batch.
    // @example properties: "streamPropertiesBuffer"
    // @retval CDMi_RESULT: Status of the multi-sample decryption operation.
    virtual CDMi_RESULT DecryptMulti(
        uint8_t*                 inData,          // Incoming encrypted data
        const uint32_t           inDataLength,    // Incoming encrypted data length
        uint8_t**                outData,         // Outgoing decrypted data
        uint32_t*                outDataLength,   // Outgoing decrypted data length
        const SampleInfo*        sampleInfo,      // Array of per-sample decrypt information
        const uint16_t           sampleCount,     // Number of samples in sampleInfo
        const IStreamProperties* properties) = 0; // Stream Properties
};

struct IRobustnessExtension {
    virtual ~IRobustnessExtension() = default;

    // @brief Gets the supported robustness levels. 
    // @details Returns the list of robustness levels supported by the DRM implementation.
    // @param levels:Output list of supported robustness levels.
    // @example levels: ["SW_SECURE_CRYPTO", "HW_SECURE_CRYPTO"]
    // @retval CDMi_RESULT: Status of the robustness query operation.
    virtual CDMi_RESULT GetSupportedRobustness(std::list<std::string>& levels /* @out */) const = 0;
};

struct ISystemFactory {
    virtual ~ISystemFactory() = default;

    // @brief Gets the media-keys implementation instance.
    // @details Returns the factory-owned object used to create and manage key sessions.
    // @retval IMediaKeys*: Pointer to the factory-owned media-keys instance.
    virtual IMediaKeys* Instance() = 0;

    // @brief Gets the key-system identifier exposed by this factory.
    // @details The returned string identifies the DRM system handled by this factory.
    // @retval const char*: Key-system identifier.
    virtual const char* KeySystem() const = 0;

    // @brief Gets the MIME types supported by this factory.
    // @details Returns the factory-owned list of supported MIME type strings.
    // @retval const std::vector<std::string>&: Reference to the supported MIME type list.
    virtual const std::vector<std::string>& MimeTypes() const = 0;

    // @brief Initializes the system factory.
    // @details Initializes the key system factory and provides the plugin shell and configuration line used during startup.
    // @param shell: Plugin shell used to initialize the factory.
    // @example shell: "pluginShellInstance"
    // @param configline: Serialized configuration used during factory initialization.
    // @example configline: "key1=value1;key2=value2"
    virtual void Initialize(const WPEFramework::PluginHost::IShell * shell, const std::string& configline) = 0;

    // @brief Deinitializes the system factory.
    // @details Tears down the factory and releases any state created during initialization.
    // @param shell: Plugin shell used to deinitialize the factory.
    // @example shell: "pluginShellInstance"
    virtual void Deinitialize(const WPEFramework::PluginHost::IShell * shell) = 0;

    // @brief Enables the DRM key system.
    // @details Requests the factory's DRM implementation to become available for use.
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, a CDMi error result.
    virtual CDMi_RESULT Enable() = 0;

    // @brief Disables the DRM key system.
    // @details Requests the factory's DRM implementation to stop accepting operations.
    // @retval CDMi_RESULT: CDMi_SUCCESS on success; otherwise, a CDMi error result.
    virtual CDMi_RESULT Disable() = 0;
};

template <typename IMPLEMENTATION>
class SystemFactoryType : public ISystemFactory {
private:
    SystemFactoryType() = delete;
    SystemFactoryType(const SystemFactoryType<IMPLEMENTATION>&) = delete;
    SystemFactoryType<IMPLEMENTATION>& operator=(const SystemFactoryType<IMPLEMENTATION>&) = delete;

public:
    SystemFactoryType(const std::vector<std::string>& list)
        : _mimes(list)
        , _instance()
    {
    }
    ~SystemFactoryType() override = default;

public:
    IMediaKeys* Instance() override
    {
        return (&_instance);
    }
    const std::vector<std::string>& MimeTypes() const override
    {
        return (_mimes);
    }
    const char* KeySystem() const override
    {
        return (typeid(IMPLEMENTATION).name());
    }

    void Initialize(const WPEFramework::PluginHost::IShell * shell, const std::string& configline) override
    {
        Initialize(shell, configline, std::integral_constant<bool, HasOnShellAndSystemInitialize<IMPLEMENTATION>::Has>());
    }
    void Deinitialize(const WPEFramework::PluginHost::IShell * shell) override
    {
        Deinitialize(shell, std::integral_constant<bool, HasOnShellAndSystemDeinitialize<IMPLEMENTATION>::Has>());
    }

    CDMi_RESULT Enable() override
    {
        return (Enable(std::integral_constant<bool, HasEnable<IMPLEMENTATION>::Has>()));
    }
    CDMi_RESULT Disable() override
    {
        return (Disable (std::integral_constant<bool, HasDisable<IMPLEMENTATION>::Has>()));
    }

private:
    template <typename T>
    struct HasOnShellAndSystemInitialize {
        template <typename U, void (U::*)(const WPEFramework::PluginHost::IShell *, const std::string&)>
        struct SFINAE {
        };
        template <typename U>
        static uint8_t Test(SFINAE<U, &U::Initialize>*);
        template <typename U>
        static uint32_t Test(...);
        static const bool Has = sizeof(Test<T>(0)) == sizeof(uint8_t);
    };

    template <typename T>
    struct HasOnShellAndSystemDeinitialize {
        template <typename U, void (U::*)(const WPEFramework::PluginHost::IShell *)>
        struct SFINAE {
        };
        template <typename U>
        static uint8_t Test(SFINAE<U, &U::Deinitialize>*);
        template <typename U>
        static uint32_t Test(...);
        static const bool Has = sizeof(Test<T>(0)) == sizeof(uint8_t);
    };


    void Initialize(const WPEFramework::PluginHost::IShell * service, const std::string& configline, std::true_type) {
        _instance.Initialize(service, configline);
    }

    void Initialize(const WPEFramework::PluginHost::IShell *, const std::string&, std::false_type) {
    }

    void Deinitialize(const WPEFramework::PluginHost::IShell * service, std::true_type) {
        _instance.Deinitialize(service);
    }

    void Deinitialize(const WPEFramework::PluginHost::IShell *, std::false_type) {
    }

    template <typename T>
    struct HasEnable{
        template <typename U, CDMi_RESULT (U::*)()>
        struct SFINAE {
        };
        template <typename U>
        static uint8_t Test(SFINAE<U, &U::Enable>*);
        template <typename U>
        static uint32_t Test(...);
        static const bool Has = sizeof(Test<T>(0)) == sizeof(uint8_t);
    };

    CDMi_RESULT Enable(std::true_type) {
        return(_instance.Enable());
    }

    CDMi_RESULT Enable(std::false_type) {
        return(CDMi_KEYSYSTEM_NOT_SUPPORTED);
    }

    template <typename T>
    struct HasDisable{
        template <typename U, CDMi_RESULT (U::*)()>
        struct SFINAE {
        };
        template <typename U>
        static uint8_t Test(SFINAE<U, &U::Disable>*);
        template <typename U>
        static uint32_t Test(...);
        static const bool Has = sizeof(Test<T>(0)) == sizeof(uint8_t);
    };

    CDMi_RESULT Disable(std::true_type) {
        return(_instance.Enable());
    }

    CDMi_RESULT Disable(std::false_type) {
        return(CDMi_KEYSYSTEM_NOT_SUPPORTED);
    }

    const std::vector<std::string> _mimes;
    IMPLEMENTATION _instance;
};

} // namespace CDMi

#ifdef __cplusplus
extern "C" {
#endif

#ifndef EXTERNAL
#ifdef _MSVC_LANG
__declspec(dllexport) CDMi::ISystemFactory* GetSystemFactory();
#else
__attribute__ ((visibility ("default"))) CDMi::ISystemFactory* GetSystemFactory();
#endif
#else
EXTERNAL CDMi::ISystemFactory* GetSystemFactory();
#endif


#ifdef __cplusplus
}
#endif
