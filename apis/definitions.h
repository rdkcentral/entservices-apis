// Compatibility bridge for the Exchange namespace, mirroring Thunder's own
// WPEFRAMEWORK_NESTEDNAMESPACE_COMPATIBILIY() pattern (see core/Portability.h,
// used by Thunder itself for Core, Plugin, PluginHost, RPC, etc).
//
// ProxyStubGenerator/JsonGenerator (patched per wpeframework-tools_5.3.bb) rewrite
// WPEFramework -> Thunder in any interface header that declares an interface class
// (IRemoteControl.h, IVoiceControl.h, IConfiguration.h, ...), relocating those
// declarations to Thunder::Exchange. Plugin implementation code is never processed
// by those generators, so it still references things via WPEFramework::Exchange
// (e.g. "class RemoteControlImplementation : public Exchange::IRemoteControl" inside
// namespace WPEFramework::Plugin) and needs this bridge to keep resolving.
WPEFRAMEWORK_NESTEDNAMESPACE_COMPATIBILIY(Exchange)

// The reverse direction: generated JsonEnum translation units compile their
// ENUM_CONVERSION_HANDLER specializations under Thunder::Core, but need visibility
// into whichever names ended up under WPEFramework::Exchange too (e.g. constants in
// Ids.h, which the generators never rewrite since it declares no interface class).
namespace Thunder {
	namespace Exchange {
		using namespace ::WPEFramework::Exchange;
	}
}
