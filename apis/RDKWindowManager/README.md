# RDKWindowManager API Examples

This document provides practical examples for testing the RDKWindowManager APIs using curl commands.

## AddKeyIntercepts API

The `addKeyIntercepts` method registers multiple key intercepts in a single operation. This allows you to configure which applications receive specific key events.

### API Parameters

The `intercepts` parameter is a JSON string containing an array of key intercept configurations. Each intercept configuration includes:

- **client** or **callSign**: The name of the client application that should receive the key events
- **keyCode**: The numeric key code to intercept (e.g., 10 for a specific key)
- **modifiers**: An array of modifier keys that must be pressed along with the key (e.g., ["shift", "ctrl"])

### Example 1: Single Key Intercept

This example registers a single key intercept for key code 10 with a shift modifier for the "searchanddiscovery" client:

```bash
curl -H 'content-type:text/plain;' --data-binary '{
  "jsonrpc": "2.0",
  "id": 1,
  "method": "org.rdk.RDKWindowManager.addKeyIntercepts",
  "params": {
    "intercepts": "[{\"client\":\"searchanddiscovery\",\"keyCode\":10,\"modifiers\":[\"shift\"]}]"
  }
}' http://127.0.0.1:9998/jsonrpc
```

### Example 2: Multiple Key Intercepts for Single Client

This example registers multiple key intercepts for the same client:

```bash
curl -H 'content-type:text/plain;' --data-binary '{
  "jsonrpc": "2.0",
  "id": 2,
  "method": "org.rdk.RDKWindowManager.addKeyIntercepts",
  "params": {
    "intercepts": "[{\"client\":\"myapp\",\"keyCode\":10,\"modifiers\":[\"shift\"]},{\"client\":\"myapp\",\"keyCode\":27,\"modifiers\":[]}]"
  }
}' http://127.0.0.1:9998/jsonrpc
```

### Example 3: Key Intercepts for Multiple Clients

This example registers key intercepts for different client applications:

```bash
curl -H 'content-type:text/plain;' --data-binary '{
  "jsonrpc": "2.0",
  "id": 3,
  "method": "org.rdk.RDKWindowManager.addKeyIntercepts",
  "params": {
    "intercepts": "[{\"client\":\"Netflix\",\"keyCode\":36,\"modifiers\":[\"ctrl\"]},{\"client\":\"searchanddiscovery\",\"keyCode\":10,\"modifiers\":[\"shift\",\"ctrl\"]}]"
  }
}' http://127.0.0.1:9998/jsonrpc
```

### Example 4: Key Intercept Without Modifiers

This example shows how to register a key intercept without any modifier keys:

```bash
curl -H 'content-type:text/plain;' --data-binary '{
  "jsonrpc": "2.0",
  "id": 4,
  "method": "org.rdk.RDKWindowManager.addKeyIntercepts",
  "params": {
    "intercepts": "[{\"client\":\"homeapp\",\"keyCode\":13,\"modifiers\":[]}]"
  }
}' http://127.0.0.1:9998/jsonrpc
```

### Expected Response

On success, the API returns:

```json
{
  "jsonrpc": "2.0",
  "id": 1,
  "result": null
}
```

### Common Key Codes

Here are some common key codes you might use:

- **10**: Number key or custom key
- **13**: Enter/Return key
- **27**: Escape key
- **36**: Home key
- **37**: Left arrow
- **38**: Up arrow
- **39**: Right arrow
- **40**: Down arrow

### Common Modifiers

The following modifiers can be used:

- **shift**: Shift key
- **ctrl**: Control key
- **alt**: Alt key
- **meta**: Meta/Windows/Command key

## Related APIs

### AddKeyIntercept (Single)

For adding a single key intercept, use the `addKeyIntercept` method:

```bash
curl -H 'content-type:text/plain;' --data-binary '{
  "jsonrpc": "2.0",
  "id": 5,
  "method": "org.rdk.RDKWindowManager.addKeyIntercept",
  "params": {
    "intercept": "{\"client\":\"myapp\",\"keyCode\":10,\"modifiers\":[\"shift\"]}"
  }
}' http://127.0.0.1:9998/jsonrpc
```

### RemoveKeyIntercept

To remove a previously registered key intercept:

```bash
curl -H 'content-type:text/plain;' --data-binary '{
  "jsonrpc": "2.0",
  "id": 6,
  "method": "org.rdk.RDKWindowManager.removeKeyIntercept",
  "params": {
    "intercept": "{\"client\":\"myapp\",\"keyCode\":10,\"modifiers\":[\"shift\"]}"
  }
}' http://127.0.0.1:9998/jsonrpc
```

## Notes

1. The `intercepts` parameter must be a JSON string (note the escaped quotes in the examples)
2. The Thunder framework endpoint is typically at `http://127.0.0.1:9998/jsonrpc` but may vary based on your configuration
3. Ensure the client application name matches an existing registered application in the system
4. Key intercepts allow applications to receive key events even when they are not in focus
