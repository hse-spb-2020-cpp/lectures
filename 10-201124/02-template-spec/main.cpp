#include "print.h"
#include <iostream>

template<>
void print(const int &value) {
    std::cout << "mwahaha " << value << "\n";
}

void foo();

int main() {
    print(1);
    print(1.23);
    foo();
}
