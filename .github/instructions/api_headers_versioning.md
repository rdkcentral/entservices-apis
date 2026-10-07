---
applyTo: "apis/**/I*.h"
---

## Changes to existing APIs

It is important to maintain compatibility with existing code when updating existing APIs.
Existing code includes both the implementation of the API (which may include the old or new API
header file) and API clients (which similarly may include the old or new API file).
To ensure this, follow the rules in this document.
Failure to follow these rules should be flagged as an API error.

### Definitions

"Existing API" means a class extending the Core::IUnknown interface that existed in a previous
version of the header file being reviewed.
"Existing code" is implementation of the API or clients of the API that have previously worked
with the existing API.
"Public callable API" means methods on the API that are public, virtual, and follow the pattern of
returning Core::hresult (or uint32_t for old code).

### Review checklist

Use this checklist during API header review for existing interfaces:

- Existing public callable methods keep their original order.
- Existing public callable methods are not removed.
- Existing public callable method signatures are unchanged.
- New public callable methods are appended at the end of the interface.
- New methods are not pure virtual and have a default implementation.
- If a version macro is used, it is bumped for API surface changes.
- New methods document the added version in their @details section.

### Do not reorder methods

The virtual functions that comprise the public callable API must not be reordered. Doing so would
cause problems with the vtable of the class.
New public API functions must be placed last, after all existing API functions.

Example:

```cpp
// Good: New method appended at the end
virtual Core::hresult ExistingMethod1() = 0;
virtual Core::hresult ExistingMethod2() = 0;
virtual Core::hresult NewMethod() { return Core::ERROR_NOT_SUPPORTED; }

// Bad: Existing methods reordered, new method inserted in the middle
virtual Core::hresult ExistingMethod2() = 0;
virtual Core::hresult NewMethod() { return Core::ERROR_NOT_SUPPORTED; }
virtual Core::hresult ExistingMethod1() = 0;
```

### Immutability of methods

A public API function must not be removed. It can be marked with the "@deprecated" tag.
A public API function must not change its parameters, whether adding or removing them, or changing
their type.

Example:

```cpp
// Good: Existing signature preserved
virtual Core::hresult Tune(const string& channel) = 0;

// Bad: Signature changed by adding a parameter
virtual Core::hresult Tune(const string& channel, bool force) = 0;
```

### Adding methods

All methods added to an existing API class must have an implementation, and must thus not be
declared as pure virtual. The recommended implementation is to return "not supported".

Example:

```cpp
// Good: New method with default implementation
virtual Core::hresult NewMethod() { return Core::ERROR_NOT_SUPPORTED; }

// Bad: New pure virtual method on an existing interface
virtual Core::hresult NewMethod() = 0;
```

### Use the preprocessor to check versioning (recommended)

The easiest way for both implementation and client to determine which version of the API header
they are including is to define a macro to contain the version number, e.g.

```
#define IEXAMPLE_VERSION 1
```

If using this strategy, the version number must be bumped when the API changes. The purpose is to
make API implementation able to conditionally implement the new functions only when including the
updated header file, and likewise for client code to determine if it's possible to call the new
API functions.
Bump the version at least (but not limited to) when adding new methods or enums.
It should be documented in the @details section on new methods which version they are added in.
The API header file must not contain conditional sections depending on the version. It is assumed
to be the newest version always.
The implementation and clients can use the version macro to ensure that they do not prematurely
use a method that is not present in the version they're compiling against.

Example:

```cpp
// Header
#define IEXAMPLE_VERSION 2

// Client or implementation side
#if IEXAMPLE_VERSION >= 2
	api->NewMethod();
#endif
```
