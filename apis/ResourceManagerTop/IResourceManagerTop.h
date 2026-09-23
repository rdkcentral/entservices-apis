#ifndef __IResourceManagerTop_H
#define __IResourceManagerTop_H

#include "Module.h"
namespace WPEFramework {
    namespace Exchange {
        struct EXTERNAL IResourceManagerTop : virtual public Core::IUnknown {
            enum { ID = ID_RESOURCE_MANAGER_TOP };

            // @event
            struct EXTERNAL IMultiplicationResultNotification : virtual public Core::IUnknown {
                enum { ID = ID_RESOURCE_MANAGER_TOP_NOTIFICATION_MULTIPLICATION_RESULT };
                virtual void OnMultiplicationResult(const int64_t result) {};
            };

            virtual Core::hresult Register(IMultiplicationResultNotification* notification) = 0;
            virtual Core::hresult Unregister(const IMultiplicationResultNotification* notification) = 0;
        };

    } // namespace Exchange
} // namespace WPEFramework

#endif // __IResourceManagerTop_H
