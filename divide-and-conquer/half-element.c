#include <stdio.h>

// ARRAY IS SORTED IN ASCENDING AND THEN DESCENDING SO ONLY WORKS FOR THESE KINDA ARRAYS
int countElem(int A[], int num, int l, int r) {
	int count = 0; 
    for (int i = l; i <= r; i++) {
        if (A[i] == num) count++; 
    }
    return count;     
} 

int halfElement(int A[], int l, int r) {
    if (l == r) return A[l]; 
    int mid = (l+r)/2; 
    int left = halfElement(A, l, mid); 
    int right = halfElement(A, mid + 1, r); 
    if (left == right) return left; 
    int leftCount = countElem(A, left, l, r); 
    int rightCount = countElem(A, right, l, r); 
    if (leftCount >= rightCount) return left; 
    return right; 
}

int main() {
	int A[] = {4, 4, 5, 6, 4, 5, 3, 5, 5};
	printf("%d\n", halfElement(A, 0, 8)); 
}