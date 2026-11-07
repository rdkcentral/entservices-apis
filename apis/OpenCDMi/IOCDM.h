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

enum OCDM_RESULT : uint32_t {
    OCDM_SUCCESS = 0,
    OCDM_S_FALSE = 1,
    OCDM_MORE_DATA_AVAILABLE = 2,
    OCDM_INTERFACE_NOT_IMPLEMENTED = 3,
    OCDM_BUFFER_TOO_SMALL = 4,
    OCDM_INVALID_ACCESSOR = 0x80000001,
    OCDM_KEYSYSTEM_NOT_SUPPORTED = 0x80000002,
    OCDM_INVALID_SESSION = 0x80000003,
    OCDM_INVALID_DECRYPT_BUFFER = 0x80000004,
    OCDM_OUT_OF_MEMORY = 0x80000005,
    OCDM_METHOD_NOT_IMPLEMENTED = 0x80000006,
    OCDM_FAIL = 0x80004005,
    OCDM_INVALID_ARG = 0x80070057,
    OCDM_SERVER_INTERNAL_ERROR = 0x8004C600,
    OCDM_SERVER_INVALID_MESSAGE = 0x8004C601,
    OCDM_SERVER_SERVICE_SPECIFIC = 0x8004C604,
    OCDM_BUSY_CANNOT_INITIALIZE = 0x8004DD00
};

// ISession defines the interface towards a DRM context that can decrypt data
// using a given key.
struct ISession : virtual public Core::IUnknown {
    enum KeyStatus : uint32_t {
        Usable = 0,
        Expired,
        Released,
        OutputRestricted,
        OutputRestrictedHDCP22,
        OutputDownscaled,
        StatusPending,
        InternalError,
        HWError
    };

    // ICallback defines the callback interface to receive
    // events originated from the session.
    struct ICallback : virtual public Core::IUnknown {
        enum { ID = ID_SESSION_CALLBACK };

        ~ICallback() override = default;

        // @brief Notifies the client that a key message has been created.
        // @details The message and optional URL can be sent to the license server to obtain or renew a license.
        // @param keyMessage: Generated key-message bytes.
        // @example keyMessage: "keyMessageBuffer"
        // @param keyLength: Number of bytes in keyMessage.
        // @example keyLength: 128
        // @param URL: Optional URL associated with the key message.
        // @example URL: "https://license.example.com"
        virtual void OnKeyMessage(const uint8_t* keyMessage /* @length:keyLength */, //__in_bcount(f_cbKeyMessage)
            const uint16_t keyLength, //__in
            const std::string& URL) = 0; //__in_z_opt

        // @brief Notifies the client that the session encountered an error.
        // @details Reports the session error, corresponding system result, and a human-readable message.
        // @param error: Session-specific error code.
        // @example error: -1
        // @param sysError: System or OCDM error result.
        // @example sysError: OCDM_FAIL
        // @param errorMessage: Description of the error.
        // @example errorMessage: "License request failed"
        virtual void OnError(const int16_t error, const OCDM_RESULT sysError, const std::string& errorMessage) = 0;

        // @brief Notifies the client that a key status has changed.
        // @details Associates the reported status with the specified key identifier.
        // @param keyID: Identifier of the key whose status changed.
        // @example keyID: "keyIdBuffer"
        // @param keyIDLength: Number of bytes in keyID.
        // @example keyIDLength: 16
        // @param status: Updated status of the key.
        // @example status: ISession::Usable
        virtual void OnKeyStatusUpdate(const uint8_t keyID[] /* @length:keyIDLength */,
                                       const uint8_t keyIDLength,
                                       const ISession::KeyStatus status) = 0;

        // @brief Notifies the client that key-status updates are complete.
        // @details Signals completion after the session has delivered its pending key-status changes.
        // @retval void: No value is returned; the callback reports completion.
        virtual void OnKeyStatusesUpdated() const = 0;
    };

    enum { ID = ID_SESSION };

    ~ISession(void) override = default;

    // @brief Loads persisted data for this session into the CDM.
    // @details Restores session state so that previously stored licenses and keys can be used.
    // @retval OCDM_RESULT: OCDM_SUCCESS when the session is loaded; otherwise an OCDM error result.
    virtual OCDM_RESULT Load() = 0;

    // @brief Applies a key-message response to the session.
    // @details Passes the license-server response to the CDM to update the session's license and key state.
    // @param keyMessage: Key-message response bytes.
    // @example keyMessage: "licenseResponseBuffer"
    // @param keyLength: Number of bytes in keyMessage.
    // @example keyLength: 256
    virtual void
    Update(const uint8_t* keyMessage /* @length:keyLength */, //__in_bcount(f_cbKeyMessageResponse)
        const uint16_t keyLength)
        = 0; //__in

    // @brief Removes licenses and keys associated with this session.
    // @details Requests deletion of the session's license and key material from the CDM.
    // @retval OCDM_RESULT: OCDM_SUCCESS when removal succeeds; otherwise an OCDM error result.
    virtual OCDM_RESULT Remove() = 0;

