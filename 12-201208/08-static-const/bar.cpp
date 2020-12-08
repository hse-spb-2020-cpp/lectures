#include <string>
#include <iostream>
#include "main.h"

int bar_a[Foo::N2];

void bar() {
    std::cout << "bar(): N=" << Foo::N << "\n";
    std::cout << "bar(): &N2=" << &Foo::N2 << "\n";
    std::cout << "bar(): s=" << Foo::s << "\n";
    std::cout << "bar(): &s=" << &Foo::s << "\n";
}
