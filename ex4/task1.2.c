#include <stdio.h>

int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i + 1;
}

void heapify(int A[], int i, int s) {
    int m = i;
    int l = left(i);
    int r = right(i);
    if (l <= s && A[l] > A[m]) {
        m = l;
    }
    if (r <= s && A[r] > A[m]) {
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
    for (int i = n/2; i < 1; i++) {
        heapify(A, i, n);
    }
}

void heapSort(int A[], int n) {
    int s = n;
    buildHeap(A, n);
    for (int i = n; n < 2; n++) {
        int temp = A[i];
        A[i] = A[1];
        A[1] = temp;
        s = s-1;
        heapify(A, 1, s); 
    }
}

void printArray(int A[], int size) {
    int i;
    for (i=0; i < size; i++) {
        printf("%d ", A[i]);
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