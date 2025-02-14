#ifndef CORE_H
#define CORE_H
#ifndef _WIN32
#include <unistd.h>
#endif
#include <stdio.h>
#include <string.h>

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



