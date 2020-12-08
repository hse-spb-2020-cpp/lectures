#include <string>
#include <iostream>
#include "main.h"
#include "foo.h"

void foo() {
    std::cout << "foo(): a=" << a << "\n";
    std::cout << "foo(): s=" << ns_for_s::s << "\n";
}
