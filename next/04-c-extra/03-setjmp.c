#include <setjmp.h>
#include <stdio.h>
#include <limits.h>

// In other words, only long jumps up the call stack are allowed.

static jmp_buf error_handler;

static int divide(int a, int b) {
    if (!b) {
        longjmp(error_handler, 1);
    }
    if (a == INT_MIN && b == -1) {
        longjmp(error_handler, 2);
    }
    return a / b;
}

int main(void) {
    if (setjmp(error_handler) != 0) {
        printf("Error! Try again\n");
    }

    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d/%d=%d\n", a, b, divide(a, b));
}
