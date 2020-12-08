#include <string>
#include <iostream>
#include "main.h"

int bar_a[N];

void bar() {
    std::cout << "bar(): N=" << N << "\n";
    std::cout << "bar(): s=" << s << "\n";
    std::cout << "bar(): &s=" << &s << "\n";
}
