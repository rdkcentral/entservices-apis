# RDK Services APIs #

RDK services APIs are a set of JSON-RPC based RESTful services that provide access to various functionalities in the entertainment devices that are powered by RDK middleware and ENTOS Operating System. App developers who would like to make use of the underlying features in the ENTOS powered entertainment devices MAY refer this documentation to write, test and deploy their apps in those devices.

RDK Services APIs are maintained and managed through a specific governance model. If you would like to contribute to this project, please fork this project and raise the PR. You will be contacted by one of the members of the governance team.

[View Latest Documentation](WILL BE UPDATED SOON!)
<br>

### Table of Contents ###

[Contributing to RDKServices APIs](#contributing-to-rdkservices-apis)<br>
[Comcast CI/CD](#comcast-cicd)<br>
[Documentation](#documentation)<br>
[Coding Guidelines](#coding-guidelines)<br>
[Versioning](#versioning)<br>
[Code Review Checklist](#code-review-checklist)<br>
[Questions?](#questions)<br>

## Contributing to RDKServices APIs ##

### **License Requirements** ###
1. Before RDK accepts your code into the project you must sign the RDK [Contributor License Agreement (CLA)](https://developer.rdkcentral.com/source/contribute/contribute/before_you_contribute/).

2. Each new file should include the latest [RDKM license header](https://developer.rdkcentral.com/source/source-code/source-code/coding_guideline/).

3. License for this project is included in the root directory and there shouldn't be any additional license file in any of the subfolders.
<br><br>

### **How to contribute?** ###
1. [Fork](https://docs.github.com/en/github/getting-started-with-github/quickstart/fork-a-repo) the repository, commit your changes, build and test it in at least one approved test platform.

2. Submit your changes as a [pull request](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request-from-a-fork) to the develop branch.

<br><br>

### **Pull request Checklist** ###
1. When a pull request is submitted, blackduck, copyright and cla checks will automatically be triggered. Ensure these checks have passed (turned into green).

2. At least one approved reviewer needs to **review and approve** the pull request.

3. [TO DO: REVIEW THIS LINE ITEM AND MODIFY IT] For tracking and release management purposes, each pull request and all the commits in the pull request shall include **RDK ticket number(s) or Github issue number(s)** and “reason for the change”.

4. [TO DO: REVIEW THIS LINE ITEM AND MODIFY IT] Any pull request from Comcast developers should include a link to successful gerrit verification (in the comment section).

<br><br>

## Comcast CI/CD ##

TO BE UPDATED!!

<br><br>

## Documentation ##

When a given RDK Service, the implementation of which, is expected to support COMRPC, the APIs are defined / described using header file (Refer rdkservices-apis/apis/<service name>/<servicename>.h for example)

When a given RDK Service, the implementation of which, is expected to support only JSONRPC, the APIs are described using [JSON Schema](https://json-schema.org/). 

Note 1: When the implementation of the service is expected to support JSONRPC in addition to COMRPC, then there is a tool available under tools/json_generator/generate_json.py which SHALL be used to generate the required JSON Schema files from the headerfile defined for COMRPC.
Note 2: When the implementation of the service is expected to support only JSONRPC, then the required JSON schema files SHALL be created manually as per the details provided below.

JSON Schema provides a standard approach for describing APIs and ensures consistency across all APIs. There are two schemas that are used to describe a service:

* [plugin.schema.json](https://github.com/rdkcentral/rdkservices-apis/blob/main/tools/md_generator/json2md/schemas/plugin.schema.json): A schema for defining a service.
* [interface.schema.json](https://github.com/rdkcentral/rdkservices-apis/blob/main/tools/md_generator/json2md/schemas/interface.schema.json): A schema for defining the properties, methods, and events of a service.

Each RDK service has an instance of these schemas in the root of the respective service folder(apis/<plugin name>/). For example, `MyServicePlugin.json` and `MyService.json`. These files are used to generate API documentation as Markdown. These generated markdown files is written to the `docs/apis` folder. The following demonstrates the folder structure:

```shell
/rdkservices-apis
    /apis
        /MyService
            /MyService.json
            /MyServicePlugin.json
    /docs
        /apis
            /MyServicePlugin.md
```

Markdown files are generated from the JSON definitions using the md_generator tool (`tools/md_generator/generate_md.py`).

The generator tool requires:

* Python 3.5 or higher
* The jsonref library

Verify your Python version:

```shell
python --version
```

Install jsonref if it is not already installed:

```shell
pip install jsonref
```

### Generating Markdown for a Single Service ###

To generate markdown for a single service:

1. Change directories to `tools/md_generator/json2md`.
2. Run `generator_json.py` and provide the location of the service JSON plugin file using the `-d` argument and the output directory using the `-o` argument. You must also include the `--no-interfaces-section` argument; otherwise, an interface section is added to the markdown. Make certain that you are pointing to the plugin definition and not the interface definition. Here is an example of using the tool:

    ```shell
    python ./generator_json.py -d ../../../apis/MyService/MyServicePlugin.json  -o ../../../docs/apis --no-interfaces-section --verbose $files
    ```

    The `MyServicePlugin.md` file is written to the `../../../docs/apis` folder. This is the standard directory where all the service API markdown files are written.

### Generating Markdown for All Services ###

A script is provided to generate the markdown for all services and does a complete build of the documentation. The script only generates the markdown for a service if the JSON definition has been updated. In addition, the script post-processes the generated markdown files to create standard link anchors and to clean the build.

To generate markdown for all services:

1. From the rdkservices-apis repository, change directories to `tools/md_generator`.
2. Run `generate_md.py`. For example:

    ```shell
    python ./generate_md.py
    ```

    All markdown files are written to the `../../docs/apis` folder. This is the standard directory where all the service API markdown files are written.

Use the existing services as a guide when learning the structure of both the plugin and interface schemas.
<br><br>

## Coding Guidelines ##

1. Be Consistent

    * The point of having style guidelines is to have a common vocabulary of coding so people can concentrate on what you’re saying rather than on how you’re saying it.

    * If the code you add to a file looks drastically different from the existing code around it, it throws readers out of their rhythm. Avoid this.

    * If you’re editing code, take a few minutes to determine the coding style of the component and apply the same style.

    * To maintain uniformity in all text-editors, set TAB size to 2 or 4 spaces and replace TAB by SPACES

    * If they use spaces around all their arithmetic operators, you should too.
    
    * If the comments have little boxes of hash marks around them, make your comments have little boxes of hash marks around them too.

    
2. All RDK Services must have a callsign with a prefix of `org.rdk`. RDK Service name must be CamelCase and start with a capital letter.

3. All method, parameter and event names must be camelCase and start with a lowercase letter.

4.  Inter-plugin communication - There might be use cases where one RDK Service needs to call APIs in another RDK Service. Don't use JSON-RPC for such communication since it's an overhead and not preferred for inter-plugin communication. JSON-RPC must be used only by applications. So, in such cases, use COM RPC. 
    <br><br>

## Versioning ##

* Versioning

TO BE UPDATED!!

* Changelog

TO BE UPDATED!!

* Deprecation
    * Breaking changes to the API should first go through Deprecation. Following needs to be done for deprecation.
        * The API/s getting deprecated should be marked with a ["deprecated"] label in the json schema. This will ensure that it's updated in the API documentation.
        * [TO DO: CHECK IF THIS LINE ITEM IS REQUIRED] Add a changelog entry with minor version update and include **Deprecated** label to call out the API/s getting deprecated. 
        * [TO DO: CHECK IF THIS LINE ITEM IS REQUIRED] If this API/s is getting replaced by a newer API then it can come in the same minor version update with changelog entry with **Added** label.
    <br><br>

## Code Review Checklist ##

This checklist is primarily intended for maintainers or reviewers. Please check for the following before approving Pull Requests.

* [Coding Guidelines](#coding-guidelines) are followed. 
* [TO DO: CHECK IF THIS LINE ITEM IS REQUIRED] API Changes are [documented](#documentation) and [versioned](#versioning).
* Approve Pull Requests to develop branch only. Moving changes from develop branch to main branch will be taken care by maintainers at the appropriate time.


## Questions? ##

If you have any questions or concerns reach out to [Ramasamy Thalavay Pillai](mailto:ramasamy_thalavaypillai@comcast.com) OR [Anand Kandasamy](mailto:anand_kandasamy@comcast.com)

For a service specific question, maintainers might refer you to the service owner(s).
<br><br>
