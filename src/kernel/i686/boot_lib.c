
#include "boot_lib.h"

#include <stddef.h>

size_t boot_strlen(const char* str)
{
  size_t len = 0;
  while (str[len])
  { 
    len++;
  } 
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

void size_t_to_str(size_t n, char* buffer, size_t buf_size)
{
  const size_t radix = 10;
  for (size_t i = 0ULL; i < buf_size; ++i)
  {
    if (n > 0)
    {
      buffer[buf_size - i - 1] = (char)(n % radix) + '0';
    }
    else
    {
      buffer[buf_size - i - 1] = ' ';
    }

    n /= radix;
  }
}