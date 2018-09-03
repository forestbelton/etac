#ifndef ETAC_UTIL_H_
#define ETAC_UTIL_H_

#include <stdlib.h>
#include <termbox.h>
#include <stdio.h>

#include "log.h"

#define verify0(pred, str) do { \
    if (!(pred)) { \
        log_fmt(LOGLEVEL_ERROR, "[%s:%d]: %s\n", __FILE__, __LINE__, (str)); \
        log_close(); \
        tb_shutdown(); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

#define verify(pred, fmt, ...) do { \
    if (!(pred)) { \
        log_fmt(LOGLEVEL_ERROR, "[%s:%d]: " fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
        log_close(); \
        tb_shutdown(); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

#define array_len(arr) ((sizeof (arr)) / (sizeof (arr)[0]))

#endif
