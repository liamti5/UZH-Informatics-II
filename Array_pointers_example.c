#include <stdio.h>

int main() {
	int arr[5] ={13, 21, 39, 19, 87};
	
	printf("%p \n", arr);  //%p is address I think
	printf("%p \n", &(arr[0]));
	
	printf("%p \n", arr+2);
	printf("%p \n", &(arr[2]));
	
	printf("%d \n", arr[2]); // %d is integer
	printf("%d \n", *(arr+2));
}
