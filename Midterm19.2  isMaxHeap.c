#include <stdio.h>
#include <limits.h>

void isMaxHeap(int A[], int i, int n) {
	int m = n/2;
	for (int j=i; j<m; j++) {
		//check left child
		if (A[j] < A[2*j +1]) {
			return 0;
	}
		//check right child
		if (2*j+2 < n && A[j] < A[2*j+2]){
			return 0;
		}
		return 1;
		}
	}


int main( ) {
	int a[] = {9,5,6,50,3,2,1};
	isMaxHeap(a, 0, 6);
	return 0;
}
