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
	int n, m, i, j, k, l;
	double  temp;
	printf("Enter the number of rows: ");
	scanf("%d", &n);
	printf("Enter the number of column: ");
	scanf("%d", &m);
	double mat[n][m];
	printf("Enter the matrix in space-separated manner\n");
	for (i = 0; i < n; i++) {
		printf("Row %d: ", i + 1);
		for (j = 0; j < m; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}
	// double mat[3][3 + 1] = { {1,1,2,3},{2,5,8,5},{4,4,8,13 - 1} };

	j = 0;
	i = 0;
	while (i < n) {
		k = i + 1;
		if (mat[i][j] == 0) {
			while (k < n) {
				if (mat[k][j] != 0) {
					break;
				}
				k++;
			}
			if (k == n) {
				j++;
				continue;
			}
			for (l = j; l < m; l++) {
				temp = mat[k][l];
				mat[k][l] = mat[i][l];
				mat[i][l] = temp;
			}
			k++;
		}

		for (l = j + 1; l < m; l++) {
			mat[i][l] /= mat[i][j];
		}
		mat[i][j] = 1;
		while (k < n) {
			l = j;
			temp = mat[k][l];
			while (l < m) {
				mat[k][l] -= temp * mat[i][l];
				l++;
			}
			k++;
		}
		j++;
		i++;
	}
	printf("Matrix after Gaussian Elimination:\n");
	print(n, m, mat);

	return 0;
}