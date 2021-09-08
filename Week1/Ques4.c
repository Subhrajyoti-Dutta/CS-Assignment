#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fact(n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {

}