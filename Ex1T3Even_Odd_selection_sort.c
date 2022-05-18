#include <stdio.h>

void selection_sort(int A[], int n){
	for (int i = 0; i<n-1; i++){
		k=i;
		for (int j=i+1; j<n; i++){
			if (A[j]<A[k]) k=j;
		}
		//exchange A[i] with A[k]
		int temp = A[i];
		A[i] = A[k];
		A[k] = temp;
		
	}return;
}


void even_odd_selection_sort(int A[], int n){
	int even_array[], odd_array[];
	int count_even = 0, count_odd = 0;
	selection_sort(A , n);
	for (int i = 0; i < n; i++){
		if (A[i]%2 == 0){
			even_array[count_even] = A[i];
			count_even ++;
		}
		else{
			odd_array[count_odd] = A[i];
			count_odd ++;
		}
	}
	printf("Sorted even numbers: ");
	for (int i = 0; i < count_even; i++){
		printf("%d", even_array[i]);
	}
	printf("Sorted odd numbers: ");
	for (int i = 0; i < count_odd; i++){
		printf("%d", odd_array[i]);
	}
	return;	
}

int main(int argc, const char * argv[]) {
	int A[100];
	int n = 0;
	
	printf("Values of A separated by spaces (non-number to stop)");
	
	while(scanf("%d", &A[n])== 1) {
		n++;
	}
	scanf("%*s"); //%s means we are reading a string value, as soon as we do not get a number anymore we break
	
	print()
}






