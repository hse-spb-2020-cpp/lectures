#include <iostream>

struct Foo {
    // int a, b;
    int b, a;
    std::string s;
    Foo() : a(10), b(a + 1) {}
};

Foo f1;  // zero initialization + constructor: b=1, a=10.

int main() {
    {
        Foo f;
        f.a = 100;
        f.b = 200;
    }
    Foo f2;  // constructor: b = a + 1 (UB + 1 == UB).
    std::cout << f1.a << " " << f1.b << "\n";
    std::cout << f2.a << " " << f2.b << "\n";
}
