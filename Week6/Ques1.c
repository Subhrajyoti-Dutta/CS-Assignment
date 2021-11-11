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

double forDiffDir(double* X, double* Y, int num, double varx) {
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
	double u = (varx - *(X)) / h;
	double res = 0, temp, temp2;
	for (int i = 0; i < num - 1; i++) {
		temp = 0;

		for (int j = 0; j < i + 1; j++) {
			temp2 = 1;
			for (int k = 0; k < i + 1; k++) {
				if (k != j) {
					temp2 *= (u - k);
				}
			}
			temp += temp2;
		}
		res += temp * table[0][i + 2] / fact(i + 1);
	}
	return res / h;
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
	double result = forDiffDir(arrX, arrY, n, varX);
	printf("The value of function at x = %lf is %lf\n", varX, result);
	return 0;
}