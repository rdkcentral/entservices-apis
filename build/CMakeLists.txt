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

cmake_minimum_required(VERSION 3.3)

project(Definitions)

find_package(WPEFramework)

project_version(4.4.1)

find_package(CompileSettingsDebug REQUIRED)
find_package(JsonGenerator REQUIRED)
find_package(${NAMESPACE}Core REQUIRED)
find_package(${NAMESPACE}PrivilegedRequest QUIET)

set(Target ${NAMESPACE}${PROJECT_NAME})

file(GLOB JSON_FILE "${CMAKE_CURRENT_SOURCE_DIR}/../apis/*/*.json" "${CMAKE_CURRENT_SOURCE_DIR}/../apis/*.json")
file(GLOB INTERFACE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/../apis/*/I*.h")

if(NOT GENERATOR_SEARCH_PATH)
    set(GENERATOR_SEARCH_PATH ${CMAKE_SYSROOT}${CMAKE_INSTALL_PREFIX}/include/${NAMESPACE})
endif()
file(GLOB_RECURSE INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}../apis")
JsonGenerator(CODE INPUT ${JSON_FILE} OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/generated" INCLUDE_PATH ${GENERATOR_SEARCH_PATH} CPPIFDIR "${INCLUDE_PATH}" LEGACY_ALT)
JsonGenerator(CODE INPUT ${INTERFACE_FILE} OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/generated" INCLUDE_PATH ${GENERATOR_SEARCH_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../apis" LEGACY_ALT)

file(GLOB JSON_ENUM_SOURCES "${CMAKE_CURRENT_BINARY_DIR}/generated/JsonEnum*.cpp")
file(GLOB JSON_LINK_HEADERS "${CMAKE_CURRENT_BINARY_DIR}/generated/J*.h")

include(CreateLink)
CreateLink(LINK "${CMAKE_CURRENT_BINARY_DIR}/generated/Module.h" TARGET "../Module.h")
list(APPEND JSON_LINK_HEADERS "${CMAKE_CURRENT_BINARY_DIR}/generated/Module.h")
CreateLink(LINK "${CMAKE_CURRENT_BINARY_DIR}/generated/Ids.h" TARGET "../Ids.h")
list(APPEND JSON_LINK_HEADERS "${CMAKE_CURRENT_BINARY_DIR}/generated/Ids.h")
CreateLink(LINK "${CMAKE_CURRENT_BINARY_DIR}/Module.h" TARGET "../apis/Module.h")
list(APPEND PUBLIC_HEADERS "${CMAKE_CURRENT_BINARY_DIR}/Module.h")
CreateLink(LINK "${CMAKE_CURRENT_BINARY_DIR}/generated/Ids_comcast.h" TARGET "../Ids_comcast.h")
list(APPEND JSON_LINK_HEADERS "${CMAKE_CURRENT_BINARY_DIR}/generated/Ids_comcast.h")

add_library(${Target} SHARED
        ${JSON_ENUM_SOURCES}
        ../apis/entservices_errorcodes.cpp
        )

target_link_libraries(${Target}
        PRIVATE
          ${NAMESPACE}Core::${NAMESPACE}Core
          CompileSettingsDebug::CompileSettingsDebug
        )

set_target_properties(${Target} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        FRAMEWORK FALSE
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        PUBLIC_HEADER "${PUBLIC_HEADERS}" # specify the public headers
        )

target_include_directories(${Target} PRIVATE
                                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../apis>
                                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                                $<INSTALL_INTERFACE:include/${NAMESPACE}>)
install(
        TARGETS ${Target} EXPORT ${Target}Targets  # for downstream dependencies
        ARCHIVE DESTINATION lib/ COMPONENT libs      # static lib
        LIBRARY DESTINATION lib/ COMPONENT libs      # shared lib
        RUNTIME DESTINATION bin COMPONENT libs      # binaries
        FRAMEWORK DESTINATION bin/ COMPONENT libs    # for mac
        INCLUDES DESTINATION include/${NAMESPACE}   # default include path
)

install(
        FILES ${JSON_LINK_HEADERS}
        DESTINATION include/${NAMESPACE}/interfaces/json
)

InstallPackageConfig(
        TARGETS ${Target}
        DESCRIPTION "Share lookup tables associated with interface enums."
        )


InstallCMakeConfig(TARGETS ${Target})
