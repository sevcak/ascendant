#include "logger.h"
#include "asserts.h"
#include "platform/platform.h"

// TODO: Temporary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void report_assertion_failure(const char *expression, const char *message, const char *file, i32 line)
{
    log_output(
        LOG_LEVEL_FATAL,
        "Assertion Failure: %s, message: '%s', in file: %s, line: %d\n",
        expression, message, file, line
    );
}

b8 initialize_logging()
{
    // TODO: Create log file.

    return TRUE;
}

void shutdown_logging()
{
    // TODO: Clean up logging / write queued entries
}

void log_output(log_level level, const char *message, ...)
{
    const char *level_strings[6] = { "[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: " };

    b8 is_error = level < LOG_LEVEL_WARN;

    char out_message[32000] = { 0 };

    // Format original message.
    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, 32000, message, arg_ptr);
    va_end(arg_ptr);

    // Prepend the log level to the message.
    char out_message2[32000] = { 0 };
    sprintf(out_message2, "%s%s\n", level_strings[level], out_message);

    // Platform specific output.
    if (is_error) {
        platform_console_write_error(out_message2, level);
    } else {
        platform_console_write(out_message2, level);
    }
}
