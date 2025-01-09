#include <stdio.h>
#include "libs/core/zmath.h"

int main() {
    // Demonstrate trigonometric functions
    double angle = ZM_PI / 4;  // 45 degrees in radians
    printf("Cosine of 45 degrees: %lf\n", zm_cos(angle));
    printf("Sine of 45 degrees: %lf\n", zm_sin(angle));
    printf("Tangent of 45 degrees: %lf\n", zm_tan(angle));

    // Demonstrate exponential and logarithmic functions
    double x = 2.0;
    printf("Exp(2) = %lf\n", zm_exp(x));
    printf("Log(2) = %lf\n", zm_log(x));
    printf("Log10(2) = %lf\n", zm_log10(x));

    // Demonstrate inverse trigonometric functions
    double asin_input = 0.5;
    printf("Arcsin(0.5) = %lf\n", zm_asin(asin_input));
    printf("Arccos(0.5) = %lf\n", zm_acos(asin_input));

    // Demonstrate absolute value and floor/ceil
    double y = -3.7;
    printf("Absolute value of -3.7: %lf\n", zm_abs(y));
    printf("Ceiling of -3.7: %lf\n", zm_ceil(y));
    printf("Floor of -3.7: %lf\n", zm_floor(y));

    // Demonstrate square root and power functions
    double z = 16.0;
    printf("Square root of 16: %lf\n", zm_sqrt(z));
    printf("2^3 = %lf\n", zm_pow(2.0, 3.0));

    // Demonstrate factorial and gamma function
    int n = 5;
    printf("Factorial of 5: %lf\n", zm_factorial(n));
    printf("Gamma(5): %lf\n", zm_gamma(n));

    // Demonstrate hypotenuse calculation
    double a = 3.0, b = 4.0;
    printf("Hypotenuse of a right triangle with sides 3 and 4: %lf\n", zm_hypot(a, b));

    // Demonstrate degree to radian conversion and vice versa
    double degrees = 45.0;
    printf("45 degrees in radians: %lf\n", zm_deg2rad(degrees));
    printf("0.785398 radians in degrees: %lf\n", zm_rad2deg(ZM_PI_4));

    // Check for NaN and Infinity
    double inf = ZM_INFINITY;
    double nan = ZM_NAN;
    printf("Is NaN? %d\n", zm_isnan(nan));
    printf("Is Infinity? %d\n", zm_isinf(inf));

    return 0;
}
