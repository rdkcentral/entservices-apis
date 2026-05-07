#ifndef __IAPPACTIONS_H__
#define __IAPPACTIONS_H__

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    /*
     * @jsonrpc AppActions
     * @brief Interface for AppActions plugin
     */

    /* @json 1.0.0 @text:keep */
    struct EXTERNAL IAppActions : virtual public Core::IUnknown {
        enum { ID = ID_APP_ACTIONS };

        /* @event */
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_APP_ACTIONS_NOTIFICATION };

            /**
             * @brief Notifies when an action start event occurs.
             * @param initiator The ID of the app/ module initiating the action.
             * @param intent The intent string describing the action.
             * @param handlerAppId The ID of the app handling the action.
             */
            // @text onActionStartRequest
            virtual void onActionStartRequest(const string& initiator, const string& intent, const string& handlerAppId) {}
        };

        /**
         * @brief Starts an action for the given intent and handler app.
         * @param initiator The ID of the app/ module initiating the action.
         * @param intent The intent string describing the action.
         * @param handlerAppId The ID of the app handling the action.
         * @retval Core::ERROR_NONE: Success
         * @retval Core::ERROR_GENERAL: Failure
         * @details Initiates an action from the initiator to the AppActions with the specified intent.
         */
        // @text actionStart
        virtual Core::hresult ActionStart(const string& initiator, const string& intent, const string& handlerAppId) = 0;

        /** Register notification interface */
        virtual Core::hresult Register(INotification *notification) = 0;

        /** Unregister notification interface */
        virtual Core::hresult Unregister(INotification *notification) = 0;
    };
} // namespace Exchange
} // namespace WPEFramework

#endif // __IAPPACTIONS_H__
