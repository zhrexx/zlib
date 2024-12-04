// =======================================================================================================
// ZHRXXgroup Project 🚀 - ZLib
// File: zlib.h
// Author(s): ZHRXXgroup
// Version: 1
// Free to use, modify, and share under our Open Source License (src.zhrxxgroup.com/OPENSOURCE_LICENSE).
// Want to contribute? Visit: issues.zhrxxgroup.com
// GitHub: https://github.com/ZHRXXgroup/zlib
// ========================================================================================================


#ifndef LOG
    #define NOLOG
#endif

void init_zlib();

//------------------------------------//
//------------------------------------//
#ifdef ZLIB_IMPLEMENTATION
#include "libs/vector.h"
#include "libs/error.h"

Vector *zerr = NULL;

#include <stdio.h>
#include <stdbool.h>

#include "libs/utils.h"
#include "libs/color.h"
#include "libs/progress_bar.h"
#include "libs/logger.h"
#include "libs/str.h"
#include "libs/menv_api.h"
#include "libs/requests.h"
#include "libs/hashmap.h"

// FUNCTION needs_rebuild
#include "libs/useful.h"

void throw_error(Error error_code) {
    if (zerr == NULL) {
        init_zlib();
    }

    vector_push(zerr, &error_code);
}

bool check_error(Error error_code) {
    if (zerr == NULL) {
        init_zlib();
    }

    return vector_contains(zerr, &error_code);
}

void init_zlib() {
     zerr = (Vector *)malloc(sizeof(Vector));
     if (!zerr) {
        fprintf(stderr, "Failed to allocate memory for zerr (zerr = ZLIB ERRORSTREAM = ~stderr )\n");
        exit(EXIT_FAILURE);
     }

    vector_init(zerr, 10, sizeof(Error));

}

#endif