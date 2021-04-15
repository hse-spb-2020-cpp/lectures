// https://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast/573574#573574
#include <stddef.h>
#include <stdio.h>

// Library
typedef struct callback_data_s *callback_data;
struct {
    void (*callback)(callback_data);
    callback_data data;
} c;

void save_func(void (*callback)(callback_data), callback_data data) {
    c.callback = callback;
    c.data = data;
}

void call_func() {
    void *p1 = 0;
    char *p2 = 0;
    // c.callback(p1);  // OK in C, error in C++.
    // c.callback(p2);  // Warning in GCC, error in C++.
    c.callback(c.data);
}

// User code
void printer(callback_data data) {
    printf("x=%d\n", *(int *)data);
}

int main(void) {
    int x = 10;
    save_func(printer, (callback_data)&x);  // Warning in C without cast, C++
                                            // needs reinterpret_cast.
    call_func();
    x = 20;
    call_func();
    call_func();
}
