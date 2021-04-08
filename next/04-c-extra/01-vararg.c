#include <stdarg.h>
#include <stdio.h>

// Works in C++ as well, but discouraged
// https://en.cppreference.com/w/c/language/variadic
// https://en.cppreference.com/w/cpp/language/variadic_arguments
// C++ alternative: void my_print(int count...) {
void my_print(int count, ...) {
    va_list args;
    va_start(args, count);
    // Also: va_copy (since C99 or C++11)

    for (int i = 0; i < count; i++) {
        int arg = va_arg(args, int);
        printf("arg[%d]=%d\n", i, arg);
    }

    va_end(args);
}

int main(void) {
    my_print(5, 1, 2, ' ', 4, (short)5);  // OK, default conversions are applied
    // float --> double; integer promotion (at least int).
    my_print(2, 123456789123456789LL);  // UB: promoted to long long, types mismatch (not exactly, but close enough).
}
