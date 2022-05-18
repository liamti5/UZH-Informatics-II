#include <stdio.h>

void swap(int *A, int *B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}
void InsertionSort(int A[], int n) {
    int i, j, t;
    for (i = 1; i < n; i++) {
    	j = i-1;
    	t = A[i];
    	while ( j>= 0 &&t < A[j]) {
    		A[j+1] = A[j];
    		j = j-1;
		}
	}A[j+1] = t;
    
}
void printArray(int A[], int n) {
	
	for (int i = 0; i < n ; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}


int main() {
	int A[] = {6, 4, 2, 5};
	int n = sizeof(A) / sizeof(A[0]);
	InsertionSort(A, n);
	printArray(A, n);
	


	return 0;
}


