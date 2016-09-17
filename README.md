# Arduino Logger
Arduino leveling logger with vsnprint-format supplied message

# Example
The library comes an example sketches. See file > examples > loggerdemo.inu as demo Arduino application.

# API Guideline
## Logging Levl

 #define LOG_LEVEL_NONE      0
 #define LOG_LEVEL_CRITICAL  1
 #define LOG_LEVEL_ERROR     2
 #define LOG_LEVEL_WARN      3
 #define LOG_LEVEL_INFO      4
 #define LOG_LEVEL_DEBUG     5
 #define LOG_LEVEL_VERBOSE   6

## Function usage

    void begin(const int level = LOG_LEVEL_DEFAULT, const long speed = 115200L);

    void critical(const char* msg, ...);
    void critical(const String msg) { critical(msg.c_str()); };

    void error(const char* msg, ...);
    void error(const String msg) { error(msg.c_str()); };

    void warn(const char* msg, ...);
    void warn(const String msg) { warn(msg.c_str()); };

    void info(const char* msg, ...);
    void info(const String msg) { info(msg.c_str()); };

    void debug(const char* msg, ...);
    void debug(const String msg) { debug(msg.c_str()); };

    void verbose(const char* msg, ...);
    void verbose(const String msg) { verbose(msg.c_str()); };

    void log(const char* msg, ...);
    void log(const String msg) { log(msg.c_str()); };
    void log(const int level, const char* msg, ...);
    void log(const int level, const String msg) { log(level, msg.c_str()); };
    void logln(const char* msg, ...);
    void logln(const String msg) { logln(msg.c_str()); };
    void logln(const int level, const char* msg, ...);
    void logln(const int level, const String msg) { logln(level, msg.c_str()); };
