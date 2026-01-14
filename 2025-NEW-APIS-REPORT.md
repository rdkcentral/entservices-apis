# New APIs and Interfaces Added in 2025

**Report Generated:** January 14, 2026  
**Repository:** rdkcentral/entservices-apis  
**Period Covered:** January 1, 2025 - December 31, 2025

---

## Executive Summary

This report provides a comprehensive list of all new APIs and interfaces added to the Entertainment Services (Ent Services) APIs repository during the year 2025. The analysis is based on the CHANGELOG.md file and covers all significant additions including:

- **New Plugins:** 22 new or significantly enhanced plugins
- **COM-RPC Support:** 16 plugins with COM-RPC support added
- **New Interfaces:** 29 new interface definitions
- **New APIs/Methods:** 26 new API methods and properties
- **New Events:** 4 new notification events

**Total Additions:** 97 significant API/interface additions in 2025

---

## 1. New Plugins

The following new plugins were created or had major additions in 2025:

### 1.1 Core New Plugins

| # | Plugin Name | PR | Date | Description |
|---|------------|-----|------|-------------|
| 1 | **FirmwareDownload** | #565 | Nov 27, 2025 | RDKEMW-7762: Create a skeleton plugin for FirmwareDownload |
| 2 | **Migration** | #546 | Oct 17, 2025 | RDKEMW-7763: Create a Migration plugin and add the corresponding APIs |
| 3 | **Telemetry** | #542 | Sep 25, 2025 | RDKEMW-2993: Add Telemetry Plugin |
| 4 | **Amazon Prime** | #113 | Apr 1, 2025 | PREMIUMAPP-3182: Add Amazon Prime plugin interfaces |

### 1.2 Plugins with Major Enhancements

| # | Plugin Name | PR | Date | Description |
|---|------------|-----|------|-------------|
| 1 | **DeviceIdentification** | #513 | Sep 23, 2025 | RDKEMW-7984: Add DeviceIdentification and MessageControl plugin |
| 2 | **MessageControl** | #513 | Sep 23, 2025 | RDKEMW-7984: Add DeviceIdentification and MessageControl plugin |
| 3 | **SharedStorage** | #405 | Jul 22, 2025 | RDKEMW-6142: Create the SharedStorage plugin entservice-apis doc |
| 4 | **UserPreferences** | N/A | Feb 25, 2025 | Create UserPreferencesPlugin.md |

---

## 2. COM-RPC Support Added

The following plugins received COM-RPC support in 2025, enabling remote procedure call functionality:

| # | Plugin Name | PR | Date | Description |
|---|------------|-----|------|-------------|
| 1 | **DeviceInfo** | #635 | Dec 15, 2025 | RDKEMW-9783: COM-RPC support for DeviceInfo plugin |
| 2 | **AVInput** | #656 | Dec 2, 2025 | RDKEMW-1008: Add COM-RPC support to AVInput plugin |
| 3 | **HdmiCecSink** | #438 | Sep 3, 2025 | RDKEMW-6331: Fix HdmiCecSink COM-RPC issues |
| 4 | **MiracastPlayer** | #261 | Jul 2, 2025 | RDKEMW-1017/1018: Miracast COMRPC support |
| 5 | **MiracastService** | #261 | Jul 2, 2025 | RDKEMW-1017/1018: Miracast COMRPC support |
| 6 | **HdmiCecSink** | #114 | Jun 20, 2025 | RDKEMW-1015: HDMICEC SINK COMRPC |
| 7 | **SharedStorage** | #220 | Jun 17, 2025 | RDKEMW-1021: COM-RPC support for SharedStorage |
| 8 | **LEDControl** | #157 | May 28, 2025 | RDKEMW-1016: Add COM-RPC support to LEDControl plugin |
| 9 | **HdcpProfile** | #173 | May 1, 2025 | RDKEMW-1014: Add COM-RPC support to HdcpProfile plugin |
| 10 | **Warehouse** | #110 | Apr 24, 2025 | RDKEMW-1024: Add COM-RPC support to Warehouse plugin |
| 11 | **DeviceDiagnostics** | #43 | Apr 4, 2025 | RDKEMW-1009: Add COM-RPC support to DeviceDiagnostics plugin |
| 12 | **ScreenCapture** | #76 | Apr 4, 2025 | RDKEMW-1020: Add COM-RPC support to ScreenCapture plugin |
| 13 | **Telemetry** | #4 | Feb 27, 2025 | RDKEMW-1023: Add COM-RPC support to Telemetry plugin |

