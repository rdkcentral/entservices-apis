# Entertainment Services APIs #

Entertainment services (a.k.a., Ent Services) APIs are a set of Interface definitions that allows RDK MW developers to build thunder plugins as services. The interface definitions are architected and designed in such a way that these services can provide apps to have access to various platform functionalities in the entertainment devices that are powered by RDK middleware. App developers who would like to make use of the underlying features in the entertainment devices MAY refer this documentation to write, test and deploy their apps in those devices that run RDK MW.

Ent Services APIs are maintained and managed through a specific governance model. Please make sure you are aware of all the details covered in the [governance document ](./governance.md) before you start contributing. 

If you would like to contribute to this project, please fork this project and raise the PR. You will be contacted by one of the members of the governance team.

[View Latest Documentation](https://rdkcentral.github.io/entservices-apis/#/README)



### Table of Contents ###

[Contributing to Ent Services APIs](#contributing-to-entservices-apis)

[Comcast CI/CD](#comcast-cicd)

[Documentation](#documentation)

[Coding Guidelines](#coding-guidelines)

[Versioning](#versioning)

[Code Review Checklist](#code-review-checklist)

[Questions?](#questions)


## Contributing to ENT Services APIs ##

### **License Requirements** ###
1. Before RDK accepts your code into the project you must sign the RDK [Contributor License Agreement (CLA)](https://developer.rdkcentral.com/source/contribute/contribute/before_you_contribute/).

2. Each new file should include the latest [RDKM license header](https://developer.rdkcentral.com/support/support/articles/coding_guideline/)

3. License for this project is included in the root directory and there shouldn't be any additional license file in any of the subfolders.

### **How to contribute?** ###
1. [Fork](https://docs.github.com/en/github/getting-started-with-github/quickstart/fork-a-repo) the repository, commit your changes, build and test it in at least one approved test platform.

2. Submit your changes as a [pull request](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request-from-a-fork) to the develop branch.


### **Pull request Checklist** ###
1. When a pull request is submitted, blackduck, copyright and cla checks will automatically be triggered. Ensure these checks have passed (turned into green).

2. At least one approved reviewer needs to **review and approve** the pull request.

3. For tracking and release management purposes, each pull request and all the commits in the pull request shall include **RDK ticket number(s) or Github issue number(s)** and "reason for the change".

4. Any pull request from Comcast developers should include a link to successful gerrit verification (in the comment section).

## Comcast CI/CD ##

TO BE UPDATED!!

## Documentation ##

**Note:** Review [Governance](./governance) document for detailed information on API specification guidelines.

- By default, the APIs are defined / described using header file so COMRPC is inherently supported by default (Refer entservices-apis/apis/<service name>/<servicename>.h for example)

- When the implementation of a given Ent Service is expected to support JSONRPC in addition to COMRPC, then interface definition must have "@json 1.0.0" and "@text:keep" 

- When the implementation of a given Ent Service is expected to support only JSONRPC, then use @stubgen:omit tag at struct/class to omit proxystub generation for COM-RPC support.

Markdown files are generated from the header file / JSON definitions using the JsonGenerator tool from ThunderTools.

The JsonGenerator tool is built and installed as part of the CI/CD workflow via CMake. To generate documentation locally:

### Generating Markdown for Incremental Changes ###

When specific files have changed, generate documentation for only those files:

```shell
install/sbin/JsonGenerator/JsonGenerator.py --docs -I install/include/WPEFramework/ --output $(pwd)/docs/apis <changed-files>
```

### Generating Markdown for All Services ###

To generate markdown for all services:

```shell
install/sbin/JsonGenerator/JsonGenerator.py --docs -I install/include/WPEFramework/ --output $(pwd)/docs/apis apis/*/I*.h apis/*/*.json
```

After generating documentation, update the sidebar with new entries:

```shell
python3 tools/update_sidebar.py
```

All markdown files are written to the `docs/apis` folder.

Use the existing services as a guide when learning the structure of both the plugin and interface schemas.

## Coding Guidelines ##

** Note:*: Refer [governance](./governance.md) document for more specific coding guidelines while the below sub section provides "generic" guidelines.

1. Be Consistent

    * The point of having style guidelines is to have a common vocabulary of coding so people can concentrate on what you're saying rather than on how you're saying it.

    * If the code you add to a file looks drastically different from the existing code around it, it throws readers out of their rhythm. Avoid this.

    * If you're editing code, take a few minutes to determine the coding style of the component and apply the same style.

    * To maintain uniformity in all text-editors, set TAB size to 2 or 4 spaces and replace TAB by SPACES

    * If they use spaces around all their arithmetic operators, you should too.

    * If the comments have little boxes of hash marks around them, make your comments have little boxes of hash marks around them too.


2. All Ent Services must have a callsign with a prefix of `org.rdk`. Ent Service name must be CamelCase and start with a capital letter.

3.  Inter-plugin communication - There might be use cases where one Ent Service needs to call APIs in another Ent Service. Don't use JSON-RPC for such communication since it's an overhead and not preferred for inter-plugin communication. JSON-RPC must be used only by applications. So, in such cases, use COM RPC. 

## Versioning ##

* Versioning
   * Refer [governance](./governance.md) document for more details on how versioning is maintained

* Changelog
     * Change log is now automated. Make sure the PR contains appropriate title, description and the description contains a line as follows:
        * version: <Major/Minor/Patch>

* Deprecation
    * Breaking changes to the API should first go through Deprecation. Following needs to be done for deprecation.
        * The API/s getting deprecated should be marked with a ["deprecated"] label in the json schema, or marked with @deprecated tag in the interface header file. This will ensure that it's updated in the API documentation

## Code Review Checklist ##

This checklist is primarily intended for maintainers or reviewers. Please check for the following before approving Pull Requests.

* [Coding Guidelines](#coding-guidelines) are followed. 
* API Changes are [documented](#documentation) and [versioned](#versioning).
* Approve Pull Requests to develop branch only. Moving changes from develop branch to main branch will be taken care by maintainers at the appropriate time.

## Questions? ##

If you have any questions or concerns reach out to [Ramasamy Thalavay Pillai](mailto:ramasamy_thalavaypillai@comcast.com) OR [Anand Kandasamy](mailto:anand_kandasamy@comcast.com)

For a service specific question, maintainers might refer you to the service owner(s).


