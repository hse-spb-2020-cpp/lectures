#include <stdexcept>
#include <iostream>

struct Foo {
    int x = 10;
    Foo(int) {
        std::cout << "Foo(int) a\n";
//        throw 0;
        std::cout << "Foo(int) b\n";
    }

    Foo(int, int) : Foo(10) {
        std::cout << "Foo(int, int) a\n";
//        throw 0;
        std::cout << "Foo(int, int) b\n";
    }

    Foo(int, int, int) : Foo(10, 20) {
        std::cout << "Foo(int, int, int) a\n";
        throw 0;
        std::cout << "Foo(int, int, int) b\n";
    }

    ~Foo() {
        std::cout << "~Foo()\n";
    }
};

int main() {
    try {
        Foo f(10, 20, 30);
    } catch (...) {
        std::cout << "exception\n";
    }
}
