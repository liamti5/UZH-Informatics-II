#include <stdio.h>


void swap(int *A, int *B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}
void BubbleSort(int A[], int n) {
	
	for (int i = n; i > 1; i--) {
		
		for (int j = 1; j < i; j++) {
			
			if (A[j] < A[j-1]) {
				swap(&A[j], &A[j-1]);
			}
		}
	}
}

void BubbleSort2(int A[], int n) {
	int i, j;
	for (i =1; i < n-1; i++) {
		
		for (j= n-1; j < i; i-- ){
			
			if (A[j] > A[j+1]) {
				swap(&A[j], &A[j+1]);
			}
		}
	}
}

void printArray(int A[], int n) {
	
	for (int i = 0; i < n ; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}


int main() {
	int A[] = {6, 5, 2, 7, 10, 11, 1};
	int n = sizeof(A) / sizeof(A[0]);
	BubbleSort(A, n);
	printArray(A, n);
	int A1[] = {6, 5, 2, 7, 10, 11, 1};
	int m = sizeof(A1) / sizeof(A1[0]);
	BubbleSort2(A1, m);
	printArray(A1, m);

	return 0;
}
