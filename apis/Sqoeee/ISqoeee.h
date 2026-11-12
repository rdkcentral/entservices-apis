#pragma once

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    // @json 1.0.0 @text:keep
    struct EXTERNAL ISqoeee : virtual public Core::IUnknown {
        // Keep this identifier stable; COM-RPC clients must use the same interface.
        enum { ID = ID_SQOEEE };

        ~ISqoeee() override = default;

        // App Gateway and Rialto timestamps are Unix epoch milliseconds. Rialto
        // callbacks echo the pipelineId/sourceId pair registered at creation.

        // @alt notifyInAppContentStart
        // @brief Notify that an application started content playback (Firebolt Metrics.startContent)
        // @param appId: Durable app ID
        // @param appVersion: Application version from Firebolt appInfo; empty when unknown
        // @param appSessionId: App session ID
        // @param appUserSessionId: App user session ID
        // @param entityId: Content entity ID; empty when unknown
        // @param avSessionId: AV session ID used to correlate with the Rialto pipeline
        // @param timestampMs: Event time in Unix epoch milliseconds
        // @example appId: "com.example.app"
        // @example avSessionId: "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60"
        // @example timestampMs: 1764752400000
        // @retval Core::ERROR_NONE: Input was accepted
        // @retval Core::ERROR_GENERAL: Input was rejected as malformed, stale, uncorrelated or over capacity
        virtual Core::hresult NotifyInAppContentStart(
            const string& appId,
            const string& appVersion,
            const string& appSessionId,
            const string& appUserSessionId,
            const string& entityId,
            const string& avSessionId,
            const uint64_t timestampMs) = 0;

        // @alt notifyInAppMedia
        // @brief Notify a Firebolt Metrics media event
        // @param appId: Durable app ID
        // @param appVersion: Application version from Firebolt appInfo; empty when unknown
        // @param appSessionId: App session ID
        // @param appUserSessionId: App user session ID
        // @param entityId: Content entity ID; empty when unknown
        // @param avSessionId: AV session ID used to correlate with the Rialto pipeline
        // @param timestampMs: Event time in Unix epoch milliseconds
        // @param mediaEventName: Firebolt method name: mediaLoadStart, mediaPlay, mediaPlaying, mediaPause, mediaWaiting, mediaSeeking, mediaSeeked or mediaEnded
        // @param mediaPosSeconds: Playback position or seek target in seconds (0 to 86400)
        // @param playbackRate: New playback rate
        // @param playbackBitrate: New bitrate in kbps
        // @param playbackWidth: New resolution width
        // @param playbackHeight: New resolution height
        // @param playbackProfile: New profile description, for example HDR
        // @example mediaEventName: "mediaPlaying"
        // @retval Core::ERROR_NONE: Input was accepted
        // @retval Core::ERROR_GENERAL: Input was rejected as malformed, stale, uncorrelated or over capacity
        virtual Core::hresult NotifyInAppMedia(
            const string& appId,
            const string& appVersion,
            const string& appSessionId,
            const string& appUserSessionId,
            const string& entityId,
            const string& avSessionId,
            const uint64_t timestampMs,
            const string& mediaEventName,
            const Core::OptionalType<uint32_t>& mediaPosSeconds,
            const Core::OptionalType<double>& playbackRate,
            const Core::OptionalType<uint32_t>& playbackBitrate,
            const Core::OptionalType<uint32_t>& playbackWidth,
            const Core::OptionalType<uint32_t>& playbackHeight,
            const Core::OptionalType<string>& playbackProfile) = 0;

        // @alt notifyInAppContentStop
        // @brief Notify that an application stopped content playback (Firebolt Metrics.stopContent)
        // @param appId: Durable app ID
        // @param appVersion: Application version from Firebolt appInfo; empty when unknown
        // @param appSessionId: App session ID
        // @param appUserSessionId: App user session ID
        // @param entityId: Content entity ID; empty when unknown
        // @param avSessionId: AV session ID used to correlate with the Rialto pipeline
        // @param timestampMs: Event time in Unix epoch milliseconds
        // @retval Core::ERROR_NONE: Input was accepted
        // @retval Core::ERROR_GENERAL: Input was rejected as malformed, stale, uncorrelated or over capacity
        virtual Core::hresult NotifyInAppContentStop(
            const string& appId,
            const string& appVersion,
            const string& appSessionId,
            const string& appUserSessionId,
            const string& entityId,
            const string& avSessionId,
            const uint64_t timestampMs) = 0;

        // @alt notifyMediaPipelineCreate
        // @brief Notify that Rialto created a media pipeline
        // @param appId: Durable app ID
        // @param avSessionId: AV session ID supplied by the app or generated by Rialto
        // @param pipelineId: Rialto pipeline identity
        // @param sourceId: Rialto source identity
        // @param resolution: Video resolution, for example 1920x1080; empty when unknown
        // @param lowLatency: Whether low-latency video is enabled
        // @param dolbyVision: Whether Dolby Vision is enabled
        // @param audioFormat: Audio format; empty when unknown
        // @param timestampMs: Event time in Unix epoch milliseconds
        // @example pipelineId: "pipeline-1"
        // @example sourceId: "rialto"
        // @retval Core::ERROR_NONE: Input was accepted
        // @retval Core::ERROR_GENERAL: Input was rejected as malformed, stale, uncorrelated or over capacity
        virtual Core::hresult NotifyMediaPipelineCreate(
            const string& appId,
            const string& avSessionId,
            const string& pipelineId,
            const string& sourceId,
            const string& resolution,
            const bool lowLatency,
            const bool dolbyVision,
            const string& audioFormat,
            const uint64_t timestampMs) = 0;

        // @alt notifyMediaPipelineStateChange
        // @brief Notify a Rialto media pipeline playback state change
        // @param appId: Durable app ID
        // @param avSessionId: AV session ID
        // @param pipelineId: Rialto pipeline identity
        // @param sourceId: Rialto source identity
        // @param mediaPipelineState: UNKNOWN, IDLE, PLAYING, PAUSED, STOPPED, END_OF_STREAM, FAILURE, PREROLLING, DISCARDING, DISCARD_DONE or FLUSHING
        // @param timestampMs: Event time in Unix epoch milliseconds
        // @example mediaPipelineState: "PLAYING"
        // @retval Core::ERROR_NONE: Input was accepted
        // @retval Core::ERROR_GENERAL: Input was rejected as malformed, stale, uncorrelated or over capacity
        virtual Core::hresult NotifyMediaPipelineStateChange(
            const string& appId,
            const string& avSessionId,
            const string& pipelineId,
            const string& sourceId,
            const string& mediaPipelineState,
            const uint64_t timestampMs) = 0;

        // @alt notifyCurrentPresentationTimeUpdate
        // @brief Notify the current presentation time of a Rialto media pipeline
        // @param appId: Durable app ID
        // @param avSessionId: AV session ID
        // @param pipelineId: Rialto pipeline identity
        // @param sourceId: Rialto source identity
        // @param currentPresentationTimeMs: Current presentation time in milliseconds
        // @param timestampMs: Event time in Unix epoch milliseconds
        // @retval Core::ERROR_NONE: Input was accepted
        // @retval Core::ERROR_GENERAL: Input was rejected as malformed, stale, uncorrelated or over capacity
        virtual Core::hresult NotifyCurrentPresentationTimeUpdate(
            const string& appId,
            const string& avSessionId,
            const string& pipelineId,
            const string& sourceId,
            const uint64_t currentPresentationTimeMs,
            const uint64_t timestampMs) = 0;

        // @alt notifyMediaPipelinePlaybackRate
        // @brief Notify the playback rate of a Rialto media pipeline
        // @param appId: Durable app ID
        // @param avSessionId: AV session ID
        // @param pipelineId: Rialto pipeline identity
        // @param sourceId: Rialto source identity
        // @param playbackRate: Playback rate
        // @param timestampMs: Event time in Unix epoch milliseconds
        // @retval Core::ERROR_NONE: Input was accepted
        // @retval Core::ERROR_GENERAL: Input was rejected as malformed, stale, uncorrelated or over capacity
        virtual Core::hresult NotifyMediaPipelinePlaybackRate(
            const string& appId,
            const string& avSessionId,
            const string& pipelineId,
            const string& sourceId,
            const double playbackRate,
            const uint64_t timestampMs) = 0;

        // @alt notifyFirstFramePresented
        // @brief Notify that a Rialto media pipeline presented its first frame
        // @param appId: Durable app ID
        // @param avSessionId: AV session ID
        // @param pipelineId: Rialto pipeline identity
        // @param sourceId: Rialto source identity
        // @param timestampMs: Event time in Unix epoch milliseconds
        // @retval Core::ERROR_NONE: Input was accepted
        // @retval Core::ERROR_GENERAL: Input was rejected as malformed, stale, uncorrelated or over capacity
        virtual Core::hresult NotifyFirstFramePresented(
            const string& appId,
            const string& avSessionId,
            const string& pipelineId,
            const string& sourceId,
            const uint64_t timestampMs) = 0;

        // @alt notifyMediaPipelineMetricEvent
        // @brief Notify a Rialto media pipeline metric event
        // @param appId: Durable app ID
        // @param avSessionId: AV session ID
        // @param pipelineId: Rialto pipeline identity
        // @param sourceId: Rialto source identity
        // @param type: VIDEO_FRAME_DROP, AUDIO_FRAME_DROP, VIDEO_FRAME_REPEAT, AUDIO_GAP, VIDEO_DECODE_ERROR, AUDIO_DECODE_ERROR or BUFFER_UNDERFLOW
        // @param phase: OCCURRENCE, STARTED or RESOLVED
        // @param count: Count associated with a resolved metric episode
        // @param durationMs: Duration of a resolved metric episode in milliseconds
        // @param ptsMs: Presentation timestamp of the metric in milliseconds
        // @param timestampMs: Event time in Unix epoch milliseconds
        // @example type: "BUFFER_UNDERFLOW"
        // @example phase: "STARTED"
        // @retval Core::ERROR_NONE: Input was accepted
        // @retval Core::ERROR_GENERAL: Input was rejected as malformed, stale, uncorrelated or over capacity
        virtual Core::hresult NotifyMediaPipelineMetricEvent(
            const string& appId,
            const string& avSessionId,
            const string& pipelineId,
            const string& sourceId,
            const string& type,
            const string& phase,
            const Core::OptionalType<uint64_t>& count,
            const Core::OptionalType<uint64_t>& durationMs,
            const Core::OptionalType<uint64_t>& ptsMs,
            const uint64_t timestampMs) = 0;

        // @alt notifyMediaPipelineDestroy
        // @brief Notify that Rialto destroyed a media pipeline
        // @param appId: Durable app ID
        // @param avSessionId: AV session ID
        // @param pipelineId: Rialto pipeline identity
        // @param sourceId: Rialto source identity
        // @param timestampMs: Event time in Unix epoch milliseconds
        // @retval Core::ERROR_NONE: Input was accepted
        // @retval Core::ERROR_GENERAL: Input was rejected as malformed, stale, uncorrelated or over capacity
        virtual Core::hresult NotifyMediaPipelineDestroy(
            const string& appId,
            const string& avSessionId,
            const string& pipelineId,
            const string& sourceId,
            const uint64_t timestampMs) = 0;

        // @alt getDiagnostics
        // @brief Get SQoEEE input, report and sink diagnostics counters
        // @param acceptedInputs: Accepted inputs
        // @param emittedReports: Reports handed to the sink
        // @param duplicateInputs: Inputs deduplicated against an equivalent signal
        // @param staleInputs: Out-of-order inputs or inputs from retired pipelines or closed sessions
        // @param uncorrelatedInputs: Inputs without a usable avSessionId or session
        // @param malformedInputs: Inputs with invalid parameters
        // @param droppedReports: Reports the sink refused
        // @param capacityRejectedInputs: Inputs rejected because the session limit was reached
        // @param expiredSessions: Partially correlated sessions that timed out
        // @param queuedReports: Reports currently waiting in the sink queue
        // @param sinkRetries: Sink delivery retries
        // @param sinkDrops: Reports dropped by the sink queue
        // @retval Core::ERROR_NONE: Diagnostics were returned
        // @retval Core::ERROR_GENERAL: SQoEEE is not configured
        virtual Core::hresult GetDiagnostics(
            uint64_t& acceptedInputs /* @out */,
            uint64_t& emittedReports /* @out */,
            uint64_t& duplicateInputs /* @out */,
            uint64_t& staleInputs /* @out */,
            uint64_t& uncorrelatedInputs /* @out */,
            uint64_t& malformedInputs /* @out */,
            uint64_t& droppedReports /* @out */,
            uint64_t& capacityRejectedInputs /* @out */,
            uint64_t& expiredSessions /* @out */,
            uint64_t& queuedReports /* @out */,
            uint64_t& sinkRetries /* @out */,
            uint64_t& sinkDrops /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
