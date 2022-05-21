#include <stdio.h>
#include <stdlib.h>

struct Node { //WHY IS THIS NOW NECESSARY BUT IN TASK 2 IT WASN'T???!!! WHAT DOES IT?
  char data;
  struct Node *next;
};

void displayList(struct Node *head) {
	struct Node *current = head;
	while (current != NULL){
		if (current->next != NULL){
			printf("%c -> ", current->data);
			current = current->next;
		} else {
			printf("%c", current ->data);
			printf("\n");
		}
		current = current -> next;
	}

}

struct Node* insertList(struct Node *head, int data) {
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

void swapNode(struct Node* prev, struct Node* cur) {
	struct Node* ne = cur -> next;
	struct Node* temp = ne -> next;
	prev -> next = ne;
	ne -> next = cur;
	cur -> next = temp;
	return;
}

struct Node* BubbleSort(struct Node *head) {
	if (head == NULL || head-> next == NULL) return head;
	struct Node *dummy = malloc(sizeof(struct Node));
	dummy -> next = head;
	struct Node *last = NULL;
	
	while(dummy -> next != last){
		struct Node *prev = dummy;
		struct Node *cur = prev -> next;
		while (cur -> next != last ) { 
		if (cur -> data > cur->next->data) {
			swapNode(prev, cur);
		}
		else {
			cur = cur -> next;
		}
		prev = prev ->next;
		}
		last = cur;
	}
	head = dummy -> next;
	free(dummy);
	return head;
}

void isAnagram(struct Node *h1, struct Node *h2) {
	struct Node *h1_cur = h1;
	struct Node *h2_cur = h2;
	while (h1_cur != NULL) {
		if (h1_cur -> data != h2_cur -> data) {
			printf("letter in h1 '%c' is not the same as in h2 '%c'.\n", h1_cur->data,
				h2_cur -> data);
			printf("Not Anagram!\n");
			return;
		}
		h2_cur = h2_cur -> next;
		h1_cur = h1_cur -> next;
	}
	printf("Anagram!\n");
}

int main() {
	char ch; 
	struct Node *h1_head = NULL;
	struct Node *h2_head = NULL;
	
	printf("Enter the first string s1 \n");
	while ((ch= getchar()) != '\n') {
		h1_head = insertList(h1_head, ch);
		
	}
	printf("Enter the second string s2 \n");
	while ((ch= getchar()) != '\n') {
		h2_head = insertList(h2_head, ch);
	}
	h1_head = BubbleSort(h1_head);
	h2_head = BubbleSort(h2_head);
	isAnagram(h1_head, h2_head);
	displayList(h1_head);
	displayList(h2_head);
}

