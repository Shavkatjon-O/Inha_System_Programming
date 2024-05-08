#ifdef LINKTIME

#include <stdio.h>
#include <stdlib.h>

void *__real_malloc(size_t size);
void __real_free(void *ptr);

void* __wrap_malloc(size_t size) {
    void* ptr = __real_malloc(size);
    if (ptr != NULL) {
        printf("[MALLOC] ALLOCATED MEMORY AT ADDRESS: %p, SIZE: %zu\n", ptr, size);
    }
    return ptr;
}

void __wrap_free(void *ptr) {
    if (ptr != NULL) {
        printf("[FREE] DEALLOCATED MEMORY AT ADDRESS: %p\n", ptr);
        __real_free(ptr);
    }
}

#endif