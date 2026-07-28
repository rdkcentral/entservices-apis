// Compatibility bridge between WPEFramework::Exchange and Thunder::Exchange.
//
// ProxyStubGenerator/JsonGenerator (patched per wpeframework-tools_5.3.bb) rewrite
// WPEFramework -> Thunder in any interface header that declares an interface class
// (IRemoteControl.h, IVoiceControl.h, IConfiguration.h, ...), relocating those
// declarations to Thunder::Exchange. Plugin implementation code is never processed
// by those generators, so it still references things via WPEFramework::Exchange
// (e.g. "class RemoteControlImplementation : public Exchange::IRemoteControl" inside
// namespace WPEFramework::Plugin) and needs a bridge to keep resolving.
//
// Generated JsonEnum translation units need the reverse: their
// ENUM_CONVERSION_HANDLER specializations compile under Thunder::Core but need
// visibility into names that stay under WPEFramework::Exchange (e.g. constants in
// Ids.h, which the generators never rewrite since it declares no interface class).
//
// Both namespaces must be pre-declared (even empty) before either using-directive:
// this header is pulled in very early via Thunder's own core/Module.h -> "Module.h"
// chain, before any of our interface headers have opened Thunder::Exchange.
namespace WPEFramework {
	namespace Exchange {
	}
}

namespace Thunder {
	namespace Exchange {
	}
}

namespace WPEFramework {
	namespace Exchange {
		using namespace ::Thunder::Exchange;
	}
}

namespace Thunder {
	namespace Exchange {
		using namespace ::WPEFramework::Exchange;
	}
}
