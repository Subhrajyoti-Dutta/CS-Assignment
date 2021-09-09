//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a, b, c;
    printf("Write the coefficient of x^2: ");
    scanf("%lf", &a);
    printf("Write the coefficient of x: ");
    scanf("%lf", &b);
    printf("Write the value of constant term: ");
    scanf("%lf", &c);
    double D = b * b - 4 * a * c;
    if (D > 0) {
        double sol1 = (-b + sqrt(D)) / (2 * a);
        double sol2 = (-b - sqrt(D)) / (2 * a);
        printf("Solution 1: %lf\n", sol1);
        printf("Solution 2: %lf\n", sol2);
    }
    else if (D == 0) {
        double sol = (-b) / (2 * a);
        printf("Single solution : %lf\n", sol);
    }
    else {
        printf("No real solution\n");
    }
    return 0;
}