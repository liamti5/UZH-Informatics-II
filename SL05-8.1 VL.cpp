#include <stdio.h>

void inc(int i){*i = *i + 1;
}

int main(){
	int x = 7;
	inc(&x);
	printf("x")
}
