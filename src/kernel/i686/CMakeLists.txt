
set(SOURCES
  boot.s
  kernel.c
  boot_lib.c
  terminal_lib.c
)
set(HEADERS
  boot_lib.h
  terminal_lib.h
)

add_executable(boot ${SOURCES})
target_link_options(boot 
  PRIVATE 
    "SHELL:-T ${CMAKE_CURRENT_SOURCE_DIR}/linker.ld"
)
set_target_properties(boot 
  PROPERTIES LINK_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/linker.ld"
)