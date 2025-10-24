<!-- Generated automatically, DO NOT EDIT! -->
<a id="WebKitBrowser_Plugin"></a>
# WebKitBrowser Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/WebKitBrowser)**

A WebKitBrowser plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Properties](#Properties)
- [Notifications](#Notifications)

<a id="Abbreviation,_Acronyms_and_Terms"></a>
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

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [reset](#reset) | Resets application data | NA |
| [addUserScript](#addUserScript) | Add user script to be executed at document start. | NA |
| [collectGarbage](#collectGarbage) | Initiate garbage collection | NA |
| [setcoookiejar](#setcoookiejar) |  | NA |
| [getFPS](#getFPS) |  | NA |
| [getURL](#getURL) |  | NA |
| [hide](#hide) |  | NA |
| [removeAllUserScripts](#removeAllUserScripts) | Remove all user scripts. | NA |
| [runJavaScript](#runJavaScript) | Run javascript in main frame. | NA |
| [setURL](#setURL) |  | NA |
| [allocated](#allocated) |  | NA |
| [identifier](#identifier) |  | NA |
| [isOperational](#isOperational) |  | NA |
| [name](#name) |  | NA |
| [process](#process) |  | NA |
| [processes](#processes) |  | NA |
| [resident](#resident) |  | NA |
| [shared](#shared) |  | NA |

<a id="reset"></a>
## *reset [<sup>method</sup>](#Methods)*

Resets application data

### Events
No Events are associated with this method.
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
## *addUserScript [<sup>method</sup>](#Methods)*

Add user script to be executed at document start.

### Events
No Events are associated with this method.
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
## *collectGarbage [<sup>method</sup>](#Methods)*

Initiate garbage collection

### Events
No Events are associated with this method.
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
## *cookieJar [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
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

<a id="getFPS"></a>
## *getFPS [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
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
    "method": "org.rdk.WebKitBrowser.getFPS"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.WebKitBrowser.getFPS"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="getURL"></a>
## *getURL [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
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
    "method": "org.rdk.WebKitBrowser.getURL"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.WebKitBrowser.getURL"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```

<a id="hide"></a>
## *hide [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
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
    "id": 5,
    "method": "org.rdk.WebKitBrowser.hide",
    "params": {
        "hidden": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.WebKitBrowser.hide", "params": {"hidden": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="removeAllUserScripts"></a>
## *removeAllUserScripts [<sup>method</sup>](#Methods)*

Remove all user scripts.

### Events
No Events are associated with this method.
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
    "method": "org.rdk.WebKitBrowser.removeAllUserScripts"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.WebKitBrowser.removeAllUserScripts"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="runJavaScript"></a>
## *runJavaScript [<sup>method</sup>](#Methods)*

Run javascript in main frame.

### Events
No Events are associated with this method.
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
    "id": 7,
    "method": "org.rdk.WebKitBrowser.runJavaScript",
    "params": {
        "script": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.WebKitBrowser.runJavaScript", "params": {"script": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

<a id="setURL"></a>
## *setURL [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
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
    "id": 8,
    "method": "org.rdk.WebKitBrowser.setURL",
    "params": {
        "URL": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.WebKitBrowser.setURL", "params": {"URL": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="allocated"></a>
## *allocated [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
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

<a id="identifier"></a>
## *identifier [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
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

<a id="isOperational"></a>
## *isOperational [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
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

<a id="name"></a>
## *name [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
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

<a id="process"></a>
## *process [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
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

<a id="processes"></a>
## *processes [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
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

<a id="resident"></a>
## *resident [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
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

<a id="shared"></a>
## *shared [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
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


<a id="Properties"></a>
# Properties
The following properties are provided by the WebKitBrowser plugin:

WebKitBrowser interface properties:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [contentLink](#contentLink)<sup>WO</sup> | URI of the associated application-specific content | NA |
| [identifier](#identifier)<sup>RO</sup> | Application-specific identification string | NA |
| [language](#language) | Current application user interface language | NA |
| [launchPoint](#launchPoint) | Application launching point | NA |
| [visible](#visible) | Current application visibility | NA |
| [bridgeEvent](#bridgeEvent)<sup>WO</sup> | Send legacy $badger event. | NA |
| [bridgeReply](#bridgeReply)<sup>WO</sup> | Response for legacy $badger. | NA |
| [fPS](#fPS)<sup>RO</sup> | Current framerate the browser is rendering at | NA |
| [hTTPCookieAcceptPolicy](#hTTPCookieAcceptPolicy) | HTTP cookies accept policy | NA |
| [localStorageEnabled](#localStorageEnabled) | Controls the local storage availability | NA |
| [mixedContentPolicy](#mixedContentPolicy) | Mixed content policy | NA |
| [securityProfile](#securityProfile) | Security profile for secure connections | NA |
| [uRL](#uRL) | Page loaded in the browser | URLChanged, LoadFinished, LoadFailed |
| [userAgent](#userAgent) | UserAgent string used by the browser | NA |
| [userScripts](#userScripts) | User scripts used by the browser | NA |
| [userStyleSheets](#userStyleSheets) | User style sheets used by the browser | NA |
| [visibility](#visibility) | Browser window visibility state | VisibilityChange |

<a id="ContentLink"></a>
## *ContentLink [<sup>property</sup>](#Properties)*

URI of the associated application-specific content

> This property is write-only.
### Events
No Events are associated with this method.
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
## *Identifier [<sup>property</sup>](#Properties)*

Application-specific identification string

> This property is read-only.
### Events
No Events are associated with this method.
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
## *Language [<sup>property</sup>](#Properties)*

Current application user interface language

### Events
No Events are associated with this method.
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
## *LaunchPoint [<sup>property</sup>](#Properties)*

Application launching point

### Events
No Events are associated with this method.
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
## *Visible [<sup>property</sup>](#Properties)*

Current application visibility

### Events
No Events are associated with this method.
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
## *BridgeEvent [<sup>property</sup>](#Properties)*

Send legacy $badger event.

> This property is write-only.
### Events
No Events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).payload | string | base64 encoded JSON string response to be delivered to $badger.callback |

### Examples


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.WebKitBrowser.bridgeEvent",
    "params": {
        "payload": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.WebKitBrowser.bridgeEvent", "params": {"payload": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": null
}
```

<a id="BridgeReply"></a>
## *BridgeReply [<sup>property</sup>](#Properties)*

Response for legacy $badger.

> This property is write-only.
### Events
No Events are associated with this method.
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
    "method": "org.rdk.WebKitBrowser.bridgeReply",
    "params": {
        "payload": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.WebKitBrowser.bridgeReply", "params": {"payload": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": null
}
```

<a id="FPS"></a>
## *FPS [<sup>property</sup>](#Properties)*

Current framerate the browser is rendering at

> This property is read-only.
### Events
No Events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).fps | integer | Current FPS |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.WebKitBrowser.fPS"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.WebKitBrowser.fPS"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": {
        "fps": 0
    }
}
```

<a id="HTTPCookieAcceptPolicy"></a>
## *HTTPCookieAcceptPolicy [<sup>property</sup>](#Properties)*

HTTP cookies accept policy

### Events
No Events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).policy | string | HTTP Cookie Accept Policy Type (e.g. always) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": {
        "policy": "ALWAYS"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy",
    "params": {
        "policy": "ALWAYS"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy", "params": {"policy": "ALWAYS"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": null
}
```

<a id="LocalStorageEnabled"></a>
## *LocalStorageEnabled [<sup>property</sup>](#Properties)*

Controls the local storage availability

### Events
No Events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).enabled | bool |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.WebKitBrowser.localStorageEnabled"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.WebKitBrowser.localStorageEnabled"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": {
        "enabled": true
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.WebKitBrowser.localStorageEnabled",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.WebKitBrowser.localStorageEnabled", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": null
}
```

<a id="MixedContentPolicy"></a>
## *MixedContentPolicy [<sup>property</sup>](#Properties)*

Mixed content policy

### Events
No Events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).policy | string | Mixed content policy type |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.WebKitBrowser.mixedContentPolicy"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.WebKitBrowser.mixedContentPolicy"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": {
        "policy": "ALLOWED"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.WebKitBrowser.mixedContentPolicy",
    "params": {
        "policy": "ALLOWED"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.WebKitBrowser.mixedContentPolicy", "params": {"policy": "ALLOWED"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": null
}
```

<a id="SecurityProfile"></a>
## *SecurityProfile [<sup>property</sup>](#Properties)*

Security profile for secure connections

### Events
No Events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).profile | string | Security profile for secure connections (e.g. compatible) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.WebKitBrowser.securityProfile"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.WebKitBrowser.securityProfile"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": {
        "profile": ""
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.WebKitBrowser.securityProfile",
    "params": {
        "profile": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.WebKitBrowser.securityProfile", "params": {"profile": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": null
}
```

<a id="URL"></a>
## *URL [<sup>property</sup>](#Properties)*

Page loaded in the browser

### Events
| Event | Description |
| :-------- | :-------- |
| [uRLChanged ](#uRLChanged ) |  Triggered when a URL changes in the browser |
| [loadFinished ](#loadFinished ) |  Triggered if the urlchange event returns true as URL loaded successfully |
| [loadFailed ](#loadFailed ) |  Triggered if the urlchange event returns false as URL failed to load |
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).url | string | Loaded URL (e.g. https://example.com) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.WebKitBrowser.uRL"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.WebKitBrowser.uRL"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": {
        "url": ""
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.WebKitBrowser.uRL",
    "params": {
        "url": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.WebKitBrowser.uRL", "params": {"url": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": null
}
```

<a id="UserAgent"></a>
## *UserAgent [<sup>property</sup>](#Properties)*

UserAgent string used by the browser

### Events
No Events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).useragent | string | UserAgent value (e.g. Mozilla/5.0 (Linux; x86_64 GNU/Linux) AppleWebKit/601.1 (KHTML, like Gecko) Version/8.0 Safari/601.1 WP) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.WebKitBrowser.userAgent"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.WebKitBrowser.userAgent"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": {
        "useragent": ""
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.WebKitBrowser.userAgent",
    "params": {
        "useragent": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.WebKitBrowser.userAgent", "params": {"useragent": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": null
}
```

<a id="UserScripts"></a>
## *UserScripts [<sup>property</sup>](#Properties)*

User scripts used by the browser

### Events
No Events are associated with this method.
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
    "id": 27,
    "method": "org.rdk.WebKitBrowser.userScripts"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.WebKitBrowser.userScripts"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": [
        ""
    ]
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.WebKitBrowser.userScripts",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.WebKitBrowser.userScripts", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": null
}
```

<a id="UserStyleSheets"></a>
## *UserStyleSheets [<sup>property</sup>](#Properties)*

User style sheets used by the browser

### Events
No Events are associated with this method.
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
    "method": "org.rdk.WebKitBrowser.userStyleSheets"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.WebKitBrowser.userStyleSheets"}' http://127.0.0.1:9998/jsonrpc
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
    "method": "org.rdk.WebKitBrowser.userStyleSheets",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.WebKitBrowser.userStyleSheets", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": null
}
```

<a id="Visibility"></a>
## *Visibility [<sup>property</sup>](#Properties)*

Browser window visibility state

### Events
| Event | Description |
| :-------- | :-------- |
| [visibilityChange ](#visibilityChange ) |  Triggered whenever the visibility of the browser changes |
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).visible | string | Visiblity state (e.g. ) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "method": "org.rdk.WebKitBrowser.visibility"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.WebKitBrowser.visibility"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": {
        "visible": "HIDDEN"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "method": "org.rdk.WebKitBrowser.visibility",
    "params": {
        "visible": "HIDDEN"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.WebKitBrowser.visibility", "params": {"visible": "HIDDEN"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
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
| [closure](#closure) |  |
| [cookieJarChanged](#cookieJarChanged) | Notifies that cookies were added, removed or modified. |
| [hidden](#hidden) |  |
| [loadFailed](#loadFailed) | Browser failed to load page |
| [loadFinished](#loadFinished) | Initial HTML document has been completely loaded and parsed |
| [pageClosure](#pageClosure) | Notifies that the web page requests to close its window |
| [uRLChange](#uRLChange) | Signals a URL change in the browser |
| [uRLChanged](#uRLChanged) |  |

<a id="visibilityChange"></a>
## *visibilityChange [<sup>event</sup>](#Notifications)*

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
    "id": 17,
    "method": "org.rdk.WebKitBrowser.visibilityChange",
    "params": {
        "hidden": true
    }
}
```

<a id="closure"></a>
## *closure [<sup>event</sup>](#Notifications)*



### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.WebKitBrowser.closure"
}
```

<a id="cookieJarChanged"></a>
## *cookieJarChanged [<sup>event</sup>](#Notifications)*

Notifies that cookies were added, removed or modified.

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.WebKitBrowser.cookieJarChanged"
}
```

<a id="hidden"></a>
## *hidden [<sup>event</sup>](#Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hidden | bool | hidden (true) or visible (false) |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.WebKitBrowser.hidden",
    "params": {
        "hidden": true
    }
}
```

<a id="loadFailed"></a>
## *loadFailed [<sup>event</sup>](#Notifications)*

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
    "id": 12,
    "method": "org.rdk.WebKitBrowser.loadFailed",
    "params": {
        "URL": ""
    }
}
```

<a id="loadFinished"></a>
## *loadFinished [<sup>event</sup>](#Notifications)*

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
    "id": 13,
    "method": "org.rdk.WebKitBrowser.loadFinished",
    "params": {
        "URL": "",
        "httpstatus": 0
    }
}
```

<a id="pageClosure"></a>
## *pageClosure [<sup>event</sup>](#Notifications)*

Notifies that the web page requests to close its window

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.WebKitBrowser.pageClosure"
}
```

<a id="uRLChange"></a>
## *uRLChange [<sup>event</sup>](#Notifications)*

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
    "id": 15,
    "method": "org.rdk.WebKitBrowser.uRLChange",
    "params": {
        "URL": "",
        "loaded": true
    }
}
```

<a id="uRLChanged"></a>
## *uRLChanged [<sup>event</sup>](#Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.WebKitBrowser.uRLChanged",
    "params": {
        "URL": ""
    }
}
```
