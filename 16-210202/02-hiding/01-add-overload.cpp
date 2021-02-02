#include <iostream>

struct Foo {
    void foo(int) { std::cout << "int\n"; }
};

struct Bar : Foo {
    using Foo::foo;
    void foo(double) { std::cout << "double\n"; }
    // void foo(int) { std::cout << "Bar int\n"; }
};

int main() {
    Foo f;
    f.foo(1);  // int
    f.foo(1.2);  // int

    Bar b;
    b.foo(1.2);  // double
    b.foo(1);  // double :(
    // Правило: если объявлен метод с именем foo() в наследнике, то смотри на перегрузки
    // только из наследника. А родительский метод "скрой" (hide).

    Foo &f2 = b;
    f2.foo(1);  // int
    f2.foo(1.2);  // int
}
