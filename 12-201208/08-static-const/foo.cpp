#include <string>
#include <iostream>
#include "main.h"

int foo_a[Foo::N2];

void foo() {
    std::cout << "foo(): N=" << Foo::N << "\n";
    std::cout << "foo(): &N2=" << &Foo::N2 << "\n";
    std::cout << "foo(): s=" << Foo::s << "\n";
    std::cout << "foo(): &s=" << &Foo::s << "\n";
}
