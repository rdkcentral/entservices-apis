#pragma once

#include <string>
#include <memory>
#include <vector>

namespace packagemanager {

enum Result : uint8_t {
    SUCCESS,
    FAILED
};
struct ConfigMetaData {
    bool dial;
    bool wanLanAccess;
    bool thunder;
    int32_t systemMemoryLimit;
    int32_t gpuMemoryLimit;
    std::vector<std::string> envVars;
    uint32_t userId;
    uint32_t groupId;
    uint32_t dataImageSize;

    bool resourceManagerClientEnabled;
    std::string dialId;
    std::string command;
    uint32_t appType;
    std::string appPath;
    std::string runtimePath;

    std::string fireboltVersion;
    bool enableDebugger;
};

class IPackageImpl {
    public:
    virtual ~IPackageImpl() = default;

    virtual Result Install(const std::string &packageId, const std::string &version, const std::string &fileLocator) = 0;
    virtual Result Uninstall(const std::string &packageId) = 0;

    virtual Result GetList(std::string &packageList) = 0;

    virtual Result Lock(const std::string &packageId, const std::string &version, std::string &unpackedPath, ConfigMetaData& configMetadata) = 0;
    virtual Result Unlock(const std::string &packageId, const std::string &version) = 0;

    virtual Result GetLockInfo(const std::string &packageId, const std::string &version, std::string &unpackedPath, bool &locked) = 0;

    static std::shared_ptr<packagemanager::IPackageImpl> instance();

};

}
