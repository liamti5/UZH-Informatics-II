#include <stdio.h>
#define TRUE 1

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// int hoarePartition(int array[], int low, int high) {
//     int x = array[high]; 
//     int i = low - 1; 
//     int j = high + 1; 

//     while (TRUE) { 
//         while (array[j] > x) j--; 
//         while (array[i] < x) i++;
//         if (i < j) swap(&array[i], &array[j]);
//         else return i; 
//     }
// }

// find the partition position (lomuto partitioning)
int lomutoPartition(int array[], int low, int high) {

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        // int pi = lomutoPartition(array, low, high);
        int pi = lomutoPartition(array, low, high); 

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

// print array elements
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6};
  
    int n = sizeof(data) / sizeof(data[0]);
  
    printf("Unsorted Array\n");
    printArray(data, n);
  
    quickSort(data, 0, n - 1);
  
    printf("Sorted array in ascending order: \n");
    printArray(data, n);

    return 0;
}