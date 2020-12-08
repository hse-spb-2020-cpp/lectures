#include <string>
#include <iostream>

extern int a;  // Типа "объявление", инициализировать нельзя.
namespace ns_for_s {
extern std::string s;  // Типа "объявление."
}

void bar() {
    std::cout << "bar(): a=" << a << "\n";
    std::cout << "bar(): s=" << ns_for_s::s << "\n";
}
