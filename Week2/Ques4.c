//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
    return x - cos(x);                  //The function whose roots we have to find
}

int main() {
    double a, b, epsilon;

    printf("Starting Point 1: ");
    scanf("%lf", &a);
    printf("Starting Point 2: ");
    scanf("%lf", &b);
    printf("Limit of accuracy: ");
    scanf("%lf", &epsilon);

    double c = a, fa, fb;
    fa = f(a);
    fb = f(b);
    double fc = fa;
    do {
        a = c;
        fa = fc;
        c = (fa * b - a * fb) / (fa - fb);
        fc = f(c);
    } while (fc != 0 && fabs(fc - fa) > epsilon && fabs(c - a) > epsilon);
    printf("The root of the function for the desired level of accuracy is: %lf\n", c);
    return 0;
}