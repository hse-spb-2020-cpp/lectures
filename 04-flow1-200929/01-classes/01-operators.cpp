#include <iostream>

struct Foo {
    int operator=(int) {
        return 123;
    }
};

struct Ratio {
    Ratio& operator+=(const Ratio &) {
        return *this;
    }
};

int main() {
    int a, b, c = 10;
    std::cout << (a = (b = c)) << "\n";
    Foo f;
    std::cout << (f = 10) << "\n";
    std::cout << (a = f = 10) << "\n";  // a = (f = 10)
    std::cout << a << "\n";  // a = 123
    return a += b;
}
