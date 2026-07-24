// Compatibility bridge for generated JsonEnum translation units.
// Thunder 5 native builds compile enum conversion macros under Thunder::Core
// while these interfaces intentionally remain in WPEFramework::Exchange for
// dual R4/Thunder compatibility.
namespace WPEFramework {
	namespace Exchange {
	}
}

namespace Thunder {
	namespace Exchange {
		using namespace ::WPEFramework::Exchange;
	}
}
