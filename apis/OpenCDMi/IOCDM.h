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

        // @brief Notifies the application that a DRM key message was generated.
        // @details This callback is fired when the session produces a key message to be delivered to the license server as part of the key exchange flow.
        // @param keyMessage: Buffer containing the generated key message.
        // @example keyMessage: "generatedKeyMessageBuffer"
        // @param keyLength: Size, in bytes, of the key message payload.
        // @example keyLength: 1024
        // @param URL: URL associated with the licensing request or response.
        // @example URL: "https://license.server.com"
        virtual void OnKeyMessage(const uint8_t* keyMessage /* @length:keyLength */, //__in_bcount(f_cbKeyMessage)
            const uint16_t keyLength, //__in
            const std::string& URL) = 0; //__in_z_opt

        // @brief Notifies the application that the session encountered an error.
        // @details This callback is used to surface a DRM session failure with the specific DRM and platform error details that caused the issue.
        // @param error: Session-specific error code reported by the CDM.
        // @example error: -1
        // @param sysError: Platform or DRM result code associated with the failure.
        // @example sysError: 0
        // @param errorMessage: Human-readable description of the error.
        // @example errorMessage: "Key exchange failed"
        virtual void OnError(const int16_t error, const OCDM_RESULT sysError, const std::string& errorMessage) = 0;

        // @brief Reports a key status update for a specific key identifier.
        // @details The callback is fired when the status of a specific key changes while a session is active.
        // @param keyID: Buffer containing the key identifier that changed status.
        // @example keyID: "keyIdentifierBuffer"
        // @param keyIDLength: Length of the key identifier buffer.
        // @example keyIDLength: 16
        // @param status: New status for the specified key.
        // @example status: Usable
        virtual void OnKeyStatusUpdate(const uint8_t keyID[] /* @length:keyIDLength */,
                                       const uint8_t keyIDLength,
                                       const ISession::KeyStatus status) = 0;

        // @brief Indicates that multiple key statuses were updated.
        // @details This callback is used to notify the application that a batch of key state
        // transitions occurred and the client should refresh the status if needed.
        virtual void OnKeyStatusesUpdated() const = 0;
    };

    enum { ID = ID_SESSION };

    ~ISession(void) override = default;

    // @brief Restores a session from persistent DRM state.
    // @details Loads the session data previously stored by the CDM so the existing license and
    // key context can be used without reinitializing the entire session.
    // @retval OCDM_SUCCESS: The session state was loaded successfully.
    // @retval OCDM_INVALID_SESSION: The session is not valid or no persistent state exists.
    virtual OCDM_RESULT Load() = 0;

    // @brief Processes a DRM key message response.
    // @details The message content is passed to the DRM implementation for decryption or
    // session continuation as part of the license exchange process.
    // @param keyMessage: Key message buffer that contains the response payload.
    // @example keyMessage: "responsePayloadBuffer"
    // @param keyLength: Size, in bytes, of the key message response.
    // @example keyLength: 256
    // @retval None: The response is processed without a return value.
    virtual void
    Update(const uint8_t* keyMessage /* @length:keyLength */, //__in_bcount(f_cbKeyMessageResponse)
        const uint16_t keyLength)
        = 0; //__in

    // @brief Removes the active session state and associated keys.
    // @details Clears the licenses, keys, and runtime data associated with the session so it can be discarded or re-created cleanly.
    // @retval OCDM_SUCCESS: The session was removed successfully.
    // @retval OCDM_INVALID_SESSION: The session was already invalid or could not be removed.
    virtual OCDM_RESULT Remove() = 0;

    // @brief Retrieves the key system metadata associated with the session.
    // @details Returns platform- and DRM-specific metadata that describes the current session state.
    // @retval metadata: Metadata string associated with the current session.
    virtual std::string Metadata() const = 0;

    // @brief Returns key-system metric data for the current session.
    // @details This method provides implementation-defined metrics and counters that can be used by the client for diagnostics or telemetry.
    // @param bufferSize: On input, the provided buffer size; on output, the size actually used.
    // @example bufferSize: 1024
    // @param buffer: Buffer receiving the metric data payload.
    // @example buffer: uint8_t buffer[1024]
    // @retval OCDM_SUCCESS: Metrics were written successfully.
    // @retval OCDM_BUFFER_TOO_SMALL: The provided buffer is too small for the metrics payload.
    virtual OCDM_RESULT Metricdata(
        uint32_t& bufferSize /* @inout */,
        uint8_t buffer[] /* @out @length:bufferSize */) const
        = 0;

    // @brief Gets the current key status for the session.
    // @details Reports the session-level status relative to the ongoing key exchange lifecycle.
    // @retval KeyStatus: Current session-level key status.
    virtual KeyStatus Status() const = 0;

    // @brief Gets the status for a specific key identifier.
    // @details This overload reports the status of the provided key in the session.
    // @param keyID: Buffer containing the key identifier to query.
    // @example keyID: uint8_t keyID[16]
    // @param keyIDLength: Length of the key identifier buffer.
    // @example keyIDLength: 16
    // @retval KeyStatus: Current status of the specified key.
    virtual KeyStatus Status(const uint8_t keyID[] /* @length:keyIDLength */, const uint8_t keyIDLength) const = 0;

    // @brief Creates a decryption buffer for the session.
    // @details Lazily allocates the shared-memory or stream buffer used for encrypted content exchange.
    // @param bufferID: The identifier of the allocated session buffer.
    // @example bufferID: string bufferID
    // @retval OCDM_SUCCESS: The session buffer was created successfully.
    // @retval OCDM_OUT_OF_MEMORY: The buffer could not be allocated.
    virtual OCDM_RESULT CreateSessionBuffer(string& bufferID /* @out */ ) = 0;

    // @brief Returns the session buffering identifier.
    // @details Provides the shared-memory name used for encrypted frame exchange between the CDM and the media pipeline.
    // @param None: This method does not take any parameters.
    // @example None: Call BufferId() to retrieve the session buffer identifier.
    // @retval bufferId: Session buffer identifier.
    virtual std::string BufferId() const = 0;

    // @brief Returns the session identifier.
    // @details Exposes the unique identifier for the current DRM session.
    // @param None: This method does not take any parameters.
    // @example None: Call SessionId() to retrieve the current session identifier.
    // @retval sessionId: Unique identifier for the current DRM session.
    virtual std::string SessionId() const = 0;

    // @brief Closes the session and releases any associated resources.
    // @details Finalizes the session lifecycle and ensures that the DRM context is no longer used.
    // @param None: This method does not take any parameters.
    // @example None: Call Close() when the session is no longer needed.
    // @retval None: The session is closed without a return value.
    virtual void Close() = 0;

    // @brief Informs the CDM that playback has stopped.
    // @details This clears output protection state that is only needed while playback is active.
    // @param None: This method does not take any parameters.
    // @example None: Call ResetOutputProtection() after playback stops.
    // @retval None: Output protection state is reset without a return value.
    virtual void ResetOutputProtection() = 0;

    // @brief Stores a name/value parameter in the CDM context.
    // @details This method allows the caller to pass implementation-specific configuration or runtime values into the CDM for the active session.
    // @param name: Parameter name to set inside the session.
    // @example name: sessionID
    // @param value: Value associated with the specified parameter.
    // @example value: "123"
    // @retval None: The parameter is stored without a return value.
    virtual void SetParameter(const std::string& name, const std::string& value) = 0;

    // @brief Releases the current callback registration.
    // @details Detaches a callback from the session, allowing the application to decouple its event handling without destroying the session object.
    // @param callback: Callback object to revoke from the session.
    // @example callback: myCallbackInstance
    // @retval None: The callback registration is revoked without a return value.
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

    // @brief Returns the extended session identifier.
    // @details Provides the DRM-specific session identifier used for extended session operations.
    // @param None: This method does not take any parameters.
    // @example None: Call SessionIdExt() to retrieve the extended session identifier.
    // @retval sessionId: Extended session identifier.
    virtual uint32_t SessionIdExt() const = 0;

    // @brief Returns the extended shared-memory identifier.
    // @details Exposes the buffer name used by the extended session for content exchange.
    // @param None: This method does not take any parameters.
    // @example None: Call BufferIdExt() to retrieve the extended session buffer identifier.
    // @retval bufferId: Extended session buffer identifier.
    virtual std::string BufferIdExt() const = 0;

    // @brief Sets the DRM header for the extended session.
    // @details Supplies the key system header bytes required to initialize DRM data for this session.
    // @param drmHeader: Buffer containing the header data for the DRM system.
    // @example drmHeader
    // @param drmHeaderLength: Size, in bytes, of the DRM header payload.
    // @example drmHeaderLength
    // @retval OCDM_SUCCESS: The header was accepted successfully.
    // @retval OCDM_INVALID_ARG: The header contents or length were invalid.
    virtual OCDM_RESULT SetDrmHeader(const uint8_t drmHeader[] /* @length:drmHeaderLength */,
        uint16_t drmHeaderLength)
        = 0;

    // @brief Retrieves challenge data for the DRM exchange.
    // @details Requests the challenge data required to continue the license acquisition flow.
    // @param challenge: Buffer for the returned challenge payload.
    // @example challenge
    // @param challengeSize: On input the buffer size; on output the amount of data written.
    // @example challengeSize
    // @param isLDL: Indicates whether the session is using the LDL mode for challenge handling.
    // @example isLDL
    // @retval OCDM_SUCCESS: Challenge data was returned successfully.
    // @retval OCDM_BUFFER_TOO_SMALL: The output buffer is too small for the challenge.
    virtual OCDM_RESULT GetChallengeDataExt(uint8_t* challenge /* @inout @length:challengeSize */,
        uint16_t& challengeSize /* @inout */,
        uint32_t isLDL)
        = 0;

    // @brief Cancels any pending challenge data request.
    // @details Clears the state associated with a challenge fetch so a new exchange can begin.
    // @param None: This method does not take any parameters.
    // @example None: Call CancelChallengeDataExt() to cancel a pending challenge request.
    // @retval OCDM_SUCCESS: The pending challenge state was canceled successfully.
    // @retval OCDM_INVALID_SESSION: The current session state does not allow cancellation.
    virtual OCDM_RESULT CancelChallengeDataExt() = 0;

    // @brief Persists license data and returns a secure stop identifier.
    // @details Writes the provided license data to the session and returns the related secure-stop identifier.
    // @param licenseData: Buffer containing the license data to store.
    // @example licenseData
    // @param licenseDataSize: Size, in bytes, of the license payload.
    // @example licenseDataSize
    // @param secureStopId: Output buffer for the secure-stop identifier, if one is created.
    // @example secureStopId
    // @retval OCDM_SUCCESS: The license data was stored successfully.
    // @retval OCDM_INVALID_ARG: The provided license data or size is invalid.
    virtual OCDM_RESULT StoreLicenseData(const uint8_t licenseData[] /* @length:licenseDataSize */,
        uint16_t licenseDataSize,
        uint8_t* secureStopId /* @out @length:16 */)
        = 0;

    // @brief Selects a specific key identifier for the session.
    // @details Chooses the key that should be used for the active decryption or license-handling flow.
    // @param keyLength: Length of the key identifier buffer.
    // @example keyLength
    // @param keyId: Buffer containing the key identifier to select.
    // @example keyId
    // @retval OCDM_SUCCESS: The key identifier was selected successfully.
    // @retval OCDM_INVALID_ARG: The key identifier is malformed or unsupported.
    virtual OCDM_RESULT SelectKeyId(const uint8_t keyLength,
        const uint8_t keyId[] /* @length:keyLength */)
        = 0;

    // @brief Clears the active decryption context.
    // @details Releases the internal decrypt context so a new content session can be established safely.
    // @param None: This method does not take any parameters.
    // @example None: Call CleanDecryptContext() before establishing a new decrypt context.
    // @retval OCDM_SUCCESS: The decrypt context was cleared successfully.
    // @retval OCDM_INVALID_SESSION: The session does not support context cleanup.
    virtual OCDM_RESULT CleanDecryptContext() = 0;
};

