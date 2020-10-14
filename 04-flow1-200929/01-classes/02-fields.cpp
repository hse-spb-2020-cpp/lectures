#include <cassert>
#include <vector>

struct Foo {
    int a = 10;
    int b = 20;
    std::vector<int> v = {1, 2};
};

int main() {
    Foo f = {30};
    assert(f.a == 30);
    assert(f.b == 20);
    assert((f.v == std::vector{1, 2}));

    Foo f2;
    assert(f2.a == 10);
    assert(f2.b == 20);
    assert((f2.v == std::vector{1, 2}));

    f2 = f;
    assert(f2.a == 30);
    assert(f2.b == 20);
    assert((f2.v == std::vector{1, 2}));
}
