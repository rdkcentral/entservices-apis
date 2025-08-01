<!-- Generated automatically, DO NOT EDIT! -->
<a name="Warehouse_Plugin"></a>
# Warehouse Plugin

A org.rdk.Warehouse plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a name="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="Description"></a>
# Description

The `Warehouse` plugin performs various types of resets (data, warehouse, etc.).

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#Thunder)].

<a name="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.Warehouse*) |
| classname | string | Class name: *org.rdk.Warehouse* |
| locator | string | Library name: *libWPEFrameworkWarehouse.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="Methods"></a>
# Methods

The following methods are provided by the org.rdk.Warehouse plugin:

Warehouse interface methods:

| Method | Description |
| :-------- | :-------- |
| [executeHardwareTest](#executeHardwareTest) | Starts a hardware test on the device |
| [getHardwareTestResults](#getHardwareTestResults) | Returns the results of the last hardware test |
| [internalReset](#internalReset) | Invokes the internal reset script, which reboots the Warehouse service (`/rebootNow |
| [isClean](#isClean) | Checks the locations on the device where customer data may be stored |
| [lightReset](#lightReset) | Resets the application data |
| [resetDevice](#resetDevice) | Resets the STB to the warehouse state |


<a name="executeHardwareTest"></a>
## *executeHardwareTest*

Starts a hardware test on the device. See `getHardwareTestResults`.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.Warehouse.executeHardwareTest"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="getHardwareTestResults"></a>
## *getHardwareTestResults*

Returns the results of the last hardware test.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.testResults | string | The test results |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.Warehouse.getHardwareTestResults",
    "params": {
        "testResults": "Timezone: NA 2021-04-15 10:35:06 Test execution start, remote trigger ver. 0011 2021-04-15 10:35:10 Test result: Audio/Video Decoder:PASSED 2021-04-15 10:35:06 Test result: Dynamic RAM:PASSED 2021-04-15 10:35:06 Test result: Flash Memory:PASSED 2021-04-15 10:35:06 Test result: HDMI Output:PASSED 2021-04-15 10:35:38 Test result: IR Remote Interface:WARNING_IR_Not_Detected 2021-04-15 10:35:06 Test result: Bluetooth:PASSED 2021-04-15 10:35:06 Test result: SD Card:PASSED 2021-04-15 10:35:06 Test result: WAN:PASSED 2021-04-15 10:35:38 Test execution completed:PASSED"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="internalReset"></a>
## *internalReset*

Invokes the internal reset script, which reboots the Warehouse service (`/rebootNow.sh -s WarehouseService &`). Note that this method checks the `/version.txt` file for the image name and fails to run if the STB image version is marked as production (`PROD`).

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.passPhrase | string | The passphrase for running the internal reset (`FOR TEST PURPOSES ONLY`) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |
| result?.error | string | <sup>*(optional)*</sup> An error message in case of a failure |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.Warehouse.internalReset",
    "params": {
        "passPhrase": "FOR TEST PURPOSES ONLY"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true,
        "error": "..."
    }
}
```

<a name="isClean"></a>
## *isClean*

Checks the locations on the device where customer data may be stored. If there are contents contained in those folders, then the device is not clean.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.age | integer | <sup>*(optional)*</sup> Ignore files/folders for the isClean checkup that were created/updated within the last age (in seconds) when this API is called |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.clean | boolean | If `true`, then the device has no customer data, otherwise `false` |
| result.files | array | A string [] of file locations for each file that is found that should have been deleted in the cleaning process. If the `clean` property is `true`, then this array is empty or `null` |
| result.files[#] | string |  |
| result.success | boolean | Whether the request succeeded |
| result.error | string | An error message in case of a failure |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.Warehouse.isClean",
    "params": {
        "age": 300
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "clean": false,
        "files": [
            "/opt/ctrlm.sql"
        ],
        "success": true,
        "error": "..."
    }
}
```

<a name="lightReset"></a>
## *lightReset*

Resets the application data.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |
| result?.error | string | <sup>*(optional)*</sup> An error message in case of a failure |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.Warehouse.lightReset"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true,
        "error": "..."
    }
}
```

<a name="resetDevice"></a>
## *resetDevice*

Resets the STB to the warehouse state.

### Events

| Event | Description |
| :-------- | :-------- |
| [resetDone](#resetDone) | Triggers when the device reset is finished indicating a successful reset or failure |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.suppressReboot | boolean | if `true`, the STB should not be rebooted, otherwise `false`. Only the `WAREHOUSE` reset type supports suppressing the reboot |
| params.resetType | string | The reset type. If `resetType` is not specified, then `WAREHOUSE` is the default. (must be one of the following: *WAREHOUSE*, *FACTORY*, *USERFACTORY*, *COLDFACTORY*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |
| result?.error | string | <sup>*(optional)*</sup> An error message in case of a failure |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.Warehouse.resetDevice",
    "params": {
        "suppressReboot": true,
        "resetType": "WAREHOUSE"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true,
        "error": "..."
    }
}
```

<a name="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.Warehouse plugin:

Warehouse interface events:

| Event | Description |
| :-------- | :-------- |
| [resetDone](#resetDone) | Notifies subscribers about the status of the warehouse reset operation |


<a name="resetDone"></a>
## *resetDone*

Notifies subscribers about the status of the warehouse reset operation.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.success | boolean | Whether the request succeeded |
| params?.error | string | <sup>*(optional)*</sup> An error message in case of a failure |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.resetDone",
    "params": {
        "success": true,
        "error": "..."
    }
}
```

