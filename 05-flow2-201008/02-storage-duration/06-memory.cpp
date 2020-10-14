#include <iostream>

int main() {
    int x;
    static int y;
    int *z = new int;

    std::cout << &x << "\n";
    std::cout << &y << "\n";
    std::cout << z << "\n";

    std::cout << (&x < z) << "\n";
}
