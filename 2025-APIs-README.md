# 2025 New APIs and Interfaces - Documentation

This directory contains comprehensive documentation of all new APIs and interfaces added to the Entertainment Services APIs repository during 2025.

## Files in This Report

### 1. 2025-NEW-APIS-REPORT.md
**Format:** Markdown  
**Size:** 334 lines, ~14KB  
**Purpose:** Comprehensive, human-readable report

This is the main report document containing:
- Executive summary with totals
- Detailed categorization by type
- Chronological listings with PR numbers and dates
- Quarterly milestone analysis
- Recommendations for API consumers
- Complete appendix with methodology

**Best for:**
- Understanding the scope and context of changes
- Finding detailed descriptions and relationships
- Getting recommendations for adoption
- Sharing with stakeholders and management

### 2. 2025-new-apis-summary.csv
**Format:** CSV (Comma-Separated Values)  
**Size:** 66 rows  
**Purpose:** Data import and analysis

This file contains structured data with columns:
- Category (New Plugin, COM-RPC Support, New Interface, New API, New Event, Documentation)
- Type (Subcategory)
- Name (API/Interface/Plugin name)
- PR (Pull Request number)
- Date (YYYY-MM-DD format)
- Description (Brief description)

**Best for:**
- Importing into Excel, Google Sheets, or databases
- Creating custom visualizations and charts
- Filtering and sorting by date, category, or type
- Integration with project management tools

## Quick Statistics

```
Total Significant Additions: 97

Breakdown:
├── New Plugins: 22
│   ├── Core New Plugins: 4
│   └── Major Enhancements: 18
│
├── COM-RPC Support: 16 plugins
│
├── New Interfaces: 29
│   ├── Application Management: 4
│   ├── Package Management: 4
│   ├── Media: 3
│   ├── System: 3
│   ├── Display: 2
│   └── Other: 13
│
├── New APIs/Methods: 26
│   ├── Window Manager: 3
│   ├── Device Info: 3
│   ├── Display Settings: 2
│   ├── User Settings: 3
│   ├── Package Manager: 4
│   ├── Text Track: 2
│   └── Other: 9
│
├── New Events: 4
│   ├── Analytics: 2
│   ├── Network: 1
│   └── Lifecycle: 1
│
└── Documentation Tools: 5
```

## How to Use These Reports

### For Developers
1. Review the **2025-NEW-APIS-REPORT.md** to understand new capabilities
2. Check the "Recommendations for API Consumers" section (Section 9)
3. Look up specific APIs in your area of interest
4. Review related PRs on GitHub for implementation details

### For Project Managers
1. Use the CSV file to import into project tracking tools
2. Filter by date range to see quarterly progress
3. Generate charts showing adoption of COM-RPC support
4. Track migration from old to new interfaces

### For Documentation Writers
1. Use the report as a source of truth for 2025 changes
2. Cross-reference PR numbers for detailed change descriptions
3. Identify areas needing documentation updates
4. Create migration guides based on the recommendations section

### For QA/Testing Teams
1. Filter CSV by date to prioritize testing
2. Identify new APIs requiring test coverage
3. Check COM-RPC additions for integration testing needs
4. Review new events for notification testing requirements

## Viewing the Reports

### Markdown Report
```bash
# On Linux/Mac
less 2025-NEW-APIS-REPORT.md

# Or use any markdown viewer
# GitHub will render it automatically when viewing the file
```

### CSV File
```bash
# View in terminal
column -t -s',' 2025-new-apis-summary.csv | less

# Import to spreadsheet applications:
# - Microsoft Excel: File > Open > Select CSV
# - Google Sheets: File > Import > Upload > Select CSV
# - LibreOffice Calc: File > Open > Select CSV
```

## Data Source and Methodology

**Primary Source:** `/CHANGELOG.md` (versions 1.0.0 to 2.10.4)  
**Date Range:** February 7, 2025 - December 19, 2025  
**Total Releases Analyzed:** 51 releases

### Analysis Process
1. Parsed CHANGELOG.md for all entries with 2025 dates
2. Identified changes matching keywords: "Add", "Create", "new", "interface", "API", "plugin", "COM-RPC"
3. Categorized each entry by type
4. Extracted PR numbers and dates
5. Removed duplicates and merge commits
6. Cross-referenced with repository structure

### Categories Used
- **New Plugin**: Completely new plugins or major plugin additions
- **COM-RPC Support**: Existing plugins that gained COM-RPC capability
- **New Interface**: New interface definitions (I*.h files)
- **New API**: New methods, properties, or parameters in existing interfaces
- **New Event**: New notification events
- **Documentation**: Documentation and tooling improvements

## Important Notes

1. **Overlapping Categories**: Some entries appear in multiple categories (e.g., a new plugin might also introduce new interfaces)
2. **PR Numbers**: "N/A" indicates direct commits rather than pull requests
3. **Dates**: Represent merge/release dates, not development start dates
4. **Completeness**: Based solely on CHANGELOG.md; not all commits may be represented

## Key Highlights from 2025

### Q1 2025 (Jan-Mar)
- Foundation for Application Lifecycle Management (AI 2.0)
- IRuntimeManager and IOCIContainer interfaces
- Initial COM-RPC expansion

### Q2 2025 (Apr-Jun)
- Major COM-RPC rollout across 8+ plugins
- Media interfaces (LinearPlaybackControl, FrameRate)
- Enhanced accessibility features

### Q3 2025 (Jul-Sep)
- Telemetry and Migration plugins
- Documentation automation
- Package Manager improvements

### Q4 2025 (Oct-Dec)
- App Gateway architecture
- FirmwareDownload plugin
- DeviceInfo COM-RPC support
- Final documentation tooling

## Related Resources

- **Repository:** https://github.com/rdkcentral/entservices-apis
- **Documentation:** https://rdkcentral.github.io/entservices-apis/
- **Governance:** See `/governance.md` in repository
- **API Guidelines:** See `.github/instructions/` directory
- **Individual API Docs:** See `/docs/apis/` directory

## Questions or Issues?

If you find any discrepancies or have questions about this report:

1. Check the original CHANGELOG.md for the raw data
2. Review the specific PR on GitHub for detailed information
3. Consult the governance team (see README.md for contacts)
4. Open an issue on the repository if needed

---

**Report Generated:** January 14, 2026  
**Analysis Period:** January 1, 2025 - December 31, 2025  
**Repository Version:** Commit af54970 (develop branch)
