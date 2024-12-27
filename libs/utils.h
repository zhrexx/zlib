#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdio.h>

int to_log();
char *input(char *prompt);

//---------------------------------
//---------------------------------


int to_log() {
    #ifndef NOLOG
        return true;
    #else
        return false;
    #endif
}

char *input(char *prompt) {
    if (to_log()) {
        static const char *color_yellow = "\033[0;33m";
        static const char *color_reset = "\033[0m";
        printf("%s[WARNING] Max input len is 255%s\n", color_yellow, color_reset);
    };

    printf("%s", prompt);

    char *input_ = malloc(256);
    if (input_ == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    scanf("%255s", input_);

    return input_;
}

#endif