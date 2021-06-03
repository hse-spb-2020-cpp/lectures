#include <iostream>
#include <sstream>

// Can be implemented in another translation unit.
// Dynamic polymorphism, not static!
int readInt(std::istream &is) {
    int x;
    is >> x;
    return x;
}

void printInt(std::ostream &os, int x) {
    os << x;
}

int main() {
    std::stringstream s1;
    std::iostream &s2 = s1;
    // iostream : istream, ostream
    printInt(s2, 10);
    printInt(std::cout, readInt(s2));
    std::cout << "\n";

    // needs virtual inheritance!
    std::ios &base = s2;
    std::cout << static_cast<bool>(base) << "\n";
    std::cout << base.fail() << "\n";
}
