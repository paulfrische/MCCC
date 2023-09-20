#ifndef BASE_LOGGING_H
#define BASE_LOGGING_H

#pragma clang diagnostic ignored "-Wformat-extra-args"

/*
log levels:
- debug
- info
- warning
- error
- critical
*/

#ifndef LEVEL
#define LEVEL 1
#endif // !LEVEL

#include <stdio.h>

#if LEVEL > 0
#define CRITICAL_ENABLE
#define CRITICAL(...)                                                                                                  \
    printf("[CRITICAL]: ");                                                                                            \
    printf(__VA_ARGS__);                                                                                               \
    printf("\n")
#else
#define CRITICAL(...)
#endif // LEVEL == 1

#if LEVEL > 1
#define ERROR_ENABLE
#define ERROR(...)                                                                                                     \
    printf("[ERROR]: ");                                                                                               \
    printf(__VA_ARGS__);                                                                                               \
    printf("\n")
#else
#define ERROR(...)
#endif

#if LEVEL > 2
#define WARNING_ENABLE
#define WARN(...)                                                                                                      \
    printf("[WARNING]: ");                                                                                             \
    printf(__VA_ARGS__);                                                                                               \
    printf("\n")
#else
#define WARN(...)
#endif

#if LEVEL > 3
#define INFO_ENABLE
#define INFO(...)                                                                                                      \
    printf("[INFO]: ");                                                                                                \
    printf(__VA_ARGS__);                                                                                               \
    printf("\n")
#else
#define INFO(...)
#endif

#if LEVEL > 4
#define DEBUG_ENABLE
#define DEBUG(...)                                                                                                     \
    printf("[DEBUG]: ");                                                                                               \
    printf(__VA_ARGS__);                                                                                               \
    printf("\n")
#else
#define DEBUG(...)
#endif

#endif // !BASE_LOGGING_H
