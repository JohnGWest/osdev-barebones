cmake_minimum_required(VERSION 3.21)

# Prelude
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR
        "In-source builds are not supported."
        "Please read the BUILDING.md document before trying to build this project."
        "You may need to delete 'CMakeCache.tx' and 'CMakeFiles/' first."
    )
endif()

include(tools/cmake/cmake-policy.cmake)

# Gather version information
message(STATUS "Gathering git information.")
execute_process(
    COMMAND git log -1 --format=%h
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE COMMIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Provided version
if(DEFINED VERSION_MAJOR AND DEFINED VERSION_MINOR AND DEFINED VERSION_PATCH)
    message(STATUS "Using provided version information. Version: ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
# Environment version
elseif(DEFINED ENV{VERSION_MAJOR} AND DEFINED ENV{VERSION_MINOR} AND DEFINED ENV{VERSION_PATCH})
    set(VERSION_MAJOR $ENV{VERSION_MAJOR})
    set(VERSION_MINOR $ENV{VERSION_MINOR})
    set(VERSION_PATCH $ENV{VERSION_PATCH})
    message(STATUS "Using environment version information. Version: ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
# File version
else()
    message(STATUS "Using file version information.")
    file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/tools/cmake/files/version_information.txt VERSION_INFO_CONTENTS)

    foreach(name_and_value ${VERSION_INFO_CONTENTS})
        string(REGEX REPLACE "^[ ]+" "" name_and_value ${name_and_value})
        string(REGEX MATCH "^[^=]+" name ${name_and_value})
        string(REPLACE "${name}=" "" value ${name_and_value})
        set(${name} "${value}")
    endforeach()
    message(STATUS "Version: ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
endif()

project( kernel
    LANGUAGES C ASM
    VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
)

# Prepare cmake environment
include(GNUInstallDirs)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/tools/cmake/modules")

### Options
option(BUILD_ALL "Build all artifacts." ${PROJECT_IS_TOP_LEVEL})
option(ENABLE_FORMAT "Generate formatting targets." ${PROJECT_IS_TOP_LEVEL})
option(ENABLE_SPELLCHECK "Generate spellcheck targets." ${PROJECT_IS_TOP_LEVEL})

# Add Source Dir
add_subdirectory(src)

### Other Targets
if(ENABLE_FORMAT)
    message("Generating formatting targets. (format-check, format-fix)")
    include(tools/cmake/format-targets.cmake)
endif()

if(ENABLE_SPELLCHECK)
    message("Generating spellcheck targets. (spell-check, spell-fix)")
    include(tools/cmake/spell-targets.cmake)
endif()