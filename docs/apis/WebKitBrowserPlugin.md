<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.WebKitBrowser_Plugin"></a>
# WebKitBrowser Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/WebKitBrowser/CHANGELOG.md)**

A WebKitBrowser plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Properties](#head.Properties)
- [Notifications](#head.Notifications)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `WebKitBrowser` plugin provides an interface for WebKitBrowser.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.WebKitBrowser) |
| classname | string | Class name: *WebKitBrowser* |
| locator | string | Library name: *libWPEFrameworkWebKitBrowser.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the WebKitBrowser plugin:

WebKitBrowser interface methods:

| Method | Description |
| :-------- | :-------- |
| [reset](#method.reset) | Resets application data |
| [allocated](#method.allocated) |  |
| [identifier](#method.identifier) |  |
| [isOperational](#method.isOperational) |  |
| [name](#method.name) |  |
| [process](#method.process) |  |
| [processes](#method.processes) |  |
| [resident](#method.resident) |  |
| [shared](#method.shared) |  |
| [addUserScript](#method.addUserScript) | Add user script to be executed at document start. |
| [collectGarbage](#method.collectGarbage) | Initiate garbage collection |
| [setcoookiejar](#method.setcoookiejar) |  |
| [cookieJarChanged](#method.cookieJarChanged) | Notifies that cookies were added, removed or modified. |
| [getFPS](#method.getFPS) |  |
| [getURL](#method.getURL) |  |
| [hide](#method.hide) |  |
| [loadFailed](#method.loadFailed) | Browser failed to load page |
| [loadFinished](#method.loadFinished) | Initial HTML document has been completely loaded and parsed |
| [pageClosure](#method.pageClosure) | Notifies that the web page requests to close its window |
| [removeAllUserScripts](#method.removeAllUserScripts) | Remove all user scripts. |
| [runJavaScript](#method.runJavaScript) | Run javascript in main frame. |
| [setURL](#method.setURL) |  |
| [uRLChange](#method.uRLChange) | Signals a URL change in the browser |
| [visibilityChange](#method.visibilityChange) | Signals a visibility change of the browser |

<a id="method.reset"></a>
## *reset [<sup>method</sup>](#head.Methods)*

Resets application data

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Type of reset to perform |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.WebKitBrowser.reset",
    "params": {
        "type": "FACTORY"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.WebKitBrowser.reset", "params": {"type": "FACTORY"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.allocated"></a>
## *allocated [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.WebKitBrowser.allocated"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.WebKitBrowser.allocated"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.identifier"></a>
## *identifier [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.WebKitBrowser.identifier"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.WebKitBrowser.identifier"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="method.isOperational"></a>
## *isOperational [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.WebKitBrowser.isOperational"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.WebKitBrowser.isOperational"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="method.name"></a>
## *name [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.WebKitBrowser.name"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.WebKitBrowser.name"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="method.process"></a>
## *process [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.processname | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.process | IProcessMemory |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.WebKitBrowser.process",
    "params": {
        "processname": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.WebKitBrowser.process", "params": {"processname": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "process": ""
    }
}
```

<a id="method.processes"></a>
## *processes [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.processnames | IStringIterator |  |
| result.processnames[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.WebKitBrowser.processes"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.WebKitBrowser.processes"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": [
        ""
    ]
}
```

<a id="method.resident"></a>
## *resident [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.WebKitBrowser.resident"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.WebKitBrowser.resident"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="method.shared"></a>
## *shared [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.WebKitBrowser.shared"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.WebKitBrowser.shared"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

<a id="method.addUserScript"></a>
## *addUserScript [<sup>method</sup>](#head.Methods)*

Add user script to be executed at document start.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.script | string | Utf8 encoded JS code string. |
| params.topFrameOnly | bool |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.WebKitBrowser.addUserScript",
    "params": {
        "script": "",
        "topFrameOnly": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.WebKitBrowser.addUserScript", "params": {"script": "", "topFrameOnly": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.collectGarbage"></a>
## *collectGarbage [<sup>method</sup>](#head.Methods)*

Initiate garbage collection

### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.WebKitBrowser.collectGarbage"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.WebKitBrowser.collectGarbage"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="method.cookieJar"></a>
## *cookieJar [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.version | integer |  |
| params.checksum | integer |  |
| params.payload | string | base64 encoded JSON string response to be delivered to $badger.callback |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.WebKitBrowser.cookieJar",
    "params": {
        "version": 0,
        "checksum": 0,
        "payload": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.WebKitBrowser.cookieJar", "params": {"version": 0, "checksum": 0, "payload": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="method.cookieJarChanged"></a>
## *cookieJarChanged [<sup>method</sup>](#head.Methods)*

Notifies that cookies were added, removed or modified.

### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.WebKitBrowser.cookieJarChanged"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.WebKitBrowser.cookieJarChanged"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="method.getFPS"></a>
## *getFPS [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.WebKitBrowser.getFPS"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.WebKitBrowser.getFPS"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```

<a id="method.getURL"></a>
## *getURL [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.WebKitBrowser.getURL"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.WebKitBrowser.getURL"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="method.hide"></a>
## *hide [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hidden | bool | hidden (true) or visible (false) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.WebKitBrowser.hide",
    "params": {
        "hidden": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.WebKitBrowser.hide", "params": {"hidden": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="method.loadFailed"></a>
## *loadFailed [<sup>method</sup>](#head.Methods)*

Browser failed to load page

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.WebKitBrowser.loadFailed",
    "params": {
        "URL": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.WebKitBrowser.loadFailed", "params": {"URL": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

<a id="method.loadFinished"></a>
## *loadFinished [<sup>method</sup>](#head.Methods)*

Initial HTML document has been completely loaded and parsed

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |
| params.httpstatus | integer | The response code of main resource request (e.g. 200) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.WebKitBrowser.loadFinished",
    "params": {
        "URL": "",
        "httpstatus": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.WebKitBrowser.loadFinished", "params": {"URL": "", "httpstatus": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="method.pageClosure"></a>
## *pageClosure [<sup>method</sup>](#head.Methods)*

Notifies that the web page requests to close its window

### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.WebKitBrowser.pageClosure"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.WebKitBrowser.pageClosure"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": null
}
```

<a id="method.removeAllUserScripts"></a>
## *removeAllUserScripts [<sup>method</sup>](#head.Methods)*

Remove all user scripts.

### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.WebKitBrowser.removeAllUserScripts"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.WebKitBrowser.removeAllUserScripts"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```

<a id="method.runJavaScript"></a>
## *runJavaScript [<sup>method</sup>](#head.Methods)*

Run javascript in main frame.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.script | string | Utf8 encoded JS code string. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.WebKitBrowser.runJavaScript",
    "params": {
        "script": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.WebKitBrowser.runJavaScript", "params": {"script": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="method.setURL"></a>
## *setURL [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.WebKitBrowser.setURL",
    "params": {
        "URL": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.WebKitBrowser.setURL", "params": {"URL": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
}
```

<a id="method.uRLChange"></a>
## *uRLChange [<sup>method</sup>](#head.Methods)*

Signals a URL change in the browser

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |
| params.loaded | bool | loaded (true) or not (false) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.WebKitBrowser.uRLChange",
    "params": {
        "URL": "",
        "loaded": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.WebKitBrowser.uRLChange", "params": {"URL": "", "loaded": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
}
```

<a id="method.visibilityChange"></a>
## *visibilityChange [<sup>method</sup>](#head.Methods)*

Signals a visibility change of the browser

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hidden | bool | hidden (true) or visible (false) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.WebKitBrowser.visibilityChange",
    "params": {
        "hidden": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.WebKitBrowser.visibilityChange", "params": {"hidden": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```


<a id="head.Properties"></a>
# Properties
The following properties are provided by the WebKitBrowser plugin:

WebKitBrowser interface properties:

| Method | Description |
| :-------- | :-------- |
| [contentLink](#property.contentLink)<sup>WO</sup> | URI of the associated application-specific content |
| [identifier](#property.identifier)<sup>RO</sup> | Application-specific identification string |
| [language](#property.language) | Current application user interface language |
| [launchPoint](#property.launchPoint) | Application launching point |
| [visible](#property.visible) | Current application visibility |
| [bridgeEvent](#property.bridgeEvent)<sup>WO</sup> | Send legacy $badger event. |
| [bridgeReply](#property.bridgeReply)<sup>WO</sup> | Response for legacy $badger. |
| [fPS](#property.fPS)<sup>RO</sup> | Current framerate the browser is rendering at |
| [hTTPCookieAcceptPolicy](#property.hTTPCookieAcceptPolicy) | HTTP cookies accept policy |
| [localStorageEnabled](#property.localStorageEnabled) | Controls the local storage availability |
| [mixedContentPolicy](#property.mixedContentPolicy) | Mixed content policy |
| [securityProfile](#property.securityProfile) | Security profile for secure connections |
| [uRL](#property.uRL) | Page loaded in the browser |
| [userAgent](#property.userAgent) | UserAgent string used by the browser |
| [userScripts](#property.userScripts) | User scripts used by the browser |
| [userStyleSheets](#property.userStyleSheets) | User style sheets used by the browser |
| [visibility](#property.visibility) | Browser window visibility state |

<a id="property.ContentLink"></a>
## *ContentLink [<sup>property</sup>](#head.Properties)*

URI of the associated application-specific content

> This property is write-only.
### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).link | string | Content URI (e.g. https://youtube.com) |

### Examples


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.WebKitBrowser.contentLink",
    "params": {
        "link": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.WebKitBrowser.contentLink", "params": {"link": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="property.Identifier"></a>
## *Identifier [<sup>property</sup>](#head.Properties)*

Application-specific identification string

> This property is read-only.
### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).id | string | Identifier string |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.WebKitBrowser.identifier"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.WebKitBrowser.identifier"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "id": ""
    }
}
```

<a id="property.Language"></a>
## *Language [<sup>property</sup>](#head.Properties)*

Current application user interface language

### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).language | string | Language string as per RFC5646 (e.g. en) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.WebKitBrowser.language"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.WebKitBrowser.language"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "language": ""
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.WebKitBrowser.language",
    "params": {
        "language": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.WebKitBrowser.language", "params": {"language": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```

<a id="property.LaunchPoint"></a>
## *LaunchPoint [<sup>property</sup>](#head.Properties)*

Application launching point

### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).point | string |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.WebKitBrowser.launchPoint"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.WebKitBrowser.launchPoint"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "point": "UNDEFINED"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.WebKitBrowser.launchPoint",
    "params": {
        "point": "UNDEFINED"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.WebKitBrowser.launchPoint", "params": {"point": "UNDEFINED"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="property.Visible"></a>
## *Visible [<sup>property</sup>](#head.Properties)*

Current application visibility

### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).visiblity | bool |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.WebKitBrowser.visible"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.WebKitBrowser.visible"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "visiblity": true
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.WebKitBrowser.visible",
    "params": {
        "visiblity": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.WebKitBrowser.visible", "params": {"visiblity": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="property.BridgeEvent"></a>
## *BridgeEvent [<sup>property</sup>](#head.Properties)*

Send legacy $badger event.

> This property is write-only.
### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).payload | string | base64 encoded JSON string response to be delivered to $badger.callback |

### Examples


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.WebKitBrowser.bridgeEvent",
    "params": {
        "payload": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.WebKitBrowser.bridgeEvent", "params": {"payload": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": null
}
```

<a id="property.BridgeReply"></a>
## *BridgeReply [<sup>property</sup>](#head.Properties)*

Response for legacy $badger.

> This property is write-only.
### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).payload | string | base64 encoded JSON string response to be delivered to $badger.callback |

### Examples


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.WebKitBrowser.bridgeReply",
    "params": {
        "payload": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.WebKitBrowser.bridgeReply", "params": {"payload": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": null
}
```

<a id="property.FPS"></a>
## *FPS [<sup>property</sup>](#head.Properties)*

Current framerate the browser is rendering at

> This property is read-only.
### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).fps | integer | Current FPS |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.WebKitBrowser.fPS"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.WebKitBrowser.fPS"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": {
        "fps": 0
    }
}
```

<a id="property.HTTPCookieAcceptPolicy"></a>
## *HTTPCookieAcceptPolicy [<sup>property</sup>](#head.Properties)*

HTTP cookies accept policy

### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).policy | string | HTTP Cookie Accept Policy Type (e.g. always) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": {
        "policy": "ALWAYS"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy",
    "params": {
        "policy": "ALWAYS"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy", "params": {"policy": "ALWAYS"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": null
}
```

<a id="property.LocalStorageEnabled"></a>
## *LocalStorageEnabled [<sup>property</sup>](#head.Properties)*

Controls the local storage availability

### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).enabled | bool |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.WebKitBrowser.localStorageEnabled"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.WebKitBrowser.localStorageEnabled"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": {
        "enabled": true
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.WebKitBrowser.localStorageEnabled",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.WebKitBrowser.localStorageEnabled", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": null
}
```

<a id="property.MixedContentPolicy"></a>
## *MixedContentPolicy [<sup>property</sup>](#head.Properties)*

Mixed content policy

### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).policy | string | Mixed content policy type |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.WebKitBrowser.mixedContentPolicy"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.WebKitBrowser.mixedContentPolicy"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": {
        "policy": "ALLOWED"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.WebKitBrowser.mixedContentPolicy",
    "params": {
        "policy": "ALLOWED"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.WebKitBrowser.mixedContentPolicy", "params": {"policy": "ALLOWED"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": null
}
```

<a id="property.SecurityProfile"></a>
## *SecurityProfile [<sup>property</sup>](#head.Properties)*

Security profile for secure connections

### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).profile | string | Security profile for secure connections (e.g. compatible) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.WebKitBrowser.securityProfile"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.WebKitBrowser.securityProfile"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": {
        "profile": ""
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.WebKitBrowser.securityProfile",
    "params": {
        "profile": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.WebKitBrowser.securityProfile", "params": {"profile": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": null
}
```

<a id="property.URL"></a>
## *URL [<sup>property</sup>](#head.Properties)*

Page loaded in the browser

### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).url | string | Loaded URL (e.g. https://example.com) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.WebKitBrowser.uRL"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.WebKitBrowser.uRL"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": {
        "url": ""
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.WebKitBrowser.uRL",
    "params": {
        "url": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.WebKitBrowser.uRL", "params": {"url": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": null
}
```

<a id="property.UserAgent"></a>
## *UserAgent [<sup>property</sup>](#head.Properties)*

UserAgent string used by the browser

### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).useragent | string | UserAgent value (e.g. Mozilla/5.0 (Linux; x86_64 GNU/Linux) AppleWebKit/601.1 (KHTML, like Gecko) Version/8.0 Safari/601.1 WP) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.WebKitBrowser.userAgent"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.WebKitBrowser.userAgent"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": {
        "useragent": ""
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.WebKitBrowser.userAgent",
    "params": {
        "useragent": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.WebKitBrowser.userAgent", "params": {"useragent": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": null
}
```

<a id="property.UserScripts"></a>
## *UserScripts [<sup>property</sup>](#head.Properties)*

User scripts used by the browser

### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).uris | IStringIterator | JSON array containing URIs pointing to user scripts, supported protocols: file:// |
| (property).uris[#] | string |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "method": "org.rdk.WebKitBrowser.userScripts"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.WebKitBrowser.userScripts"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": [
        ""
    ]
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "method": "org.rdk.WebKitBrowser.userScripts",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.WebKitBrowser.userScripts", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": null
}
```

<a id="property.UserStyleSheets"></a>
## *UserStyleSheets [<sup>property</sup>](#head.Properties)*

User style sheets used by the browser

### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).uris | IStringIterator | JSON array containing URIs pointing to user scripts, supported protocols: file:// |
| (property).uris[#] | string |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "method": "org.rdk.WebKitBrowser.userStyleSheets"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.WebKitBrowser.userStyleSheets"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": [
        ""
    ]
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "method": "org.rdk.WebKitBrowser.userStyleSheets",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.WebKitBrowser.userStyleSheets", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": null
}
```

<a id="property.Visibility"></a>
## *Visibility [<sup>property</sup>](#head.Properties)*

Browser window visibility state

### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).visible | string | Visiblity state (e.g. ) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "method": "org.rdk.WebKitBrowser.visibility"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 30, "method": "org.rdk.WebKitBrowser.visibility"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": {
        "visible": "HIDDEN"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "method": "org.rdk.WebKitBrowser.visibility",
    "params": {
        "visible": "HIDDEN"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 30, "method": "org.rdk.WebKitBrowser.visibility", "params": {"visible": "HIDDEN"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": null
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the WebKitBrowser plugin:

WebKitBrowser interface events:

| Event | Description |
| :-------- | :-------- |
| [visibilityChange](#event.visibilityChange) | Application visibility changes |
| [closure](#event.closure) |  |
| [hidden](#event.hidden) |  |
| [loadFinished](#event.loadFinished) |  |
| [uRLChanged](#event.uRLChanged) |  |

<a id="event.visibilityChange"></a>
## *visibilityChange [<sup>event</sup>](#head.Notifications)*

Application visibility changes

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hidden | bool | hidden (true) or visible (false) |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.WebKitBrowser.visibilityChange",
    "params": {
        "hidden": true
    }
}
```

<a id="event.closure"></a>
## *closure [<sup>event</sup>](#head.Notifications)*



### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.WebKitBrowser.closure"
}
```

<a id="event.hidden"></a>
## *hidden [<sup>event</sup>](#head.Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hidden | bool | hidden (true) or visible (false) |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.WebKitBrowser.hidden",
    "params": {
        "hidden": true
    }
}
```

<a id="event.loadFinished"></a>
## *loadFinished [<sup>event</sup>](#head.Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.WebKitBrowser.loadFinished",
    "params": {
        "URL": ""
    }
}
```

<a id="event.uRLChanged"></a>
## *uRLChanged [<sup>event</sup>](#head.Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.WebKitBrowser.uRLChanged",
    "params": {
        "URL": ""
    }
}
```
