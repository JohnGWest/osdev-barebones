#ifndef STRING_LIB_H
#define STRING_LIB_H

#include <stddef.h>
#include <stdint.h>

void size_to_str(size_t n, char* buf, size_t buf_size);
void uint32_to_str(uint32_t n, char* buf, size_t buf_size);
void int32_to_str(int32_t n, char* buf, size_t buf_size);

#endif // STRING_LIB_H