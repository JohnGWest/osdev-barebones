#ifndef BOOT_LIB_H
#define BOOT_LIB_H

#include <stddef.h>

size_t boot_strlen(const char* str);
void boot_memcpy(void* restrict destination,
                 const void* restrict source,
                 size_t num);
void size_t_to_str(size_t n, char* buff, size_t buff_size);

#endif  // BOOT_LIB_H
