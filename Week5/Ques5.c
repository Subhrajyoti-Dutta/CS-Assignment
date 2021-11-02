//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fact(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * fact(n - 1);
	}
}

double backDiff(double* X, double* Y, int num, double varx) {
	double table[num][num + 1];
	for (int i = 0; i < num; i++) {
		table[i][0] = *(X + i);
		table[i][1] = *(Y + i);
	}
	for (int j = 2; j < num + 1; j++) {
		for (int i = 0; i < num - j + 1; i++) {
			table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]);
		}
	}
	double h = *(X + 1) - *(X + 0);
	double u = (varx - *(X + num - 1)) / h;
	double res = 0, temp;
	for (int i = 0; i < num; i++) {
		temp = 1;
		for (int j = 0; j < i; j++) {
			temp *= (u + j);
		}
		res += temp * table[num - i - 1][i + 1] / fact(i);
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
	scanf("%lf", &varX);
	double result;
	result = backDiff(arrX, arrY, n, varX);
	printf("The value of function at x = %lf is %lf\n", varX, result);
	return 0;
}