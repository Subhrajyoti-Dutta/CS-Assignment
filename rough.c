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

int main() {
	printf("%d", fact(6));
}