#include <stdio.h>

void swap(int *A, int *B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}
void SelectionSort(int A[], int n) {
    int i, j, k;
    for (i = 0; i<= n-1; i++){
        k = i;
        for (j = i+1; j<= n-1; j++) {
            if (A[j] < A[k]) {
                k = j;
            }
        }swap(&A[i], &A[k]);
    }
}

void SelectionSort2(int A[], int n) {
    int i,j,k;
    for (i = n-1; i > 1; i--) {
        k =i; 
        for (j = i-1; j>=0; j--) {
            if (A[j] > A[k]) {
                k = j;
            }
        }swap(&A[i], &A[k]);
    }
}
void SelectionSortReverse(int A[], int n) {
    int i, j, k;
    for (i = 0; i<= n-1; i++){
        k = i;
        for (j = i+1; j<= n-1; j++) {
            if (A[j] > A[k]) { //only this unequal sign has to be changed to make it reverse
                k = j;
            }
        }swap(&A[i], &A[k]);
    }
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
	SelectionSort(A, n);
	printArray(A, n);
	
	int A1[] = {6, 4, 2, 5};
	int m = sizeof(A1) / sizeof(A1[0]);
	SelectionSort2(A1, m);
	printArray(A1, m);
	
	int A2[] = {6, 4, 2, 5};
	int x = sizeof(A2) / sizeof(A2[0]);
	SelectionSortReverse(A2, x);
	printArray(A2, x);

	return 0;
}


