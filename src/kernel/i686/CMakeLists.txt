add_executable(boot boot.s kernel.c)

set_target_properties(boot PROPERTIES LINK_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/linker.ld")

target_link_options(boot PRIVATE "SHELL:-T ${CMAKE_CURRENT_SOURCE_DIR}/linker.ld")