struct IAccessorOCDM : virtual public Core::IUnknown {

    enum { ID = ID_ACCESSOROCDM };

    ~IAccessorOCDM() override = default;

    // @brief Determines whether a key system and MIME type are supported.
    // @details This helper validates whether the underlying DRM implementation can handle the requested combination of key system and content type.
    // @param keySystem: Name of the DRM key system to query.
    // @example keySystem: "com.widevine.alpha"
    // @param mimeType: MIME type of the content being protected.
    // @example mimeType: "video/mp4"
    // @retval true: The combination is supported by the CDM.
    // @retval false: The combination is not supported.
    virtual bool IsTypeSupported(const std::string& keySystem,
        const std::string& mimeType) const = 0;

    // @brief Returns key-system metadata.
    // @details Provides implementation-specific metadata describing the requested DRM system.
    // @param keySystem: Name of the key system for which metadata is requested.
    // @example keySystem: "com.widevine.alpha"
    // @param metadata: Output string containing the key system metadata.
    // @example metadata: std::string metadata;
    // @retval OCDM_SUCCESS: Metadata was retrieved successfully.
    // @retval OCDM_KEYSYSTEM_NOT_SUPPORTED: The requested key system is not available.
    virtual OCDM_RESULT Metadata(const std::string& keySystem, std::string& metadata /* @out */) const = 0;

