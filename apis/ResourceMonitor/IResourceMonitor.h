#ifndef __IResourceMonitor_H
#define __IResourceMonitor_H

#include "Module.h"
namespace WPEFramework {
    namespace Exchange {
        struct EXTERNAL IResourceMonitor : virtual public Core::IUnknown {
            enum { ID = ID_RESOURCE_MONITOR };
            // @event
            struct EXTERNAL IProcessKilledNotification : virtual public Core::IUnknown {
                enum { ID = ID_RESOURCE_MONITOR_NOTIFICATION_PROCESS_KILLED };
                virtual void OnProcessKilled(const string& processName, const int pid, const int exitCode) {};
            };

            virtual Core::hresult Register(IProcessKilledNotification* notification) = 0;
            virtual Core::hresult Unregister(const IProcessKilledNotification* notification) = 0;

            virtual Core::hresult GetApiVersionNumber(int& version /* @out */) = 0;
            virtual Core::hresult GetState() = 0;
            virtual Core::hresult GetSystemResourceInfo(string& topresult /* @out */) = 0;


            //@brief Kill a process by PID
            //@param PID: Process ID of the process to be killed
            virtual Core::hresult KillProcess(int PID, bool& result /* @out */ ) = 0;

        };

    } // namespace Exchange
} // namespace WPEFramework

#endif // __IResourceMonitor_H