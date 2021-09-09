//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fact(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

double sine(double n) {
    double res = 0;
    for (int i = 0; i < 10; i++) {
        res += pow(-1, i) * pow(n, 2 * i + 1) / fact(2 * i + 1);
    }
    return res;
}

int main() {
    double angle;
    printf("Enter the angle: ");
    scanf("%lf", &angle);
    double val = sine(angle);
    printf("%lf\n", val);
    return 0;
}