#include <string>
#include <iostream>

extern int a;  // Типа "объявление", инициализировать нельзя.
namespace ns_for_s {
extern std::string s;  // Типа "объявление."
}

void foo() {
    std::cout << "foo(): a=" << a << "\n";
    std::cout << "foo(): s=" << ns_for_s::s << "\n";
}
