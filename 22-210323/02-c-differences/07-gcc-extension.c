#include <assert.h>

int main() {
    char buf[10];
    void *ptr = buf;
    void *ptr2 = ptr + 5;  // GCC extension! -pedantic only emits warning, see -pedantic-errors
    assert(ptr2 == (char*)ptr + 5);  // Valid C.
}
