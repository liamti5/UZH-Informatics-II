#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next; //recursion!! Node = one circle
};

struct Node *insertListEnd(struct Node *head, int data1) {
    // what if list is empty? --> list is empty if head pointer == NULL
    if (head == NULL) {
        // dynamic memory allocation with malloc
        // specify how many bites we "need", and malloc reserves this and returns a pointer to it
        // after reserving memory, we know where to store the struct
        head = malloc(sizeof(struct Node));
        
        // head is a pointer, so we have to dereference it (follow the pointer) and then access the element
        head -> data = data1; // == (head*).data
        head -> next = NULL;
        return head; 
    }
    else {
        struct Node *newNode = malloc(sizeof(struct Node)); // we initiate a node called newNode with the size of Node
        newNode -> data = data1;
        // create temp pointer called "current" which we can move through the whole list
        struct Node *current = head; // no malloc because we don't need it after function finishes
        // since we insert newNode at the end, it must point to NULL
        newNode -> next = NULL;

        // loop through linked list untill we reach the end and insert element here
        while (current -> next != NULL) {
            current = current -> next;
        }
        // current reaches end, so we can insert the Node here
        current -> next = newNode;
        return head;
    }
}

void swap_nodes(struct Node *prev, struct Node *cur) {
  // before swap: prev->cur->ne->temp
  // after swap: prev->ne->cur->temp
  struct Node * ne = cur->next;
  struct Node * temp = ne->next;
  prev->next = ne;
  ne->next = cur;
  cur->next = temp;
  return;
}

struct Node *bubbleSort(struct Node *head) {
    if (head == NULL || head -> next == NULL) {
        return head; 
    }

    struct Node *dummy = malloc(sizeof(struct Node));
    dummy -> next = head; 
    struct Node *last = NULL;

    while (dummy -> next != last) {
        struct Node *prev = dummy;
        struct Node *cur = prev -> next;
        while (cur -> next != last) {
            if (cur -> data > cur -> next -> data) {
                swap_nodes(prev, cur);
            }
            else {
                cur = cur -> next;
            }
            prev = prev -> next;
        }
        last = cur;
    }
    head = dummy -> next;
    free(dummy);
    return head;
}

void displayList(struct Node *head) {
    // again create a temporary pointer
    struct Node *current = head;
    while (current != NULL) {
        if (current -> next != NULL) { // check if we are not at the last element
            printf(" %d ->", current -> data);
        }
        else {
            printf(" %d\n", current -> data); //otherwise print the last element without an arrow
        }
        current = current -> next;
    }
}

void isAnagram(struct Node *s1, struct Node *s2) {
    
}


int main() {
    char ch;
    struct Node *s1_head = NULL;
    struct Node *s2_head = NULL;

    printf("Enter the first string s1 \n");
    while ((ch = getchar()) != '\n') {
        s1_head = insertListEnd(s1_head, ch);
    }
    printf("Enter the second string s2 \n");
    while ((ch = getchar()) != '\n') {
        s2_head = insertListEnd(s2_head, ch);
    }
    s1_head = bubbleSort(s1_head);
    s2_head = bubbleSort(s2_head);
    // isAnagram(s1_head, s2_head);
    displayList(s1_head);
    displayList(s2_head);
        
    return 0;
}