#include <cassert>
#include <iostream>

struct Foo {
    explicit operator int() {
        return 123;
    }
};

void foo(int) {
}

/*int bar() {
    return Foo{};
}*/

int main() {
    Foo f;
//    [[maybe_unused]] int x1 = f;
    [[maybe_unused]] int x2(f);
    [[maybe_unused]] int x3{f};
//    x3 = f;
//
//    foo(f);
    foo(static_cast<int>(f));
    foo(int(f));  // functional cast, C-style cast
}
