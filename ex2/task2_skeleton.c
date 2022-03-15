/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 2 - Task 2                                                      *
 *                                                                          *
 * @author <your name>                                                      *
 ****************************************************************************/

#include <stdio.h>

// hard-coded maximum length for input strings
const int MAX_LENGTH = 1000;

// TODO: your implementation
int rec_function(int arr[], int upper_limit, int smallest, int second_smallest){
	// base cases:
	if (upper_limit == 0) {
		if (arr[0] < smallest) {
			return smallest;
		}
		else if (arr[0] < second_smallest && arr[0] != smallest) {
			return arr[0];
		}
		else {
			return second_smallest;
		}
	}

	// recursive case:
	if (arr[upper_limit] < smallest) {
		second_smallest = smallest;
		smallest = arr[upper_limit];
	}
	else if (arr[upper_limit] < second_smallest && arr[upper_limit] != smallest) {
		second_smallest = arr[upper_limit];
	}
	printf("rec_function(arr, %d, %d, %d)\n", upper_limit, smallest, second_smallest);
	return rec_function(arr, upper_limit - 1, smallest, second_smallest);	
}

int main() {
	printf("Values of array separated by spaces (non-number to stop): ");
	int arr[MAX_LENGTH];
	int pos = 0;
	while (scanf("%d", &arr[pos]) == 1) {
		pos++;
	}
	// variable pos will contain number of integers read in from user

	// TODO: your implementation - largest number possible: 9999 - 1
	int result = rec_function(arr, pos -1, 9999, 9999);
	printf("%d\n", result);


	return 0;
}
