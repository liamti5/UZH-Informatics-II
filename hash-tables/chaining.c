#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

# define m 365


struct node {
    int data; 
    struct node *next;  
};
struct node *HT[m];

void displayList(struct node *head) {
    struct node *current = head; 
    while (current != NULL) {
        if (current -> next != NULL) {
            printf(" %d ->", current -> data);
        } else {
            printf(" %d\n", current -> data); 
        }
        current = current -> next; 
    }
}

struct node *insertList(struct node *head, int data) {
    if (head == NULL) {
        head = malloc(sizeof(struct node));
        head -> data = data; 
        head -> next = NULL; 
        return head;  
    }
    struct node *newNode = malloc(sizeof(struct node));
    newNode -> data = data; 
    newNode -> next = NULL; 
    struct node *current = head; 
    while (current -> next != NULL) current = current -> next; 
    current -> next = newNode; 
    return head; 
}

int hash(int key) {
    return key % 3; 
}

void insertHT(int key, int value) {
    int index = hash(key);
    HT[index] = insertList(HT[index], value);
}

void printHT() {
    int i; 
    while (i < m && HT[i] != NULL) {
        printf("%d (index of HT)\n", i);
        displayList(HT[i]); 
        i++; 
    }
}

int main() {
    insertHT(1, 1);
    insertHT(2, 2); 
    insertHT(3, 3); 
    insertHT(4, 4); 
    insertHT(5, 5); 
    insertHT(6, 6); 
    printHT();
}