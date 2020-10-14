#include <cassert>
#include <iostream>
#include <vector>

void foo(int) {
    std::cout << "1\n";
}

void foo(char) {
    std::cout << "2\n";
}

template<typename T>
void foo(const T&) {
    std::cout << "3\n";
}

int main() {
    foo(10);
    foo('1');
    foo(10.0);

    foo<>(10);
}
