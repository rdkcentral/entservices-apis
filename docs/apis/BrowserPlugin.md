<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Browser_Plugin"></a>
# Browser Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/Browser/CHANGELOG.md)**

A Browser plugin for Thunder framework.

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

The `Browser` plugin provides an interface for Browser.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Browser) |
| classname | string | Class name: *Browser* |
| locator | string | Library name: *libWPEFrameworkBrowser.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the Browser plugin:

Browser interface methods:

| Method | Description |
| :-------- | :-------- |
| [addUserScript](#method.addUserScript) | Add user script to be executed at document start. |
| [collectGarbage](#method.collectGarbage) | Initiate garbage collection |
| [cookieJar](#method.cookieJar) |  |
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

<a id="method.addUserScript"></a>
## *addUserScript [<sup>method</sup>](#head.Methods)*

Add user script to be executed at document start.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.script | string | Utf8 encoded JS code string. |
| params.topFrameOnly | bool | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Browser.addUserScript",
    "params": {
        "script": "",
        "topFrameOnly": true
    }
}
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
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.Browser.collectGarbage"
}
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
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.version | uint32_t | - |
| params.checksum | uint32_t | - |
| params.payload | string | base64 encoded JSON string response to be delivered to $badger.callback |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.Browser.cookieJar",
    "params": {
        "version": 0,
        "checksum": 0,
        "payload": ""
    }
}
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
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.Browser.cookieJarChanged"
}
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
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.Browser.getFPS"
}
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
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.Browser.getURL"
}
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
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hidden | bool | hidden (true) or visible (false) |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.Browser.hide",
    "params": {
        "hidden": true
    }
}
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
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.Browser.loadFailed",
    "params": {
        "URL": ""
    }
}
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
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |
| params.httpstatus | int32_t | The response code of main resource request (e.g. 200) |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.Browser.loadFinished",
    "params": {
        "URL": "",
        "httpstatus": 0
    }
}
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
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.Browser.pageClosure"
}
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
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.Browser.removeAllUserScripts"
}
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
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.script | string | Utf8 encoded JS code string. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.Browser.runJavaScript",
    "params": {
        "script": ""
    }
}
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
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.Browser.setURL",
    "params": {
        "URL": ""
    }
}
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
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |
| params.loaded | bool | loaded (true) or not (false) |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.Browser.uRLChange",
    "params": {
        "URL": "",
        "loaded": true
    }
}
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
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hidden | bool | hidden (true) or visible (false) |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.Browser.visibilityChange",
    "params": {
        "hidden": true
    }
}
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
The following properties are provided by the Browser plugin:

Browser interface properties:

| Method | Description |
| :-------- | :-------- |
| [BridgeEvent](#property.BridgeEvent)<sup>WO</sup> | Send legacy $badger event. |
| [BridgeReply](#property.BridgeReply)<sup>WO</sup> | Response for legacy $badger. |
| [FPS](#property.FPS)<sup>RO</sup> | Current framerate the browser is rendering at |
| [HTTPCookieAcceptPolicy](#property.HTTPCookieAcceptPolicy) | HTTP cookies accept policy |
| [LocalStorageEnabled](#property.LocalStorageEnabled) | Controls the local storage availability |
| [MixedContentPolicy](#property.MixedContentPolicy) | Mixed content policy |
| [SecurityProfile](#property.SecurityProfile) | Security profile for secure connections |
| [URL](#property.URL) | Page loaded in the browser |
| [UserAgent](#property.UserAgent) | UserAgent string used by the browser |
| [UserScripts](#property.UserScripts) | User scripts used by the browser |
| [UserStyleSheets](#property.UserStyleSheets) | User style sheets used by the browser |
| [Visibility](#property.Visibility) | Browser window visibility state |

<a id="property.BridgeEvent"></a>
## *BridgeEvent [<sup>property</sup>](#head.Properties)*

Send legacy $badger event.

> This property is write-only.
### Events
No events are associated with this method.
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
    "method": "org.rdk.Browser.bridgeEvent",
    "params": {
        "payload": ""
    }
}
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
No events are associated with this method.
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
    "method": "org.rdk.Browser.bridgeReply",
    "params": {
        "payload": ""
    }
}
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
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).fps | uint8_t | Current FPS |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.Browser.fPS"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": ""
}
```

<a id="property.HTTPCookieAcceptPolicy"></a>
## *HTTPCookieAcceptPolicy [<sup>property</sup>](#head.Properties)*

HTTP cookies accept policy

### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).policy | HTTPCookieAcceptPolicyType | HTTP Cookie Accept Policy Type (e.g. always) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.Browser.hTTPCookieAcceptPolicy"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": "ALWAYS"
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.Browser.hTTPCookieAcceptPolicy",
    "params": {
        "policy": "ALWAYS"
    }
}
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
No events are associated with this method.
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
    "method": "org.rdk.Browser.localStorageEnabled"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": true
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.Browser.localStorageEnabled",
    "params": {
        "enabled": true
    }
}
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
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).policy | MixedContentPolicyType | Mixed content policy type |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.Browser.mixedContentPolicy"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": "ALLOWED"
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.Browser.mixedContentPolicy",
    "params": {
        "policy": "ALLOWED"
    }
}
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
No events are associated with this method.
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
    "method": "org.rdk.Browser.securityProfile"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": ""
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.Browser.securityProfile",
    "params": {
        "profile": ""
    }
}
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
No events are associated with this method.
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
    "method": "org.rdk.Browser.uRL"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": ""
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.Browser.uRL",
    "params": {
        "url": ""
    }
}
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
No events are associated with this method.
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
    "method": "org.rdk.Browser.userAgent"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": ""
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.Browser.userAgent",
    "params": {
        "useragent": ""
    }
}
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
No events are associated with this method.
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
    "method": "org.rdk.Browser.userScripts"
}
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
    "method": "org.rdk.Browser.userScripts",
    "params": {
        "uris": [
            ""
        ]
    }
}
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
No events are associated with this method.
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
    "method": "org.rdk.Browser.userStyleSheets"
}
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
    "method": "org.rdk.Browser.userStyleSheets",
    "params": {
        "uris": [
            ""
        ]
    }
}
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
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).visible | VisibilityType | Visiblity state (e.g. ) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "method": "org.rdk.Browser.visibility"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": "HIDDEN"
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "method": "org.rdk.Browser.visibility",
    "params": {
        "visible": "HIDDEN"
    }
}
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

The following events are provided by the Browser plugin:

Browser interface events:

| Event | Description |
| :-------- | :-------- |
| [closure](#event.closure) |  |
| [hidden](#event.hidden) |  |
| [loadFinished](#event.loadFinished) |  |
| [uRLChanged](#event.uRLChanged) |  |

<a id="event.closure"></a>
## *closure [<sup>event</sup>](#head.Notifications)*



### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.Browser.closure"
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
    "method": "org.rdk.Browser.hidden",
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
    "method": "org.rdk.Browser.loadFinished",
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
    "method": "org.rdk.Browser.uRLChanged",
    "params": {
        "URL": ""
    }
}
```