    // @brief Retrieves key-system-specific metadata for this session.
    // @details Returns metadata maintained by the CDM for the active session.
    // @retval std::string: Session metadata, or an empty string when no metadata is available.
    virtual std::string Metadata() const = 0;

    // @brief Retrieves key-system-specific metrics for this session.
    // @details Writes metric data into the caller-provided buffer and updates its size as required.
    // @param bufferSize: On input, buffer capacity; on output, bytes written or required.
    // @example bufferSize: 1024
    // @param buffer: Output buffer receiving the metric data.
    // @example buffer: "metricsBuffer"
    // @retval OCDM_RESULT: OCDM_SUCCESS when metrics are retrieved; otherwise an OCDM error result, including OCDM_BUFFER_TOO_SMALL when applicable.
    virtual OCDM_RESULT Metricdata(
        uint32_t& bufferSize /* @inout */,
        uint8_t buffer[] /* @out @length:bufferSize */) const
        = 0;

    // @brief Retrieves the current key-exchange status of the session.
    // @details Reports the aggregate session status without selecting a particular key.
    // @retval KeyStatus: Current session key status.
    virtual KeyStatus Status() const = 0;

    // @brief Retrieves the status of a specific key in the session.
    // @details Looks up the status associated with the supplied key identifier.
    // @param keyID: Identifier of the key to query.
    // @example keyID: "keyIdBuffer"
    // @param keyIDLength: Number of bytes in keyID.
    // @example keyIDLength: 16
    // @retval KeyStatus: Status of the requested key.
    virtual KeyStatus Status(const uint8_t keyID[] /* @length:keyIDLength */, const uint8_t keyIDLength) const = 0;

    // @brief Creates the shared decryption buffer for the session.
    // @details Creates the buffer on demand and returns its identifier to the caller.
    // @param bufferID: Receives the identifier of the created buffer.
    // @example bufferID: "sessionBuffer"
    // @retval OCDM_RESULT: OCDM_SUCCESS when the buffer is created; otherwise an OCDM error result.
    virtual OCDM_RESULT CreateSessionBuffer(string& bufferID /* @out */ ) = 0;

    // @brief Retrieves the shared-memory buffer name for encrypted fragments.
    // @details The returned identifier can be used to locate the session's decryption buffer.
    // @retval std::string: Shared-memory buffer identifier.
    virtual std::string BufferId() const = 0;

    // @brief Retrieves the identifier of this session.
    // @details Returns the session identifier assigned by the CDM.
    // @retval std::string: Session identifier.
    virtual std::string SessionId() const = 0;

    // @brief Closes this session.
    // @details Indicates that the client is finished with the session and allows the CDM to release its resources.
    virtual void Close() = 0;

    // @brief Resets output protection for the session.
    // @details Informs the CDM that playback has stopped so it can disable session output protection as appropriate.
    virtual void ResetOutputProtection() = 0;

    // @brief Sets a named parameter in the CDM.
    // @details Stores a key-system-specific name and value pair for this session.
    // @param name: Parameter name.
    // @example name: "playbackMode"
    // @param value: Parameter value.
    // @example value: "streaming"
    virtual void SetParameter(const std::string& name, const std::string& value) = 0;

    // @brief Detaches the session callback.
    // @details Revokes the callback previously associated with this session, allowing the client to stop receiving events.
    // @param callback: Callback interface to revoke.
    // @example callback: "sessionCallback"
    virtual void Revoke(ISession::ICallback* callback) = 0;
};

struct ISessionExt : virtual public Core::IUnknown {
    enum { ID = ID_SESSION_EXTENSION };

    enum LicenseTypeExt { Invalid = 0,
        LimitedDuration,
        Standard };

    enum SessionStateExt {
        LicenseAcquisitionState = 0,
        InactiveDecryptionState,
        ActiveDecryptionState,
        InvalidState
    };

    // @brief Retrieves the numeric identifier of the extended session.
    // @details Returns the implementation-specific session identifier.
    // @retval uint32_t: Numeric session identifier.
    virtual uint32_t SessionIdExt() const = 0;

    // @brief Retrieves the shared-memory buffer name for encrypted fragments.
    // @details Returns the extended session's buffer identifier.
    // @retval std::string: Shared-memory buffer identifier.
    virtual std::string BufferIdExt() const = 0;

    // @brief Sets the DRM header for the session.
    // @details Supplies header bytes used by the key system during license or challenge processing.
    // @param drmHeader: DRM header bytes.
    // @example drmHeader: "drmHeaderBuffer"
    // @param drmHeaderLength: Number of bytes in drmHeader.
    // @example drmHeaderLength: 128
    // @retval OCDM_RESULT: OCDM_SUCCESS when the header is accepted; otherwise an OCDM error result.
    virtual OCDM_RESULT SetDrmHeader(const uint8_t drmHeader[] /* @length:drmHeaderLength */,
        uint16_t drmHeaderLength)
        = 0;

