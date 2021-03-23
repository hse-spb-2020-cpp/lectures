#include <stdio.h>

void for_each(int *begin, int *end, void (*f)(int)) {
    while (begin != end)
        f(*begin++);
}

int main(void) {
    int arr[10] = {
        // Designated initializers for arrays.
        [3] = 100,
        [5] = 200
    };

    // Careful: nested function is GCC extension.
    void print_int(int x) {
        printf("%d\n", x);
    }

    for_each(arr, arr + 10, print_int);
}
