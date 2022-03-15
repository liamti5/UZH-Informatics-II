/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 2 - Task 3                                                      *
 *                                                                          *
 * @author <your name>                                                      *
 ****************************************************************************/

#include <stdio.h>

// TODO: your implementation
int count_blinks(int n){
	int s = 2;
	int l = 1;

	if (n == 1){
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	return count_blinks(n - 1) + count_blinks(n - 2); // either do 2 short blinks or 1 long
}

int main() {
	int input;
	printf("Enter the number of blinks: ");
	scanf("%d", &input);

	// TODO: your implementation
	int result = count_blinks(input);
	printf("%d\n", result);
	return 0;
}
