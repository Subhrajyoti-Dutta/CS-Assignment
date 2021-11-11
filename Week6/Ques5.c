//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simpThreeEighthIntegral(double* X, double* Y, int num) {
	double h = *(X + 1) - *(X + 0);
	double res = 0;
	res += *Y;
	for (int i = 1; i < num - 1; i += 3) {
		res += 3 * *(Y + i);
	}
	for (int i = 2; i < num - 1; i += 3) {
		res += 3 * *(Y + i);
	}
	for (int i = 3; i < num - 1; i += 3) {
		res += 2 * *(Y + i);
	}
	res += *(Y + num - 1);
	return res * 3 * h / 8;
}

int main() {
	int n;
	printf("Type the number of available points: ");
	scanf("%d", &n);
	double arrX[n];
	double arrY[n];
	printf("Type the x coordinate of the points in order in space separated manner:\n");
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arrX[i]);
	}
	printf("Type the y coordinate of the points in order in space separated manner:\n");
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arrY[i]);
	}

	double result = simpThreeEighthIntegral(arrX, arrY, n);
	printf("The integral result using simson's 3/8th rule is: %lf\n", result);
	return 0;
}