#include <stdio.h>


void swap(int *A, int *B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}

void printArray(int A[], int n) {
	for (int i = 0; i <n ; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void heapify(int A[], int i, int s) {
	int m = i;
	int l = 2*i;
	int r = 2* i + 1;
	//important; not as in pseudocode! s = size of array
	if (l < s && A[l]>A[m]) {
		m = l;
	}
	if (r < s && A[r]>A[m]) {
		m = r;	
	}
	//& = ampersand
	if (i != m) {
		swap(&A[i], &A[m]);
		heapify(A, m, s);
	} 
}

void buildheap(int A[], int n){
	for (int i = (n/2)-1; i >= 0; --i) {
		heapify(A, i, n);
		printArray(A,n);
	}
}

void heapsort(int A[], int n) {
	//int s = n;
	buildheap(A, n);
	
	for (int i = n -1; i >= 0; --i) {
		swap(&A[i], &A[0]);
	//	s = s-1;
		heapify(A, 0, i);
		printArray(A, n);
	}
}

int main() {
	int A[] = {11, 0, 9, 19, 8, 1, 5, 13, 18, 7};
	heapsort(A, 10);
	printf("State of A after heapsort:\n");
	printArray(A, 10);
	return 0;
}
