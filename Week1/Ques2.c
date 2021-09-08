#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a, b, c;
    double sol1, sol2;
    printf("Write the coefficient of x^2: ");
    scanf("%lf", &a);
    printf("Write the coefficient of x: ");
    scanf("%lf", &b);
    printf("Write the value of constant term: ");
    scanf("%lf", &c);
    sol1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    sol2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    printf("Solution 1: %lf\n", sol1);
    printf("Solution 2: %lf", sol2);
    return 0;
}