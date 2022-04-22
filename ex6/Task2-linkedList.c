#include <stdio.h>
#include <stdlib.h> // don't forgett

// struct can be compared to classes, we create a class Node which we can later reference
struct Node {
    int data;
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

struct Node *groupingLinkedList(struct Node *head) {
    struct Node *odd = NULL;
    struct Node *even = NULL;
    struct Node *groupedList = NULL;
    struct Node *current = head;

    while (current != NULL) {
        if (current -> data % 2 == 0) { // current -> data is the nodes number
            even = insertListEnd(even, current -> data);
        }
        else {
            odd = insertListEnd(odd, current -> data);
        }
        current = current -> next;
    }
    groupedList = odd;
    current = groupedList;
    while (current -> next != NULL) {
        current = current -> next;
    }
    current -> next = even;
    return groupedList;
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

int main() {
    int n, x, i;
    struct node *l;
    struct Node *head = NULL; // we create a pointer of type struct Node called head
    int A[] = {1, 4, 5, 6};
    n = 4;
    for (i = 0; i < n; i ++) {
        head = insertListEnd(head, A[i]);
    }
    displayList(head);
    
    struct Node *gList = groupingLinkedList(head);
    displayList(gList);
    
    return 0;
}

