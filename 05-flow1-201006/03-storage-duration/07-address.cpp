#include <iostream>

int x1, x2, x3;

int main() {
    int y1, y2, y3;
    int *z = new int;

    std::cout << &x1 << " " << &x2 << " " << &x3 << "\n";
    std::cout << &y1 << " " << &y2 << " " << &y3 << "\n";
    std::cout << z << " " << &z << "\n";

    // Unspecified behavior
    std::cout << (&x1 < z) << "\n";

    delete z;
}
