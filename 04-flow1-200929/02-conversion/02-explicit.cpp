#include <cassert>
#include <vector>

struct Foo {
    int x = 0;

    Foo() {}
    explicit Foo(int x_) : x(x_) {}
};

void foo(Foo f) {
    assert(f.x == 30);
}

int main() {
    std::vector<int> v(10);
    // v = 10;

    Foo f(20);
    f = 30;
    foo(30);
}
