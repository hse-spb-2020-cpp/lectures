#include <string>
#include <iostream>

int a = 10;  // Типа "определение."
namespace ns_for_s {
std::string s = "hello";  // Типа "определение."
}

void foo();
void bar();

int main() {
    a++;
    ns_for_s::s += "!";
    std::cout << "a=" << a << "\n";
    std::cout << "s=" << ns_for_s::s << "\n";
    foo();
    bar();
}
