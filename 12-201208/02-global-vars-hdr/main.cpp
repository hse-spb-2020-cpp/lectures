#include <string>
#include <iostream>
#include "main.h"
#include "foo.h"
#include "bar.h"

int a = 10;  // Типа "определение."
namespace ns_for_s {
std::string s = "hello";  // Типа "определение."
}

int main() {
    a++;
    ns_for_s::s += "!";
    std::cout << "a=" << a << "\n";
    std::cout << "s=" << ns_for_s::s << "\n";
    foo();
    bar();
}
