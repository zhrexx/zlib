// ========================================================================================>
// ZHRXXgroup Project 🚀 - ZLib
// File: error.h
// Author(s): ZHRXXgroup
// Version: 1
// ========================================================================================>



#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef enum {
    NO_ERROR = 0,

    // Non-Fatal error > 100 < 1000
    ERROR = 100,
    DEFAULT_ERROR,

   // Fatal error > 1000
    FATAL_ERROR = 1000,

} Error;


//--------------------------------------------
//--------------------------------------------

#define RED "\033[1;31m"
#define RESET "\033[0m"

void throw_error_with_no_errorcode(const char *format, ...) {
    va_list args;
    va_start(args, format);
    fprintf(stderr, RED "Error: ");
    vfprintf(stderr, format, args);
    fprintf(stderr, RESET "\n");
    va_end(args);
    exit(1);
}


// Currently not Implemented
void not_impl_yet(char *name) {
    throw_error_with_no_errorcode("'%s' is not implemented yet!", name);
}
