#include <iostream>
#include <cstring>

void my_strcpy(char *dest, const char *src) {
    for (int i = 0;; i++) {
        dest[i] = src[i];
        if (!src[i]) {
            return;
        }
    }
}

void run(char *foo, char *bar, char *baz) {
    my_strcpy(foo, bar);  // foo = bar
    std::cout << "|" << foo << "|" << bar << "|\n";

    my_strcpy(foo, baz);
    std::cout << "|" << foo << "|\n";

    my_strcpy(foo, "12345");  // OK.
    std::cout << "|" << foo << "|\n";

    my_strcpy(foo, "123456");  // UB! Но мы про это не знаем.
    std::cout << "|" << foo << "|\n";

    std::strcpy(foo, "123456");  // UB! Но мы про это не знаем.
    std::cout << "|" << foo << "|\n";
}

int main() {
    char foo[] = "Hello";
    char bar[] = "World";
    char baz[] = "Hi";
    run(foo, bar, baz);
}
