# Arduino Logger
Arduino leveling logger with vsnprint-format supplied message

# Example
The library comes an example sketches. See file > examples > loggerdemo.ino as demo Arduino application.

# API Guideline
## Logging Level

 LOG_LEVEL_NONE<br>
 LOG_LEVEL_CRITICAL<br>
 LOG_LEVEL_ERROR<br>
 LOG_LEVEL_WARN<br>
 LOG_LEVEL_INFO<br>
 LOG_LEVEL_DEBUG<br>
 LOG_LEVEL_VERBOSE<br>

## Function Usage

    // Initial minimum threshold level of logging and Serial speed
    void begin(const int level = LOG_LEVEL_DEFAULT, const long speed = 115200L);

    // Critical level with format <timestamp in millis> <level> <message>
    void critical(const char* msg, ...);
    void critical(const String msg) { critical(msg.c_str()); };

    // Error level with format <timestamp in millis> <level> <message>
    void error(const char* msg, ...);
    void error(const String msg) { error(msg.c_str()); };

    // Warn level with format <timestamp in millis> <level> <message>
    void warn(const char* msg, ...);
    void warn(const String msg) { warn(msg.c_str()); };

    // Info level with format <timestamp in millis> <level> <message>
    void info(const char* msg, ...);
    void info(const String msg) { info(msg.c_str()); };

    // Debug level with format <timestamp in millis> <level> <message>
    void debug(const char* msg, ...);
    void debug(const String msg) { debug(msg.c_str()); };

    // Verbose level with format <timestamp in millis> <level> <message>
    void verbose(const char* msg, ...);
    void verbose(const String msg) { verbose(msg.c_str()); };

    // Free style logging
    void log(const char* msg, ...);
    void log(const String msg) { log(msg.c_str()); };
    void log(const int level, const char* msg, ...);
    void log(const int level, const String msg) { log(level, msg.c_str()); };

    // Free style logging with new line at the end of message
    void logln(const char* msg, ...);
    void logln(const String msg) { logln(msg.c_str()); };
    void logln(const int level, const char* msg, ...);
    void logln(const int level, const String msg) { logln(level, msg.c_str()); };

# License

This code is released under the GPL License.
