#include <assert.h>

int main() {
    char buf[10];
    void *ptr = buf;
    void *ptr2 = ptr + 5;  // GCC extension!
    assert(ptr2 == (char*)ptr + 5);  // Valid C.
}