    // @brief Retrieves challenge data for the extended session.
    // @details Writes challenge bytes into the supplied buffer and supports low-delay license acquisition.
    // @param challenge: Buffer that receives challenge data.
    // @example challenge: "challengeBuffer"
    // @param challengeSize: On input, buffer capacity; on output, challenge size or required size.
    // @example challengeSize: 512
    // @param isLDL: Nonzero to request a low-delay license challenge; zero otherwise.
    // @example isLDL: 1
    // @retval OCDM_RESULT: OCDM_SUCCESS when challenge data is retrieved; otherwise an OCDM error result.
    virtual OCDM_RESULT GetChallengeDataExt(uint8_t* challenge /* @inout @length:challengeSize */,
        uint16_t& challengeSize /* @inout */,
        uint32_t isLDL)
        = 0;

    // @brief Cancels pending challenge-data generation.
    // @details Requests cancellation of an outstanding extended challenge operation.
    // @retval OCDM_RESULT: OCDM_SUCCESS when cancellation succeeds; otherwise an OCDM error result.
    virtual OCDM_RESULT CancelChallengeDataExt() = 0;

    // @brief Stores license data for the extended session.
    // @details Persists the supplied license data and optionally writes a secure-stop identifier.
    // @param licenseData: License data bytes.
    // @example licenseData: "licenseDataBuffer"
    // @param licenseDataSize: Number of bytes in licenseData.
    // @example licenseDataSize: 512
    // @param secureStopId: Output buffer receiving the 16-byte secure-stop identifier.
    // @example secureStopId: "secureStopIdBuffer"
    // @retval OCDM_RESULT: OCDM_SUCCESS when license data is stored; otherwise an OCDM error result.
    virtual OCDM_RESULT StoreLicenseData(const uint8_t licenseData[] /* @length:licenseDataSize */,
        uint16_t licenseDataSize,
        uint8_t* secureStopId /* @out @length:16 */)
        = 0;

    // @brief Selects the key identifier used by the session.
    // @details Associates the supplied key ID with subsequent session decryption operations.
    // @param keyLength: Number of bytes in keyId.
    // @example keyLength: 16
    // @param keyId: Key identifier bytes.
    // @example keyId: "keyIdBuffer"
    // @retval OCDM_RESULT: OCDM_SUCCESS when the key ID is selected; otherwise an OCDM error result.
    virtual OCDM_RESULT SelectKeyId(const uint8_t keyLength,
        const uint8_t keyId[] /* @length:keyLength */)
        = 0;
    // @brief Clears the session's decryption context.
    // @details Removes transient state maintained for decryption in this session.
    // @retval OCDM_RESULT: OCDM_SUCCESS when the context is cleared; otherwise an OCDM error result.
    virtual OCDM_RESULT CleanDecryptContext() = 0;
};

struct IAccessorOCDM : virtual public Core::IUnknown {

    enum { ID = ID_ACCESSOROCDM };

    ~IAccessorOCDM() override = default;

    // @brief Checks whether a key system supports the requested media type.
    // @details Queries the accessor's configured DRM implementations for the key-system and MIME-type combination.
    // @param keySystem: Key-system identifier to check.
    // @example keySystem: "com.example.drm"
    // @param mimeType: Media MIME type to check.
    // @example mimeType: "video/mp4"
    // @retval bool: True when the combination is supported; otherwise false.
    virtual bool IsTypeSupported(const std::string& keySystem,
        const std::string& mimeType) const = 0;

    // @brief Retrieves metadata for a key system.
    // @details Writes key-system-specific metadata to the output string.
    // @param keySystem: Key-system identifier whose metadata is requested.
    // @example keySystem: "com.example.drm"
    // @param metadata: Receives the returned metadata.
    // @example metadata: "drmMetadata"
    // @retval OCDM_RESULT: OCDM_SUCCESS when metadata is retrieved; otherwise an OCDM error result.
    virtual OCDM_RESULT Metadata(const std::string& keySystem, std::string& metadata /* @out */) const = 0;

    // FairPlay-specific accessor operations.

    // @brief Creates a FairPlay movie session.
    // @details Initializes a movie session using a certificate and supported-version list.
    // @param keySystem: Key-system identifier.
    // @example keySystem: "com.apple.fps"
    // @param version: FairPlay interface version.
    // @example version: 1
    // @param cert: Certificate bytes.
    // @example cert: "certificateBuffer"
    // @param certificateLength: Number of bytes in cert.
    // @example certificateLength: 256
    // @param versionlist: Supported FairPlay version-list bytes.
    // @example versionlist: "versionListBuffer"
    // @param versionListSize: Number of bytes in versionlist.
    // @example versionListSize: 8
    // @param movieIdOut: Output buffer receiving the movie identifier.
    // @example movieIdOut: "movieIdBuffer"
    // @param movieIdSize: Capacity of movieIdOut in bytes.
    // @example movieIdSize: 8
    // @retval OCDM_RESULT: OCDM_SUCCESS when the movie session is created; otherwise an OCDM error result.
    virtual OCDM_RESULT CreateMovieSession(const string& keySystem, uint32_t version, const uint8_t* cert /* @in @length:certificateLength */, uint32_t certificateLength, const uint8_t* versionlist /* @in @length:versionListSize */, uint32_t versionListSize, uint8_t* movieIdOut /* @out @length:movieIdSize */, uint32_t movieIdSize) const = 0;

