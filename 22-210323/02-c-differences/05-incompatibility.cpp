#include <stdlib.h>
#include <stdio.h>

int main(void) {
//    int *a = malloc(5 * sizeof(int));  // new int[5];
    int *a = static_cast<int*>(malloc(5 * sizeof(int)));  // new int[5];
    free(a);  // delete[] a

    printf("%d %d\n", (int)sizeof('A'), (int)sizeof(char));
}
