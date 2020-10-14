#include <cassert>
#include <vector>
#include <iostream>

struct Foo {
    const int a;// = 10;
    int b = 20;
    std::vector<int> v = {1, 2};

    Foo(int x, int y) : a(x + y) {
    }

    Foo(int) : a(33), b(a) {
    }
};

int main() {
    {
        // aggregate initialization
        Foo f(100, 200);
        assert(f.a == 300);
        assert(f.b == 20);
        assert((f.v == std::vector<int>{1, 2}));
        f.b++;
    }
    {
        // aggregate initialization
        Foo f(100);
        std::cout << f.a << " " << f.b << "\n";
        assert(f.a == 33);
        assert(f.b == 33);
        assert((f.v == std::vector<int>{1, 2}));
    }
}
