#include <stdio.h>

void algo1(int A[], int n, int k) {
	int sum = 0;
	for (int i=0; i<k; i++) {
		int maxi = i; 
		for (int j = i; j<n; j++){
			if (A[j]> A[maxi]) {
			maxi =j;
			}
		}
		sum = sum + A[maxi];
		int swp = A[i];
		A[i] = A[maxi];
		A[maxi] = swp;
		
	}
	printf("The sum is %d\n", sum);
	printf("The new list is %d", A);
}

int main() {
	int A[] = {1,2,3,4,5,6};
	algo1(A, 6, 1);
	
}
