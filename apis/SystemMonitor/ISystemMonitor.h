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
            
	    // @event	    
	    struct EXTERNAL INotification : virtual public Core::IUnknown
	    {
		enum { ID = ID_SYSTEM_MONITOR_NOTIFICATION };
		/* 
		 * Called when memory usage crossed the configured threahold
		 */
		virtual void OnLowMemory( const uint64_t freeMemory, const uint64_t threshold) {}
		/*
         	 * Called when CPU usage crosses the configured high-usage threshold.
         	 */
        	virtual void OnHighCpuUsage(const double cpuUsage, const double threshold) {}
		};

		/* COM RPC notification subscription */
	        virtual Core::hresult Register(Exchange::ISystemMonitor::INotification* notification) = 0;

	        virtual Core::hresult Unregister(Exchange::ISystemMonitor::INotification* notification) = 0;

            //using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
 
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

	    /*
     * Temporary APIs for notification testing.
     * These can be removed after validation.
     */
    virtual Core::hresult TriggerMemoryNotification() = 0;

    virtual Core::hresult TriggerCpuNotification() = 0;
        };
    }
}

