#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
    return x - cos(x);                  //The function whose roots we have to find
}

double df(double x) {
    return 1 + sin(x);
}

int main() {
    double a, epsilon;

    printf("Starting Point: ");
    scanf("%lf", &a);
    printf("Limit of accuracy: ");
    scanf("%lf", &epsilon);

    double c = a, fa = f(a), fc = fa;
    do {
        a = c;
        fa = fc;
        c = a - fa / df(a);
        fc = f(c);
    } while (fc != 0 && fabs(fc - fa) > epsilon && fabs(c - a) > epsilon);
    printf("The root of the function for the desired level of accuracy is: %lf\n", c);
    return 0;
}