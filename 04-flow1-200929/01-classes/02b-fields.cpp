#include <cassert>
#include <vector>

struct Foo {
    const int a = 10;  // Initialization is optional.
    int b = 20;
    std::vector<int> v = {1, 2};
};

int main() {
    Foo f = {/*a=*/30};
    assert(f.a == 30);
    assert(f.b == 20);
    assert((f.v == std::vector{1, 2}));

    Foo f2;
    assert(f2.a == 10);
    assert(f2.b == 20);
    assert((f2.v == std::vector{1, 2}));

    Foo f3 = f;
    assert(f3.a == 30);
    assert(f3.b == 20);
    assert((f3.v == std::vector{1, 2}));

    f2.b = 444;
    assert(f2.b == 444);

    std::vector<Foo> vec;
    vec.insert(vec.begin(), Foo{});

/*    f2 = f;
    assert(f2.a == 30);
    assert(f2.b == 20);
    assert((f2.v == std::vector{1, 2}));*/
}
