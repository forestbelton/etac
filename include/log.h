#ifndef ETAC_LOG_H_
#define ETAC_LOG_H_

enum log_level {
    LOGLEVEL_TRACE,
    LOGLEVEL_DEBUG,
    LOGLEVEL_INFO,
    LOGLEVEL_WARN,
    LOGLEVEL_ERROR
};

void log_init(enum log_level level);

void log_close();

void log_fmt(enum log_level level, const char *fmt, ...);

#endif
