#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int *a = malloc(5 * sizeof(int));  // new int[5];
    // int *a = (int*)malloc(5 * sizeof(int)); // very bad style
    free(a);  // delete[] a

    // decltype('A') == int in C
    printf("%d %d\n", (int)sizeof('A'), (int)sizeof(char));
}
