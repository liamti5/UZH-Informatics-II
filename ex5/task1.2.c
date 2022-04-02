#include <stdio.h>

void printArray(int A[], int size) {
    int i;
    for (i=0; i < size; i++) {
        printf("%d ", A[i]);
    }
}

int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}

void heapify(int A[], int i, int s) {
    int m = i;
    int l = left(i);
    int r = right(i);
    
    // diff from pseudocode, s = size of array
    if (l < s && A[l] > A[m]) {
        m = l;
    }
    if (r < s && A[r] > A[m]) {
        m = r;
    }
    if (i != m) {
        int temp = A[i];
        A[i] = A[m];
        A[m] = temp;
        heapify(A, m, s);
    }
}

void buildHeap(int A[], int n) {
    // different from pseudocode due to start of indexing at 0
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(A, i, n);
    }
}

void heapSort(int A[], int n) {
    int s = n;
    buildHeap(A, n);

    for (int i = n-1; i >= 0; i--) {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        s = s-1;
        heapify(A, 0, i); 
    }
}

int main() {
    int A[] = {11, 0, 9, 19, 8, 1, 5, 13, 18, 7};
    int n = 10;
    printArray(A, n);
    printf("\n");
    heapSort(A, n);
    printArray(A, n);
    return 0;
}