    // @brief Destroys a FairPlay movie session.
    // @details Releases resources associated with the specified movie session.
    // @param keySystem: Key-system identifier.
    // @example keySystem: "com.apple.fps"
    // @param version: FairPlay interface version.
    // @example version: 1
    // @param movieId: Identifier of the movie session to destroy.
    // @example movieId: 12345
    // @retval OCDM_RESULT: OCDM_SUCCESS when the movie session is destroyed; otherwise an OCDM error result.
    virtual OCDM_RESULT DestroyMovieSession(const string& keySystem, uint32_t version, uint64_t movieId) const = 0;

    // @brief Generates a FairPlay license challenge using a version list.
    // @details Combines asset, version-list, streamer-challenge, and cryptor data to produce challenge and session outputs.
    // @param keySystem: Key-system identifier.
    // @example keySystem: "com.apple.fps"
    // @param version: FairPlay interface version.
    // @example version: 1
    // @param movieId: Identifier of the movie session.
    // @example movieId: 12345
    // @param assetidData: Asset identifier bytes.
    // @example assetidData: "assetIdBuffer"
    // @param assetidSize: Number of bytes in assetidData.
    // @example assetidSize: 16
    // @param versionlist: Supported FairPlay version-list bytes.
    // @example versionlist: "versionListBuffer"
    // @param versionListSize: Number of bytes in versionlist.
    // @example versionListSize: 8
    // @param streamerChallengeData: Streamer-provided challenge bytes.
    // @example streamerChallengeData: "streamerChallengeBuffer"
    // @param streamerChallengeSize: Number of bytes in streamerChallengeData.
    // @example streamerChallengeSize: 128
    // @param cryptorId: Identifier of the cryptor associated with the operation.
    // @example cryptorId: 98765
    // @param licenseChallengeBuffer: Output buffer receiving the license challenge.
    // @example licenseChallengeBuffer: "licenseChallengeBuffer"
    // @param licenseChallengeMaxSize: Capacity of licenseChallengeBuffer.
    // @example licenseChallengeMaxSize: 1024
    // @param licenseSize: Output value receiving the generated license size.
    // @example licenseSize: 512
    // @param license_bytes: Capacity of the license-size output buffer.
    // @example license_bytes: 4
    // @param session: Output buffer receiving server-exchange session data.
    // @example session: "serverExchangeSessionBuffer"
    // @param session_bytes: Capacity of the session output buffer.
    // @example session_bytes: 512
    // @retval OCDM_RESULT: OCDM_SUCCESS when the challenge is generated; otherwise an OCDM error result.
    virtual OCDM_RESULT GenerateChallengeWithVersionList(const string& keySystem, uint32_t version, uint64_t movieId, const uint8_t* assetidData /* @in @length:assetidSize */, uint32_t assetidSize,  const uint8_t* versionlist /* @in @length:versionListSize */, uint32_t versionListSize,
         const uint8_t* streamerChallengeData /* @in @length:streamerChallengeSize */, uint32_t streamerChallengeSize,
         uint64_t cryptorId, uint8_t* licenseChallengeBuffer /* @out @length:licenseChallengeMaxSize */, uint32_t licenseChallengeMaxSize, uint8_t *licenseSize /* @out @length:license_bytes */, uint32_t license_bytes, uint8_t *session /* @out @length:session_bytes */, uint32_t session_bytes) const = 0;

    // @brief Destroys a FairPlay server exchange.
    // @details Releases the server-exchange state represented by the supplied session data.
    // @param keySystem: Key-system identifier.
    // @example keySystem: "com.apple.fps"
    // @param version: FairPlay interface version.
    // @example version: 1
    // @param session: Server-exchange session data.
    // @example session: "serverExchangeSessionBuffer"
    // @param session_bytes: Number of bytes in session.
    // @example session_bytes: 512
    // @retval OCDM_RESULT: OCDM_SUCCESS when the exchange is destroyed; otherwise an OCDM error result.
    virtual OCDM_RESULT DestroyServerExchange(const string& keySystem, uint32_t version, uint8_t* session /* @in @length:session_bytes */, uint32_t session_bytes) const = 0;

    // @brief Initializes a key-system library.
    // @details Ensures the requested FairPlay/key-system implementation is initialized before use.
    // @param keySystem: Key-system identifier to initialize.
    // @example keySystem: "com.apple.fps"
    // @retval OCDM_RESULT: OCDM_SUCCESS when initialization succeeds; otherwise an OCDM error result.
    virtual OCDM_RESULT InitLibrary(const string& keySystem) const = 0;

