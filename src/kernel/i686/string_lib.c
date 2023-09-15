#include "string_lib.h"

#include <stddef.h>
#include <stdint.h>

void size_to_str(size_t n, char* buf, size_t buf_size)
{
  for (size_t i = 0; i < buf_size; ++i)
  {
    if (n > 0)
    {
      buf[buf_size - i - 1] = n % 10 + '0';
    }
    else
    {
      buf[buf_size - i - 1] = ' ';
    }

    n /= 10;
  }
}

void uint32_to_str(uint32_t n, char* buf, size_t buf_size)
{
  for (size_t i = 0; i < buf_size; ++i)
  {
    if (n > 0)
    {
      buf[buf_size - i - 1] = n % 10 + '0';
    }
    else
    {
      buf[buf_size - i - 1] = ' ';
    }

    n /= 10;
  }
}

// void uint16_to_str(uint16_t n, char* buf, size_t buf_size)
// {
//   for (size_t i = 0; i < buf_size; ++i)
//   {
//     if (n > 0)
//     {
//       buf[buf_size - i - 1] = n % 10 + '0';
//     }
//     else
//     {
//       buf[buf_size - i - 1] = ' ';
//     }

//     n /= 10;
//   }
// }

// void uint8_to_str(uint8_t n, char* buf, size_t buf_size)
// {
//   for (size_t i = 0; i < buf_size; ++i)
//   {
//     if (n > 0)
//     {
//       buf[buf_size - i - 1] = n % 10 + '0';
//     }
//     else
//     {
//       buf[buf_size - i - 1] = ' ';
//     }

//     n /= 10;
//   }
// }

void int32_to_str(int32_t n, char* buf, size_t buf_size)
{
  size_t is_negative;
  if (n < 0)
  {
    is_negative = 1;
    n *= -1;
  }
  else
  {
    is_negative = 0;
  }

  uint32_to_str(n, buf, buf_size);
  size_t start;
  for (start = 0; buf[start] == ' ' && start < buf_size; ++start);
  if (start > 0)
  {
    buf[start - 1] = '-';
  }
}