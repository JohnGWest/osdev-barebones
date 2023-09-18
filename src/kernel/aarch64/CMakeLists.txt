
set(SOURCES
  boot.s
  kernel.c
)
set(HEADERS

)

add_executable(boot ${SOURCES})
target_link_options(boot
  PRIVATE
    "SHELL:-T ${CMAKE_CURRENT_SOURCE_DIR}/linker.ld"
)
set_target_properties(boot
  PROPERTIES LINK_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/linker.ld"
)