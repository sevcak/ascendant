#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

#if ARELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level {
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5,
} log_level;

b8 initialize_logging();
void shutdown_logging();

AAPI void log_output(log_level level, const char *message, ...);

#ifndef AFATAL
/*
 * Log a fatal-level message.
 */
#define AFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);
#endif

#ifndef AERROR
/*
 * Log an error-level message.
 */
#define AERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
/*
 * Log a warning-level message.
 */
#define AWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
// Do nothing when LOG_WARN_ENABLED != 1
#define AWARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
/*
 * Log an info-level message.
 */
#define AINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
// Do nothing when LOG_INFO_ENABLED != 1
#define AINFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
/*
 * Log a debug-level message.
 */
#define ADEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
// Do nothing when LOG_DEBUG_ENABLED != 1
#define ADEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
/*
 * Log a trace-level message.
 */
#define ATRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
// Do nothing when LOG_TRACE_ENABLED != 1
#define ATRACE(message, ...)
#endif