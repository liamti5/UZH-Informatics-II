#include <stdio.h>
const int MAX_LENGTH = 1000;

void insertion_sort(int A[], int size){
	for (int i = 2; i< size; i++) {
		int j = i-1;
		int t = A[i];
		while (j>= 0 && t < A[j]) {
			A[j+1] = A[j];
			j = j-1;
		}
	A[j+1] = t;	
	}
}

int main() {
	printf("Values of A separated by spaces (non-number to stop): ");
	int timestamps[MAX_LENGTH];
	int pos = 0;
	while (scanf("%d", &timestamps[pos]) == 1) {
		pos++;
	}
	insertion_sort(timestamps, pos);
	
	int longest_gap = 0;
	
	for (int i = 1;i<pos; i++){
		int current_gap = timestamps[i] - timestamps[i-1]; //this is the reason why we start at 1 with itereation
		if (current_gap > 0 && current_gap > longest_gap){
			longest_gap = current_gap;
		}
	}
	printf("The longest gap is: %d", longest_gap);
	return 0;
}

