// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    // @json 1.0.0 @text:keep
    struct EXTERNAL IPowerManagerRenegotiation : virtual public Core::IUnknown {
        enum { ID = ID_POWER_MANAGER_RENEGOTIATION };

        // @text delayPowerModeChangeBy
        // @brief Delay a power-mode change, optionally restarting pre-change negotiation after the delay.
        // @param clientId: Identifier returned by AddPowerModePreChangeClient.
        // @param transactionId: Transaction identifier received in OnPowerModePreChange.
        // @param delayPeriod: Delay in seconds.
        // @param renegotiateAfterwards(optional): Defaults to false. Set true to restart negotiation after the delay; false preserves the legacy delay behavior.
        // @retval ErrorCode::ERROR_NONE: Delay accepted.
        // @retval ErrorCode::ERROR_INVALID_PARAMETER: Invalid client or transaction, no active round, retry pending, or negative renegotiation delay.
        // @retval ErrorCode::ERROR_ILLEGAL_STATE: The negotiation round has already completed.
        // @retval ErrorCode::ERROR_UNAVAILABLE: The implementation is shutting down.
        virtual Core::hresult DelayPowerModeChangeBy(const uint32_t clientId, const int transactionId,
            const int delayPeriod, const bool renegotiateAfterwards /* @optional */ = false) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
