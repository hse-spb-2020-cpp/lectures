#include <stdio.h>  // Kinda optional because of implicit declarations.
/*
Oldest standard: C89
  // is a C++-style comment
  variables: on the top of functions
  implicit declarations:
     f(1, 2, 3, 4, "foo") --> int f();
     void *malloc() vs int malloc().
     gcc thinks it's ok in C11 still
  K&R (old-style) function definitions (deleted in C23).
*/

void foo(a, b) 
int a; char b;
{
    printf("a=%d, b=%c\n", a, b);
}

int main(void) {
    /*for (int i = 0; i < 10; i++) {
    }*/
    int i;

    for (i = 0; i < 10; i++) {
        printf("i=%d\n", i);
    }

    // int j;  // Error in C89, but not in modern GCC.
    // fooo(1, 2, "hello");  // Error in C99, link error in C89 (or GCC with C99+)
    foo(10, 'x');
}