    // @brief Returns key-system metric data.
    // @details Supplies implementation-specific metrics for a given DRM system and content pipeline.
    // @param keySystem: Name of the key system being queried.
    // @example keySystem: "com.widevine.alpha"
    // @param bufferSize: On input the buffer size; on output the bytes used.
    // @example bufferSize: 1024
    // @param buffer: Output buffer receiving the metric payload.
    // @example buffer: 1024
    // @retval OCDM_SUCCESS: Metrics were returned successfully.
    // @retval OCDM_BUFFER_TOO_SMALL: The output buffer is too small.
    virtual OCDM_RESULT Metricdata(
        const std::string& keySystem,
        uint32_t& bufferSize /* @inout */,
        uint8_t buffer[] /* @out @length:bufferSize */) const
        = 0;

    // @brief Requests the robustness levels supported by the DRM implementation.
    // @details Lists the DRM robustness values available for a specific key system.
    // @param keySystem: Name of the key system for which to query robustness.
    // @example keySystem
    // @param robustness: Output iterator containing the supported robustness strings.
    // @example robustness
    // @retval OCDM_SUCCESS: The robustness list was provided successfully.
    // @retval OCDM_KEYSYSTEM_NOT_SUPPORTED: The requested key system is unavailable.
    virtual OCDM_RESULT GetSupportedRobustness(
        const std::string& keySystem,
        RPC::IStringIterator*& robustness /* @out */) const = 0;

