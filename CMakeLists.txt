# If not stated otherwise in this file or this component's license file the
# following copyright and licenses apply:
#
# Copyright 2020 Metrological
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.12)

project(Marshalling)

if (BUILD_REFERENCE)
    add_definitions (-DBUILD_REFERENCE=${BUILD_REFERENCE})
endif()

find_package(WPEFramework NAMES WPEFramework Thunder)

project_version(4.4.1)

find_package(CompileSettingsDebug REQUIRED)
find_package(ProxyStubGenerator REQUIRED)
find_package(${NAMESPACE}Core REQUIRED)
find_package(${NAMESPACE}COM REQUIRED)

set(Target ${NAMESPACE}${PROJECT_NAME})

if(NOT GENERATOR_SEARCH_PATH)
    set(GENERATOR_SEARCH_PATH ${CMAKE_SYSROOT}${CMAKE_INSTALL_PREFIX}/include/${NAMESPACE})
endif()

file(GLOB_RECURSE INTERFACES_HEADERS_INPUT ./apis/*/I*.h ./apis/I*.h)
set(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/apis")
ProxyStubGenerator(INPUT "${INTERFACES_HEADERS_INPUT}" OUTDIR "${CMAKE_CURRENT_BINARY_DIR}/generated" INCLUDE_PATH ${GENERATOR_SEARCH_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/apis" PROJECT_DIR ${PROJECT_DIR})

file(GLOB_RECURSE INTERFACES_HEADERS ./apis/*/I*.h ./apis/*.h)
file(GLOB PROXY_STUB_SOURCES "${CMAKE_CURRENT_BINARY_DIR}/generated/ProxyStubs*.cpp")
file(MAKE_DIRECTORY ${CMAKE_SYSROOT}${CMAKE_INSTALL_PREFIX}/include/${NAMESPACE}/interfaces)
add_custom_target(install_headers ALL
        COMMAND ${CMAKE_COMMAND} -E copy ${INTERFACES_HEADERS} ${CMAKE_SYSROOT}${CMAKE_INSTALL_PREFIX}/include/${NAMESPACE}/interfaces
)

add_library(${Target} SHARED
        ./apis/Module.cpp
		./apis/entservices_errorcodes.cpp
        ${PROXY_STUB_SOURCES}
        )
add_dependencies(${NAMESPACE}Marshalling install_headers)
file(GLOB INTERFACE_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/apis/*")
target_include_directories(${Target} PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> 
                                             $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/apis>)

foreach(dir ${INTERFACE_DIRS})
    target_include_directories(${Target} PRIVATE 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${dir}>
)
endforeach()

target_link_libraries(${Target}
        PRIVATE
          ${NAMESPACE}Core::${NAMESPACE}Core
          ${NAMESPACE}COM::${NAMESPACE}COM
          CompileSettingsDebug::CompileSettingsDebug
        )

set_target_properties(${Target} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        FRAMEWORK FALSE
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        )
		
string(TOLOWER ${NAMESPACE} NAMESPACE_LIB)
install(
        TARGETS ${Target} EXPORT ${Target}Targets  # for downstream dependencies
        LIBRARY DESTINATION lib/${NAMESPACE_LIB}/proxystubs COMPONENT libs      # shared lib
)

install(
        FILES ${INTERFACES_HEADERS}
        DESTINATION include/${NAMESPACE}/interfaces
)

include(CreateLink)

CreateLink(
        LINK "${CMAKE_SYSROOT}${CMAKE_INSTALL_PREFIX}/include/cdmi.h"
        TARGET "${CMAKE_SYSROOT}${CMAKE_INSTALL_PREFIX}/include/${NAMESPACE}/interfaces/IDRM.h"
)

add_subdirectory(build)
add_dependencies(${NAMESPACE}Definitions install_headers)
