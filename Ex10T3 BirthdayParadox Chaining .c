#inlcude <time.h
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define m 365 

srand(time(NULL));
int r = rand();

struct Node{
	int data;
	struct Node* next;
};

struct Node *HT[m];

void displayList(struct Node* head) {
	struct Node* current = head;
	while (current != NULL) {
		if (current-> next != NULL) {
			printf(" %d ->", current->data);
		}else {
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
