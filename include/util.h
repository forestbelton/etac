#ifndef ETAC_UTIL_H_
#define ETAC_UTIL_H_

#include <stdlib.h>
#include <termbox.h>
#include <stdio.h>

#define verify0(pred, str) do { \
    if (!(pred)) { \
        fprintf(stderr, "error[%s@%d]: %s\n", __FILE__, __LINE__, (str)); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

#define verify(pred, fmt, ...) do { \
    if (!(pred)) { \
        fprintf(stderr, "error [%s@%d]: ", __FILE__, __LINE__); \
        fprintf(stderr, fmt, ##__VA_ARGS__); \
        fprintf(stderr, "\n"); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

#define array_len(arr) ((sizeof (arr)) / (sizeof (arr)[0]))

#endif
