#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double f(double x) {
    return x - cos(x);                  //The function whose roots we have to find
}

int main() {
    double a, b, epsilon, c, fa, fb, fc;

    printf("Right hand Limit (a): ");
    scanf("%lf", &a);
    printf("Left hand Limit (b): ");
    scanf("%lf", &b);
    printf("Limit of accuracy: ");
    scanf("%lf", &epsilon);

    bool monotonic = (f(a) < f(b));
    if (!monotonic) {
        double t = a;
        a = b;
        b = t;
    }

    fa = f(a);
    fb = f(b);
    while (true) {
        c = (fa * b - a * fb) / (fa - fb);
        fc = f(c);
        if (fc == 0) {
            break;
        }
        if (fabs(a - c) < epsilon) {
            break;
        }
        a = c;
        fa = fc;
    }
    printf("The root of the function for the desired level of accuracy is: %lf\n", a);
    return 0;
}