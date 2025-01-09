#ifndef ENUM_H
#define ENUM_H
#include <stdbool.h>


int enumCounter = 0;
int enumerate(bool reset) {
    if (reset) {
        enumCounter = 0;
    }

    enumCounter++;

    return enumCounter;
}

#endif // ENUM_H



