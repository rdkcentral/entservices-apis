 /*
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

// @json 1.0.0 @text:keep

struct EXTERNAL IRMTestHarness : virtual public Core::IUnknown {
    enum { ID = ID_RMTESTHARNESS };
    /** Create a logical RM client context */
    // @text initClient
    // @brief Create a client essos application.
    // @param success Operation result.
    // @param clientId Auto-assigned logical client identifier.
    virtual Core::hresult InitClient(bool& success /* @out*/, std::string& clientId /* @out*/) = 0;

    /** Destroy a logical client context */
    // @text destroyClient
    // @brief Destroy a client essos application.
    // @param clientId Logical client identifier.
    // @param success Operation result.
    virtual Core::hresult DestroyClient(const std::string& clientId, bool& success /* @out */) = 0;

    /** Request one resource */
    // @text requestResource
    // @brief Request a resource for a client.
    // @param clientId Logical client identifier.
    // @param type Resource type.
    // @param usage Usage bitmask.
    // @param priority Arbitration priority.
    // @param success Operation result.
    // @param assignedId Assigned resource id.
    virtual Core::hresult RequestResource(const std::string& clientId, int type, int usage, int priority,
                                          bool& success /* @out */, int& assignedId /* @out */) = 0;

    /** Release one resource */
    // @text releaseResource
    // @brief Release an assigned resource.
    // @param clientId Logical client identifier.
    // @param type Resource type.
    // @param assignedId Assigned resource id.
    // @param success Operation result.
    virtual Core::hresult ReleaseResource(const std::string& clientId, int type, int assignedId, bool& success /* @out */) = 0;

    /** Cleanup all clients/resources */
    // @text cleanupAll
    // @brief Releases and destroys all client contexts.
    // @param success Operation result.
    virtual Core::hresult CleanupAllClients(bool& success /* @out */) = 0;

    /** Get policy priority tie behavior */
    // @text getPolicyPriorityTie
    // @brief Returns policy tie-break behavior.
    // @param clientId Logical client identifier.
    // @param success Operation result.
    // @param requesterWins True if requester wins tie.
    virtual Core::hresult GetPolicyPriorityTie(const std::string& clientId,
                                               bool& success /* @out*/,
                                               bool& requesterWins /* @out*/) = 0;

    /** Get aggregate AV state */
    // @text getAVState
    // @brief Returns aggregate AV state for the client session.
    // @param clientId Logical client identifier.
    // @param success Operation result.
    // @param state AV state value.
    virtual Core::hresult GetAVState(const std::string& clientId,
                                     bool& success /* @out*/,
                                     int& state /* @out*/) = 0;

    /** Get resource count by type */
    // @text resourceGetCount
    // @brief Returns resource count for the given type.
    // @param clientId Logical client identifier.
    // @param type Resource type.
    // @param success Operation result.
    // @param count Resource count.
    virtual Core::hresult ResourceGetCount(const std::string& clientId,
                                           int type,
                                           bool& success /* @out*/,
                                           int& count /* @out*/) = 0;

    /** Get resource owner info */
    // @text resourceGetOwner
    // @brief Returns owner info for a resource.
    // @param clientId Logical client identifier.
    // @param type Resource type.
    // @param id Resource id.
    // @param success Operation result.
    // @param client Owner client identifier value.
    // @param priority Owner priority.
    virtual Core::hresult ResourceGetOwner(const std::string& clientId,
                                           int type,
                                           int id,
                                           bool& success /* @out*/,
                                           int& client /* @out*/,
                                           int& priority /* @out*/) = 0;

    /** Get resource capabilities */
    // @text resourceGetCaps
    // @brief Returns capability bitmask for a resource.
    // @param clientId Logical client identifier.
    // @param type Resource type.
    // @param id Resource id.
    // @param success Operation result.
    // @param caps Capability bitmask.
    virtual Core::hresult ResourceGetCaps(const std::string& clientId,
                                          int type,
                                          int id,
                                          bool& success /* @out*/,
                                          int& caps /* @out*/) = 0;

    /** Set resource state */
    // @text resourceSetState
    // @brief Sets the state for a resource.
    // @param clientId Logical client identifier.
    // @param type Resource type.
    // @param id Resource id.
    // @param state New state value.
    // @param success Operation result.
    virtual Core::hresult ResourceSetState(const std::string& clientId,
                                           int type,
                                           int id,
                                           int state,
                                           bool& success /* @out*/) = 0;

    /** Get resource state */
    // @text resourceGetState
    // @brief Returns current state for a resource.
    // @param clientId Logical client identifier.
    // @param type Resource type.
    // @param id Resource id.
    // @param success Operation result.
    // @param state Current state value.
    virtual Core::hresult ResourceGetState(const std::string& clientId,
                                           int type,
                                           int id,
                                           bool& success /* @out*/,
                                           int& state /* @out*/) = 0;

    /** Set request priority */
    // @text requestSetPriority
    // @brief Updates priority for an existing request.
    // @param clientId Logical client identifier.
    // @param type Resource type.
    // @param requestId Request id.
    // @param priority New priority.
    // @param success Operation result.
    virtual Core::hresult RequestSetPriority(const std::string& clientId,
                                             int type,
                                             int requestId,
                                             int priority,
                                             bool& success /* @out*/) = 0;

    /** Set request usage */
    // @text requestSetUsage
    // @brief Updates usage for an existing request.
    // @param clientId Logical client identifier.
    // @param type Resource type.
    // @param requestId Request id.
    // @param usage New usage value.
    // @param success Operation result.
    virtual Core::hresult RequestSetUsage(const std::string& clientId,
                                          int type,
                                          int requestId,
                                          int usage,
                                          bool& success /* @out*/) = 0;

    /** Cancel resource request */
    // @text requestCancel
    // @brief Cancels an existing request.
    // @param clientId Logical client identifier.
    // @param type Resource type.
    // @param requestId Request id.
    // @param success Operation result.
    virtual Core::hresult RequestCancel(const std::string& clientId,
                                        int type,
                                        int requestId,
                                        bool& success /* @out*/) = 0;

    /** Dump resource manager state */
    // @text dumpState
    // @brief Dumps current RM state.
    // @param clientId Logical client identifier.
    // @param success Operation result.
    virtual Core::hresult DumpState(const std::string& clientId,
                                    bool& success /* @out*/) = 0;

    /** Add application to blacklist */
    // @text addToBlackList
    // @brief Adds an application id to blacklist.
    // @param clientId Logical client identifier.
    // @param appId Application identifier.
    // @param success Operation result.
    virtual Core::hresult AddToBlackList(const std::string& clientId,
                                         const std::string& appId,
                                         bool& success /* @out*/) = 0;

    /** Remove application from blacklist */
    // @text removeFromBlackList
    // @brief Removes an application id from blacklist.
    // @param clientId Logical client identifier.
    // @param appId Application identifier.
    // @param success Operation result.
    virtual Core::hresult RemoveFromBlackList(const std::string& clientId,
                                              const std::string& appId,
                                              bool& success /* @out*/) = 0;

    /** Get blacklist state */
    // @text getBlackListState
    // @brief Returns whether blacklist feature is enabled.
    // @param clientId Logical client identifier.
    // @param success Operation result.
    // @param blackListEnabled Blacklist state.
    virtual Core::hresult GetBlackListState(const std::string& clientId,
                                            bool& success /* @out*/,
                                            bool& blackListEnabled /* @out*/) = 0;
};

} // Exchange
} // WPEFramework

