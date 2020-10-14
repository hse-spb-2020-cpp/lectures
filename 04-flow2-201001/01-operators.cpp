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

Ratio foo(Ratio a, Ratio b) {
    return c = a += b;
}

int main() {
    int a, b, c = 10;
    std::cout << (a = (b = c)) << "\n";
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";

    std::cout << "=====\n";
    Foo f;
    std::cout << (a = f = 10) << "\n"; // (a = (f = 10))
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";

    Ratio x, y;
    x += y;
}
