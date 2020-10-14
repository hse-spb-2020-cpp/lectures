#include <cassert>
#include <vector>

struct Foo {
    const int a = 10;
    int b = 20;
    std::vector<int> v = {1, 2};
};

int main() {
    // aggregate initialization
    Foo f = {100};
    assert(f.a == 100);
    assert(f.b == 20);
    assert((f.v == std::vector<int>{1, 2}));

    // f = f;
    // f.a++;
    f.b++;
    assert(f.b == 21);

    std::vector<Foo> vec;
    vec.push_back(Foo{});
    vec.insert(vec.begin(), Foo{});

    Foo f2 = {};
    assert(f2.a == 10);
    assert(f2.b == 20);
    assert((f2.v == std::vector<int>{1, 2}));

    Foo f3 = {100, 200};
    assert(f3.a == 100);
    assert(f3.b == 200);
    assert((f3.v == std::vector<int>{1, 2}));

    Foo f4 = {100, 200, {3}};
    assert(f4.a == 100);
    assert(f4.b == 200);
    assert((f4.v == std::vector<int>{3}));
}
