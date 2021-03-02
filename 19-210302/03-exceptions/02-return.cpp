#include <iostream>

int remaining = 1;

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
            std::cout << "exception\n";
            return Foo();
        }
    } else {
        return b;
    }
}

int main() {
    Foo f = func(0);
    std::cout << "&f=" << &f << "\n";
}
