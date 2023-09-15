
#include <stddef.h>
#include <stdint.h>

#include "boot_lib.h"
#include "terminal_lib.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error \
  "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main(void)
{
  /* Initialize terminal interface */
  terminal_initialize();

  terminal_write_string("0123456789");
  terminal_write_string("0123456789");
  terminal_write_string("0123456789");
  terminal_write_string("0123456789");
  terminal_write_string("0123456789");
  terminal_write_string("0123456789");
  terminal_write_string("0123456789");
  terminal_write_string("0123456789");
  terminal_write_string("0123456789\n");
  terminal_write_uint32(25565);
  terminal_write_string("Testing negative number display!!!");
  terminal_write_int32(-25565);
}