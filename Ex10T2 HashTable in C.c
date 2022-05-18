#include <stdio.h>
#include <math.h>

#define m 7

#define OCC 0
#define EMP -1 
#define DEL -2 

struct HTElement {
	int value;
	int status; // 0: OCC ; -1: EMP; -2; DEL
};

void init(struct HTElement A[]) { 
	
	for (int i=0; i<=m; i++) {
		A[i].value = 0;
		A[i].status=-1;
	}
}

int hash(int k, int i) {
	
	int m1 = m -1;
	int h1 = (k % m) + 1;
	int h2 = m1 - (k % m1);
	return (int)(h1 + i*h2) % m;
}

void insert(struct HTElement A[], int key) {
	int counter = 0;
	int hkey;
	do{
		hkey = hash(key, counter);
	} while (A[hkey].status==OCC && counter++ < m);
	A[hkey].value = key;
	A[hkey].status = OCC;
}

int deleteN(struct HTElement A[], int key) {
	int counter = 0; 
	int hkey;
	do{
		hkey = hash(key, counter);
		if (A[hkey].value == key){
			A[hkey].status = DEL;
		//	printf("%d", A[hkey].status);
			return key;
		}
	}while (A[hkey].value != key && A[hkey].status ==OCC && counter++ < m);
	return -1;
}

int search(struct HTElement A[], int key) {
	int counter = 0;
	int hkey; 
	do{
		hkey = hash(key, counter);
	}while (A[hkey].value != key && A[hkey].status ==OCC && counter++ < m);
	if (A[hkey].value == key) {return hkey;
	}else {
		return -1;
	}	
}

void printHashTable(struct HTElement A[]) {
	int i;
	printf("Table size = %d \n", m);
	for (i = 0; i <m; i++) {
		if (A[i].status == OCC) {
			printf("i: %d   key: %d\n", i, A[i].value);
		}
	}
}


int main() {
	int A[] = {};
	init(A);
	insert(A, 5);
	insert(A, 33);
	insert(A, 55);
	insert(A, 56);
	insert(A, 98);
	printHashTable(A);
	deleteN(A, 98);	
}






