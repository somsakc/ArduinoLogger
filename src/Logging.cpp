#include "Logging.h"

void Logging::begin(const int level, const long speed) {
  _level = constrain(level, LOG_LEVEL_NONE, LOG_LEVEL_VERBOSE);
  _speed = speed;
  Serial.begin(_speed);
}

void Logging::critical(const char* msg, ...) {
  if (LOG_LEVEL_CRITICAL <= _level) {
    va_list argptr;
    va_start(argptr, msg);
    _print("%010lu %s ", _timestamp(), "C");
    _vprintln(msg, argptr);
    va_end(argptr);
  }
}

void Logging::error(const char* msg, ...) {
  if (LOG_LEVEL_ERROR <= _level) {
    va_list argptr;
    va_start(argptr, msg);
    _print("%010lu %s ", _timestamp(), "E");
    _vprintln(msg, argptr);
    va_end(argptr);
  }
}

void Logging::warn(const char* msg, ...) {
  if (LOG_LEVEL_WARN <= _level) {
    va_list argptr;
    va_start(argptr, msg);
    _print("%010lu %s ", _timestamp(), "W");
    _vprintln(msg, argptr);
    va_end(argptr);
  }
}

void Logging::info(const char* msg, ...) {
  if (LOG_LEVEL_INFO <= _level) {
    va_list argptr;
    va_start(argptr, msg);
    _print("%010lu %s ", _timestamp(), "I");
    _vprintln(msg, argptr);
    va_end(argptr);
  }
}

void Logging::debug(const char* msg, ...) {
  if (LOG_LEVEL_DEBUG <= _level) {
    va_list argptr;
    va_start(argptr, msg);
    _print("%010lu %s ", _timestamp(), "D");
    _vprintln(msg, argptr);
    va_end(argptr);
  }
}

void Logging::verbose(const char* msg, ...) {
  if (LOG_LEVEL_VERBOSE <= _level) {
    va_list argptr;
    va_start(argptr, msg);
    _print("%010lu %s ", _timestamp(), "V");
    _vprintln(msg, argptr);
    va_end(argptr);
  }
}

void Logging::log(const char* msg, ...) {
  if (LOG_LEVEL_NONE < _level) {
    va_list argptr;
    va_start(argptr, msg);
    _vprint(msg, argptr);
    va_end(argptr);
  }
}

void Logging::log(const int level, const char* msg, ...) {
  if (level <= _level) {
    va_list argptr;
    va_start(argptr, msg);
    _vprint(msg, argptr);
    va_end(argptr);
  }
}

void Logging::logln(const char* msg, ...) {
  if (LOG_LEVEL_NONE < _level) {
    va_list argptr;
    va_start(argptr, msg);
    _vprintln(msg, argptr);
    va_end(argptr);
  }
}

void Logging::logln(const int level, const char* msg, ...) {
  if (level <= _level) {
    va_list argptr;
    va_start(argptr, msg);
    _vprintln(msg, argptr);
    va_end(argptr);
  }
}

void Logging::_print(const char* msg, ...) {
  va_list argptr;
  va_start(argptr, msg);
  _vprint(msg, argptr);
  va_end(argptr);
}

void Logging::_println(const char* msg, ...) {
  va_list argptr;
  va_start(argptr, msg);
  _vprintln(msg, argptr);
  va_end(argptr);
}

void Logging::_vprint(const char* format, va_list argptr) {
  char buffer[LOG_BUFFER_SIZE];
  vsnprintf(buffer, LOG_BUFFER_SIZE, format, argptr);
  Serial.print(buffer);
}

void Logging::_vprintln(const char* format, va_list argptr) {
  _vprint(format, argptr);
  Serial.println();
}

Logging Log = Logging();
