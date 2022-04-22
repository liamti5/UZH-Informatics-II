#include <stdio.h>
#include <math.h>

// ex1

int sum(int a[], int b[], int n) {
    int y;

    for (int i = n-1; i >= n; --i) {
        int z = (int)pow(10 , n -i-1);
        y = y + (a[i] + b[i])*z;         
    }
    return y;
}


int main () {
    int a[] = {1, 0, 0};
    int b[] = {1, 0, 0};
    int n = 3;
    int result = sum(a, b, n);
    printf("%d", result);



    return 0;
}