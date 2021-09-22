//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

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
    double a, a1, a2, epsilon;

    printf("Eqn: x - cos(x) = 0\n\n");
    printf("Starting Point 1: ");
    scanf("%lf", &a1);
    printf("Starting Point 2: ");
    scanf("%lf", &a2);
    printf("Limit of accuracy: ");
    scanf("%lf", &epsilon);
    a = (a1 + a2) / 2;
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