#ifndef WRAP_MALLOC_COMPILE_H
#define WRAP_MALLOC_COMPILE_H

#define malloc(size) wrapMalloc(size)
#define free(ptr) wrapFree(ptr)

#include <stddef.h>

void* wrapMalloc(size_t size);
void wrapFree(void* ptr);

#endif