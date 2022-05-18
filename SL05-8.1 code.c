#include <stdio.h>

void inc(int i) { //this code does not work--> x is not really changed
//only locally changed but no globally
	i = i + 1;
}

void inc2(int *i) { (//here i is globally incremented
	*i = *i + 1;
}
int main() {
	int x = 7;
	printf("%d\n", x ); //d
	inc(x);
	printf("%d\n", x);// does not increment value x 
	inc2(&x);
	printf("%d\n", x); //works
	
}
