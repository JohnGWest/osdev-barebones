

if (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
  message("System Target: x86_64")
  add_subdirectory(i686)
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
  message("System Target: AARCH64")
  add_subdirectory(aarch64)
endif()