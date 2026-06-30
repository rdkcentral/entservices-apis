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

    /** Allow the plugin to initialize to use service object */
    // @text initClient
    // @brief Create a client essos application.
    // @param clientId Additional options for creating the application.
    // @param success This should indicate the success of the operation.
    virtual Core::hresult InitClient(const std::string& clientId, bool& success /* @out */) = 0;
};

} // Exchange
} // WPEFramework

