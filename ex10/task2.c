#include <math.h>
#include <stdio.h>

#define m 7
#define OCC 0
#define EMP -1
#define DEL -2

struct HTElement {
  int value;
  int status; // 0: occupied, -1: empty, -2: deleted
};

void init(struct HTElement A[]) {
  int i;
  for (i = 0; i < m; i++) { 
    A[i].value = 0;
    A[i].status = -1; 
  }
}

int hash(int k, int i) {
  int h1 = (k % m) + 1;
  int h2 = (m-1)-(k % (m-1));
  return (int)(h1 + i * h2) % m;
}

void insert(struct HTElement A[], int key) {
  int counter = 0;
  int hkey;
  do {
    hkey = hash(key, counter);
  } while(A[hkey].status == OCC && counter++ < m);
  A[hkey].value = key;
  A[hkey].status = OCC;
}

int delete(struct HTElement A[], int key) {
  int counter = 0;
  int hkey;
  do {
    hkey = hash(key, counter);
    if (A[hkey].value == key) {
      A[hkey].status = DEL;
      return key;
    }
  } while ( (A[hkey].value != key || A[hkey].status!=OCC) && A[hkey].status != EMP && counter++ < m);
  return -1;
}

int search(struct HTElement A[], int key) {
  int counter = 0;
  int hkey;
  do {
    hkey = hash(key, counter);
  } while( (A[hkey].value != key || A[hkey].status!=OCC) && A[hkey].status != EMP && counter++ < m);
  if (A[hkey].value == key) { return hkey; }
	else { return -1; }
}

void printHashTable(struct HTElement A[]) {
  int i;
  printf("Table size: %d\n", m);
  for (i = 0; i < m; i++) {
    if (A[i].status == OCC) {
      printf("i: %d\tkey: %d\n", i, A[i].value);
    }
  }
}

int main() {
  struct HTElement A[m];
  init(A);

  insert(A, 1313);
  insert(A, 1314);
  insert(A, 1315);

  insert(A, 2000);
  insert(A, 2001);
  insert(A, 2002);

  printHashTable(A);

  int searchValues[] = {2000, 10, 1314, 1313, 337};
  int i;
  for (i = 0; i < 5; i++) {
    if (search(A, searchValues[i]) == -1) {
      printf("Searching for %d, not found\n", searchValues[i]);
    }
    else {
      printf("Searching for %d, found %d\n", searchValues[i], search(A, searchValues[i]));
    }
  }
  printf("deleting 1313\n");
  delete(A, 1313);
  printHashTable(A);

  printf("re-inserting 1313\n");
  insert(A, 1313);
  printHashTable(A);
  
  printf("deleting 1313 again\n");
  delete(A, 1313);
  printHashTable(A);

  for (i = 0; i < 5; i++) {
    if (search(A, searchValues[i]) == -1) {
      printf("Searching for %d, not found\n", searchValues[i]);
    }
    else {
      printf("Searching for %d, found %d\n", searchValues[i], search(A, searchValues[i]));
    }
  }
}

