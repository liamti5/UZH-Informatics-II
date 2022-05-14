#include <stdio.h>

void inc(int* i) {
    *i = *i + 1; 
}

int main() {
	int x = 7;
    int* p_x = &x; 
    printf("%d\n", x);
    inc(p_x);
    printf("%d\n", x);
}


// vs (which doesn't increment x because changes in void are local!!)

// void inc(int i) {
//     i = i + 1; 
// }

// int main() {
// 	int x = 7; 
//     printf("%d\n", x);
//     inc(x);
//     printf("%d\n", x);
// }
