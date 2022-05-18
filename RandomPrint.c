#include <stdio.h>

int main(){
	int j = 10;
    int A[] = {11, 0, 9, 19, 8, 1, 5, 13, 18, 7}; // one integer is 4 bytes --> whole list is 40 bytes
	int n = sizeof(A);
	printf("%d", n);
}