    // @brief Processes FairPlay license data.
    // @details Applies license response data to a server exchange and writes the resulting cryptor identifier.
    // @param keySystem: Key-system identifier.
    // @example keySystem: "com.apple.fps"
    // @param version: FairPlay interface version.
    // @example version: 1
    // @param session: Server-exchange session data.
    // @example session: "serverExchangeSessionBuffer"
    // @param session_bytes: Number of bytes in session.
    // @example session_bytes: 512
    // @param licenseData: License response bytes.
    // @example licenseData: "licenseDataBuffer"
    // @param licenseDataSize: Number of bytes in licenseData.
    // @example licenseDataSize: 512
    // @param cryptoId: Input/output cryptor identifier buffer.
    // @example cryptoId: "cryptorIdBuffer"
    // @param cryptoId_bytes: Number of bytes available in cryptoId.
    // @example cryptoId_bytes: 8
    // @retval OCDM_RESULT: OCDM_SUCCESS when the license is processed; otherwise an OCDM error result.
    virtual OCDM_RESULT ProcessLicense(const string& keySystem, uint32_t version, uint8_t* session /* @in @length:session_bytes */, uint32_t session_bytes, const uint8_t* licenseData /* @in @length:licenseDataSize */, uint32_t licenseDataSize, uint8_t *cryptoId /* @inout @length:cryptoId_bytes */, uint32_t cryptoId_bytes) const = 0;

    // @brief Destroys a FairPlay cryptor.
    // @details Releases the cryptor identified by cryptoId for the specified key system.
    // @param keySystem: Key-system identifier.
    // @example keySystem: "com.apple.fps"
    // @param version: FairPlay interface version.
    // @example version: 1
    // @param cryptoId: Identifier of the cryptor to destroy.
    // @example cryptoId: 98765
    // @retval OCDM_RESULT: OCDM_SUCCESS when the cryptor is destroyed; otherwise an OCDM error result.
    virtual OCDM_RESULT DestroyCryptor(const string& keySystem, uint32_t version, uint64_t cryptoId) const = 0;

    // @brief Retrieves key-system-specific metrics.
    // @details Writes metric data into the caller-provided buffer and updates its size as required.
    // @param keySystem: Key-system identifier whose metrics are requested.
    // @example keySystem: "com.example.drm"
    // @param bufferSize: On input, buffer capacity; on output, bytes written or required.
    // @example bufferSize: 1024
    // @param buffer: Output buffer receiving the metric data.
    // @example buffer: "metricsBuffer"
    // @retval OCDM_RESULT: OCDM_SUCCESS when metrics are retrieved; otherwise an OCDM error result, including OCDM_BUFFER_TOO_SMALL when applicable.
    virtual OCDM_RESULT Metricdata(
        const std::string& keySystem,
        uint32_t& bufferSize /* @inout */,
        uint8_t buffer[] /* @out @length:bufferSize */) const
        = 0;

    // @brief Retrieves supported robustness levels for a key system.
    // @details Returns the robustness strings through a framework string iterator.
    // @param keySystem: Key-system identifier to query.
    // @example keySystem: "com.example.drm"
    // @param robustness: Receives an iterator over supported robustness levels.
    // @example robustness: "robustnessIterator"
    // @retval OCDM_RESULT: OCDM_SUCCESS when the levels are retrieved; otherwise an OCDM error result.
    virtual OCDM_RESULT GetSupportedRobustness(
        const std::string& keySystem,
        RPC::IStringIterator*& robustness /* @out */) const = 0;

    // @brief Creates a media-key session.
    // @details Creates a session for the requested key system using initialization data, optional CDM data, and a callback.
    // @param keySystem: Key-system identifier for the session.
    // @example keySystem: "com.example.drm"
    // @param licenseType: Requested license type.
    // @example licenseType: 1
    // @param initDataType: Format of the initialization data.
    // @example initDataType: "cenc"
    // @param initData: Initialization data bytes.
    // @example initData: "initDataBuffer"
    // @param initDataLength: Number of bytes in initData.
    // @example initDataLength: 128
    // @param CDMData: Optional CDM-specific data bytes.
    // @example CDMData: "cdmDataBuffer"
    // @param CDMDataLength: Number of bytes in CDMData.
    // @example CDMDataLength: 256
    // @param callback: Callback used to receive session events.
    // @example callback: "sessionCallback"
    // @param sessionId: Receives the created session identifier.
    // @example sessionId: "session-123"
    // @param session: Receives the created session interface.
    // @example session: "sessionInterface"
    // @retval OCDM_RESULT: OCDM_SUCCESS when the session is created; otherwise an OCDM error result.
    virtual OCDM_RESULT
    CreateSession(const string& keySystem, const int32_t licenseType,
        const std::string& initDataType, const uint8_t* initData /* @length:initDataLength */,
        const uint16_t initDataLength, const uint8_t* CDMData /* @length:CDMDataLength */,
        const uint16_t CDMDataLength, ISession::ICallback* callback,
        std::string& sessionId /* @out */, ISession*& session /* @out */)
        = 0;

    // @brief Sets the server certificate for a key system.
    // @details Supplies the certificate used to authenticate or secure communication with the license server.
    // @param keySystem: Key-system identifier.
    // @example keySystem: "com.example.drm"
    // @param serverCertificate: Server certificate bytes.
    // @example serverCertificate: "serverCertificateBuffer"
    // @param serverCertificateLength: Number of bytes in serverCertificate.
    // @example serverCertificateLength: 512
    // @retval OCDM_RESULT: OCDM_SUCCESS when the certificate is accepted; otherwise an OCDM error result.
    virtual OCDM_RESULT
    SetServerCertificate(const string& keySystem, const uint8_t* serverCertificate /* @length:serverCertificateLength */,
        const uint16_t serverCertificateLength)
        = 0;

