# include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int A[], int i, int s) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
 
  if (left < s && A[left] > A[largest])
    largest = left;
 
  if (right < s && A[right] > A[largest])
    largest = right;
 
  if (largest != i) {
    swap(&A[i], &A[largest]);
    heapify(A, largest, s);
  }

}

void printArray(int A[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void buildheap(int A[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--){
    heapify(A, i, n);
    // printArray(A, n);
  }

}


void heapSort(int A[], int n) {
  buildheap(A, n);
  printArray(A, n); 
  for (int i = n - 1; i >= 0; i--) {
    swap(&A[0], &A[i]);
    heapify(A, 0, i);
    // printArray(A, n);
  }
}  

int isMaxHeap(int a[], int i,  int n) {
  if (i > (n-2)/2) {
    return 1; 
  } 
  // int largest = i;
  // int left = 2 * i + 1;
  // int right = 2 * i + 2;
  int left_check = 0;
  int right_check = 0;

  if (a[i] >= a[2*i+1]) {
    left_check = isMaxHeap(a, 2*i+1, n);
  }

  if (2*i + 2 < n) {
    if (a[i] >= a[2*i+2]) {
      right_check = isMaxHeap(a, 2*i+2, n); 
    }
  }
  return left_check, right_check;

}

int main() {
  int A[] = {11, 0, 9, 19, 8, 1, 5, 13, 18, 7}; 
  // int A[] = {19, 18, 9, 13, 8, 1, 5, 11, 0, 7};
  int n = sizeof(A) / sizeof(A[0]);
  int i = 0;
  printArray(A, n);
  heapSort(A, n);
  printf("State of A after heapSort: \n");
  printArray(A, n);
  // printf("%d", isMaxHeap(A, i, n));

}
