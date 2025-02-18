/*
███████╗██╗     ██╗██████╗ 
╚══███╔╝██║     ██║██╔══██╗
  ███╔╝ ██║     ██║██████╔╝
 ███╔╝  ██║     ██║██╔══██╗
███████╗███████╗██║██████╔╝
╚══════╝╚══════╝╚═╝╚═════╝ 
*/ 
#ifndef CORE_H
#define CORE_H
#ifndef _WIN32
#include <unistd.h>
#endif
#include <stdio.h>
#include <string.h>

#if defined(__GNUC__) || defined(__clang__)
    #define DEPRECATED __attribute__((deprecated))
    #define DEPRECATED_MSG(msg) __attribute__((deprecated(msg)))
    #define LINUX_ONLY __attribute__((error("This function is Linux-only!")))
    #define WINDOWS_ONLY __attribute__((error("This function is Windows-only!")))
    #define MAC_ONLY __attribute__((error("This function is Mac-only!")))
    #define ONLY_64BIT __attribute__((error("This function is 64-bit only!")))
#elif defined(_MSC_VER)
    #define DEPRECATED __declspec(deprecated)
    #define DEPRECATED_MSG(msg) __declspec(deprecated)
    #define LINUX_ONLY __declspec(deprecated("This function is Linux-only!"))
    #define WINDOWS_ONLY __declspec(deprecated("This function is Windows-only!"))
    #define MAC_ONLY __declspec(deprecated("This function is Mac-only!"))
    #define ONLY_64BIT __declspec(deprecated("This function is 64-bit only!"))
#elif __cplusplus >= 201402L
    #define DEPRECATED [[deprecated]]
    #define DEPRECATED_MSG(msg) [[deprecated(msg)]]
    #define LINUX_ONLY [[deprecated("This function is Linux-only!")]]
    #define WINDOWS_ONLY [[deprecated("This function is Windows-only!")]]
    #define MAC_ONLY [[deprecated("This function is Mac-only!")]]
    #define ONLY_64BIT [[deprecated("This function is 64-bit only!")]]
#else
    #define DEPRECATED
    #define DEPRECATED_MSG(msg)
    #define LINUX_ONLY
    #define WINDOWS_ONLY
    #define MAC_ONLY
    #define ONLY_64BIT
#endif

#if defined(__linux__)
    #undef LINUX_ONLY
    #define LINUX_ONLY
#endif

#if defined(_WIN32) || defined(_WIN64)
    #undef WINDOWS_ONLY
    #define WINDOWS_ONLY
#endif

#if defined(__APPLE__) && defined(__MACH__)
    #undef MAC_ONLY
    #define MAC_ONLY
#endif

#if defined(__x86_64__) || defined(_M_X64) || defined(__aarch64__)
    #undef ONLY_64BIT
    #define ONLY_64BIT
#endif




char *shift(int *argc, char ***argv) {
    if (*argc == 0 || *argv == NULL || **argv == NULL) {
        return NULL;
    }

    char *element = strdup((*argv)[0]);
    if (!element) {
        return NULL;
    }

    for (int i = 1; i < *argc; i++) {
        (*argv)[i - 1] = (*argv)[i];
    }
    
    (*argv)[*argc - 1] = NULL; 
    (*argc)--;

    return element;
}



#endif // CORE_H