    // @brief Retrieves the current time reported by a DRM system.
    // @details Queries the selected key-system implementation for its system-time value.
    // @param keySystem: Key-system identifier to query.
    // @example keySystem: "com.example.drm"
    // @retval uint64_t: DRM system time, in the units defined by the implementation.
    virtual uint64_t GetDrmSystemTime(const std::string& keySystem) const = 0;

    // @brief Retrieves the extended version string of a DRM implementation.
    // @details Returns the version exposed by the selected key system's extension.
    // @param keySystem: Key-system identifier to query.
    // @example keySystem: "com.example.drm"
    // @retval std::string: Extended DRM implementation version.
    virtual std::string GetVersionExt(const std::string& keySystem) const = 0;

    // @brief Retrieves the low-delay-license session limit.
    // @details Queries the maximum number of low-delay-license sessions supported by the key system.
    // @param keySystem: Key-system identifier to query.
    // @example keySystem: "com.example.drm"
    // @retval uint32_t: Maximum low-delay-license session count.
    virtual uint32_t GetLdlSessionLimit(const std::string& keySystem) const = 0;

    // @brief Checks whether secure-stop support is enabled.
    // @details Reports the secure-stop configuration for the selected key system.
    // @param keySystem: Key-system identifier to query.
    // @example keySystem: "com.example.drm"
    // @retval bool: True when secure stop is enabled; otherwise false.
    virtual bool IsSecureStopEnabled(const std::string& keySystem) = 0;

    // @brief Enables or disables secure-stop support.
    // @details Applies the requested secure-stop setting for the selected key system.
    // @param keySystem: Key-system identifier to configure.
    // @example keySystem: "com.example.drm"
    // @param enable: True to enable secure stop; false to disable it.
    // @example enable: true
    // @retval OCDM_RESULT: OCDM_SUCCESS when the setting is applied; otherwise an OCDM error result.
    virtual OCDM_RESULT EnableSecureStop(const std::string& keySystem,
        bool enable)
        = 0;

    // @brief Resets secure-stop records for a key system.
    // @details Clears the secure-stop records maintained by the selected key system.
    // @param keySystem: Key-system identifier whose records are reset.
    // @example keySystem: "com.example.drm"
    // @retval uint32_t: Number of secure-stop records reset.
    virtual uint32_t ResetSecureStops(const std::string& keySystem) = 0;

    // @brief Retrieves secure-stop identifiers.
    // @details Copies available secure-stop IDs into the supplied array and updates the returned count.
    // @param keySystem: Key-system identifier to query.
    // @example keySystem: "com.example.drm"
    // @param ids: Output array receiving secure-stop identifiers.
    // @example ids: "secureStopIdsBuffer"
    // @param idsLength: Capacity of ids in bytes.
    // @example idsLength: 256
    // @param count: On input, available array capacity; on output, number of identifiers returned or required.
    // @example count: 16
    // @retval OCDM_RESULT: OCDM_SUCCESS when IDs are retrieved; otherwise an OCDM error result.
    virtual OCDM_RESULT GetSecureStopIds(const std::string& keySystem,
        uint8_t ids[] /* @out @length:idsLength */, uint16_t idsLength,
        uint32_t& count /* @inout */)
        = 0;

    // @brief Retrieves the stored data for a secure stop.
    // @details Copies the secure-stop record associated with sessionID into rawData.
    // @param keySystem: Key-system identifier.
    // @example keySystem: "com.example.drm"
    // @param sessionID: Identifier of the secure-stop session.
    // @example sessionID: "secureStopIdBuffer"
    // @param sessionIDLength: Number of bytes in sessionID.
    // @example sessionIDLength: 16
    // @param rawData: Output buffer receiving the secure-stop data.
    // @example rawData: "secureStopDataBuffer"
    // @param rawSize: On input, output-buffer capacity; on output, data size or required size.
    // @example rawSize: 1024
    // @retval OCDM_RESULT: OCDM_SUCCESS when the data is retrieved; otherwise an OCDM error result.
    virtual OCDM_RESULT GetSecureStop(const std::string& keySystem,
        const uint8_t sessionID[] /* @length:sessionIDLength */,
        uint16_t sessionIDLength, uint8_t* rawData /* @out @length:rawSize */,
        uint16_t& rawSize /* @inout */)
        = 0;

