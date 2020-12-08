#include <string>
#include <iostream>
#include "main.h"
#include "bar.h"

void bar() {
    std::cout << "bar(): a=" << a << "\n";
    std::cout << "bar(): s=" << ns_for_s::s << "\n";
}
