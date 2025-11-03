<!-- Generated automatically, DO NOT EDIT! -->
<a id="WebKitBrowser_Plugin"></a>
# WebKitBrowser Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/WebKitBrowser/IApplication.h)**

A WebKitBrowser plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Properties](#Properties)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `WebKitBrowser` plugin provides an interface for WebKitBrowser.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.WebKitBrowser) |
| classname | string | Class name: *WebKitBrowser* |
| locator | string | Library name: *libWPEFrameworkWebKitBrowser.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the WebKitBrowser plugin:

WebKitBrowser interface methods:

| Method | Description |
| :-------- | :-------- |
| [reset](#reset) | Resets application data |
| [addUserScript](#addUserScript) | Add user script to be executed at document start. |
| [collectGarbage](#collectGarbage) | Initiate garbage collection |
| [setcoookiejar](#setcoookiejar) |  |
| [removeAllUserScripts](#removeAllUserScripts) | Remove all user scripts. |
| [runJavaScript](#runJavaScript) | Run javascript in main frame. |

<a id="reset"></a>
## *reset*

Resets application data

### Events
Event details will be updated soon.
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

<a id="addUserScript"></a>
## *addUserScript*

Add user script to be executed at document start.

### Events
Event details will be updated soon.
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

<a id="collectGarbage"></a>
## *collectGarbage*

Initiate garbage collection

### Events
Event details will be updated soon.
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

<a id="cookieJar"></a>
## *cookieJar*



### Events
Event details will be updated soon.
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

<a id="removeAllUserScripts"></a>
## *removeAllUserScripts*

Remove all user scripts.

### Events
Event details will be updated soon.
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
    "method": "org.rdk.WebKitBrowser.removeAllUserScripts"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.WebKitBrowser.removeAllUserScripts"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="runJavaScript"></a>
## *runJavaScript*

Run javascript in main frame.

### Events
Event details will be updated soon.
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
    "id": 4,
    "method": "org.rdk.WebKitBrowser.runJavaScript",
    "params": {
        "script": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.WebKitBrowser.runJavaScript", "params": {"script": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```


<a id="Properties"></a>
# Properties
The following properties are provided by the WebKitBrowser plugin:

WebKitBrowser interface properties:

| Property | Description |
| :-------- | :-------- |
| [contentLink](#contentLink)<sup>WO</sup> | URI of the associated application-specific content |
| [identifier](#identifier)<sup>RO</sup> | Application-specific identification string |
| [language](#language) | Current application user interface language |
| [launchPoint](#launchPoint) | Application launching point |
| [visible](#visible) | Current application visibility |
| [bridgeEvent](#bridgeEvent)<sup>WO</sup> | Send legacy $badger event. |
| [bridgeReply](#bridgeReply)<sup>WO</sup> | Response for legacy $badger. |
| [fPS](#fPS)<sup>RO</sup> | Current framerate the browser is rendering at |
| [hTTPCookieAcceptPolicy](#hTTPCookieAcceptPolicy) | HTTP cookies accept policy |
| [localStorageEnabled](#localStorageEnabled) | Controls the local storage availability |
| [mixedContentPolicy](#mixedContentPolicy) | Mixed content policy |
| [securityProfile](#securityProfile) | Security profile for secure connections |
| [uRL](#uRL) | Page loaded in the browser |
| [userAgent](#userAgent) | UserAgent string used by the browser |
| [userScripts](#userScripts) | User scripts used by the browser |
| [userStyleSheets](#userStyleSheets) | User style sheets used by the browser |
| [visibility](#visibility) | Browser window visibility state |

<a id="ContentLink"></a>
## *ContentLink*

URI of the associated application-specific content

> This property is write-only.
### Events
Event details will be updated soon.
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

<a id="Identifier"></a>
## *Identifier*

Application-specific identification string

> This property is read-only.
### Events
Event details will be updated soon.
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

<a id="Language"></a>
## *Language*

Current application user interface language

### Events
Event details will be updated soon.
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

<a id="LaunchPoint"></a>
## *LaunchPoint*

Application launching point

### Events
Event details will be updated soon.
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

<a id="Visible"></a>
## *Visible*

Current application visibility

### Events
Event details will be updated soon.
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

<a id="BridgeEvent"></a>
## *BridgeEvent*

Send legacy $badger event.

> This property is write-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).payload | string | base64 encoded JSON string response to be delivered to $badger.callback |

### Examples


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.WebKitBrowser.bridgeEvent",
    "params": {
        "payload": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.WebKitBrowser.bridgeEvent", "params": {"payload": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="BridgeReply"></a>
## *BridgeReply*

Response for legacy $badger.

> This property is write-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).payload | string | base64 encoded JSON string response to be delivered to $badger.callback |

### Examples


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.WebKitBrowser.bridgeReply",
    "params": {
        "payload": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.WebKitBrowser.bridgeReply", "params": {"payload": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
}
```

<a id="FPS"></a>
## *FPS*

Current framerate the browser is rendering at

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).fps | integer | Current FPS |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.WebKitBrowser.fPS"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.WebKitBrowser.fPS"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "fps": 0
    }
}
```

<a id="HTTPCookieAcceptPolicy"></a>
## *HTTPCookieAcceptPolicy*

HTTP cookies accept policy

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).policy | string | HTTP Cookie Accept Policy Type (e.g. always) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "policy": "ALWAYS"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy",
    "params": {
        "policy": "ALWAYS"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy", "params": {"policy": "ALWAYS"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```

<a id="LocalStorageEnabled"></a>
## *LocalStorageEnabled*

Controls the local storage availability

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).enabled | bool |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.WebKitBrowser.localStorageEnabled"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.WebKitBrowser.localStorageEnabled"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "enabled": true
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.WebKitBrowser.localStorageEnabled",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.WebKitBrowser.localStorageEnabled", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": null
}
```

<a id="MixedContentPolicy"></a>
## *MixedContentPolicy*

Mixed content policy

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).policy | string | Mixed content policy type |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.WebKitBrowser.mixedContentPolicy"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.WebKitBrowser.mixedContentPolicy"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "policy": "ALLOWED"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.WebKitBrowser.mixedContentPolicy",
    "params": {
        "policy": "ALLOWED"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.WebKitBrowser.mixedContentPolicy", "params": {"policy": "ALLOWED"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": null
}
```

<a id="SecurityProfile"></a>
## *SecurityProfile*

Security profile for secure connections

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).profile | string | Security profile for secure connections (e.g. compatible) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.WebKitBrowser.securityProfile"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.WebKitBrowser.securityProfile"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": {
        "profile": ""
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.WebKitBrowser.securityProfile",
    "params": {
        "profile": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.WebKitBrowser.securityProfile", "params": {"profile": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": null
}
```

<a id="URL"></a>
## *URL*

Page loaded in the browser

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).url | string | Loaded URL (e.g. https://example.com) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.WebKitBrowser.uRL"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.WebKitBrowser.uRL"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": {
        "url": ""
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.WebKitBrowser.uRL",
    "params": {
        "url": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.WebKitBrowser.uRL", "params": {"url": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": null
}
```

<a id="UserAgent"></a>
## *UserAgent*

UserAgent string used by the browser

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).useragent | string | UserAgent value (e.g. Mozilla/5.0 (Linux; x86_64 GNU/Linux) AppleWebKit/601.1 (KHTML, like Gecko) Version/8.0 Safari/601.1 WP) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.WebKitBrowser.userAgent"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.WebKitBrowser.userAgent"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": {
        "useragent": ""
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.WebKitBrowser.userAgent",
    "params": {
        "useragent": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.WebKitBrowser.userAgent", "params": {"useragent": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": null
}
```

<a id="UserScripts"></a>
## *UserScripts*

User scripts used by the browser

### Events
Event details will be updated soon.
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
    "id": 20,
    "method": "org.rdk.WebKitBrowser.userScripts"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.WebKitBrowser.userScripts"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": [
        ""
    ]
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.WebKitBrowser.userScripts",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.WebKitBrowser.userScripts", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": null
}
```

<a id="UserStyleSheets"></a>
## *UserStyleSheets*

User style sheets used by the browser

### Events
Event details will be updated soon.
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
    "id": 21,
    "method": "org.rdk.WebKitBrowser.userStyleSheets"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.WebKitBrowser.userStyleSheets"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": [
        ""
    ]
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.WebKitBrowser.userStyleSheets",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.WebKitBrowser.userStyleSheets", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": null
}
```

<a id="Visibility"></a>
## *Visibility*

Browser window visibility state

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).visible | string | Visiblity state (e.g. ) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.WebKitBrowser.visibility"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.WebKitBrowser.visibility"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": {
        "visible": "HIDDEN"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.WebKitBrowser.visibility",
    "params": {
        "visible": "HIDDEN"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.WebKitBrowser.visibility", "params": {"visible": "HIDDEN"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": null
}
```


<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the WebKitBrowser plugin:

WebKitBrowser interface events:

| Event | Description |
| :-------- | :-------- |
| [visibilityChange](#visibilityChange) | Signals a visibility change of the browser |
| [cookieJarChanged](#cookieJarChanged) | Notifies that cookies were added, removed or modified. |
| [loadFailed](#loadFailed) | Browser failed to load page |
| [loadFinished](#loadFinished) | Initial HTML document has been completely loaded and parsed |
| [pageClosure](#pageClosure) | Notifies that the web page requests to close its window |
| [uRLChange](#uRLChange) | Signals a URL change in the browser |

<a id="visibilityChange"></a>
## *visibilityChange*

Signals a visibility change of the browser

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hidden | bool | hidden (true) or visible (false) |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.WebKitBrowser.visibilityChange",
    "params": {
        "hidden": true
    }
}
```

<a id="cookieJarChanged"></a>
## *cookieJarChanged*

Notifies that cookies were added, removed or modified.

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.WebKitBrowser.cookieJarChanged"
}
```

<a id="loadFailed"></a>
## *loadFailed*

Browser failed to load page

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.WebKitBrowser.loadFailed",
    "params": {
        "URL": ""
    }
}
```

<a id="loadFinished"></a>
## *loadFinished*

Initial HTML document has been completely loaded and parsed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |
| params.httpstatus | integer | The response code of main resource request (e.g. 200) |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.WebKitBrowser.loadFinished",
    "params": {
        "URL": "",
        "httpstatus": 0
    }
}
```

<a id="pageClosure"></a>
## *pageClosure*

Notifies that the web page requests to close its window

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.WebKitBrowser.pageClosure"
}
```

<a id="uRLChange"></a>
## *uRLChange*

Signals a URL change in the browser

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |
| params.loaded | bool | loaded (true) or not (false) |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.WebKitBrowser.uRLChange",
    "params": {
        "URL": "",
        "loaded": true
    }
}
```
