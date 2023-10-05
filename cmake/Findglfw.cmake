# Usage:
# find_package(glfw required)
# target_link_libraries([target] glfw)

if (NOT GLFW_FOUND)
    INCLUDE(FetchContent)

    FetchContent_Declare(glfw URL https://github.com/glfw/glfw/archive/refs/tags/3.3.8.tar.gz)
    FetchContent_GetProperties(glfw)
    if (NOT GLFW_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(glfw)
        add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
        set(GLFW_FOUND TRUE)
    endif ()
endif ()