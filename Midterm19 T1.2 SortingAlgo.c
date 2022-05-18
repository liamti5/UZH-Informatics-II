#include <stdio.h>

int B1(int A[], int n) {
	int index = n-1;
	while (index >=0) {
		if (index == n) {
			index = index -1;
		}
		if (A[index] >= A[index+1]) {
		index = index-1;
		}
		else {
			int tmp = A[index];
			A[index] = A[index+1];
			A[index+1] = tmp;
			index = index +1;
		}
	}return 0;
}

int main() {
	int A[] = {5, 4, 2, 6};
	printf(B1(A, 4));
	return 0;
}
