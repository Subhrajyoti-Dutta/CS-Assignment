//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double interpolate(double* X, double* Y, int num, double varx) {
	double res = 0.0, temp;
	for (int i = 0; i < num; i++) {
		temp = 1;
		for (int j = 0; j < num; j++) {
			if (i != j) {
				temp *= (varx - *(X + j)) / (*(X + i) - *(X + j));
			}
		}
		res += *(Y + i) * temp;
	}
	return res;
}

int main() {
	int n;
	printf("Type the number of available points: ");
	scanf("%d", &n);
	double arrX[n];
	double arrY[n];
	double varX;
	printf("Type the x coordinate of the points in order in space separated manner:\n");
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arrX[i]);
	}
	printf("Type the y coordinate of the points in order in space separated manner:\n");
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arrY[i]);
	}
	printf("Type the x coordinate of the point you want to predict: ");
	scanf("%lf", varX);
	double varY;
	varY = interpolate(arrX, arrY, n, varX);
	printf("The y coordinate at x = %lf is %lf\n", varX, varY);
	return 0;
}