/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 3                                    *
 *                                                                          *
 * @date 2022-02-10                                                         *
 ****************************************************************************/

#include <stdio.h>

void selectionSort(int A[], int n) {
	for (int i = 0; i < n; i ++){
		int k = i;
		for (int j = i + 1; j < n; j ++){
			if (A[j] < A[k]){
				k = j;
			}
		}
		int temp = A[i];
		A[i] = A[k];
		A[k] = temp; 
	}
	// for (int i = 0; i < n; i ++){
	// 	printf("%d ", A[i]);
	// }

	return;
}


void evenOddSelectionSort(int A[], int n){
	int even[n];
	int odd[n];
	int e = 0;
	int o = 0;
	selectionSort(A, n);

	for (int i = 0; i < n; i++){
		
		if (A[i] % 2 == 0){
			even[e] = A[i];
			e++;
		}
		else{
			odd[o] = A[i];
			o++;
		}
	}



	for (int i = 0; i < e; i ++){
		printf("%d ", even[i]);
	}

	printf("\n");

	for (int i = 0; i < o; i ++){
		printf("%d ", odd[i]);
	}

	return;
}



int main(int argc, const char * argv[]) {
	int A[100];
	int n = 0;

	printf("Values of A separated by spaces (non-number to stop):");
	
	while (scanf("%d", &A[n]) == 1) {
		n++;
	}

	scanf("%*s");
	
	printf("Result: ");
	//selectionSort(A, n);
	evenOddSelectionSort(A, n);
}

// Linux, Mac: gcc task4.c -o task4; ./task4
