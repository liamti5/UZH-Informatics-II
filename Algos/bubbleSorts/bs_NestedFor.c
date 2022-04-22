#include <stdio.h>

//BubbleSort

void bubbleSort(int A[], int n) {
    for (int i = n; i > 1; i--) { 
        for (int j = 0; j < i; j++) { // as i gets smaller, all elements behind i are already sorted. So j only has to compare element smaller than i
            if (A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
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
    bubbleSort(A, n);
    printArray(A, n);
    return 0;
}