#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define m 365

struct Node {
  int data;
  struct Node *next;
};

struct Node *HT[m];

void displayList(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    if (current->next != NULL) {
      printf(" %d ->", current->data);
    } else {
      printf(" %d", current->data);
      printf("\n");
    }
    current = current->next;
  }
}

int calculateListLength(struct Node *head) {
  int length = 0;
  struct Node *current = head;
  while (current != NULL) {
    length++;
    current = current->next;
  }
  return length;
}

struct Node *insertList(struct Node *head, int data) {
  if (head == NULL) {
    head = malloc(sizeof(struct Node));
    head->data = data;
    head->next = NULL;
    return head;
  } else {
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *current = head;
    newNode->data = data;
    newNode->next = NULL;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
    return head;
  }
}

void printHashTable() {
  int i;
  printf("Table size: %d\n", m);
  for (i = 0; i < m; i++) {
    if (HT[i] != NULL) {
      printf("i: %d\t, length: %d\t", i, calculateListLength(HT[i]));
      displayList(HT[i]);
    }
  }
}

int hash(int key) { return key % m; }

void insertHT(int key, int value) {
  HT[hash(key)] = insertList(HT[hash(key)], value);
};

void clearHT() {
  int i;
  for (i = 0; i < m; i++) {
    HT[i] = NULL;
  }
}

int find_num_shared_birthday() {
  // returns the number of shared birthday
  int i = 0;
  int length;
  int num_shared_birthday = 0;
  for (i = 0; i < m; i++) {
    if (HT[i] != NULL) {
      length = calculateListLength(HT[i]);
      if (length > 1) {
        num_shared_birthday += 1;
      }
    }
  }
  return num_shared_birthday;
}

int find_num_people_with_shared_birthday() {
  // returns the number of people with shared birthday
  int i = 0;
  int length;
  int num_shared_birthday = 0;
  for (i = 0; i < m; i++) {
    if (HT[i] != NULL) {
      length = calculateListLength(HT[i]);
      if (length > 1) {
        num_shared_birthday += length;
      }
    }
  }
  return num_shared_birthday;
}

int main() {
  int i, j, k;
  int num_trials = 1000;
  int at_least_one_shared_birthday = 0;
  int sum_shared_birthday = 0;
  int num_people[] = {10, 20, 25, 50, 60};
  srand(time(NULL));

  for (k = 0; k < 5; k++) {
    for (j = 0; j < num_trials; j++) {
      int shared_birthday = 0;
      for (i = 0; i < num_people[k]; i++) {
        int r = rand();
        insertHT(r, i);
      }
      shared_birthday = find_num_shared_birthday();
      sum_shared_birthday += find_num_people_with_shared_birthday();
      if (shared_birthday > 0) {
        at_least_one_shared_birthday += 1;
      }
      clearHT();
    }
    printf(
        "With %d people, probability for at least one shared birthday: %f, "
        "total shared birthday: %f \n",
        num_people[k], 
        at_least_one_shared_birthday / (float)num_trials,
        sum_shared_birthday / (float)num_trials );
    at_least_one_shared_birthday = 0;
    sum_shared_birthday = 0;
  }
}