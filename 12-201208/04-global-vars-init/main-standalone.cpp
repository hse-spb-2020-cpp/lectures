#include <iostream>

extern int a;
int b = a + 1;
int a = 10;

int main() {
    std::cout << "a=" << a << "\n";
    std::cout << "b=" << b << "\n";
}
