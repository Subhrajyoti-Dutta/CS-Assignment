//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double cube_root(double x, double num) {
    return pow(x, 3.0) - num;                  //The function whose roots we have to find
}

int main() {
    double a, b, epsilon, num, c, fc;
    printf("Enter the number whose cube root we have to find: ");
    scanf("%lf", &num);
    printf("Right hand Limit (a): ");
    scanf("%lf", &a);
    printf("Left hand Limit (b): ");
    scanf("%lf", &b);
    printf("Limit of accuracy: ");
    scanf("%lf", &epsilon);

    int iter = 0;
    while (fabs(a - b) > epsilon) {
        c = (a + b) / 2;
        fc = cube_root(c, num);
        if (fc == 0) {
            iter++;
            break;
        }
        else if (fc > 0) {
            b = c;
        }
        else {
            a = c;
        }
        iter++;
    }
    printf("The cube root of %g for the desired level of accuracy is: %lf\n", num, (a + b) / 2);
    return 0;
}