//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x, double y) {
	return x * (y + 1);
}

int main() {
	double x, y, h, x0;
	printf("Eqn: y' = x(y+1)\n\n");
	printf("Value of initial x: ");
	scanf("%lf", &x);
	printf("Value of initial y: ");
	scanf("%lf", &y);
	printf("Value of h: ");
	scanf("%lf", &h);
	printf("Compute value at x = ");
	scanf("%lf", &x0);

	int n = (x0 - x) / h;
	for (int i = 0; i < n; i++) {
		y += h * func(x, y);
		x += h;
	}

	printf("Using Eular's Method: y(%lf) = %lf\n", x0, y);
	return 0;

}