/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 6 - Task 2 (b): Sample Solution                                 *
 *                                                                          *
 * @date 2022-02-28                                                         *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

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

struct Node* insertList(struct Node *head, int data) {
  if (head == NULL) { // if the linked list head is empty
    head = malloc(sizeof(struct Node));
    head->data = data;
    head->next = NULL;
    return head;
  } else { 
    struct Node *newNode = malloc(sizeof(struct Node)); // create a new node to store the new value 
    struct Node *current = head; 
    newNode->data = data;
    newNode->next = NULL;
    while (current->next != NULL) { // go through the whole linked list untill we get to the end
      current = current->next;
    }
    current->next = newNode;
    return head;
  }
}

struct Node* deleteVal(struct Node* head, int val) {
  if (head == NULL) {    
    printf("linked list is empty ...\n");
  }
  struct Node* current = head; 
  if (current -> data == val) { //special case if val = root... Doesn't work yet
    head = current -> next; 
    displayList(head);
    free(current);
  } else {
    while (current -> next -> data != val && current -> next != NULL) {
      current = current -> next; 
    }
    struct Node* temp = current -> next; 
    displayList(temp);
    current -> next = temp -> next; 
    displayList(current);
    free(temp); 
  }
}

struct Node* groupingLinkedList(struct Node *head) {
  struct Node *odd = NULL;
  struct Node *even = NULL;
  struct Node *groupedList = NULL;
  struct Node *current = head;

  while (current != NULL) {
    if (current->data % 2 == 0) {
      even = insertList(even, current->data);
    } else {
      odd = insertList(odd, current->data);
    }
    current = current->next;
  }
  groupedList = odd;
  current = groupedList;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = even;
  return groupedList;
}

// rearranges elements so that elements smaller than head are to the left of it and the rest to the right. 
struct Node* rearrange(struct Node* h) {
  struct Node* before = NULL;
  struct Node* after = NULL;
  struct Node* rearranged = NULL;
  struct Node *current = h;
  while (current != NULL) {
    if (current -> data < h -> data) {
      before = insertList(before, current -> data);
    }
    else {
      after = insertList(after, current -> data);
    }
    current = current -> next;
  }
  rearranged = before; 
  current = rearranged;
  while (current -> next != NULL) {
    current = current -> next; 
  }
  current -> next = after; 
  return rearranged; 
}

void swap_nodes(struct Node *prev, struct Node *cur) {
  struct Node *ne = cur-> next;
  struct Node *temp = ne -> next;
  prev -> next = ne; 
  ne -> next = cur; 
  cur -> next = temp;
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
      } else {
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

int main() {
  int n, x, i;
  struct node *l;
  struct Node *head = NULL;
  n = 5; 
  head = insertList(head, 6);
  head = insertList(head, 3);
  head = insertList(head, 4);
  head = insertList(head, 12);
  head = insertList(head, 8);

  
  displayList(head);
  // printf("Before Grouping:");
  // displayList(head);
  // struct Node *gList = groupingLinkedList(head);
  // printf("After Grouping:");
  // displayList(gList);

  // struct Node* aList = rearrange(head);
  // displayList(aList);
  // displayList(head);
  head = bubbleSort(head);

  // deleteVal(head, 12);
  displayList(head);
  return 0;
}
