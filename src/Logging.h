#ifndef LOGGING_H
#define LOGGING_H

#include <Arduino.h>
#include <stdarg.h>

#define LOG_LEVEL_NONE      0
#define LOG_LEVEL_CRITICAL  1
#define LOG_LEVEL_ERROR     2
#define LOG_LEVEL_WARN      3
#define LOG_LEVEL_INFO      4
#define LOG_LEVEL_DEBUG     5
#define LOG_LEVEL_VERBOSE   6

#define LOG_LEVEL_DEFAULT   LOG_LEVEL_INFO
#define LOG_BUFFER_SIZE     1024

class Logging {
  public:
    Logging() {} ;

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

  private:
    void _print(const char* msg, ...);
    void _println(const char* msg, ...);
    void _vprint(const char* format, va_list argptr);
    void _vprintln(const char* format, va_list argptr);
    unsigned long _timestamp() { return millis(); };

    int _level;
    long _speed;

};

extern Logging Log;

#endif
