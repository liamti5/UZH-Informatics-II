/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 7 - Task 2: Sample Solution                                     *
 *                                                                          *
 * @date 2022-03-29                                                         *
 ****************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#define EMPTY -1
#define SUCCESS_VALUE 1
#define ERROR_VALUE -1

typedef struct Stack {
	unsigned int capacity;
	int* items;
  int top;
} Stack;

/**
 * Allocates memory for a new (empty) stack
 * @param capacity the number of items the stack is capable to hold
 * @pre capacity > 0
 * @return pointer to the newly created stack
 */
Stack* create(unsigned int capacity) {
	Stack* new_stack = malloc(sizeof(Stack));
	if (!new_stack) {
		return NULL;
  }
	new_stack->capacity = capacity;
  new_stack->top = EMPTY;
	new_stack->items = malloc(capacity * sizeof(int));
	return new_stack;
}

/**
 * Checks whether a stack is empty
 * @param s the stack to check
 * @pre s != NULL
 * @return 1 if the stack is empty, 0 otherwise
 */
int is_empty(Stack* s) {
  if (s->top == EMPTY) {
    return 1;
  }
  else {
    return 0;
  }
}

/**
 * Checks whether a stack is full
 * @param s the stack to check
 * @pre s != NULL
 * @return 1 if the stack is full, 0 otherwise
 */
int is_full(Stack* s) {
  if (s->top == s->capacity - 1) {
    return 1;
  }
  else {
    return 0;
  }
}

/**
 * Returns the capacity of the stack
 * @param s the stack for which the capacity shall be determined
 * @pre s != NULL
 */
int get_capacity(Stack* s) {
  return s->capacity;
}

/**
 * Returns the number of items currently stored in a stack
 * @param s the stack for which the number of items shall be determined
 * @pre s != NULL
 */
int num_items(Stack* s) {
  return s->top + 1;
}

/**
 * Returns the item at the top of the stack without removing it
 * @param s the stack for which the top item shall be returned
 * @pre s != NULL
 * @return the top item of the stack (or an error value if the stack is empty)
 */
int peek(Stack* s) {
  if (is_empty(s)) {
    printf("Error: cannot peek the stack: stack empty\n");
    return ERROR_VALUE;
  }
  else {
	   return s->items[s->top];
  }
}

/**
 * Returns the item at the top of the stack and removes it
 * @param s the stack from which the top item shall be popped
 * @pre s != NULL
 * @return the top item of the stack (or an error value if the stack is empty)
 */
int pop(Stack* s) {
	if (is_empty(s)) {
    printf("Error: cannot pop from the stack: stack empty\n");
    return ERROR_VALUE;
  }
  else {
    s->top--;
    return s->items[s->top + 1];
  }
}

/**
 * Pushes a new item to the stack
 * @param s the stack to which a new item shall be pushed
 * @param value the value of the item to be pushed onto the stack
 * @pre s != NULL
 * @return SUCCESS_VALUE if successful, ERROR_VALUE if stack is full
 */
int push(Stack* s, int value) {
  if (is_full(s)) {
    printf("Error: cannot push item %d to the stack: stack full\n", value);
    return ERROR_VALUE;
  }
  s->top++;
	s->items[s->top] = value;
  return SUCCESS_VALUE;
}

/**
 * Frees the memory allocated for the stack (i.e. deletes the stack)
 * @param s the stack which shall be deleted
 * @pre s != NULL
 */
void delete(Stack* s) {
  free(s->items);
  free(s);
}

/**
 * Prints the content of the stack
 * @param s the stack for which the content shall be printed
 * @pre s != NULL
 */
void print(Stack* s) {
  if (num_items(s) > 0) {
    printf("(top) -> ");
    for (int i = num_items(s) - 1; i >= 0; i--) {
      printf("%d ", s->items[i]);
    }
    printf("\n");
  }
  else {
    printf("(stack is empty)\n");
  }
}

/**
 * Checks if two given stacks have identical contents
 * @param s the stack for which the content shall be printed
 * @param s the stack for which the content shall be printed
 * @pre s1 != NULL && s2 != NULL
 * @return 1 if the content of the stacks is equal, 0 otherwise
 */
int is_equal(Stack* s1, Stack* s2) {
  int is_equal = 0;
  if (num_items(s1) == num_items(s2)) {
    is_equal = 1;
    for (int i = 0; i < num_items(s1); i++) {
      if (s1->items[i] != s2->items[i]) {
        is_equal = 0;
        break;
      }
    }
  }
  return is_equal;
}

/**
 * Reverses the order of the stack (direct access to ADT parts)
 * @param s the stack which shall be reversed
 * @pre s != NULL
 */
void reverse(Stack* s) {
  int n = num_items(s);
  for (int i = 0; i < n / 2; i++) {
    int temp = s->items[i];
    s->items[i] = s->items[n - i - 1];
    s->items[n - i - 1] = temp;
  }
}

/**
 * Reverses the order of the stack (returning pointer to modified stack)
 * @param s the stack which shall be reversed
 * @pre s != NULL
 */
Stack* reverse_return_modified(Stack* s) {
  Stack* temp_stack = create(get_capacity(s));
  while (!is_empty(s)) {
    int current_item = pop(s);
    push(temp_stack, current_item);
  }
  delete(s);
  return temp_stack;
}

/**
 * Reverses the order of the stack (changing the pointer to the stack)
 * @param s the stack which shall be reversed
 * @pre s != NULL
 */
void reverse_change_pointer(Stack** s) {
  Stack* temp_stack = create(get_capacity(*s));
  while (!is_empty(*s)) {
    int current_item = pop(*s);
    push(temp_stack, current_item);
  }
  Stack* old_stack = *s;
  *s = temp_stack;
  delete(old_stack);
}

int main() {
  Stack* s1 = create(6);
  Stack* s2 = create(6);
  push(s1, 1);
  push(s1, 3);
  push(s1, 5);
  push(s1, 7);
  push(s1, 42);
  push(s1, 17);
  print(s1);
  print(s2);
  printf("Check whether s1 is full: %d\n", is_full(s1));
  printf("Check whether s2 is full: %d\n", is_full(s2));
  printf("Number of elements in s1: %d\n", num_items(s1));
  printf("Number of elements in s2: %d\n", num_items(s2));
  printf("Overflow test... ");
  push(s1, 99);
  printf("Element popped from s1: %d\n", pop(s1));
  printf("Element popped from s1: %d\n", pop(s1));
  printf("Element peeked from s1: %d\n", peek(s1));
  for (int i = 0; i < 4; i++) {
    push(s2, i + i + 1);
  }
  print(s1);
  print(s2);
  printf("Comparison of s1 with s2: %d\n", is_equal(s1, s2));
  printf("Element popped from s2: %d\n", pop(s2));
  printf("Comparison of s1 with s2: %d\n", is_equal(s1, s2));
  for (int i = 0; i < 4; i++) {
    pop(s1);
  }
  print(s1);
  print(s2);
  printf("Check whether s1 is empty: %d\n", is_empty(s1));
  printf("Check whether s2 is empty: %d\n", is_empty(s2));
  printf("Underflow test... ");
  pop(s1);
  printf("Underflow test... ");
  peek(s1);
  push(s2, 9);
  push(s2, 8);
  push(s2, 2);
  print(s2);
  reverse(s2);
  print(s2);
  s2 = reverse_return_modified(s2);
  print(s2);
  reverse_change_pointer(&s2);
  print(s2);
  delete(s1);
  delete(s2);
  return 0;
}
