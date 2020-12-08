#include <string>
#include <iostream>

#include "main.h"

void foo();
void bar();

int main_a[N];

int main() {
    std::cout << "N=" << N << "\n";
    std::cout << "s=" << s << "\n";
    std::cout << "&s=" << &s << "\n";
    foo();
    bar();
}
