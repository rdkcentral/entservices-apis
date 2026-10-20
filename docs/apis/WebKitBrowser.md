<!-- Generated automatically, DO NOT EDIT! -->
<a id="WebKitBrowser_Module"></a>
# WebKitBrowser Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/WebKitBrowser/IApplication.h)**

A WebKitBrowser module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IApplication](#IApplication)
    - [Methods](#IApplication-Methods)
    - [Properties](#IApplication-Properties)
  - [IWebBrowser](#IWebBrowser)
    - [Methods](#IWebBrowser-Methods)
    - [Notifications](#IWebBrowser-Notifications)
    - [Properties](#IWebBrowser-Properties)
  - [IBrowserResources](#IBrowserResources)
    - [Properties](#IBrowserResources-Properties)
  - [IBrowserSecurity](#IBrowserSecurity)
    - [Properties](#IBrowserSecurity-Properties)
  - [IBrowserScripting](#IBrowserScripting)
    - [Methods](#IBrowserScripting-Methods)
  - [IBrowserCookieJar](#IBrowserCookieJar)
    - [Methods](#IBrowserCookieJar-Methods)
    - [Notifications](#IBrowserCookieJar-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `WebKitBrowser` module provides the following interface(s):

- IApplication
- IWebBrowser
- IBrowserResources
- IBrowserSecurity
- IBrowserScripting
- IBrowserCookieJar

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.WebKitBrowser) |
| classname | string | Class name: *WebKitBrowser* |
| locator | string | Library name: *libWPEFrameworkWebKitBrowser.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IApplication"></a>
## IApplication Interface

<a id="IApplication-Methods"></a>
### Methods

The following methods are provided by the IApplication Interface:

| Method | Description |
| :-------- | :-------- |
| [reset](#reset) | Resets application data |

<a id="reset"></a>
## *reset*

Clears the selected category of application data.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Type of reset to perform. Possible values: FACTORY, CACHE, CREDENTIALS, RECORDINGS |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.WebKitBrowser.reset",
    "params": {
        "type": "FACTORY"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.WebKitBrowser.reset", "params": {"type": "FACTORY"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "result": null
}
```

<a id="IApplication-Properties"></a>
### Properties

The following properties are provided by the IApplication Interface:

| Property | Description |
| :-------- | :-------- |
| [contentLink](#contentLink)<sup>WO</sup> | URI of the associated application-specific content |
| [identifier](#identifier)<sup>RO</sup> | Application-specific identification string |
| [language](#language) | Current application user interface language |
| [launchPoint](#launchPoint) | Application launching point |
| [visible](#visible) | Current application visibility |

<a id="contentLink"></a>
## *contentLink*

Sets the URI that identifies the content associated with this application.

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
    "jsonrpc": "2.0",
    "id": 2,
    "method": "org.rdk.WebKitBrowser.contentLink",
    "params": {
        "link": "https://youtube.com"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 2, "method": "org.rdk.WebKitBrowser.contentLink", "params": {"link": "https://youtube.com"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "result": null
}
```

<a id="identifier"></a>
## *identifier*

Retrieves the identifier associated with this application.

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
    "jsonrpc": "2.0",
    "id": 3,
    "method": "org.rdk.WebKitBrowser.identifier"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 3, "method": "org.rdk.WebKitBrowser.identifier"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "result": {
        "id": "com.example.application"
    }
}
```

<a id="language"></a>
## *language*

Retrieves the application's user interface language using an RFC 5646 language tag.

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
    "jsonrpc": "2.0",
    "id": 4,
    "method": "org.rdk.WebKitBrowser.language"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 4, "method": "org.rdk.WebKitBrowser.language"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "result": {
        "language": "en-US"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "method": "org.rdk.WebKitBrowser.language",
    "params": {
        "language": "en-US"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 4, "method": "org.rdk.WebKitBrowser.language", "params": {"language": "en-US"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "result": null
}
```

<a id="launchPoint"></a>
## *launchPoint*

Retrieves the launch point that identifies how the application was started.

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).point | string | Receives the application's launch point. Possible values: UNDEFINED, DIAL, DEDICATED_BUTTON, DEDICATED_ICON, APPLICATION_LIST, INTEGRATED_TILE, SEARCH_RESULT, SEARCH_CONTINUATION, VOICE_CONTROL, VOICE_SEARCH_RESULT, VISUAL_GESTURE, TOUCH_GESTURE, EPG_GRID, CHANNEL_NUMBER, CHANNEL_ZAP, CHANNEL_BAR, WEB_BROWSER, POWER_ON, POWER_ON_FROM_DEDICATED_BUTTON, SUSPENDED_POWER_ON, RESTART, SUSPENDED_RESTART, RESUMED_FROM_SCREEN_SAVER, RESUMED_FROM_STANDBY, BANNER_AD, TITLE_RECOMMENDATION, APPLICATION_PROMOTION |

### Examples


#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "method": "org.rdk.WebKitBrowser.launchPoint"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 5, "method": "org.rdk.WebKitBrowser.launchPoint"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "result": {
        "point": "DIAL"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "method": "org.rdk.WebKitBrowser.launchPoint",
    "params": {
        "point": "DIAL"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 5, "method": "org.rdk.WebKitBrowser.launchPoint", "params": {"point": "DIAL"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "result": null
}
```

<a id="visible"></a>
## *visible*

Retrieves whether the application is currently hidden.

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).visiblity | bool | Receives true when the application is hidden |

### Examples


#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "method": "org.rdk.WebKitBrowser.visible"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 6, "method": "org.rdk.WebKitBrowser.visible"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "result": {
        "visiblity": true
    }
}
```


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "method": "org.rdk.WebKitBrowser.visible",
    "params": {
        "visiblity": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 6, "method": "org.rdk.WebKitBrowser.visible", "params": {"visiblity": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "result": null
}
```

---

<a id="IWebBrowser"></a>
## IWebBrowser Interface

<a id="IWebBrowser-Methods"></a>
### Methods

The following methods are provided by the IWebBrowser Interface:

| Method | Description |
| :-------- | :-------- |
| [collectGarbage](#collectGarbage) | Initiate garbage collection |

<a id="collectGarbage"></a>
## *collectGarbage*

Requests garbage collection in the browser process.

### Events Triggered
None
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
    "jsonrpc": "2.0",
    "id": 4,
    "method": "org.rdk.WebKitBrowser.collectGarbage"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 4, "method": "org.rdk.WebKitBrowser.collectGarbage"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "result": null
}
```

<a id="IWebBrowser-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IWebBrowser Interface:

| Event | Description |
| :-------- | :-------- |
| [visibilityChange](#visibilityChange) | Signals a visibility change of the browser |
| [loadFailed](#loadFailed) | Browser failed to load page |
| [loadFinished](#loadFinished) | Initial HTML document has been completely loaded and parsed |
| [pageClosure](#pageClosure) | Notifies that the web page requests to close its window |
| [uRLChange](#uRLChange) | Signals a URL change in the browser |

<a id="visibilityChange"></a>
## *visibilityChange*

Sent when the browser transitions between hidden and visible states.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hidden | bool | hidden (true) or visible (false) |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "method": "org.rdk.WebKitBrowser.visibilityChange",
    "params": {
        "hidden": true
    }
}
```

<a id="loadFailed"></a>
## *loadFailed*

Indicates that navigation to the requested page did not complete successfully.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been failed to load (e.g. https://example.com) |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "method": "org.rdk.WebKitBrowser.loadFailed",
    "params": {
        "URL": "https://example.com"
    }
}
```

<a id="loadFinished"></a>
## *loadFinished*

Indicates completion of loading and parsing the main HTML document.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded (e.g. https://example.com) |
| params.httpstatus | integer | The response code of main resource request (e.g. 200) |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "method": "org.rdk.WebKitBrowser.loadFinished",
    "params": {
        "URL": "https://example.com",
        "httpstatus": 200
    }
}
```

<a id="pageClosure"></a>
## *pageClosure*

Indicates that the current web page requested closure of its window.

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "method": "org.rdk.WebKitBrowser.pageClosure"
}
```

<a id="uRLChange"></a>
## *uRLChange*

Reports the new URL and whether its content has finished loading.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.URL | string | The URL that has been loaded or requested (e.g. https://example.com) |
| params.loaded | bool | loaded (true) or not (false) |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "method": "org.rdk.WebKitBrowser.uRLChange",
    "params": {
        "URL": "https://example.com",
        "loaded": true
    }
}
```

<a id="IWebBrowser-Properties"></a>
### Properties

The following properties are provided by the IWebBrowser Interface:

| Property | Description |
| :-------- | :-------- |
| [bridgeEvent](#bridgeEvent)<sup>WO</sup> | Send legacy $badger  |
| [bridgeReply](#bridgeReply)<sup>WO</sup> | Response for legacy $badger. |
| [fPS](#fPS)<sup>RO</sup> | Current framerate the browser is rendering at |
| [hTTPCookieAcceptPolicy](#hTTPCookieAcceptPolicy) | HTTP cookies accept policy |
| [localStorageEnabled](#localStorageEnabled) | Controls the local storage availability |
| [uRL](#uRL) | Page loaded in the browser |
| [userAgent](#userAgent) | UserAgent string used by the browser |
| [visibility](#visibility) | Browser window visibility state |

<a id="bridgeEvent"></a>
## *bridgeEvent*

Sends an event payload to the legacy window.$badger.event handler.

> This property is write-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).payload | string | base64 encoded JSON string response to be delivered to window.$badger.event |

### Examples


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "method": "org.rdk.WebKitBrowser.bridgeEvent",
    "params": {
        "payload": "..."
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 11, "method": "org.rdk.WebKitBrowser.bridgeEvent", "params": {"payload": "..."}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "result": null
}
```

<a id="bridgeReply"></a>
## *bridgeReply*

Delivers a response payload to the legacy $badger callback.

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
    "jsonrpc": "2.0",
    "id": 12,
    "method": "org.rdk.WebKitBrowser.bridgeReply",
    "params": {
        "payload": "..."
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 12, "method": "org.rdk.WebKitBrowser.bridgeReply", "params": {"payload": "..."}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 12,
    "result": null
}
```

<a id="fPS"></a>
## *fPS*

Retrieves the current browser rendering rate in frames per second.

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
    "jsonrpc": "2.0",
    "id": 13,
    "method": "org.rdk.WebKitBrowser.fPS"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 13, "method": "org.rdk.WebKitBrowser.fPS"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 13,
    "result": {
        "fps": 60
    }
}
```

<a id="hTTPCookieAcceptPolicy"></a>
## *hTTPCookieAcceptPolicy*

Retrieves the policy that controls which HTTP cookies the browser accepts.

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).policy | string | HTTP Cookie Accept Policy Type (e.g. always). Possible values: ALWAYS, NEVER, ONLY_FROM_MAIN_DOCUMENT_DOMAIN, EXCLUSIVELY_FROM_MAIN_DOCUMENT_DOMAIN |

### Examples


#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 14, "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "result": {
        "policy": "ONLY_FROM_MAIN_DOCUMENT_DOMAIN"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy",
    "params": {
        "policy": "ONLY_FROM_MAIN_DOCUMENT_DOMAIN"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 14, "method": "org.rdk.WebKitBrowser.hTTPCookieAcceptPolicy", "params": {"policy": "ONLY_FROM_MAIN_DOCUMENT_DOMAIN"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "result": null
}
```

<a id="localStorageEnabled"></a>
## *localStorageEnabled*

Retrieves whether browser local storage is enabled.

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).enabled | bool | True if local storage is enabled, false otherwise |

### Examples


#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 15,
    "method": "org.rdk.WebKitBrowser.localStorageEnabled"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 15, "method": "org.rdk.WebKitBrowser.localStorageEnabled"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 15,
    "result": {
        "enabled": true
    }
}
```


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 15,
    "method": "org.rdk.WebKitBrowser.localStorageEnabled",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 15, "method": "org.rdk.WebKitBrowser.localStorageEnabled", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 15,
    "result": null
}
```

<a id="uRL"></a>
## *uRL*

Retrieves the URL currently loaded in the browser.

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
    "jsonrpc": "2.0",
    "id": 18,
    "method": "org.rdk.WebKitBrowser.uRL"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 18, "method": "org.rdk.WebKitBrowser.uRL"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 18,
    "result": {
        "url": "https://example.com"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 18,
    "method": "org.rdk.WebKitBrowser.uRL",
    "params": {
        "url": "https://example.com"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 18, "method": "org.rdk.WebKitBrowser.uRL", "params": {"url": "https://example.com"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 18,
    "result": null
}
```

<a id="userAgent"></a>
## *userAgent*

Retrieves the user-agent value sent by the browser.

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
    "jsonrpc": "2.0",
    "id": 19,
    "method": "org.rdk.WebKitBrowser.userAgent"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 19, "method": "org.rdk.WebKitBrowser.userAgent"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 19,
    "result": {
        "useragent": "Mozilla/5.0"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 19,
    "method": "org.rdk.WebKitBrowser.userAgent",
    "params": {
        "useragent": "Mozilla/5.0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 19, "method": "org.rdk.WebKitBrowser.userAgent", "params": {"useragent": "Mozilla/5.0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 19,
    "result": null
}
```

<a id="visibility"></a>
## *visibility*

Retrieves whether the browser window is hidden or visible.

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).visible | string | Visiblity state (e.g. ). Possible values: HIDDEN, VISIBLE |

### Examples


#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 22,
    "method": "org.rdk.WebKitBrowser.visibility"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 22, "method": "org.rdk.WebKitBrowser.visibility"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 22,
    "result": {
        "visible": "VISIBLE"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 22,
    "method": "org.rdk.WebKitBrowser.visibility",
    "params": {
        "visible": "VISIBLE"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 22, "method": "org.rdk.WebKitBrowser.visibility", "params": {"visible": "VISIBLE"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 22,
    "result": null
}
```

---

<a id="IBrowserResources"></a>
## IBrowserResources Interface

<a id="IBrowserResources-Properties"></a>
### Properties

The following properties are provided by the IBrowserResources Interface:

| Property | Description |
| :-------- | :-------- |
| [userScripts](#userScripts) | User scripts used by the browser |
| [userStyleSheets](#userStyleSheets) | User style sheets used by the browser |

<a id="userScripts"></a>
## *userScripts*

Retrieves the URIs of user scripts configured for execution by the browser.

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).uris | array | JSON array containing URIs pointing to user scripts, supported protocols: file:// |
| (property).uris[#] | string |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 20,
    "method": "org.rdk.WebKitBrowser.userScripts"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 20, "method": "org.rdk.WebKitBrowser.userScripts"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 20,
    "result": [
        "file:///opt/app/styles.css"
    ]
}
```


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 20,
    "method": "org.rdk.WebKitBrowser.userScripts",
    "params": [
        "file:///opt/app/styles.css"
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 20, "method": "org.rdk.WebKitBrowser.userScripts", "params": ["file:///opt/app/styles.css"]}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 20,
    "result": null
}
```

<a id="userStyleSheets"></a>
## *userStyleSheets*

Retrieves the URIs of user style sheets configured for the browser.

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).uris | array | JSON array containing URIs pointing to user style sheets, supported protocols: file:// |
| (property).uris[#] | string |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 21,
    "method": "org.rdk.WebKitBrowser.userStyleSheets"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 21, "method": "org.rdk.WebKitBrowser.userStyleSheets"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 21,
    "result": [
        "file:///opt/app/styles.css"
    ]
}
```


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 21,
    "method": "org.rdk.WebKitBrowser.userStyleSheets",
    "params": [
        "file:///opt/app/styles.css"
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 21, "method": "org.rdk.WebKitBrowser.userStyleSheets", "params": ["file:///opt/app/styles.css"]}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 21,
    "result": null
}
```

---

<a id="IBrowserSecurity"></a>
## IBrowserSecurity Interface

<a id="IBrowserSecurity-Properties"></a>
### Properties

The following properties are provided by the IBrowserSecurity Interface:

| Property | Description |
| :-------- | :-------- |
| [mixedContentPolicy](#mixedContentPolicy) | Mixed content policy |
| [securityProfile](#securityProfile) | Security profile for secure connections |

<a id="mixedContentPolicy"></a>
## *mixedContentPolicy*

Retrieves whether mixed content is allowed or blocked.

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).policy | string | Mixed content policy type. Possible values: ALLOWED, BLOCKED |

### Examples


#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 16,
    "method": "org.rdk.WebKitBrowser.mixedContentPolicy"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 16, "method": "org.rdk.WebKitBrowser.mixedContentPolicy"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 16,
    "result": {
        "policy": "BLOCKED"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 16,
    "method": "org.rdk.WebKitBrowser.mixedContentPolicy",
    "params": {
        "policy": "BLOCKED"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 16, "method": "org.rdk.WebKitBrowser.mixedContentPolicy", "params": {"policy": "BLOCKED"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 16,
    "result": null
}
```

<a id="securityProfile"></a>
## *securityProfile*

Retrieves the profile used to configure secure browser connections.

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
    "jsonrpc": "2.0",
    "id": 17,
    "method": "org.rdk.WebKitBrowser.securityProfile"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 17, "method": "org.rdk.WebKitBrowser.securityProfile"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 17,
    "result": {
        "profile": "compatible"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 17,
    "method": "org.rdk.WebKitBrowser.securityProfile",
    "params": {
        "profile": "compatible"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 17, "method": "org.rdk.WebKitBrowser.securityProfile", "params": {"profile": "compatible"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 17,
    "result": null
}
```

---

<a id="IBrowserScripting"></a>
## IBrowserScripting Interface

<a id="IBrowserScripting-Methods"></a>
### Methods

The following methods are provided by the IBrowserScripting Interface:

| Method | Description |
| :-------- | :-------- |
| [addUserScript](#addUserScript) | Add user script to be executed at document start. |
| [removeAllUserScripts](#removeAllUserScripts) | Remove all user scripts. |
| [runJavaScript](#runJavaScript) | Run javascript in main frame. |

<a id="addUserScript"></a>
## *addUserScript*

Registers a script for execution when a document begins loading.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.script | string | Utf8 encoded JS code string. |
| params.topFrameOnly | bool | True to execute only in the top-level frame |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "method": "org.rdk.WebKitBrowser.addUserScript",
    "params": {
        "script": "window.appReady = true",
        "topFrameOnly": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 1, "method": "org.rdk.WebKitBrowser.addUserScript", "params": {"script": "window.appReady = true", "topFrameOnly": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "result": null
}
```

<a id="removeAllUserScripts"></a>
## *removeAllUserScripts*

Clears all user scripts previously registered through this interface.

### Events Triggered
None
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
    "jsonrpc": "2.0",
    "id": 2,
    "method": "org.rdk.WebKitBrowser.removeAllUserScripts"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 2, "method": "org.rdk.WebKitBrowser.removeAllUserScripts"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "result": null
}
```

<a id="runJavaScript"></a>
## *runJavaScript*

Executes the supplied JavaScript source in the page's main frame.

### Events Triggered
None
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
    "jsonrpc": "2.0",
    "id": 3,
    "method": "org.rdk.WebKitBrowser.runJavaScript",
    "params": {
        "script": "window.appReady = true"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 3, "method": "org.rdk.WebKitBrowser.runJavaScript", "params": {"script": "window.appReady = true"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "result": null
}
```

---

<a id="IBrowserCookieJar"></a>
## IBrowserCookieJar Interface

<a id="IBrowserCookieJar-Methods"></a>
### Methods

The following methods are provided by the IBrowserCookieJar Interface:

| Method | Description |
| :-------- | :-------- |
| [setcoookiejar](#setcoookiejar) | Updates the cookie-jar snapshot. |

<a id="setcoookiejar"></a>
## *setcoookiejar*

Replaces cookie-jar data using its version, checksum, and serialized payload.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.version | integer | Cookie-jar version |
| params.checksum | integer | Cookie-jar checksum |
| params.payload | string | Serialized cookie-jar data |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.WebKitBrowser.setcoookiejar",
    "params": {
        "version": 1,
        "checksum": 12345,
        "payload": "..."
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.WebKitBrowser.setcoookiejar", "params": {"version": 1, "checksum": 12345, "payload": "..."}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "result": null
}
```

<a id="IBrowserCookieJar-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IBrowserCookieJar Interface:

| Event | Description |
| :-------- | :-------- |
| [cookieJarChanged](#cookieJarChanged) | Notifies that cookies were added, removed or modified. |

<a id="cookieJarChanged"></a>
## *cookieJarChanged*

Signals that the browser cookie jar contents have changed.

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "method": "org.rdk.WebKitBrowser.cookieJarChanged"
}
```

