/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 7 - Task 4: Sample Solution                                     *
 *                                                                          *
 * @date 2022-04-01                                                         *
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

int is_empty(Stack* s) {
  if (s->top == EMPTY) {
    return 1;
  }
  else {
    return 0;
  }
}

int is_full(Stack* s) {
  if (s->top == s->capacity - 1) {
    return 1;
  }
  else {
    return 0;
  }
}

int num_items(Stack* s) {
  return s->top + 1;
}

int peek(Stack* s) {
  if (is_empty(s)) {
    printf("Error: cannot peek the stack: stack empty\n");
    return ERROR_VALUE;
  }
  else {
	   return s->items[s->top];
  }
}

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

int push(Stack* s, int value) {
  if (is_full(s)) {
    printf("Error: cannot push item %d to the stack: stack full\n", value);
    return ERROR_VALUE;
  }
  s->top++;
	s->items[s->top] = value;
  return SUCCESS_VALUE;
}

void delete(Stack* s) {
  free(s->items);
  free(s);
}

/**
 * Checks whether two given arrays represent possible sequences of push and
   pop operations on a stack
 * @param in sequence of values pushed to the stack
 * @param out sequence of values popped from the stack
 * @pre pushed != NULL && popped != NULL && pushed not empty && popped not empty
 * @return 1 if arrays in and out represent possible sequences of push and
           pop operations on a stack, 0 otherwise
 */
int is_valid(int in[], int in_size, int out[], int out_size) {
  Stack* helper_stack = create(in_size);
  int out_pos = 0;
  for (int in_pos = 0; in_pos < in_size; in_pos++) {
    push(helper_stack, in[in_pos]);
    while (!is_empty(helper_stack) && peek(helper_stack) == out[out_pos]) {
      pop(helper_stack); // pop from helper_stack if top of helper_stack equals x element of out_pos
      out_pos++;
    }
  }
  int result = is_empty(helper_stack); // helper_stack is empty if it is possible, otherwise not. 
  delete(helper_stack);
  return result;
}

int main() {
  int in1[] = {1, 2, 3, 4, 5};
  int size_in1 = sizeof(in1) / sizeof(in1[0]);
  int out1[] = {4, 5, 3, 2, 1};
  int size_out1 = sizeof(out1) / sizeof(out1[0]);
  int result1 = is_valid(in1, size_in1, out1, size_out1);
  printf("Result for first two arrays: %d\n", result1);
  int in2[] = {1, 2, 3, 4, 5};
  int size_in2 = sizeof(in2) / sizeof(in2[0]);
  int out2[] = {4, 3, 5, 1, 2};
  int size_out2 = sizeof(out2) / sizeof(out2[0]);
  int result2 = is_valid(in2, size_in2, out2, size_out2);
  printf("Result for second two arrays: %d\n", result2);
  return 0;
}
