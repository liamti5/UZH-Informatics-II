/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 7 - Task 3: Sample Solution                                     *
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
 * Helper function for printing an array of integers
 */
void print(int input[], int size) {
	printf("[");
	for (int i = 0; i < size - 1; i++) {
		printf("%d, ", input[i]);
	}
	printf("%d]\n", input[size - 1]);
}

/**
 * Naïve solution, runs in O(n^2)
 */
void get_span_naive(int data[], int num_data, int* spans) {
  for (int i = 0; i < num_data; i++) {
    int span_length = 1;
    while (span_length <= i && data[i - span_length] <= data[i]) {
      span_length++;
    }
    spans[i] = span_length;
  }
}

void printst(Stack *s) {
	if (num_items(s) > 0) {
		printf("(top) -> ");
		for (int i = num_items(s) - 1; i >= 0; i--) {
			printf(" %d", s -> items[i]);
		}
		printf("\n");
	}
	else {
		printf("stack is empty\n");
	}
}

/**
 * Calculates the span of the element in the data array at the given index
 */
void get_span(int data[], int num_data, int* spans) {
  Stack* helper_stack = create(num_data);
  for (int i = 0; i < num_data; i++) {
    while (!is_empty(helper_stack) && data[i] >= data[peek(helper_stack)]) {
      pop(helper_stack);
    }
    if (is_empty(helper_stack)) {
      spans[i] = i + 1;
    }
    else {
      spans[i] = i - peek(helper_stack);
    }
    push(helper_stack, i);
    printst(helper_stack);
    print(spans, i);
  }
  
  delete(helper_stack);
}

int main() {
  int data1[] = {6, 3, 4, 5, 2};
  const int num_data1 = sizeof(data1) / sizeof(data1[0]);
  int spans1[num_data1];
  get_span(data1, num_data1, spans1);
  print(spans1, num_data1);
  return 0;
}
