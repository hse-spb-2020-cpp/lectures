#include <utility>

struct Foo {
    Foo() {}
    Foo(const Foo&) = delete;
    Foo(Foo&&) = delete;
};

Foo create_foo() {
    // return std::move(Foo());
    return Foo();
}

int main() {
    Foo f = create_foo();
}
