#include <stdio.h>

// Go To Statement Considered Harmful:
// https://homepages.cwi.nl/~storm/teaching/reader/Dijkstra68.pdf

int main() {
    int n = 10;
    int i = 0;
label:
    printf("%d\n", i);
    i++;
    int x = 5;
    printf("  x=%d\n", x);
    x++;
    if (i < n)
        goto label;
    printf("end\n");

    {
    foo:;
    }
    {
    bar:;  // Not in C++?
        int x;
    }
}
