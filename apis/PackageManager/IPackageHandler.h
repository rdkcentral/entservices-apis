#pragma once
#include "Module.h"

namespace WPEFramework {
namespace Exchange {
    // @json 1.0.0 @text:keep
    struct EXTERNAL IPackageHandler : virtual public Core::IUnknown {
        enum { ID = ID_PACKAGE_HANDLER };

        ~IPackageHandler() override = default;

        enum LockReason : uint8_t {
            SYSTEM_APP,
            LAUNCH
        };

        // @text lock
        // @param packageId: Package Id
        // @param version: Version
        // @param lockReason: LockReason
        // @param lockId: Lock Id
        // @param unpackedPath: Unpacked Path
        // @param configMetadata: Config Metadata
        // @param appMetadata: App Metadata
        virtual Core::hresult Lock(
            const string &packageId,
            const string &version,
            const LockReason &lockReason,
            uint32_t &lockId /* @out */,
            string &unpackedPath /* @out */,
            string &configMetadata /* @out */,
            string &appMetadata /* @out */
            // XXX: appContextPath ?!
            ) = 0;

        // @text unlock
        // @param packageId: Package Id
        // @param version: Version
        virtual Core::hresult Unlock(
            const string &packageId,
            const string &version) = 0;

        // @text getLockedInfo
        // @param packageId: Package Id
        // @param version: Version
        virtual Core::hresult GetLockedInfo(
            const string &packageId,
            const string &version,
            string &unpackedPath /* @out */,
            string &configMetadata /* @out */,
            string &gatewayMetadataPath /* @out */,
            bool &locked /* @out */
            ) = 0;

   };

} // Exchange
} // WPEFramework
