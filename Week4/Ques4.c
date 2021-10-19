//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void matMul(int Ar, int Ac, int Bc, double A[Ar][Ac], double B[Ac][Bc], double res[Ar][Bc]) {
	double temp[Ar][Bc];

	for (int i = 0; i < Ar; i++) {
		for (int j = 0; j < Bc; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < Ac; k++) {
				temp[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	for (int i = 0; i < Ar; i++) {
		for (int j = 0; j < Bc; j++) {
			res[i][j] = temp[i][j];
		}
	}
}

void eye(int n, double Arr[n][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Arr[i][j] = (i == j) ? 1 : 0;
		}
	}
}

int main() {
	int n, i, j, maxCorrX, maxCorrY;
	double lambda, maxm, tanTwoTheta, theta;
	printf("Order of Matrix: ");
	scanf("%d", &n);
	double arr[n][n];
	printf("Enter the matrix in space-separated manner:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%lf", &arr[i][j]);
		}
	}

	double B[n][n];
	eye(n, B);       // transforms B into a identity matrix

	for (int iter = 0; iter < 20; iter++) {
		maxm = arr[0][1];
		maxCorrX = 0, maxCorrY = 1;
		for (i = 0; i < n - 1; i++) {
			for (j = i + 1; j < n; j++) {
				if (maxm < arr[i][j]) {
					maxCorrX = i;
					maxCorrY = j;
					maxm = arr[i][j];
				}
			}
		}

		if (arr[maxCorrX][maxCorrX] - arr[maxCorrY][maxCorrY] != 0) {
			tanTwoTheta = 2 * arr[maxCorrX][maxCorrY] / (arr[maxCorrX][maxCorrX] - arr[maxCorrY][maxCorrY]);
			theta = atan(tanTwoTheta) / 2;
		}
		else {
			theta = M_PI_4;
		}

		double B0[n][n];
		double B0inv[n][n];
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				B0[i][j] = 0;
				B0inv[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			B0[i][i] = (i == maxCorrX || i == maxCorrY) ? (cos(theta)) : (1);
			B0inv[i][i] = (i == maxCorrX || i == maxCorrY) ? (cos(theta)) : (1);
		}
		B0[maxCorrX][maxCorrY] = sin(theta);
		B0[maxCorrY][maxCorrX] = -sin(theta);
		B0inv[maxCorrX][maxCorrY] = -sin(theta);
		B0inv[maxCorrY][maxCorrX] = sin(theta);
		matMul(n, n, n, B, B0, B);						//B = B X B0
		matMul(n, n, n, B0, arr, arr);					//arr = B0 X arr
		matMul(n, n, n, arr, B0inv, arr);				//arr = arr X B0inv
	}

	for (int i = 0; i < n; i++) {
		printf("Eigen val: %lf\n", arr[i][i]);
		printf("[ ");
		for (int j = 0; j < n; j++) {
			printf("%lf", B[j][i]);
			if (j != n - 1) {
				printf(", ");
			}
		}
		printf(" ]\n");

	}


	return 0;
}