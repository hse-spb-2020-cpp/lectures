#include <iostream>

int remaining = 2;

struct Foo {
    Foo() {
        std::cout << "Foo() " << this << "\n";
    }
    Foo(const Foo &) {
        std::cout << "Foo(const Foo&) " << this << "\n";
        if (!--remaining) {
            throw 0;
        }
    }
    Foo &operator=(const Foo &) {
        std::cout << "operator=(const Foo&) " << this << "\n";
        if (!--remaining) {
            throw 0;
        }
        return *this;
    }
    ~Foo() {
        std::cout << "~Foo " << this << "\n";
    }
};

Foo func(int x) {
    Foo a, b;
    // Чтобы обхитрить компилятор и нельзя было сделать NRVO так просто.
    if (x == 0) {
        try {
            return a;
        } catch (...) {
            std::cout << "exception in func\n";
            return Foo();
        }
    } else {
        return b;
    }
}

int main() {
    Foo f;
    try {
        std::cout << "&f=" << &f << "\n";
        f = func(0);
        std::cout << "after f\n";
    } catch (...) {
        std::cout << "exception in main\n";
    }
}
