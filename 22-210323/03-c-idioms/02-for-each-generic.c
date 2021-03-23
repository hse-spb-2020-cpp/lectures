#include <stdio.h>
#include <stddef.h>

void for_each(void *begin, void *end, size_t elem_size, void (*f)(const void*)) {
    while (begin != end)
        f(begin += elem_size);  // GCC extension: arithmetics on void*
}

int main(void) {
    int arr[10] = {
        // Designated initializers for arrays.
        [3] = 100,
        [5] = 200
    };

    // Careful: nested function is GCC extension.
    void print_int(int *x) {
        printf("%d\n", *x);
    }

    for_each(arr, arr + 10, sizeof arr[0],
        print_int  // WARNING: invalid conversion. GCC does not even care about 'const'.
    );
}
