#include <string>
#include <iostream>

int main_zero;  // zero-initialized.

int main_a = 10;
extern int foo_a;
extern int bar_a;
int main_b = bar_a + 1;

int main() {
    std::cout << "main_zero=" << main_zero << "\n";  // 0
    std::cout << "main_a=" << main_a << "\n";  // 10
    std::cout << "foo_a=" << foo_a << "\n";  // 11
    std::cout << "bar_a=" << bar_a << "\n";  // 12
    std::cout << "main_b=" << main_b << "\n";  // 13
}
