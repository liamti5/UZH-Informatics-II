#include <stdio.h>


//InsertionSort

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int t = A[i];
        while (j >= 0 && t < A[j]) {
            A[j+1] = A[j];
            j = j-1;
        }
    A[j+1] = t; 
    }
}

void printArray(int input[], int size) {
	printf("[");
	for (int i = 0; i < size - 1; i++) {
		printf("%d, ", input[i]);
	}
	printf("%d]\n", input[size - 1]);
}

int main() {
    int A[] = {5, 2, 4, 7, 1, 3, 6};
    int n = 7;
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}