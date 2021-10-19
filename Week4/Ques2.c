//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n;
	printf("Number of Equations: ");
	scanf("%d", &n);
	double arr[n][n + 1];
	printf("Type the coefficients of augmented matrix in space-separated manner:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			scanf("%lf", &arr[i][j]);
		}
	}
	double X[n];							//initialised to zeros
	int numOfIterations = 20;
	for (int iter = 0; iter < numOfIterations; iter++) {
		for (int i = 0; i < n; i++) {
			X[i] = arr[i][n];
			for (int j = 0; j < n; j++) {
				if (j != i) {
					X[i] -= X[j] * arr[i][j];
				}
			}
			X[i] /= arr[i][i];
		}
	}

	for (int i = 0; i < n; i++) {
		printf("x%d = %lf\n", i, X[i]);
	}

	return 0;
}