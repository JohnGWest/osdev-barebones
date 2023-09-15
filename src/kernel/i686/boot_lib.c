
#include "boot_lib.h"

#include <stddef.h>

#include "terminal_lib.h"

size_t boot_strlen(const char* str)
{
  size_t len = 0;
  while (str[len]) len++;
  return len;
}

void boot_memcpy(void *restrict destination, const void *restrict source, size_t num)
{
  for (size_t i = 0; i < num; ++i)
  {
    ((char *)destination)[i] = ((const char *)source)[i];
  }
}

void size_t_to_str(size_t n, char* buff, size_t buff_size)
{
  for (size_t i = 0; i < buff_size; ++i)
  {
    if (n > 0)
    {
      buff[buff_size - i - 1] = n % 10 + '0';
    }
    else
    {
      buff[buff_size - i - 1] = ' ';
    }

    n /= 10;
  }
}