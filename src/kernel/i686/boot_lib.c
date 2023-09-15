
#include "boot_lib.h"

#include <stddef.h>

size_t boot_strlen(const char* str)
{
  size_t len = 0;
  while (str[len]) len++;
  return len;
}

void boot_memcpy(void* restrict destination,
                 const void* restrict source,
                 size_t num)
{
  for (size_t i = 0; i < num; ++i)
  {
    ((char*)destination)[i] = ((const char*)source)[i];
  }
}

void boot_volatile_memcpy(volatile void* restrict destination,
                 volatile const void* restrict source,
                 size_t num)
{
  for (size_t i = 0; i < num; ++i)
  {
    ((char*)destination)[i] = ((const char*)source)[i];
  }
}
