#include <vector>

struct Foo {
    int a = 10;
    std::vector<int> v;

    void method();
};

Foo* get_foo() {
    return new Foo();
}
