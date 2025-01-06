#ifndef ENUM_H
#define ENUM_H
#include <stdbool.h>


static int enum_counter = 0;
int enumerate(bool reset) {
    if (reset) {
        enum_counter = 0;
    }

    enum_counter++;

    return enum_counter;
}

#endif // ENUM_H



