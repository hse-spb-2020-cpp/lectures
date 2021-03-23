#include <iostream>

// void foo(const char *strs[]) {
void foo(const char **strs) {
    std::cout << strs[0] << " " << strs[1] << "\n";
}

int main() {
    const char *strs[] = {
        "Hello",
        "World"
    };
    foo(strs);
}
