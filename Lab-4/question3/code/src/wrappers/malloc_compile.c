#ifdef COMPILETIME

// standard header files
#include <stdio.h>
#include <stdlib.h>

// custom header files
#include <malloc.h>

void* wrapMalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr != NULL) {
        printf("[MALLOC] ALLOCATED MEMORY AT ADDRESS: %p, SIZE: %zu\n", ptr, size);
    }
    return ptr;
}

void wrapFree(void *ptr) {
    if (ptr != NULL) {
        printf("[FREE] DEALLOCATED MEMORY AT ADDRESS: %p\n", ptr);
        free(ptr);
    }
}

#endif