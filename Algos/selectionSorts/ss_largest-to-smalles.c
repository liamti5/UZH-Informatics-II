#include <stdio.h>

// selectionSort

void printArray(int input[], int size) {
	printf("[");
	for (int i = 0; i < size - 1; i++) {
		printf("%d, ", input[i]);
	}
	printf("%d]\n", input[size - 1]);
}

void selectionSort(int A[], int n) {
    for (int i = n-1; i > 1; i--) {
        int k = i; 
        for (int j = i-1; j >= 0; j--) {
            if (A[j] > A[k]) {
                k = j; 
            }
        }
        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}

int main() {
    int A[] = {5, 2, 4, 7, 1, 3, 6};
    int n = 7;
    selectionSort(A, n);
    printArray(A, n);
    return 0;
}