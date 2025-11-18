<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.PerformanceMetrics_Plugin"></a>
# PerformanceMetrics Plugin

A PerformanceMetrics plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)

<a name="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="head.Description"></a>
# Description

The Performance Metrics plugin can output metrics on a plugin (e.g. uptime, resource usage).

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a name="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *PerformanceMetrics*) |
| classname | string | Class name: *PerformanceMetrics* |
| locator | string | Library name: *libWPEFrameworkPerformanceMetrics.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

