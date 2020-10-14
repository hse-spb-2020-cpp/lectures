#include <cassert>

struct Foo {
    int x = 0;

    Foo() {}
    Foo(int x_) : x(x_) {
    }
};

void foo(Foo f) {
    assert(f.x == 30);
}

int main() {
    // cast
    int x = 10;
    double y = x;
    y += 0.5;

    int z = y;
    double z2 = static_cast<int>(y);

    assert(x == 10);
    assert(y == 10.5);
    assert(z == 10);
    assert(z2 == 10);

    Foo f = 10;  // Foo f(10);
    assert(f.x == 10);
    f = 20;  // F = Foo(20)
    assert(f.x == 20);
    foo(30);

    Foo f2;
}
