/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 7 - Task 2                                                      *
 *                                                                          *
 * @author <LITEvm>                                                      *
 ****************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#define EMPTY -1
#define SUCCESS_VALUE 1
#define ERROR_VALUE -1

typedef struct Stack {
	unsigned int capacity; // unsigned -> int capacity can't be < 0
	int* items; // list of items in the stack
  	int top; // like the max index of the stack -> stack -> items[stack -> top] is the top element of the stack
} Stack;

//TODO: your implementation

// a) create stack function
Stack *create(unsigned int capacity) {
	Stack *new_stack = malloc(sizeof(Stack));
	if (!new_stack) {
		return NULL;
	}
	new_stack -> capacity = capacity;
	new_stack -> top = EMPTY;
	new_stack -> items = malloc(capacity * sizeof(int)); // = -1
	return new_stack;	
}

// b) delete stack function
void delete(Stack *s) {
	free(s -> items);
	free(s);
}

// c) is stack empty function
int is_empty(Stack *s) {
	if (s -> top == EMPTY) {
		return 1;
	}
	return 0;
}

// d) is stack full function
int is_full(Stack *s) {
	if (s -> top == s -> capacity - 1) {
		return 1;
	}
	return 0;
}

// f) return num of items stored in stack function
int num_items(Stack *s) {
	return s -> top + 1;
}

// g) push new item to stack function
int push(Stack *s, int value) {
	s -> top++;
	s -> items[s -> top] = value;
	return SUCCESS_VALUE;
}

// h) pop item from stack function
int pop(Stack *s) {
	s -> top--;
	return s -> items[s -> top + 1];
}

// i) peek: view item at the top of the stack function
void peek(Stack *s) {
	printf("%d\n",  s -> items[s -> top]);
}


// j) print stack function
void print(Stack *s) {
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

// k) check if 2 stacks are equal function
int is_equal(Stack *s1, Stack *s2) {
	int equal = 0; 
	if (num_items(s1) == num_items(s2)) {
		equal = 1; 
		for (int i = 0; i < num_items(s1); i++) {
			if (s1 -> items[i] != s2 -> items[i]) {
				equal = 0; 
				break;
			}
		}
	}
	return equal; 
}

// l) reverse stack function
void reverse1(Stack *s) {
	int A[s -> top];
	int n = s -> top; 
	for (int i = 0; i <= n; i++) {
		A[i] = pop(s);
	}
	for (int i = 0; i <= n; i++) {
		push(s, A[i]);
	}
}

// l) different reverse stack function
Stack *reverse2(Stack *s) {
	Stack *s1 = create(4);
	for (int i = 0; i <= s -> top; i++) {
		push(s1, pop(s));
	}
	return s1;
}

int main() {
	//TODO: your implementation
	Stack *s1 = create(3);
	push(s1, 4);
	push(s1, 2);
	push(s1, 1);
	// printf("is empty? %d\n", is_empty(s1));
	// printf("is full? %d\n", is_full(s1));
	print(s1);
	// pop(s1);
	// print(s1);
	// Stack *s2 = create(4);
	// push(s2, 4);
	// push(s2, 2);
	// print(s2);
	// printf("is equal? %d\n", is_equal(s1, s2));
	reverse2(s1);
	print(s1);
	return 0;
}