    // @brief Creates a media key session using the supplied initialization data.
    // @details Instantiates a DRM session for the requested key system and binds it to the callback that will receive key messages and status updates.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.widevine.alpha"
    // @param licenseType: Type of license requested for the session.
    // @example licenseType: 0
    // @param initDataType: MIME or protocol type for the initialization data.
    // @example initDataType: "cenc"
    // @param initData: Initialization data passed to the DRM implementation.
    // @example initData
    // @param initDataLength: Length of the initialization data buffer.
    // @example initDataLength
    // @param CDMData: CDM-specific data required by the platform.
    // @example CDMData
    // @param CDMDataLength: Length of the CDM-specific data buffer.
    // @example CDMDataLength
    // @param callback: Callback object used for session events.
    // @example callback
    // @param sessionId: Output identifier for the created session.
    // @example sessionId: "session123"
    // @param session: Output pointer to the created session instance.
    // @example session
    // @retval OCDM_SUCCESS: The session was created successfully.
    // @retval OCDM_INVALID_ARG: One or more inputs are invalid.
    // @retval OCDM_KEYSYSTEM_NOT_SUPPORTED: The key system is not supported.
    virtual OCDM_RESULT
    CreateSession(const string& keySystem, const int32_t licenseType,
        const std::string& initDataType, const uint8_t* initData /* @length:initDataLength */,
        const uint16_t initDataLength, const uint8_t* CDMData /* @length:CDMDataLength */,
        const uint16_t CDMDataLength, ISession::ICallback* callback,
        std::string& sessionId /* @out */, ISession*& session /* @out */)
        = 0;

