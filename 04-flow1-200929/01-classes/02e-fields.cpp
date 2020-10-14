#include <cassert>
#include <iostream>

struct Foo {
    int a = 10;
    int &b;
    int c = 30;
};

struct Bar {
    const int &x;
    Bar(int, int &x_) : x(x_) {}  // Mind the '&'!
};

int main() {
    int x = 20;
    Foo f = {40, x};
    assert(f.a == 40);
    assert(f.b == 20);
    assert(f.c == 30);
    assert(x == 20);

    f.b++;
    assert(f.a == 40);
    assert(f.b == 21);
    assert(f.c == 30);
    assert(x == 21);

    Bar b(1234, x);
    assert(b.x == 21);
    x++;
//    b.x++;
    assert(x == 22);
    assert(b.x == 22);

    // b = b;
}
