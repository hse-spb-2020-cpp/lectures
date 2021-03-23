// Compiles with -pedantic-errors

#include <stdio.h>
#include <stddef.h>

void for_each(void *begin, void *end, size_t elem_size, void (*f)(const void*)) {
    for (; begin != end; begin = (char*)begin + elem_size)
        f(begin);
}

void print_int(const void *x_void) {
    const int *x = x_void;
    printf("%d\n", *x);
}

int main(void) {
    int arr[10] = {
        // Designated initializers for arrays.
        [3] = 100,
        [5] = 200
    };

    for_each(arr, arr + 10, sizeof arr[0], print_int);
}
