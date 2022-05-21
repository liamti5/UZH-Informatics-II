#include <stdio.h>
#include <string.h>
char vowels[10] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
int is_vowel(char letter){
	if (letter == 'A' || letter == 'a' || letter == 'E'|| letter == 'I' || letter =='O' || letter == 'U'
	|| letter == 'e' || letter == 'i' || letter =='o' || letter == 'u'){
		return 1;
	}
	else {
	return 0;
	
	}
}
int get_length(char input_string[]) {
	int pos = 0;
	while (input_string[pos] != '\0') {
		pos++;
	}
	return pos;
}
int count_vowels(char A[]){
	int count_v = 0;
	int pos = 0;
	int length;
	
	while (A[pos] != '\0'){
		if (is_vowel(A[pos])){
			count_v++;
		}
		pos++;
	}
	return count_v;	
}

void BS(char A[]) {
	int count = count_vowels(A);
	const int new_len = get_length(A) + 2 * count; /* pro vowel komment zwei neue buchstabe hinzu!*/
	char bsprache[new_len + 1];
	int pos_input = 0;
	int pos_bsprache = 0;
	while (A[pos_input] != '\0'){
		if (is_vowel(A[pos_input])) {
			bsprache[pos_bsprache] = A[pos_input];
			bsprache[pos_bsprache + 1] = 'b';
			bsprache[pos_bsprache + 2] = A[pos_input];
			pos_bsprache = pos_bsprache + 3;
		}
		else {
			bsprache[pos_bsprache] = A[pos_input];
			pos_bsprache = pos_bsprache + 1;
			
		}
		pos_input ++;
		
	}
	bsprache[new_len] = '\0'; /* guarantees that the word is ended at the end of the iteration*/
	printf("B_sprache: %s\n", bsprache);
	
}	
int count;
int main() {
	char A[100];
	printf("Enter a word: ");
	scanf("%[^\n]s", A);
	
	printf("Number of vowels: %d \n", count_vowels(A));
	BS(A);
	return 0;
}
