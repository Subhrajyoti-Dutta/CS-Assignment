//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void forDiffTable(double* X, double* Y, int num) {
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
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%lf ", table[i][j]);
		}
		for (int j = 2; j < num + 1 - i; j++) {
			printf("Δ%dy%d = %lf ", j - 1, i, table[i][j]);
		}

		printf("\n");
	}
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
	forDiffTable(arrX, arrY, n);
}