    // @brief Installs a server certificate for a key system.
    // @details Provides the certificate required by the DRM implementation to authenticate the license server.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.widevine.alpha"
    // @param serverCertificate: Buffer containing the server certificate.
    // @example serverCertificate: const uint8_t* serverCertificate = ...;
    // @param serverCertificateLength: Length of the certificate buffer.
    // @example serverCertificateLength: uint16_t serverCertificateLength = ...;
    // @retval OCDM_SUCCESS: The certificate was set successfully.
    // @retval OCDM_INVALID_ARG: The certificate data or length is invalid.
    virtual OCDM_RESULT
    SetServerCertificate(const string& keySystem, const uint8_t* serverCertificate /* @length:serverCertificateLength */,
        const uint16_t serverCertificateLength)
        = 0;

    // @brief Returns the DRM time for a key system.
    // @details Retrieves the device or DRM system time that is relevant to the requested key system.
    // @param keySystem: DRM key system name.
    // @example keySystem
    // @retval systemTime: DRM system time for the requested key system.
    virtual uint64_t GetDrmSystemTime(const std::string& keySystem) const = 0;

    // @brief Returns the implementation version string.
    // @details Provides the version information for the DRM system implementation associated with the key system.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.microsoft.playready"
    // @retval version: Version string for the DRM implementation.
    virtual std::string GetVersionExt(const std::string& keySystem) const = 0;

    // @brief Returns the maximum number of LDL sessions allowed.
    // @details Indicates the configured session cap for low-delay license sessions for the key system.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.microsoft.playready"
    // @retval sessionLimit: Maximum number of LDL sessions allowed.
    virtual uint32_t GetLdlSessionLimit(const std::string& keySystem) const = 0;

    // @brief Determines whether secure stop is enabled.
    // @details Reports whether the requested DRM system is configured to enforce secure-stop handling.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.microsoft.playready"
    // @retval true: Secure stop is enabled.
    // @retval false: Secure stop is disabled.
    virtual bool IsSecureStopEnabled(const std::string& keySystem) = 0;

    // @brief Enables or disables secure-stop handling.
    // @details Configures the secure-stop feature for the specified key system.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.microsoft.playready"
    // @param enable: True to enable secure stop, false to disable it.
    // @example enable: true
    // @retval OCDM_SUCCESS: The secure-stop state was updated successfully.
    // @retval OCDM_INVALID_ARG: The key system is invalid.
    virtual OCDM_RESULT EnableSecureStop(const std::string& keySystem,
        bool enable)
        = 0;

    // @brief Resets secure-stop entries for the key system.
    // @details Clears the secure-stop state associated with the requested DRM system.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.microsoft.playready"
    // @retval result: Numeric result of the secure-stop reset operation.
    virtual uint32_t ResetSecureStops(const std::string& keySystem) = 0;

