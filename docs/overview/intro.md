# Entertainment Services Overview

Entertainment services are a set of JSON-RPC services for accessing component functionality that is available on RDK devices. The services are implemented as plugins for the Thunder framework. The Thunder framework is responsible for, among other things, managing plugins and handling client requests.

Many of the traditional services available on an RDK device are implemented as Thunder plugins. These plugins are commonly referred to as *Entertainment services* because of their JSON-RPC services-based interface. The terms Entertainment services and Thunder plugins are synonymous.

Entertainment services are invoked using their JSON-RPC service interface over HTTP or Web Sockets. This makes Entertainment services easily accessible to Lightning applications or any web client (standalone or browser-based) that can process JSON. For native applications, you can also invoke Entertainment services directly using C/C++ native code.

