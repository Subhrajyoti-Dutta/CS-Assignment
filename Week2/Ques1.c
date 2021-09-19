#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double f(double x) {
    return x * exp(x) - 1;                  //The function whose roots we have to find
}

int main() {
    double a, b, epsilon, c, fc;

    printf("Right hand Limit (a): ");
    scanf("%lf", &a);
    printf("Left hand Limit (b): ");
    scanf("%lf", &b);
    printf("Limit of accuracy: ");
    scanf("%lf", &epsilon);

    bool monotonic = (f(a) < f(b));

    int iter = 0;
    while (fabs(a - b) > epsilon) {
        c = (a + b) / 2;
        fc = f(c);
        if (fc == 0) {
            iter++;
            break;
        }
        else if (fc > 0 && monotonic || fc < 0 && !monotonic) {
            b = c;
        }
        else {
            a = c;
        }
        iter++;
    }
    printf("The number of iteration for the desired level of accuracy is: %d\n", iter);
    return 0;
}