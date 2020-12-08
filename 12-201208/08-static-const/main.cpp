#include <string>
#include <iostream>

#include "main.h"

int Foo::N = 100;
const int Foo::N2;
const std::string Foo::s = "hello";  // Нетривиальные константы надо определять в .cpp

void foo();
void bar();

int main_a[Foo::N3];

int main() {
    std::cout << "N=" << Foo::N << "\n";
    std::cout << "&N2=" << &Foo::N2 << "\n";
    std::cout << "s=" << Foo::s << "\n";
    std::cout << "&s=" << &Foo::s << "\n";
    foo();
    bar();
}