    // @brief Commits a secure-stop record using a server response.
    // @details Passes the license-server response to the key system to finalize the secure-stop transaction.
    // @param keySystem: Key-system identifier.
    // @example keySystem: "com.example.drm"
    // @param sessionID: Identifier of the secure-stop session.
    // @example sessionID: "secureStopIdBuffer"
    // @param sessionIDLength: Number of bytes in sessionID.
    // @example sessionIDLength: 16
    // @param serverResponse: Server response bytes for the secure-stop transaction.
    // @example serverResponse: "serverResponseBuffer"
    // @param serverResponseLength: Number of bytes in serverResponse.
    // @example serverResponseLength: 256
    // @retval OCDM_RESULT: OCDM_SUCCESS when the secure stop is committed; otherwise an OCDM error result.
    virtual OCDM_RESULT CommitSecureStop(const std::string& keySystem,
        const uint8_t sessionID[] /* @length:sessionIDLength */,
        uint16_t sessionIDLength,
        const uint8_t serverResponse[] /* @length:serverResponseLength */,
        uint16_t serverResponseLength)
        = 0;

    // @brief Deletes the key store for a key system.
    // @details Requests removal of the persistent key-store data associated with the key system.
    // @param keySystem: Key-system identifier whose key store is deleted.
    // @example keySystem: "com.example.drm"
    // @retval OCDM_RESULT: OCDM_SUCCESS when the key store is deleted; otherwise an OCDM error result.
    virtual OCDM_RESULT DeleteKeyStore(const std::string& keySystem) = 0;

    // @brief Deletes the secure store for a key system.
    // @details Requests removal of the persistent secure-store data associated with the key system.
    // @param keySystem: Key-system identifier whose secure store is deleted.
    // @example keySystem: "com.example.drm"
    // @retval OCDM_RESULT: OCDM_SUCCESS when the secure store is deleted; otherwise an OCDM error result.
    virtual OCDM_RESULT DeleteSecureStore(const std::string& keySystem) = 0;

    // @brief Retrieves the key-store hash.
    // @details Writes the hash of the selected key system's key store to the caller-provided buffer.
    // @param keySystem: Key-system identifier.
    // @example keySystem: "com.example.drm"
    // @param keyStoreHash: Output buffer receiving the hash.
    // @example keyStoreHash: "keyStoreHashBuffer"
    // @param keyStoreHashLength: Capacity of keyStoreHash in bytes.
    // @example keyStoreHashLength: 32
    // @retval OCDM_RESULT: OCDM_SUCCESS when the hash is retrieved; otherwise an OCDM error result.
    virtual OCDM_RESULT GetKeyStoreHash(const std::string& keySystem,
        uint8_t keyStoreHash[] /* @out @length:keyStoreHashLength */,
        uint16_t keyStoreHashLength)
        = 0;

    // @brief Retrieves the secure-store hash.
    // @details Writes the hash of the selected key system's secure store to the caller-provided buffer.
    // @param keySystem: Key-system identifier.
    // @example keySystem: "com.example.drm"
    // @param secureStoreHash: Output buffer receiving the hash.
    // @example secureStoreHash: "secureStoreHashBuffer"
    // @param secureStoreHashLength: Capacity of secureStoreHash in bytes.
    // @example secureStoreHashLength: 32
    // @retval OCDM_RESULT: OCDM_SUCCESS when the hash is retrieved; otherwise an OCDM error result.
    virtual OCDM_RESULT GetSecureStoreHash(const std::string& keySystem,
        uint8_t secureStoreHash[] /* @out @length:secureStoreHashLength */,
        uint16_t secureStoreHashLength)
        = 0;
};

class EXTERNAL KeyId {
public:
    static constexpr uint8_t KEY_LENGTH = 16;

    inline KeyId()
        : _status(ISession::StatusPending)
    {
        ::memset(_kid, ~0, sizeof(_kid));
    }
    inline KeyId(const uint8_t kid[], const uint8_t length)
        : _status(ISession::StatusPending)
    {
        uint8_t copyLength(length > sizeof(_kid) ? sizeof(_kid) : length);

        ::memcpy(_kid, kid, copyLength);

        if (copyLength < sizeof(_kid)) {
            ::memset(&(_kid[copyLength]), 0, sizeof(_kid) - copyLength);
        }
    }
    // Microsoft playready XML flavor retrieval of KID
    inline KeyId(const uint32_t a, const uint16_t b, const uint16_t c, const uint8_t d[])
        : _status(ISession::StatusPending)
    {
        // A bit confused on how the mapping of the Microsoft KeyId's should go, looking at the spec:
        // https://msdn.microsoft.com/nl-nl/library/windows/desktop/aa379358(v=vs.85).aspx
        // Some test cases have a little endian byte ordering for the GUID, other a MSB ordering.
        _kid[0] = a & 0xFF;
        _kid[1] = (a >> 8) & 0xFF;
        _kid[2] = (a >> 16) & 0xFF;
        _kid[3] = (a >> 24) & 0xFF;
        _kid[4] = b & 0xFF;
        _kid[5] = (b >> 8) & 0xFF;
        _kid[6] = c & 0xFF;
        _kid[7] = (c >> 8) & 0xFF;

        ::memcpy(&(_kid[8]), d, 8);
    }
    inline KeyId(const KeyId& copy)
        : _status(copy._status)
    {
        ::memcpy(_kid, copy._kid, sizeof(_kid));
    }
    ~KeyId() = default;

