#include <cassert>
#include <iostream>

struct Foo {
    int value;

    Foo() : value(0) {}
    Foo(int init_value) : value(init_value) {}

//    int to_int() { return value; }
    operator int() const {
        std::cout << "operator int() called!\n";
        return value;
    }
};

int main() {
    Foo f = 10;

    const Foo &g = f;
    int x = g;
    assert(x == 10);
}
