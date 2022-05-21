#include <stdio.h>

struct node {
	int val;
	struct node *next; 
};

struct node *rearrange (struct node *h) {
	struct node *d1 = malloc(sizeof(struct node));
	struct node *d2 = malloc(sizeof(struct node));
	struct node *smaller = d1;
	struct node *larger = d2; 
	struct node *current = h; 
	while (current != NULL) {
		if (current  > h -> val) {
			smaller -> next = current -> val; 
			smaller = smaller -> next;
		} else {
			larger -> next = current -> val; 
			larger = larger -> next; 
		}		
		current -> next = current -> val; 
	}
	
	while (smaller != 0) {
		smaller = smaller -> next; 
	}
	smaller -> next = larger; 
	return smaller; 
}

int main() {
	struct node *head; 
}
