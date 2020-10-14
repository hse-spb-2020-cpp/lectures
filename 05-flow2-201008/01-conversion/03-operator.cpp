#include <iostream>

struct Foo {
    int x;
    Foo(int init) : x(init) {}

    operator int() const {
        std::cout << "operator int() called\n";
        return x;
    }

    operator int&() {
        return x;
    }
};

void foo(int &) {
}

int main() {
    Foo f = 10;
    int x = f;
    std::cout << "x = " << x << "\n";
    foo(f);
}
