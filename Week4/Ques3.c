//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n, i, j;
	double lambda;
	printf("Order of Matrix: ");
	scanf("%d", &n);
	double arr[n][n];
	printf("Enter the matrix in space-separated manner:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%lf", &arr[i][j]);
		}
	}
	double vec[n];
	printf("Enter the initial eigen vector in space-separated manner\n");
	for (i = 0; i < n; i++) {
		scanf("%lf", &vec[i]);
	}

	int numOfIterations = 20;
	double tempVec[n];
	for (int iter = 0; iter < numOfIterations; iter++) {
		for (i = 0; i < n; i++) {
			tempVec[i] = 0;
			for (j = 0; j < n; j++) {
				tempVec[i] += arr[i][j] * vec[j];
			}
		}
		lambda = tempVec[0];
		for (i = 1; i < n; i++) {
			if (tempVec[i] > lambda) {
				lambda = tempVec[i];
			}
		}
		for (i = 0; i < n; i++) {
			vec[i] = tempVec[i] / lambda;
		}
	}
	printf("Value of largest lambda: %lf\n", lambda);
	printf("Corresponding eigen vector: [ ");
	for (i = 0; i < n; i++) {
		printf("%lf", vec[i]);
		if (i != n - 1) {
			printf(", ");
		}
	}
	printf(" ]\n");
	return 0;
}