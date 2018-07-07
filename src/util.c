#include <stdio.h>
#include <stdlib.h>

#include "util.h"

void *safe_malloc(size_t n) {
    void *ptr = malloc(n);

    if (ptr == NULL) {
        fprintf(stderr, "error: out of memory\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}
