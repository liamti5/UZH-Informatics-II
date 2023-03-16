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

// groupes the vals of a linked list into odd and even nbrs
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

struct Node *rearrange2 (struct Node *h) {
	struct Node *d1 = malloc(sizeof(struct Node)); //initialize pointer d1 that points to a space strucuture node 
	struct Node *d2 = malloc(sizeof(struct Node));
	struct Node *smaller = d1; // pointer to a pointer
	struct Node *larger = d2; 
	struct Node *current = h; 
	while (current != NULL) {
		if (current -> data < h -> data) {
			smaller -> next = current; 
			smaller = smaller -> next;
		} else {
			larger -> next = current; 
			larger = larger -> next; 
		}		
		current = current -> next; 
	}	

	smaller -> next = d2 -> next;
  larger -> next = NULL; 
  struct Node *newh = d1 -> next; 

	return newh; 
}

// exchanges 2 nodes
void swap_nodes(struct Node *prev, struct Node *cur) {
  struct Node *ne = cur-> next;
  struct Node *temp = ne -> next;
  prev -> next = ne; 
  ne -> next = cur; 
  cur -> next = temp;
  return;
}

// sorts the list with bubble sort
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

// merges 2 lists
struct Node *merge2lists(struct Node *rootA, struct Node *rootB) {
  struct Node *current = rootA; 
  while (current -> next != NULL) {
    current = current -> next; 
  }
  current -> next = rootB; 
  struct Node *result = rootA -> next; 
  result = bubbleSort(result); 
  return result; 
}

// merges 2 lists, from midterm 2020-2 
void merge(struct Node **A, struct Node **B) {
  if (*A == NULL && *B == NULL) return; 
  else if (*A == NULL) {
    *A = *B; 
    return; 
  }
  else if (*B == NULL) {
    *B = *A;
    return; 
  }
  struct Node* curr = *A; 
  struct Node* next = *B; 
  while (next != NULL) {
    struct Node *temp = next; 
    next = curr -> next; 
    curr -> next = temp; 
    curr = temp;  
  }
  *B = *A; 
}

// checks if 2 lists are anagrams of each other
void isAnagram(struct Node *s1, struct Node *s2) {
  s1 = bubbleSort(s1);
  s2 = bubbleSort(s2);
  struct Node *cur1 = s1; 
  struct Node *cur2 = s2; 
  while (cur1 -> next != NULL) {
    if (cur1 -> data != cur2 -> data) {
      printf("not anagrams, value %d and %d are different\n", cur1 -> data, cur2 -> data);
      return; 
    } else {
      cur1 = cur1 -> next;
      cur2 = cur2 -> next; 
    }
  }
  printf("anagrams confirmed\n");
}

int main() {
  int n, x, i;
  struct Node *l = NULL;
  struct Node *head = NULL;
  n = 5; 
  head = insertList(head, 1);
  head = insertList(head, 2);
  head = insertList(head, 3);
  // head = insertList(head, 12);
  // head = insertList(head, 8);

  l = insertList(l, 6);
  l = insertList(l, 4);
  l = insertList(l, 5);
  // l = insertList(l, 12);
  // l = insertList(l, 9);

  displayList(head);
  displayList(l); 
  // merge2lists(head, l);
  merge(&head, &l);
  displayList(head);

  // isAnagram(head, l);



  
  // displayList(head);
  // printf("Before Grouping:");
  // displayList(head);
  // struct Node *gList = groupingLinkedList(head);
  // printf("After Grouping:");
  // displayList(gList);

  // struct Node* aList = rearrange(head);
  // displayList(aList);
  // displayList(head);
  // head = bubbleSort(head);


  // deleteVal(head, 12);
  // displayList(head);
  return 0;
}
