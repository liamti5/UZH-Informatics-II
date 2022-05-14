#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OCC 0
#define EMP -1
#define DEL -2
#define m 11

struct HTElement{
 int val; 
 // int key; here, val is the key
 int status; // 0: occupied,–1: empty,–2: deleted
};


void init(struct HTElement A[]){
  for (int i = 0; i < m; i++){
    A[i].val = 0;
    A[i].status = EMP;
  }
}

int hash(int k, int i){
  int h1 = (k % m) +1;
  int h2= m - 1 - (k % (m-1));
  return (h1 + i*h2) % m;
}

void insert(struct HTElement A[], int key){
  int counter = 0;
  int hkey;
  do{
    hkey = hash(key, counter);
  } while(A[hkey].status == OCC && counter++ < m); // do-while loop
  
  A[hkey].val = key;
  A[hkey].status = OCC; 
}

int search(struct HTElement A[], int key){
  int counter = 0;
  int hkey;
  do {
    hkey=hash(key, counter);
  } while(A[hkey].val != key && A[hkey].status == OCC && counter++ < m);

  if (A[hkey].val == key) { 
    return hkey;
  } else {
    return -1;
  }
}

int delete(struct HTElement A[], int key){
  int counter = 0; 
  int hkey;
  do {
    hkey = hash(key, counter);
    if (A[hkey].val == key) {
      A[hkey].status = DEL;
      return key;
    }
  } while (A[hkey].val != key && A[hkey].status == OCC && counter++ < m);  
  return -1;
}

 void delete2(struct HTElement A[], int key) {
   int index = search(A, key);

   if (index == -1) {
     printf("element not in HT\n");
   }

   A[index].val = 0;
   A[index].status = DEL;
 }

void printHashTable(struct HTElement A[]) {
  int i;
  printf("Table size:-%d\n", m);
  for (i = 0; i < m; i++) {
    if (A[i].status == OCC) {
      printf("i: %d\tkey: %d\n", i, A[i].val);
    }
  }
}

