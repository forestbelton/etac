#ifndef ETAC_UTIL_H_
#define ETAC_UTIL_H_

#include <stddef.h>

#define ARRAYLEN(arr) ((sizeof (arr)) / (sizeof (arr)[0]))

/*
 * Allocate memory or abort the program.
 * @param n The number of bytes to allocate.
 */
void *safe_malloc(size_t n);

#endif
