#include <stdio.h>

int main () {
    double d = 1.5;
    int i = 1;
    char ch = 'a';

    double *p_d = &d; // init. pointer + assigning a value in one line
    int *p_i; // doing the same thing but in 2 lines
    p_i = &i;
    char *p_ch;
    p_ch = &ch;

    // values of variables and pointers    
    printf("%f\n", d);
    printf("%d\n", i);
    printf("%c\n", ch);
    printf("%f\n", *p_d);
    printf("%d\n", *p_i);
    printf("%c\n", *p_ch);

    // print addresses pointed to 
    printf("%p\n", p_d);
    printf("%p\n", p_i);
    printf("%p\n", p_ch);
    // print addresses of pointers
    printf("address of pointer p_d %p\n", &p_d);
    printf("address of pointer p_i %p\n", &p_i);
    printf("address of pointer p_ch %p\n", &p_ch);

    // memory sizes
    printf("size of double %d\n", sizeof(d));
    printf("size of int %d\n", sizeof(i));
    printf("size of char %d\n", sizeof(ch));
    printf("size of pointer %d\n", sizeof(p_d)); // size of a pointer is always 8
    printf("size of pointer %d\n", sizeof(p_i));
    printf("size of pointer %d\n", sizeof(p_ch));
    
}