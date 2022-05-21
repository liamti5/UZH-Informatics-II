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

int LomutoPartition(int A[], int l, int r) {
	int x = A[r];
	int i = l-1;
	for (int j = l; j <= r-1; j++) {
		if (A[j] <= x) {
			i++;
			swap(&A[i], &A[j]);
			printArray(A, 10);
		}
	}
	swap(&A[i+1], &A[r]);
	printArray(A, 10);
	return i + 1; 
 }
 
void QuickSort1(int A[], int l, int r) {
	if (l < r) {
		int mi  = LomutoPartition(A, l, r);
		QuickSort1(A, l, mi - 1);
		QuickSort1(A, mi + 1, r);
	}
} 

int HoarePartition(int A[], int l, int r) {
	int x = A[r];
	int i = l-1;
	int j = r + 1;
//	while (A[j] <= x && A[i] >= x) {   //how to do the two conditions separately
	//	j = j-1;
	//	i = i+1;
	while (1) {
		do{
			j--;
		} while (A[j] < x);
		do {
			i++;
		} while (A[i] > x);
	}
		if (i >= j) {
			return i;
		swap(&A[i], &A[j]);
		printArray(A,10);
		
		}
	}
	
void QuickSort2(int A[], int l, int r) {
	if (l < r ) {
		int mi  = HoarePartition(A, l, r);
		QuickSort2(A, l, mi -1 );
		QuickSort2(A, mi + 1, r);
	}
} 

int main() {
	int A[] = {11, 0, 9, 19, 8, 1, 5, 13, 18, 7};
	int n = sizeof(A)/sizeof(A[0]);
	printf("Lomuto: \n");
	printArray(A, n);
	QuickSort1(A, 0, n-1);
	printArray(A, n);
	printf("\n");
	
	printf("\nHoare: \n");
	printArray(A, n); 
	QuickSort2(A, 0, n-1);
	printArray(A, n);
	
	return 0;
}
