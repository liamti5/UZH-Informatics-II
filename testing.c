#include <stdio.h>

void whatDoesItDo(int A[], int n, int k) {
	int result = -1000;
	int i;
	int j; 
	for (i = 0; i < n; i++){
		int current = 0;
		for (j = i; j < n; j += k) {
			current = current + A[j];
		}
		if (current > result) {
			result = current;
		}
	}
    printf("%d\n", result); 
}

int main() {
	int A[] = {3, 4, 6, 1, 10, 8};
    whatDoesItDo(A, 6, 2);
    return 0;
}