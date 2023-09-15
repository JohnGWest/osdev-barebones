#ifndef BOOT_LIB_H
#define BOOT_LIB_H

#include <stddef.h>

size_t boot_strlen(const char* str);
void boot_memcpy(void* restrict destination,
                 const void* restrict source,
                 size_t num);
void boot_volatile_memcpy(volatile void* restrict destination,
          volatile const void* restrict source,
          size_t num);

#endif  // BOOT_LIB_H
