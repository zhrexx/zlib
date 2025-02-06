#ifndef CORE_H
#define CORE_H
#ifndef _WIN32
#include <unistd.h>
#endif
#include <stdio.h>
#include <string.h>

char *shift(int argc, char **argv) {
    char *element = strdup(argv[0]);

    for (int i = 1; i < argc; i++) {
        argv[i-1] = argv[i];
    }
    return element;
}


#endif // CORE_H



