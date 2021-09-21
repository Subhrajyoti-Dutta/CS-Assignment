#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double f(double x) {
    return x * exp(x) - 1;                  //The function whose roots we have to find
}

int main() {
    double a, b, epsilon, c, fa, fb, fc;

    printf("Right hand Limit (a): ");
    scanf("%lf", &a);
    printf("Left hand Limit (b): ");
    scanf("%lf", &b);
    printf("Limit of accuracy: ");
    scanf("%lf", &epsilon);

    int iter = 0;
    while (fabs(fa - fb) > epsilon && fabs(a - b) > epsilon) {
        c = (a + b) / 2;
        fc = f(c);
        if (fc == 0) {
            iter++;
            break;
        }
        else if (fc * fa < 0) {
            b = c;
            fb = fc;
        }
        else {
            a = c;
            fa = fc;
        }
        iter++;
    }
    printf("The number of iteration for the desired level of accuracy is: %d\n", iter);
    return 0;
}