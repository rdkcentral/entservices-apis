#pragma once
#include <string>

//namespace WPEFramework {
//namespace Exchange {

// @text:keep
struct RuntimeConfig {
    // @brief dial
    bool dial;
    // @brief wanLanAccess
    bool wanLanAccess;
    // @brief thunder
    bool thunder;
    // @brief systemMemoryLimit
    int32_t systemMemoryLimit;
    // @brief gpuMemoryLimit
    int32_t gpuMemoryLimit;
    // @brief envVars
    std::string envVars;
    // @brief userId
    uint32_t userId;
    // @brief groupId
    uint32_t groupId;
    // @brief dataImageSize
    uint32_t dataImageSize;
};

//}
//}