#include <stdio.h>

void foo(int a) {
    printf("%s\n", (char*)a);  // UB, possibly. E.g. on 64-bit machine.
}

void bar() {   // Any arguments!
}

void baz(void) {   // No arguments
}

int main(void) {
    foo("hello");  // Kinda works, conversion (maybe GCC-specific)?
    bar(1, 2, 3);
    // baz(1, 2, 3);
    baz();
}
