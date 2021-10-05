//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rounding(double x, int precision) {
	int res = x * pow(10, precision) + 0.5;
	return (double)res / pow(10, precision);
}

int main() {
	int n, a, pre;
	double mul;
	printf("Enter the order of the Matrix: ");
	scanf("%d", &n);
	printf("Enter the precision of the numbers: ");
	scanf("%d", &pre);
	if (n < 1) {
		return 1;
	}
	double mat[n][n];
	printf("Enter the matrix in space-separated manner\n");
	for (int i = 0; i < n; i++) {
		printf("Row %d: ", i + 1);
		for (int j = 0; j < n; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}

	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mul = 0;
			for (int k = 0; k < n; k++) {
				mul += mat[i][k] * mat[j][k];
			}
			mul = rounding(mul, pre - 1);
			if (((i != j) && (mul != 0)) || ((i == j) && (mul != 1.0))) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
	}
	(flag == 1) ? printf("It is not a orthogonal matrix\n") : printf("It is a orthogonal matrix\n");
	return 0;
}