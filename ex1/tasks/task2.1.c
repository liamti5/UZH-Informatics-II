#include <stdio.h>
#include <string.h>

int count_vowels(char []);

int main(){
    char A[1000] = "informaAatik";
    int result = count_vowels(A);
    printf("%d\n", result);

    return 0;
}

int count_vowels(char A[]){
    char vowels[] = "AaEeIiOoUu";
    int nvowels = 0;
    for (int i = 0; i < 1000; i++){ // for loop for each index of A
        char ch = A[i];
        for (int v = 0; v < 10; v++){ // for loop for each index of vowels and 10 b.c. there are only 10 vowels
            if (ch == vowels[v]){
                nvowels++;
            }
        }
    }
    return nvowels;
}