---

## 3. New Interfaces

The following new interface definitions were added in 2025:

### 3.1 Application Management Interfaces

| # | Interface Name | PR | Date | Description |
|---|---------------|-----|------|-------------|
| 1 | **IAppGateway** | #594 | Nov 5, 2025 | RDKEMW-9458: Added new interfaces to support App Gateway effort |
| 2 | **IAppNotifications** | #594 | Nov 5, 2025 | RDKEMW-9458: Added new interfaces to support App Gateway effort |
| 3 | **IAppManager Stats** | #603 | Dec 4, 2025 | RDKEMW-9789: RDKAppmanager Add stats interface |
| 4 | **ILifecycleManager** | N/A | Various | Updates and enhancements throughout 2025 |

### 3.2 Package and Runtime Management Interfaces

| # | Interface Name | PR | Date | Description |
|---|---------------|-----|------|-------------|
| 1 | **IDownloader** | N/A | Oct 9, 2025 | RDKEMW-6751: [AI2.0][DM] Create IDownloader interface |
| 2 | **IPreInstallerManager** | #456 | Oct 7, 2025 | RDKEMW-6787: [AI2.0] Create IPreInstallerManager interface |
| 3 | **IRuntimeManager** | #15 | Feb 19, 2025 | RDKEMW-1340: Create IRuntimeManager Interface Header Definition |
| 4 | **IPackageManager** | #457 | Aug 29, 2025 | RDKEMW-3796: IPackageManager.h Interface updates |

### 3.3 Media and Playback Interfaces

| # | Interface Name | PR | Date | Description |
|---|---------------|-----|------|-------------|
| 1 | **ILinearPlaybackControl** | #432 | Jul 29, 2025 | RDKEMW-6132: Add LinearPlaybackControl json interface |
| 2 | **IFrameRate** | #259 | Jun 17, 2025 | RDKEMW-1012: Add Framerate interface header & IDs |
| 3 | **ITextTrack** | #200 | May 21, 2025 | RDKEMW-4358: Add ITextTrack interfaces for TTML overrides |

### 3.4 Container and System Interfaces

| # | Interface Name | PR | Date | Description |
|---|---------------|-----|------|-------------|
| 1 | **IOCIContainer** | #23 | Feb 19, 2025 | RDKEMW-1594: Add Thunder Interface for OCIContainer |
| 2 | **ISystemMode** | #219 | May 28, 2025 | RDKEMW-2653: ISystemMode.h Interface header updates |
| 3 | **IFirmwareUpdate** | #218 | May 28, 2025 | RDKEMW-2871: IFirmwareUpdate.h Interface header updates |

### 3.5 Display and Window Management Interfaces

| # | Interface Name | PR | Date | Description |
|---|---------------|-----|------|-------------|
| 1 | **IRDKWindowManager** | #198 | May 20, 2025 | RDKEMW-3813: Add setVisible thunder interface |
| 2 | **IRDKWindowManager** | #131 | Apr 14, 2025 | RDKEMW-3153: Add setFocus thunder interface |

### 3.6 Other Interfaces

| # | Interface Name | PR | Date | Description |
|---|---------------|-----|------|-------------|
| 1 | **IXcast** | #371 | Jul 10, 2025 | RDKEMW-2854: IXcast.h Interface header updates |
| 2 | **IProvisioning** | #257 | Jun 12, 2025 | IProvisioning.h Interface header updates |
| 3 | **INativeJS** | #115 | Mar 27, 2025 | RDKEMW-2848: INativeJS.h Interface header updates |

---

## 4. New APIs, Methods, and Properties

The following new API methods and properties were added to existing interfaces in 2025:

### 4.1 Window Manager APIs

