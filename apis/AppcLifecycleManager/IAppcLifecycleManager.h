#pragma once

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

// @json 1.0.0 @text:keep
struct EXTERNAL IAppcLifecycleManager : virtual public Core::IUnknown {

    enum LifecycleState : uint8_t {
        UNLOADED,
        LOADING,
        INITIALIZING,
        PAUSED,
        ACTIVE,
        SUSPENDED,
        HIBERNATED,
        TERMINATING
    };


    /** Get the list of loaded applications */
    // @text setTargetAppState
    // @brief Set the state for the application instance
    // @param appInstanceId: Instance ID of the application
    // @param targetLifecycleState: Target lifecycle state to set
    // @param launchIntent: Launch intent to use
    virtual Core::hresult SetTargetAppState(const string& appInstanceId /* @in */, const LifecycleState targetLifecycleState /* @in */, const string& launchIntent /* @in */) = 0;

};
} // namespace Exchange
} // namespace WPEFramework
