#include <stdarg.h>
#include <time.h>

#include "log.h"
#include "util.h"

FILE *log_file;
enum log_level current_level = LOGLEVEL_INFO;

static const char *log_current_time();

void log_init(enum log_level level) {
    log_file = fopen("etac.log", "a+");
    verify0(log_file != NULL, "could not open log file for appending");

    current_level = level;
}

void log_close() {
    fclose(log_file);
}

void log_fmt(enum log_level level, const char *fmt, ...) {
    static char *level_name[] = {
        [LOGLEVEL_TRACE] = "TRACE",
        [LOGLEVEL_DEBUG] = "DEBUG",
        [LOGLEVEL_INFO] = "INFO",
        [LOGLEVEL_WARN] = "WARN",
        [LOGLEVEL_ERROR] = "ERROR"
    };

    if (level >= current_level) {
        va_list args;

        fprintf(log_file, "%s: %5s: ", log_current_time(), level_name[level]);

        va_start(args, fmt);
        vfprintf(log_file, fmt, args);
        va_end(args);

        fputc('\n', log_file);
        fflush(log_file);
    }
}

static const char *log_current_time() {
    static char formatted[80];
    time_t raw_time;
    struct tm *info;

    time(&raw_time);
    info = localtime(&raw_time);

    strftime(&formatted[0], sizeof formatted, "%Y-%m-%d %H:%M:%S", info);
    return &formatted[0];
}