    // @brief Retrieves the stored secure-stop identifiers.
    // @details Lists secure-stop IDs associated with the provided key system and fills the supplied buffer.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.microsoft.playready"
    // @param ids: Output buffer for secure-stop identifiers.
    // @example ids: { 0x01, 0x02, 0x03, 0x04 }
    // @param idsLength: Capacity of the output buffer in bytes.
    // @example idsLength: 4
    // @param count: On input the count capacity; on output the number of IDs returned.
    // @example count: 4
    // @retval OCDM_SUCCESS: Secure-stop IDs were returned successfully.
    // @retval OCDM_BUFFER_TOO_SMALL: The output buffer is too small.
    virtual OCDM_RESULT GetSecureStopIds(const std::string& keySystem,
        uint8_t ids[] /* @out @length:idsLength */, uint16_t idsLength,
        uint32_t& count /* @inout */)
        = 0;

    // @brief Retrieves the secure-stop data for a session identifier.
    // @details Fetches the stored secure-stop payload associated with a session and fills the supplied output buffer.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.microsoft.playready"
    // @param sessionID: Session identifier associated with the secure-stop record.
    // @example sessionID: { 0x01, 0x02, 0x03, 0x04 }
    // @param sessionIDLength: Length of the session identifier buffer.
    // @example sessionIDLength: 4
    // @param rawData: Output buffer for the raw secure-stop payload.
    // @example rawData: { 0x0A, 0x0B, 0x0C, 0x0D }
    // @param rawSize: On input the output buffer size; on output the actual size used.
    // @example rawSize: 4
    // @retval OCDM_SUCCESS: Secure-stop data was returned successfully.
    // @retval OCDM_BUFFER_TOO_SMALL: The output buffer is too small.
    virtual OCDM_RESULT GetSecureStop(const std::string& keySystem,
        const uint8_t sessionID[] /* @length:sessionIDLength */,
        uint16_t sessionIDLength, uint8_t* rawData /* @out @length:rawSize */,
        uint16_t& rawSize /* @inout */)
        = 0;

    // @brief Commits a secure-stop response from the service.
    // @details Persists the secure-stop server response for the specified session state.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.microsoft.playready"
    // @param sessionID: Session identifier associated with the secure-stop response.
    // @example sessionID: { 0x01, 0x02, 0x03, 0x04 }
    // @param sessionIDLength: Length of the session identifier buffer.
    // @example sessionIDLength: 4
    // @param serverResponse: Response payload received from the secure-stop service.
    // @example serverResponse: { 0x0A, 0x0B, 0x0C, 0x0D }
    // @param serverResponseLength: Size, in bytes, of the response payload.
    // @example serverResponseLength: 4
    // @retval OCDM_SUCCESS: The secure-stop response was committed successfully.
    // @retval OCDM_INVALID_ARG: The secure-stop response is malformed or invalid.
    virtual OCDM_RESULT CommitSecureStop(const std::string& keySystem,
        const uint8_t sessionID[] /* @length:sessionIDLength */,
        uint16_t sessionIDLength,
        const uint8_t serverResponse[] /* @length:serverResponseLength */,
        uint16_t serverResponseLength)
        = 0;

    // @brief Deletes the key store for the key system.
    // @details Removes the persistent key-store data associated with the DRM implementation.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.microsoft.playready"
    // @retval OCDM_SUCCESS: The key store was deleted successfully.
    // @retval OCDM_KEYSYSTEM_NOT_SUPPORTED: The key system is not available.
    virtual OCDM_RESULT DeleteKeyStore(const std::string& keySystem) = 0;

    // @brief Deletes the secure store for the key system.
    // @details Removes the secure-store data associated with the DRM implementation.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.microsoft.playready"
    // @retval OCDM_SUCCESS: The secure store was deleted successfully.
    // @retval OCDM_KEYSYSTEM_NOT_SUPPORTED: The key system is not available.
    virtual OCDM_RESULT DeleteSecureStore(const std::string& keySystem) = 0;

