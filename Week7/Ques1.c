//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fact(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return n * fact(n - 1);
	}
}

double func(double x, double y) {
	return x * (y + 1);
}

double nthDeg(double x, double y, int n) {
	if (n == 1) {
		return func(x, y);
	}
	else {
		double epsilon = 0.000001;
		double dfdx = (nthDeg(x + epsilon, y, n - 1) - nthDeg(x - epsilon, y, n - 1)) / (2 * epsilon);
		double dfdy = (nthDeg(x, y + epsilon, n - 1) - nthDeg(x, y - epsilon, n - 1)) / (2 * epsilon);
		return dfdx + dfdy * func(x, y);
	}

}

double diffEqn(double x, double y, double h, int deg) {
	double res = y;

	for (int i = 1; i <= deg; i++) {
		res += pow(h, i) / fact(i) * nthDeg(x, y, i);
	}

	return res;
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
		y = diffEqn(x, y, h, 2);
		x += h;
	}
	printf("Using Taylor Series Method: y(%lf) = %lf\n", x0, y);
	return 0;
}