//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(int n, int m, double mat[n][m]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%lf ", mat[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int n, i, j, k;
	double temp;
	printf("Enter the order of matrix: ");
	scanf("%d", &n);
	double A[n][n];
	double U[n][n];
	double L[n][n];

	printf("Enter the matrix in space-separated manner\n");
	for (i = 0; i < n; i++) {
		printf("Row %d: ", i + 1);
		for (j = 0; j < n; j++) {
			scanf("%lf", &A[i][j]);
		}
	}

	for (i = 0; i < n; i++) {
		L[i][i] = 1;
	}

	for (i = 0; i < n; i++) {
		U[0][i] = A[0][i];
	}

	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			temp = 0;
			for (k = 0; k < j; k++) {
				temp += L[i][k] * U[k][j];
			}
			L[i][j] = (A[i][j] - temp) / U[j][j];
		}
		for (j = i; j < n; j++) {
			temp = 0;
			for (k = 0; k < i; k++) {
				temp += L[i][k] * U[k][j];
			}

			U[i][j] = A[i][j] - temp;
		}
	}

	printf("\nOriginal Matrix:\n");
	print(n, n, A);
	printf("\nL Matrix:\n");
	print(n, n, L);
	printf("\nU Matrix:\n");
	print(n, n, U);

	return 0;
}