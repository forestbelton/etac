#include <stdarg.h>

#include "log.h"
#include "util.h"

FILE *log_file;
enum log_level current_level = LOGLEVEL_INFO;

void log_init(enum log_level level) {
    log_file = fopen("etac.log", "a+");
    verify0(log_file != NULL, "could not open log file for appending");

    current_level = level;
}

void log_close() {
    fclose(log_file);
}

void log_fmt(enum log_level level, const char *fmt, ...) {
    va_list args;

    if (level >= current_level) {
        va_start(args, fmt);

        vfprintf(log_file, fmt, args);
        fputc('\n', log_file);

        va_end(args);
    }
}
