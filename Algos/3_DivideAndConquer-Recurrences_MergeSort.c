#include <stdio.h>

void Merge(int A[], int l, int r, int m) {
    int B[r];
    for (int i = l; i < m; i++) {
        B[i] = A[i];
    }
    for (int i = m+1; i < r; i++) {
        B[r+m-i+1] = A[i];
    }
    int i = l;
    int j = r;
    for (int k = l; k < r; k++) {
        if (B[i] < B[j]) {
            A[k] = B[i];
            i++;
        } 
        else {
            A[k] = B[j];
            j = j-1;
        }
    }
}

void MergeSort(int A[], int l, int r) {
    if (l + 1 < r) {
        int m = (l + r) / 2;
        MergeSort(A, l, m);
        MergeSort(A, m+1, r);
        Merge(A, l, r, m);
    }
}

void printArray(int A[], int size) {
    int i;
    for (i=0; i < size; i++) {
        printf("%d ", A[i]);
    }
}

int main() {
    int A[] = {5, 2, 4, 7, 1, 3, 6, 2};
    int l = 0;
    int r = 7;
    printArray(A, r);
    printf("\n");
    MergeSort(A, l, r);
    printArray(A, r);
    return 0;
}