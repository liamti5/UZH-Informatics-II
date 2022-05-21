#include <stdio.h>

void inc(int* i) {
    *i = *i + 1; 
}

int f(int x, int *py, int **ppz) {
    int y, z;
    **ppz += 1; 
    z = **ppz; 
    *py += 2;
    y = *py;
    x += 3; 
    return z;     
}

int main() {
	// int x = 7;
    // int* p_x = &x; 
    // printf("%d\n", x);
    // inc(p_x);
    // printf("%d\n", x);
    int c, *b, **a; 
    c = 4; 
    b = &c; 
    a = &b; 
    printf("%d\n", f(c, b, a));
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