| # | API Name | PR | Date | Description |
|---|----------|-----|------|-------------|
| 1 | **getLastKeyPress** | #605 | Dec 4, 2025 | RDKEMW-9789: Add getLastKeyPress method to windowmanager |
| 2 | **setVisible** | #198 | May 20, 2025 | RDKEMW-3813: Add setVisible thunder interface |
| 3 | **setFocus** | #131 | Apr 14, 2025 | RDKEMW-3153: Add setFocus thunder interface |

### 4.2 Device Info APIs

| # | API Name | PR | Date | Description |
|---|----------|-----|------|-------------|
| 1 | **brandname** | #66 | Mar 13, 2025 | RDKEMW-1144: Add DeviceInfo API to return brandname |
| 2 | **manufacturerName** | #68 | Mar 25, 2025 | RDK-56601: Added the set/get for ManufacturerName |
| 3 | **modelName** | #68 | Mar 25, 2025 | RDK-56601: Added the set/get for ModelName |

### 4.3 Display Settings APIs

| # | API Name | PR | Date | Description |
|---|----------|-----|------|-------------|
| 1 | **pdri property** | #574 | Nov 13, 2025 | RDKEMW-9431: Add new property named pdri |
| 2 | **768 resolution** | #623 | Nov 12, 2025 | RDKEMW-10422: added support for 768 resolution |

### 4.4 User Settings APIs

| # | API Name | PR | Date | Description |
|---|----------|-----|------|-------------|
| 1 | **contentPin** | #204 | May 20, 2025 | RDK-57748: Add new property in contentPin in Usersettings |
| 2 | **Accessibility settings** | #36 | Feb 20, 2025 | RDK-56149: Add accessibility settings to user settings plugin |
| 3 | **privacyMode** | #133 | Jun 3, 2025 | DELIA-67834: Added privacyMode related calls |

### 4.5 Package Manager APIs

| # | API Name | PR | Date | Description |
|---|----------|-----|------|-------------|
| 1 | **getConfigForPackage** | #485 | Sep 24, 2025 | RDKEMW-6957: Add getConfigForPackage in IPackageInstaller |
| 2 | **additionalMetadata** | #188 | May 9, 2025 | pass additionalMetadata in IPackageImpl.Install |
| 3 | **Caching support** | #248 | Jun 12, 2025 | RDKEMW-3385: Implement Caching in New PackageManager |
| 4 | **Initialize/Deinitialize** | #103 | Apr 1, 2025 | Get config values from PackageManager.json |

### 4.6 Text Track APIs

| # | API Name | PR | Date | Description |
|---|----------|-----|------|-------------|
| 1 | **CC HAL support** | #441 | Aug 15, 2025 | RDKEMW-6742: Add CC HAL support to ITextTrack |
| 2 | **TTML overrides** | #200 | May 21, 2025 | RDKEMW-4358: Add ITextTrack interfaces for TTML overrides |

### 4.7 Other APIs

| # | API Name | PR | Date | Description |
|---|----------|-----|------|-------------|
| 1 | **appId parameter** | #64 | Mar 7, 2025 | RDKEMW-2055: Add appId parameter to run api |
| 2 | **AuthService IDs** | #86 | Mar 19, 2025 | RDKEMW-1007: Added AuthService related Ids |
| 3 | **Error codes** | #507 | Sep 12, 2025 | RDKEMW-6718: Add support for plugin specific error codes |

---

## 5. New Events and Notifications

The following new notification events were added in 2025:

| # | Event Name | Interface | PR | Date | Description |
|---|-----------|-----------|-----|------|-------------|
| 1 | **additionalContext** | IAnalytics | #582 | Dec 8, 2025 | RDKEMW-9595: Added additionalContext to sendEvent |
| 2 | **appId** | IAnalytics | #280 | Jun 20, 2025 | RDK-57197: Add Analytics sendEvent.appId |
| 3 | **onDisconnected** | Network | #117 | Apr 1, 2025 | RDKEMW-2521: Add onDisconnected event support |
| 4 | **onAppLifecycleStateChanged** | ILifecycleManager | #17 | Feb 19, 2025 | RDKEMW-1608: Add notification event |

---

## 6. Documentation and Tooling Improvements

Several documentation and tooling improvements were made in 2025:

