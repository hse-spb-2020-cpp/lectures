#include <cstring>
#include <iostream>

void my_strncpy(char *dest, const char *src, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
        if (!src[i]) {
            return;
        }
    }
}

int main() {
    char foo[] = "Hello";
    my_strncpy(foo, "123456", sizeof foo);  // UB отсутствует.
    std::cout << foo << "\n";  // UB! Строчка не null-terminated.

    strncpy(foo, "123456", sizeof foo);  // UB отсутствует.
    std::cout << foo << "\n";  // UB! Строчка не null-terminated.
}
