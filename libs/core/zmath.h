#ifndef ZMATH_H
#define ZMATH_H

#include <stdio.h>

#define ZM_E 2.71828182845904523536028747135266249775724709369995






double zm_cos(double x) {
    double term = 1.0;
    double sum = term;
    int max_terms = 10;
    int sign = -1;

    for (int i = 1; i < max_terms; i++) {
        term *= x * x / ((2 * i - 1) * (2 * i));
        sum += sign * term;
        sign *= -1;
    }

    return sum;
}

double zm_sin(double x) {
    double term = x;
    double sum = term;
    int max_terms = 10;
    int sign = -1;

    for (int i = 1; i < max_terms; i++) {
        term *= x * x / ((2 * i) * (2 * i + 1));
        sum += sign * term;
        if (term < 1e-10) break;
        sign *= -1;
    }

    return sum;
}

#endif
