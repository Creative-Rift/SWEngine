cmake_minimum_required( VERSION 3.20...3.22 )

project( "ShipWreck Engine"
        VERSION
        0.1
        DESCRIPTION
        "Graphical Engine written in c++ with openGL."
        )

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/${CMAKE_PROJECT_VERSION} )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/${CMAKE_PROJECT_VERSION} )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/${CMAKE_PROJECT_VERSION} )
set( PREFIX_MESSAGE "[SWEngine] " )
set( EXEC SWEngine )

add_definitions(-DBOOST_JSON_NO_LIB)
add_definitions(-DBOOST_CONTAINER_NO_LIB)

message(${PREFIX_MESSAGE} "Build type set to: " ${CMAKE_BUILD_TYPE})
message(${PREFIX_MESSAGE} "Current cmake location: " ${CMAKE_CURRENT_SOURCE_DIR})
message(${PREFIX_MESSAGE} "Project location: " ${CMAKE_SOURCE_DIR})

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

## GET SOURCES
## <=====================================>
file(GLOB_RECURSE SRC "${PROJECT_SOURCE_DIR}/sources/*")
## <=====================================>

## GET Header
## <=====================================>
set(HEADER
        "${PROJECT_SOURCE_DIR}/includes/"
        "${PROJECT_SOURCE_DIR}/external/"
)
## <=====================================>

## OUTPUT
## <=====================================>
## Build shared lib
add_library(${EXEC} SHARED ${SRC})
## <=====================================>

## ADD INCLUDES
## <=====================================>
target_include_directories(${EXEC} PUBLIC ${HEADER})
## <=====================================>

## SETUP DEPENDENCIES
## <=====================================>
if (WIN32)
    message(${PREFIX_MESSAGE} "Preparing dependencies for windows...")
    # include(cmake/windows.cmake)
    set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
    find_package(glfw REQUIRED)
    target_link_libraries(${EXEC} glfw)

else()
    message(FATAL_ERROR "System not supported!")
endif()
## <=====================================>

if (${CMAKE_BUILD_TYPE} MATCHES Debug)
    set_target_properties(${EXEC} PROPERTIES
            DEBUG_POSTFIX "d")
endif()

