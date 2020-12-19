#include <iostream>

struct Ratio {
    int num = 0, denom = 1;
};

std::ostream& operator<<(std::ostream &os, const Ratio &r) {
    os << r.num << "/" << r.denom;
    return os;
}

std::istream& operator>>(std::istream &is, Ratio &r) {
    is >> r.num;
    ..............
    return is;
}

int main() {
    Ratio r;
    std::cout << r << "\n";
    (std::cout << r) << "\n";
    (operator<<(std::cout, r)) << "\n";
    operator<<(operator<<(std::cout, r), "\n");
}