    inline KeyId& operator=(const KeyId& rhs)
    {
        _status = rhs._status;
        ::memcpy(_kid, rhs._kid, sizeof(_kid));
        return (*this);
    }

public:
    inline bool IsValid() const
    {
        const KeyId InvalidKey;
        return (operator!=(InvalidKey));
    }
    inline bool operator==(const uint8_t rhs[]) const
    {
        // Hack, in case of PlayReady, the key offered on the interface might be
        // ordered incorrectly, cater for this situation, by silenty comparing with this incorrect value.
        bool equal = false;

        // Regardless of the order, the last 8 bytes should be equal
        if (memcmp(&_kid[8], &(rhs[8]), 8) == 0) {

            // Lets first try the non swapped byte order.
            if (memcmp(_kid, rhs, 8) == 0) {
                // this is a match :-)
                equal = true;
            } else {
                // Let do the byte order alignment as suggested in the spec and see if it matches than :-)
                // https://msdn.microsoft.com/nl-nl/library/windows/desktop/aa379358(v=vs.85).aspx
                uint8_t alignedBuffer[8];
                alignedBuffer[0] = rhs[3];
                alignedBuffer[1] = rhs[2];
                alignedBuffer[2] = rhs[1];
                alignedBuffer[3] = rhs[0];
                alignedBuffer[4] = rhs[5];
                alignedBuffer[5] = rhs[4];
                alignedBuffer[6] = rhs[7];
                alignedBuffer[7] = rhs[6];
                equal = (memcmp(_kid, alignedBuffer, 8) == 0);
            }
        }
        return (equal);
    }    
    inline bool operator!=(const uint8_t rhs[]) const
    {
        return !(operator==(rhs));
    }
    inline bool operator==(const KeyId& rhs) const
    {
        return (operator==(rhs._kid));
    }
    inline bool operator!=(const KeyId& rhs) const
    {
        return !(operator==(rhs));
    }
    inline const uint8_t* Id() const
    {
        return (_kid);
    }
    inline static uint8_t Length()
    {
        return (KEY_LENGTH);
    }
    inline string ToString() const
    {
        const uint8_t HexArray[] = "0123456789ABCDEF";

        string result;
        for (uint8_t teller = 0; teller < sizeof(_kid); teller++) {
            result += HexArray[(_kid[teller] >> 4) & 0x0f];
            result += HexArray[_kid[teller] & 0x0f];
        }
        return (result);
    }
    void Status(ISession::KeyStatus status)
    {
        _status = status;
    }
    ISession::KeyStatus Status() const
    {
        return (_status);
    }

private:
    uint8_t _kid[KEY_LENGTH];
    ISession::KeyStatus _status;
};

struct EXTERNAL IGoogleCastAuthExtension : virtual public Core::IUnknown {
    enum { ID = ID_GOOGLE_CAST_AUTH_EXTENSION };

    virtual ~IGoogleCastAuthExtension() override = default;

    // @brief Signs a hash using the wrapped device key.
    // @details Uses the device key material to produce a signature for the supplied hash.
    // @param wrappedDeviceKey: Wrapped device-key data used for signing.
    // @example wrappedDeviceKey: "wrappedDeviceKey"
    // @param hash: Hash bytes or encoded hash value to sign.
    // @example hash: "hashValue"
    // @param signature: Receives the generated signature.
    // @example signature: "signatureOutput"
    // @retval OCDM_RESULT: OCDM_SUCCESS when signing succeeds; otherwise an OCDM error result.
    virtual OCDM_RESULT SignHash(const string& wrappedDeviceKey, const string& hash, string& signature /* @out */) = 0;

    // @brief Generates a device key and its X.509 certificate.
    // @details Creates a new RSA device key and returns the wrapped key and corresponding certificate.
    // @param wrappedDeviceKey: Receives the generated wrapped device key.
    // @example wrappedDeviceKey: "wrappedDeviceKeyOutput"
    // @param deviceCertificate: Receives the generated X.509 device certificate.
    // @example deviceCertificate: "deviceCertificateOutput"
    // @retval OCDM_RESULT: OCDM_SUCCESS when key and certificate generation succeeds; otherwise an OCDM error result.
    virtual OCDM_RESULT GenDeviceKeyAndCert(string& wrappedDeviceKey /* @out */, string& deviceCertificate /* @out */) = 0;

    // @brief Retrieves the model certificate chain.
    // @details Returns the certificate chain provisioned for the device model.
    // @param certChain: Receives the model certificate chain.
    // @example certChain: "certificateChainOutput"
    // @retval OCDM_RESULT: OCDM_SUCCESS when the certificate chain is retrieved; otherwise an OCDM error result.
    virtual OCDM_RESULT GetModelCertChain(string& certChain /* @out */) const = 0;

    // @brief Retrieves the system identifier of the implementation.
    // @details Returns the system ID exposed by the underlying Google Cast authentication implementation.
    // @param id: Receives the system identifier.
    // @example id: 1234
    // @retval OCDM_RESULT: OCDM_SUCCESS when the identifier is retrieved; otherwise an OCDM error result.
    virtual OCDM_RESULT GetSystemId(uint32_t& id /* @out */) const = 0;
};

} //namespace Exchange
} //namespace WPEFramework

