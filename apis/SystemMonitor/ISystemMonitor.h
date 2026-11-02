#pragma once
#include "Module.h"
 
// @stubgen:include <com/IIteratorType.h>
 
//Interface for system monitoring functions
 
namespace WPEFramework
{
    namespace Exchange
    {
        /* @json 1.0.0 @text:keep */
        struct EXTERNAL ISystemMonitor : virtual public Core::IUnknown
        {
            enum { ID = ID_SYSTEM_MONITOR };
 
            using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
 
            virtual ~ISystemMonitor() = default;
 
            /**
             * @brief Get system uptime.
             
             * @text uptime
             *
             * @param uptime System uptime in seconds.
             *
             * @return Core::ERROR_NONE on success.
             */
            virtual Core::hresult Uptime(uint64_t& uptime /* @out */) const = 0;
 
            /**
             * @brief Get total system memory.
             * @text totalMemory
             *
             * @param memory Total memory in bytes.
             *
             * @return Core::ERROR_NONE on success.
             */
            virtual Core::hresult TotalMemory(uint64_t& memory /* @out */) const = 0;
 
            /**
             * @brief Get currently available system memory.
             *
             * @text freeMemory
             * @param memory Available memory in bytes.
             *
             * @return Core::ERROR_NONE on success.
             */
            virtual Core::hresult FreeMemory(uint64_t& memory /*@out */) const = 0;
 
            /**
             * @brief Get current CPU utilization.
             *
             * @text cpuLoad
             * @param load CPU utilization percentage (0.0 - 100.0).
             *
             * @return Core::ERROR_NONE on success.
             */
            virtual Core::hresult CpuLoad(double& load /*@out */)  const = 0;
        };
    }
}

