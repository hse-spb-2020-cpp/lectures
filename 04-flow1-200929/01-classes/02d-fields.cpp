#include <cassert>
#include <vector>
#include <iostream>

struct Foo {
    const int a = 10;  // Initialization is optional.
    int b = 20;
    std::vector<int> v = {1, 2};

    Foo(int x, int y) : a(x + y) {  // member initialization list
//        a = x + y;
    }
    Foo(int) : a(b), b(33) {
//        a = 239;
    }
};

int main() {
    Foo f(100, 200);
    assert(f.a == 300);
    assert(f.b == 20);
    assert((f.v == std::vector{1, 2}));

    Foo f2(123);
    std::cout << f2.a << " " << f2.b << "\n";
    assert(f2.a == 33);
    assert(f2.b == 33);
    assert((f2.v == std::vector{1, 2}));
}
