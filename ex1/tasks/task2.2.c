/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 2                                                      *
 *                                                                          *
 * @author <your name>                                                      *
 ****************************************************************************/

#include <stdio.h>

// hard-coded maximum length for input strings
const int MAX_LENGTH = 1000;

int check_vowel(char letter){
	char vowels[] = "AaEeIiOoUu";
    int nvowels = 0;
    for (int v = 0; v < 10; v++){ // for loop for each index of vowels and 10 b.c. there are only 10 vowels
        if (letter == vowels[v]){
            return 1;
        }
    }
	return 0; 
}

void BS(char A[]) {
	char result[MAX_LENGTH];
	char b[] = "b";

	int x = 0;

	for (int i = 0; i < MAX_LENGTH; i++){
		if (check_vowel(A[i]) == 1){
			result[x] = b[0];
			result[x+1] = A[i];
			result[x+2] = b[0];
			x = x + 3;
		}
		else{
			result[x] = A[i];
			x++;
		}
	}

	printf("Result: %s\n", result);
	return;
}

int main() {
	char input_string[MAX_LENGTH + 1];
	printf("Enter a string: ");
	scanf("%[^\n]s", input_string);
	BS(input_string);
	return 0;
}
