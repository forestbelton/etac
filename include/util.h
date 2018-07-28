#ifndef ETAC_UTIL_H_
#define ETAC_UTIL_H_

#include <stdlib.h>
#include <termbox.h>
#include <stdio.h>

#define verify(pred, fmt, ...) do { \
    if (!(pred)) { \
        fprintf(stderr, "error [%s@%d]: ", __FILE__, __LINE__); \
        fprintf(stderr, fmt, ##__VA_ARGS__); \
        fprintf(stderr, "\n"); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

#endif
