//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    //Eq1: 2x + 3y = 6
    //Eq2: 4x + 9y = 15
    float p1 = 2, q1 = 3, c1 = 6;
    float p2 = 4, q2 = 9, c2 = 15;

    float x, y;

    x = (c1 * q2 - c2 * q1) / (p1 * q2 - p2 * q1);
    y = -(c1 * p2 - c2 * p1) / (p1 * q2 - p2 * q1);

    printf("Value of x is: %lf\n", x);
    printf("Value of y is: %lf\n", y);


    return 0;
}