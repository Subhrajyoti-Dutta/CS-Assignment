//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(int n, double mat[n][n + 1]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			printf("%lf ", mat[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int n = 3, i, j, k, l;
	double  temp;
	printf("Enter the number of the Variable/Equation: ");
	scanf("%d", &n);
	double mat[n][n + 1];
	printf("Enter the augmented matrix in space-separated manner\n");
	for (i = 0; i < n; i++) {
		printf("Eqn %d: ", i + 1);
		for (j = 0; j < n + 1; j++) {
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
			for (l = j; l < n + 1; l++) {
				temp = mat[k][l];
				mat[k][l] = mat[i][l];
				mat[i][l] = temp;
			}
			k++;
		}

		for (l = j + 1; l < n + 1; l++) {
			mat[i][l] /= mat[i][j];
		}
		mat[i][j] = 1;
		while (k < n) {
			l = j;
			temp = mat[k][l];
			while (l < n + 1) {
				mat[k][l] -= temp * mat[i][l];
				l++;
			}
			k++;
		}
		j++;
		i++;
	}
	int flag = 0, flag2;
	i = n - 1;
	while (i >= 0) {
		j = 0;
		flag2 = 0;
		while (j < n) {
			if (mat[i][j] != 0) {
				flag2 = 1;
				break;
			}
			j++;
		}
		if (flag2 == 1) {
			break;
		}
		else if (flag2 == 0 && mat[i][n] != 0) {
			flag = 1;
			break;
		}
		i--;
	}
	(flag) ? printf("The Linear Equations are not consistent\n") : printf("The Linear Equations are  consistent\n");
	return 0;
}