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

# ---------------------------------------------------------------------------
# Standalone APIs
#
# Without options, all apis/<dir> and the common files (Ids.h, Module.h, ...)
# are built together into one Marshalling (COM-RPC proxy/stub) and one Definitions (JSON-RPC enum tables) library.
#
# A single apis/<dir> can instead be built and packaged as a standalone API,
# e.g. by a dedicated recipe pinned to a different revision of this repo:
#   main build       : -DSTANDALONE_APIS=OpenCDMi  - everything except the standalone APIs
#   standalone build : -DSTANDALONE_API=OpenCDMi   - only apis/OpenCDMi, without the common files,
#                      into ${NAMESPACE}OpenCDMiMarshalling and ${NAMESPACE}OpenCDMiDefinitions
#
# Every API in STANDALONE_APIS needs its own STANDALONE_API build, 
# and every STANDALONE_API must be listed in STANDALONE_APIS of the main build -
# otherwise the API is missing or built (and installed) twice.
# ---------------------------------------------------------------------------
set(STANDALONE_APIS "" CACHE STRING "apis/ subdirectories built as standalone APIs elsewhere, skipped here (;-separated)")
set(STANDALONE_API "" CACHE STRING "Build only this apis/ subdirectory, as a standalone API")

if(STANDALONE_API AND STANDALONE_APIS)
    message(FATAL_ERROR "STANDALONE_API and STANDALONE_APIS cannot be used together")
endif()

foreach(dir ${STANDALONE_APIS} ${STANDALONE_API})
    if(NOT IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/apis/${dir}")
        message(FATAL_ERROR "STANDALONE_API(S): apis/${dir} does not exist")
    endif()
endforeach()

if(STANDALONE_API)
    list(LENGTH STANDALONE_API standalone_count)
    if(NOT standalone_count EQUAL 1)
        message(FATAL_ERROR "STANDALONE_API takes exactly one apis/ subdirectory, got: ${STANDALONE_API}")
    endif()
    set(API_DIRS ${STANDALONE_API})
    # Common files are provided by the main build
    set(WITH_COMMON_FILES OFF)
else()
    file(GLOB API_ENTRIES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/apis" "${CMAKE_CURRENT_SOURCE_DIR}/apis/*")
    set(API_DIRS "")
    foreach(entry ${API_ENTRIES})
        if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/apis/${entry}" AND NOT entry IN_LIST STANDALONE_APIS)
            list(APPEND API_DIRS ${entry})
        endif()
    endforeach()
    set(WITH_COMMON_FILES ON)
endif()

set(API_INTERFACE_HEADERS "")
set(API_JSON_FILES "")
foreach(dir ${API_DIRS})
    file(GLOB dir_headers "${CMAKE_CURRENT_SOURCE_DIR}/apis/${dir}/I*.h")
    file(GLOB dir_json "${CMAKE_CURRENT_SOURCE_DIR}/apis/${dir}/*.json")
    list(APPEND API_INTERFACE_HEADERS ${dir_headers})
    list(APPEND API_JSON_FILES ${dir_json})
endforeach()

set(API_COMMON_HEADERS "")
if(WITH_COMMON_FILES)
    file(GLOB API_COMMON_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/apis/*.h")
    file(GLOB common_json "${CMAKE_CURRENT_SOURCE_DIR}/apis/*.json")
    list(APPEND API_JSON_FILES ${common_json})
endif()

message(STATUS "entservices-apis: building ${API_DIRS} (common files: ${WITH_COMMON_FILES})")

# Library names: see "Standalone APIs" above
set(Target ${NAMESPACE}${STANDALONE_API}${PROJECT_NAME})
set(DefinitionsTarget ${NAMESPACE}${STANDALONE_API}Definitions)

if(NOT GENERATOR_SEARCH_PATH)
    set(GENERATOR_SEARCH_PATH ${CMAKE_SYSROOT}${CMAKE_INSTALL_PREFIX}/include/${NAMESPACE})
endif()

set(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/apis")
ProxyStubGenerator(INPUT "${API_INTERFACE_HEADERS}" OUTDIR "${CMAKE_CURRENT_BINARY_DIR}/generated" INCLUDE_PATH ${GENERATOR_SEARCH_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/apis" PROJECT_DIR ${PROJECT_DIR})

set(INTERFACES_HEADERS ${API_INTERFACE_HEADERS} ${API_COMMON_HEADERS})
file(GLOB PROXY_STUB_SOURCES "${CMAKE_CURRENT_BINARY_DIR}/generated/ProxyStubs*.cpp")
file(MAKE_DIRECTORY ${CMAKE_SYSROOT}${CMAKE_INSTALL_PREFIX}/include/${NAMESPACE}/interfaces)
add_custom_target(install_headers ALL
        COMMAND ${CMAKE_COMMAND} -E copy ${INTERFACES_HEADERS} ${CMAKE_SYSROOT}${CMAKE_INSTALL_PREFIX}/include/${NAMESPACE}/interfaces
)

add_library(${Target} SHARED
        ./apis/Module.cpp
        ${PROXY_STUB_SOURCES}
        )
add_dependencies(${Target} install_headers)
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

add_subdirectory(build)
add_dependencies(${DefinitionsTarget} install_headers)
