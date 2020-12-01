#include <iostream>
#include <utility>

struct Foo {
    Foo() {
        std::cout << "Foo()\n";
    }

    Foo(const Foo &) {
        std::cout << "Foo(const Foo&)\n";
    }

    Foo(Foo &&) {
        std::cout << "Foo(Foo&&)\n";
    }

    Foo& operator=(const Foo &) {
        std::cout << "operator=(const Foo&)\n";
        return *this;
    }

    Foo& operator=(Foo &&) {
        std::cout << "operator=(Foo&&)\n";
        return *this;
    }
};

int main() {
    Foo a;
    Foo b(/* lvalue */ a);
    Foo c(/* xvalue */ std::move(a));
    Foo d;

    b = /* lvalue */ d;
    b = /* xvalue */ std::move(d);
}
