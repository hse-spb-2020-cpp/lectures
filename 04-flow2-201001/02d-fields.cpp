#include <cassert>
#include <vector>
#include <iostream>

struct Foo {
    int a = 10;
    int &b;
    int c = 30;

    // Foo f;
};

struct Bar {
    const int &x;
    const int z;
    Bar(int, const int &y) : x(y), z(y) {}
    void check() {
        assert(x == z);
    }
};

int main() {
    int x = 50;
    Foo f = {40, x};
    assert(f.a == 40);
    assert(f.b == 50);
    assert(f.c == 30);
    assert(x == 50);

    f.b++;
    assert(f.a == 40);
    assert(f.b == 51);
    assert(f.c == 30);
    assert(x == 51);

    Bar b(10, x);
//    std::cout << b.x << "\n";
    assert(b.x == 51);
    x++;
    b.check();
}
