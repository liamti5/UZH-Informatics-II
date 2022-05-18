#include <stdio.h>
#include <stdlib.h>

int A[] = {4,5,3,2,7,9,8,1};
int B[] = {};

int n = sizeof(A)/sizeof(A[0]);

void printA(int A[], int l, int r) {

	printf("A[%d, %d]=[", l, r);
	for (int i=l;i<r; i++) {
		printf("%d,", A[i]);
	}
	printf("%d]\n", A[r]);

}

void Merge(int *A, int l, int r, int m) {

	for (int i = l; i <= m; i++) {
		B[i] = A[i];
	}
	for  (int i= m+1; i<=r;i ++) {
		B[r+m-i+1] = A[i];
	}
	int i =l; int j =r;
	for (int k=l; k<=r; k++) {
		if (B[i] < B[j]) {
			A[k] = B[i];
			i++;
		}
		else {
			A[k] = B[j];
			j--;
		}
	}
}

void MergeSort(int A[], int l, int r) {

	if (l<r) {
		int m = (l+r)/2;
		MergeSort(A,l,m);
		MergeSort(A,m+1,r);
		Merge(A,l,r,m);
		printA(A,l,r);
	}
//	printA(A,l,r);
}

int main() {
	printA(A,0,n-1);
	MergeSort(A,0,n-1);
}

