<!-- Generated automatically, DO NOT EDIT! -->
<a id="Sqoeee_Module"></a>
# Sqoeee Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Sqoeee/ISqoeee.h)**

A Sqoeee module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [ISqoeee](#ISqoeee)
    - [Methods](#ISqoeee-Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `Sqoeee` module provides the following interface(s):

- ISqoeee

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Sqoeee) |
| classname | string | Class name: *Sqoeee* |
| locator | string | Library name: *libWPEFrameworkSqoeee.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="ISqoeee"></a>
## ISqoeee Interface

<a id="ISqoeee-Methods"></a>
### Methods

The following methods are provided by the ISqoeee Interface:

| Method | Description |
| :-------- | :-------- |
| [getDiagnostics](#getDiagnostics) | Get SQoEEE input, report and sink diagnostics counters |
| [notifyCurrentPresentationTimeUpdate](#notifyCurrentPresentationTimeUpdate) | Notify the current presentation time of a Rialto media pipeline |
| [notifyFirstFramePresented](#notifyFirstFramePresented) | Notify that a Rialto media pipeline presented its first frame |
| [notifyInAppContentStart](#notifyInAppContentStart) | Notify that an application started content playback (Firebolt Metrics.startContent) |
| [notifyInAppContentStop](#notifyInAppContentStop) | Notify that an application stopped content playback (Firebolt Metrics.stopContent) |
| [notifyInAppMedia](#notifyInAppMedia) | Notify a Firebolt Metrics media event |
| [notifyMediaPipelineCreate](#notifyMediaPipelineCreate) | Notify that Rialto created a media pipeline |
| [notifyMediaPipelineDestroy](#notifyMediaPipelineDestroy) | Notify that Rialto destroyed a media pipeline |
| [notifyMediaPipelineMetricEvent](#notifyMediaPipelineMetricEvent) | Notify a Rialto media pipeline metric event |
| [notifyMediaPipelinePlaybackRate](#notifyMediaPipelinePlaybackRate) | Notify the playback rate of a Rialto media pipeline |
| [notifyMediaPipelineStateChange](#notifyMediaPipelineStateChange) | Notify a Rialto media pipeline playback state change |

<a id="getDiagnostics"></a>
## *getDiagnostics*

Get SQoEEE input, report and sink diagnostics counters

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.acceptedInputs | integer | Accepted inputs |
| result.emittedReports | integer | Reports handed to the sink |
| result.duplicateInputs | integer | Inputs deduplicated against an equivalent signal |
| result.staleInputs | integer | Out-of-order inputs or inputs from retired pipelines or closed sessions |
| result.uncorrelatedInputs | integer | Inputs without a usable avSessionId or session |
| result.malformedInputs | integer | Inputs with invalid parameters |
| result.droppedReports | integer | Reports the sink refused |
| result.capacityRejectedInputs | integer | Inputs rejected because the session limit was reached |
| result.expiredSessions | integer | Partially correlated sessions that timed out |
| result.queuedReports | integer | Reports currently waiting in the sink queue |
| result.sinkRetries | integer | Sink delivery retries |
| result.sinkDrops | integer | Reports dropped by the sink queue |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.Sqoeee.getDiagnostics"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.Sqoeee.getDiagnostics"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "result": {
        "acceptedInputs": 0,
        "emittedReports": 0,
        "duplicateInputs": 0,
        "staleInputs": 0,
        "uncorrelatedInputs": 0,
        "malformedInputs": 0,
        "droppedReports": 0,
        "capacityRejectedInputs": 0,
        "expiredSessions": 0,
        "queuedReports": 0,
        "sinkRetries": 0,
        "sinkDrops": 0
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "error": {
        "code": 1,
        "message": "SQoEEE is not configured"
    }
}
```

<a id="notifyCurrentPresentationTimeUpdate"></a>
## *notifyCurrentPresentationTimeUpdate*

Notify the current presentation time of a Rialto media pipeline

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | Durable app ID |
| params.avSessionId | string | AV session ID |
| params.pipelineId | string | Rialto pipeline identity |
| params.sourceId | string | Rialto source identity |
| params.currentPresentationTimeMs | integer | Current presentation time in milliseconds |
| params.timestampMs | integer | Event time in Unix epoch milliseconds |
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
    "method": "org.rdk.Sqoeee.notifyCurrentPresentationTimeUpdate",
    "params": {
        "appId": "com.example.app",
        "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60",
        "pipelineId": "pipeline-1",
        "sourceId": "rialto",
        "currentPresentationTimeMs": 0,
        "timestampMs": 1764752400000
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 1, "method": "org.rdk.Sqoeee.notifyCurrentPresentationTimeUpdate", "params": {"appId": "com.example.app", "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60", "pipelineId": "pipeline-1", "sourceId": "rialto", "currentPresentationTimeMs": 0, "timestampMs": 1764752400000}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "error": {
        "code": 1,
        "message": "Input was rejected as malformed, stale, uncorrelated or over capacity"
    }
}
```

<a id="notifyFirstFramePresented"></a>
## *notifyFirstFramePresented*

Notify that a Rialto media pipeline presented its first frame

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | Durable app ID |
| params.avSessionId | string | AV session ID |
| params.pipelineId | string | Rialto pipeline identity |
| params.sourceId | string | Rialto source identity |
| params.timestampMs | integer | Event time in Unix epoch milliseconds |
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
    "method": "org.rdk.Sqoeee.notifyFirstFramePresented",
    "params": {
        "appId": "com.example.app",
        "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60",
        "pipelineId": "pipeline-1",
        "sourceId": "rialto",
        "timestampMs": 1764752400000
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 2, "method": "org.rdk.Sqoeee.notifyFirstFramePresented", "params": {"appId": "com.example.app", "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60", "pipelineId": "pipeline-1", "sourceId": "rialto", "timestampMs": 1764752400000}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "error": {
        "code": 1,
        "message": "Input was rejected as malformed, stale, uncorrelated or over capacity"
    }
}
```

<a id="notifyInAppContentStart"></a>
## *notifyInAppContentStart*

Notify that an application started content playback (Firebolt Metrics.startContent)

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | Durable app ID |
| params.appVersion | string | Application version from Firebolt appInfo; empty when unknown |
| params.appSessionId | string | App session ID |
| params.appUserSessionId | string | App user session ID |
| params.entityId | string | Content entity ID; empty when unknown |
| params.avSessionId | string | AV session ID used to correlate with the Rialto pipeline |
| params.timestampMs | integer | Event time in Unix epoch milliseconds |
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
    "method": "org.rdk.Sqoeee.notifyInAppContentStart",
    "params": {
        "appId": "com.example.app",
        "appVersion": "",
        "appSessionId": "",
        "appUserSessionId": "",
        "entityId": "",
        "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60",
        "timestampMs": 1764752400000
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 3, "method": "org.rdk.Sqoeee.notifyInAppContentStart", "params": {"appId": "com.example.app", "appVersion": "", "appSessionId": "", "appUserSessionId": "", "entityId": "", "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60", "timestampMs": 1764752400000}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "error": {
        "code": 1,
        "message": "Input was rejected as malformed, stale, uncorrelated or over capacity"
    }
}
```

<a id="notifyInAppContentStop"></a>
## *notifyInAppContentStop*

Notify that an application stopped content playback (Firebolt Metrics.stopContent)

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | Durable app ID |
| params.appVersion | string | Application version from Firebolt appInfo; empty when unknown |
| params.appSessionId | string | App session ID |
| params.appUserSessionId | string | App user session ID |
| params.entityId | string | Content entity ID; empty when unknown |
| params.avSessionId | string | AV session ID used to correlate with the Rialto pipeline |
| params.timestampMs | integer | Event time in Unix epoch milliseconds |
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
    "method": "org.rdk.Sqoeee.notifyInAppContentStop",
    "params": {
        "appId": "com.example.app",
        "appVersion": "",
        "appSessionId": "",
        "appUserSessionId": "",
        "entityId": "",
        "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60",
        "timestampMs": 1764752400000
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 4, "method": "org.rdk.Sqoeee.notifyInAppContentStop", "params": {"appId": "com.example.app", "appVersion": "", "appSessionId": "", "appUserSessionId": "", "entityId": "", "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60", "timestampMs": 1764752400000}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "error": {
        "code": 1,
        "message": "Input was rejected as malformed, stale, uncorrelated or over capacity"
    }
}
```

<a id="notifyInAppMedia"></a>
## *notifyInAppMedia*

Notify a Firebolt Metrics media event

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | Durable app ID |
| params.appVersion | string | Application version from Firebolt appInfo; empty when unknown |
| params.appSessionId | string | App session ID |
| params.appUserSessionId | string | App user session ID |
| params.entityId | string | Content entity ID; empty when unknown |
| params.avSessionId | string | AV session ID used to correlate with the Rialto pipeline |
| params.timestampMs | integer | Event time in Unix epoch milliseconds |
| params.mediaEventName | string | Firebolt method name: mediaLoadStart, mediaPlay, mediaPlaying, mediaPause, mediaWaiting, mediaSeeking, mediaSeeked or mediaEnded |
| params?.mediaPosSeconds | integer | <sup>(optional)</sup>Playback position or seek target in seconds (0 to 86400) |
| params?.playbackRate | double | <sup>(optional)</sup>New playback rate |
| params?.playbackBitrate | integer | <sup>(optional)</sup>New bitrate in kbps |
| params?.playbackWidth | integer | <sup>(optional)</sup>New resolution width |
| params?.playbackHeight | integer | <sup>(optional)</sup>New resolution height |
| params?.playbackProfile | string | <sup>(optional)</sup>New profile description, for example HDR |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "method": "org.rdk.Sqoeee.notifyInAppMedia",
    "params": {
        "appId": "com.example.app",
        "appVersion": "",
        "appSessionId": "",
        "appUserSessionId": "",
        "entityId": "",
        "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60",
        "timestampMs": 1764752400000,
        "mediaEventName": "mediaPlaying",
        "mediaPosSeconds": 0,
        "playbackRate": 0.0,
        "playbackBitrate": 0,
        "playbackWidth": 0,
        "playbackHeight": 0,
        "playbackProfile": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 5, "method": "org.rdk.Sqoeee.notifyInAppMedia", "params": {"appId": "com.example.app", "appVersion": "", "appSessionId": "", "appUserSessionId": "", "entityId": "", "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60", "timestampMs": 1764752400000, "mediaEventName": "mediaPlaying", "mediaPosSeconds": 0, "playbackRate": 0.0, "playbackBitrate": 0, "playbackWidth": 0, "playbackHeight": 0, "playbackProfile": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "error": {
        "code": 1,
        "message": "Input was rejected as malformed, stale, uncorrelated or over capacity"
    }
}
```

<a id="notifyMediaPipelineCreate"></a>
## *notifyMediaPipelineCreate*

Notify that Rialto created a media pipeline

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | Durable app ID |
| params.avSessionId | string | AV session ID supplied by the app or generated by Rialto |
| params.pipelineId | string | Rialto pipeline identity |
| params.sourceId | string | Rialto source identity |
| params.resolution | string | Video resolution, for example 1920x1080; empty when unknown |
| params.lowLatency | bool | Whether low-latency video is enabled |
| params.dolbyVision | bool | Whether Dolby Vision is enabled |
| params.audioFormat | string | Audio format; empty when unknown |
| params.timestampMs | integer | Event time in Unix epoch milliseconds |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "method": "org.rdk.Sqoeee.notifyMediaPipelineCreate",
    "params": {
        "appId": "com.example.app",
        "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60",
        "pipelineId": "pipeline-1",
        "sourceId": "rialto",
        "resolution": "",
        "lowLatency": true,
        "dolbyVision": true,
        "audioFormat": "",
        "timestampMs": 1764752400000
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 6, "method": "org.rdk.Sqoeee.notifyMediaPipelineCreate", "params": {"appId": "com.example.app", "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60", "pipelineId": "pipeline-1", "sourceId": "rialto", "resolution": "", "lowLatency": true, "dolbyVision": true, "audioFormat": "", "timestampMs": 1764752400000}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "error": {
        "code": 1,
        "message": "Input was rejected as malformed, stale, uncorrelated or over capacity"
    }
}
```

<a id="notifyMediaPipelineDestroy"></a>
## *notifyMediaPipelineDestroy*

Notify that Rialto destroyed a media pipeline

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | Durable app ID |
| params.avSessionId | string | AV session ID |
| params.pipelineId | string | Rialto pipeline identity |
| params.sourceId | string | Rialto source identity |
| params.timestampMs | integer | Event time in Unix epoch milliseconds |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "method": "org.rdk.Sqoeee.notifyMediaPipelineDestroy",
    "params": {
        "appId": "com.example.app",
        "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60",
        "pipelineId": "pipeline-1",
        "sourceId": "rialto",
        "timestampMs": 1764752400000
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 7, "method": "org.rdk.Sqoeee.notifyMediaPipelineDestroy", "params": {"appId": "com.example.app", "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60", "pipelineId": "pipeline-1", "sourceId": "rialto", "timestampMs": 1764752400000}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "error": {
        "code": 1,
        "message": "Input was rejected as malformed, stale, uncorrelated or over capacity"
    }
}
```

<a id="notifyMediaPipelineMetricEvent"></a>
## *notifyMediaPipelineMetricEvent*

Notify a Rialto media pipeline metric event

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | Durable app ID |
| params.avSessionId | string | AV session ID |
| params.pipelineId | string | Rialto pipeline identity |
| params.sourceId | string | Rialto source identity |
| params.type | string | VIDEO_FRAME_DROP, AUDIO_FRAME_DROP, VIDEO_FRAME_REPEAT, AUDIO_GAP, VIDEO_DECODE_ERROR, AUDIO_DECODE_ERROR or BUFFER_UNDERFLOW |
| params.phase | string | OCCURRENCE, STARTED or RESOLVED |
| params?.count | integer | <sup>(optional)</sup>Count associated with a resolved metric episode |
| params?.durationMs | integer | <sup>(optional)</sup>Duration of a resolved metric episode in milliseconds |
| params?.ptsMs | integer | <sup>(optional)</sup>Presentation timestamp of the metric in milliseconds |
| params.timestampMs | integer | Event time in Unix epoch milliseconds |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "method": "org.rdk.Sqoeee.notifyMediaPipelineMetricEvent",
    "params": {
        "appId": "com.example.app",
        "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60",
        "pipelineId": "pipeline-1",
        "sourceId": "rialto",
        "type": "BUFFER_UNDERFLOW",
        "phase": "STARTED",
        "count": 0,
        "durationMs": 0,
        "ptsMs": 0,
        "timestampMs": 1764752400000
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 8, "method": "org.rdk.Sqoeee.notifyMediaPipelineMetricEvent", "params": {"appId": "com.example.app", "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60", "pipelineId": "pipeline-1", "sourceId": "rialto", "type": "BUFFER_UNDERFLOW", "phase": "STARTED", "count": 0, "durationMs": 0, "ptsMs": 0, "timestampMs": 1764752400000}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "error": {
        "code": 1,
        "message": "Input was rejected as malformed, stale, uncorrelated or over capacity"
    }
}
```

<a id="notifyMediaPipelinePlaybackRate"></a>
## *notifyMediaPipelinePlaybackRate*

Notify the playback rate of a Rialto media pipeline

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | Durable app ID |
| params.avSessionId | string | AV session ID |
| params.pipelineId | string | Rialto pipeline identity |
| params.sourceId | string | Rialto source identity |
| params.playbackRate | double | Playback rate |
| params.timestampMs | integer | Event time in Unix epoch milliseconds |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "method": "org.rdk.Sqoeee.notifyMediaPipelinePlaybackRate",
    "params": {
        "appId": "com.example.app",
        "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60",
        "pipelineId": "pipeline-1",
        "sourceId": "rialto",
        "playbackRate": 0.0,
        "timestampMs": 1764752400000
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 9, "method": "org.rdk.Sqoeee.notifyMediaPipelinePlaybackRate", "params": {"appId": "com.example.app", "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60", "pipelineId": "pipeline-1", "sourceId": "rialto", "playbackRate": 0.0, "timestampMs": 1764752400000}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "error": {
        "code": 1,
        "message": "Input was rejected as malformed, stale, uncorrelated or over capacity"
    }
}
```

<a id="notifyMediaPipelineStateChange"></a>
## *notifyMediaPipelineStateChange*

Notify a Rialto media pipeline playback state change

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | Durable app ID |
| params.avSessionId | string | AV session ID |
| params.pipelineId | string | Rialto pipeline identity |
| params.sourceId | string | Rialto source identity |
| params.mediaPipelineState | string | UNKNOWN, IDLE, PLAYING, PAUSED, STOPPED, END_OF_STREAM, FAILURE, PREROLLING, DISCARDING, DISCARD_DONE or FLUSHING |
| params.timestampMs | integer | Event time in Unix epoch milliseconds |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "method": "org.rdk.Sqoeee.notifyMediaPipelineStateChange",
    "params": {
        "appId": "com.example.app",
        "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60",
        "pipelineId": "pipeline-1",
        "sourceId": "rialto",
        "mediaPipelineState": "PLAYING",
        "timestampMs": 1764752400000
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 10, "method": "org.rdk.Sqoeee.notifyMediaPipelineStateChange", "params": {"appId": "com.example.app", "avSessionId": "6f1c1f3e-2b7a-4c4b-9f3e-1d2c3b4a5f60", "pipelineId": "pipeline-1", "sourceId": "rialto", "mediaPipelineState": "PLAYING", "timestampMs": 1764752400000}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "error": {
        "code": 1,
        "message": "Input was rejected as malformed, stale, uncorrelated or over capacity"
    }
}
```