    // @brief Retrieves the key-store hash for a DRM system.
    // @details Generates or returns the digest for the key store to support validation or diagnostics.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.microsoft.playready"
    // @param keyStoreHash: Output buffer containing the key-store hash.
    // @example keyStoreHash: { 0x3A, 0x7F, 0x12, 0xBC }
    // @param keyStoreHashLength: Capacity of the output buffer.
    // @example keyStoreHashLength: 32
    // @retval OCDM_SUCCESS: The hash was produced successfully.
    // @retval OCDM_BUFFER_TOO_SMALL: The output buffer is too small.
    virtual OCDM_RESULT GetKeyStoreHash(const std::string& keySystem,
        uint8_t keyStoreHash[] /* @out @length:keyStoreHashLength */,
        uint16_t keyStoreHashLength)
        = 0;

    // @brief Retrieves the secure-store hash for a DRM system.
    // @details Generates or returns the digest for the secure store to support integrity validation.
    // @param keySystem: DRM key system name.
    // @example keySystem: "com.microsoft.playready"
    // @param secureStoreHash: Output buffer containing the secure-store hash.
    // @example secureStoreHash: { 0x3A, 0x7F, 0x12, 0xBC }
    // @param secureStoreHashLength: Capacity of the output buffer.
    // @example secureStoreHashLength: 32
    // @retval OCDM_SUCCESS: The secure-store hash was produced successfully.
    // @retval OCDM_BUFFER_TOO_SMALL: The output buffer is too small.
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

    // @brief Signs a hash using the provided device key.
    // @details Creates a device-specific signature from the supplied wrapped key and hash payload.
    // @param wrappedDeviceKey: Wrapped device key used for signing.
    // @example wrappedDeviceKey: std::string wrappedDeviceKey;
    // @param hash: Hash value to sign.
    // @example hash: std::string hash;
    // @param signature: Output signature produced by the signing operation.
    // @example signature
    // @retval OCDM_SUCCESS: The hash was signed successfully.
    // @retval OCDM_INVALID_ARG: One or more signing inputs are invalid.
    virtual OCDM_RESULT SignHash(const string& wrappedDeviceKey, const string& hash, string& signature /* @out */) = 0;

    // @brief Generates a new device key and certificate pair.
    // @details Creates a new RSA device key as well as the associated X.509 device certificate.
    // @param wrappedDeviceKey: Output wrapped device key for the generated key pair.
    // @example wrappedDeviceKey
    // @param deviceCertificate: Output certificate generated for the device key.
    // @example deviceCertificate
    // @retval OCDM_SUCCESS: The key pair and certificate were generated successfully.
    // @retval OCDM_OUT_OF_MEMORY: The required key material could not be allocated.
    virtual OCDM_RESULT GenDeviceKeyAndCert(string& wrappedDeviceKey /* @out */, string& deviceCertificate /* @out */) = 0;

    // @brief Returns the model certificate chain.
    // @details Retrieves the certificate chain associated with the underlying device model and DRM implementation.
    // @param certChain: Output certificate chain encoded as a string.
    // @example certChain: "certificateChain"
    // @retval OCDM_SUCCESS: The certificate chain was returned successfully.
    // @retval OCDM_INVALID_SESSION: No valid certificate chain is available.
    virtual OCDM_RESULT GetModelCertChain(string& certChain /* @out */) const = 0;

    // @brief Returns the underlying implementation system identifier.
    // @details Provides the DRM implementation-specific system ID for the device.
    // @param id: Output identifier value for the system.
    // @example id
    // @retval OCDM_SUCCESS: The system identifier was returned successfully.
    virtual OCDM_RESULT GetSystemId(uint32_t& id /* @out */) const = 0;
};

} //namespace Exchange
} //namespace WPEFramework