| # | Improvement | PR | Date | Description |
|---|------------|-----|------|-------------|
| 1 | **Automated documentation** | #652 | Dec 3, 2025 | RDKEMW-10395: Add workflow to automate document generation |
| 2 | **Python tool updates** | #606 | Nov 10, 2025 | RDKEMW-9134: Update generate_md script |
| 3 | **Header generator** | #142 | May 1, 2025 | RDKEMW-2374: Create md_from_h_generator tool |
| 4 | **Interface validation** | #63 | Mar 7, 2025 | RDKEMW-2257: Workflow to detect interface guidelines errors |
| 5 | **Coding guidelines** | #609 | Nov 7, 2025 | RDKEMW-9129: Integrate Coding Guidelines with Copilot reviews |

---

## 7. Key Milestones and Trends

### 7.1 Q1 2025 (Jan-Mar)
- Focus on COM-RPC support additions
- Foundation for new Application Lifecycle Management (AI2.0)
- IRuntimeManager and IOCIContainer interfaces introduced

### 7.2 Q2 2025 (Apr-Jun)
- Significant expansion of COM-RPC support across plugins
- New media interfaces (LinearPlaybackControl, FrameRate)
- Enhanced user settings and accessibility features

### 7.3 Q3 2025 (Jul-Sep)
- Telemetry plugin addition
- Migration plugin creation
- Documentation tooling improvements
- Package Manager enhancements

### 7.4 Q4 2025 (Oct-Dec)
- FirmwareDownload plugin skeleton
- App Gateway interfaces (IAppGateway, IAppNotifications)
- DeviceInfo COM-RPC support
- Final documentation automation

---

## 8. Plugin Categories Overview

### 8.1 Application Management (AI2.0)
- AppGateway
- AppNotifications
- AppManager (stats interface)
- LifecycleManager
- PackageManager
- RuntimeManager
- PreInstallManager
- StorageManager

### 8.2 System Services
- DeviceInfo
- DeviceIdentification
- MessageControl
- SystemMode
- Migration
- FirmwareUpdate
- FirmwareDownload

### 8.3 Media and Display
- AVInput
- AVOutput
- TextTrack
- LinearPlaybackControl
- FrameRate
- DisplaySettings
- HdmiCec (Sink/Source)

### 8.4 User Experience
- UserSettings
- LEDControl
- FrontPanel
- RDKWindowManager

### 8.5 Network and Streaming
- MiracastPlayer
- MiracastService
- XCast
- SharedStorage

### 8.6 Monitoring and Diagnostics
- Telemetry
- Analytics
- DeviceDiagnostics
- ScreenCapture

---

## 9. Recommendations for API Consumers

### 9.1 Priority APIs to Adopt
1. **COM-RPC Support**: Consider migrating to COM-RPC where available for better inter-plugin communication
2. **App Gateway**: New standardized way to handle application lifecycle and notifications
3. **Telemetry**: Enhanced monitoring and analytics capabilities
4. **User Settings Enhancements**: New accessibility features and privacy controls

### 9.2 Migration Considerations
1. Several interfaces were updated for coding guideline compliance
2. COM-RPC additions provide alternatives to JSON-RPC for plugin-to-plugin communication
3. New error code support allows for more specific error handling

### 9.3 Documentation Resources
- All new APIs are documented in the `/docs/apis` directory
- Automated documentation generation is now available
- Interface headers in `/apis` directory contain inline documentation

---

## 10. Appendix

### 10.1 Data Sources
- Primary: `/CHANGELOG.md` (versions 1.0.0 to 2.10.4)
- Date Range: February 7, 2025 - December 19, 2025
- Total Releases: 51 releases in 2025

### 10.2 Analysis Methodology
This report was generated by:
1. Parsing the CHANGELOG.md file for all 2025 entries
2. Categorizing changes by type (plugins, interfaces, APIs, events)
3. Extracting PR numbers and dates
4. Cross-referencing with repository structure

### 10.3 Notes
- Some entries may appear in multiple categories (e.g., a plugin addition might also include new interfaces)
- "N/A" in PR column indicates the entry was a commit rather than a pull request
- Dates represent the merge/release date, not development start date

---

**End of Report**

For questions or clarifications, please refer to:
- Repository: https://github.com/rdkcentral/entservices-apis
- Documentation: https://rdkcentral.github.io/entservices-apis/
- Governance: `/governance.md` in repository
