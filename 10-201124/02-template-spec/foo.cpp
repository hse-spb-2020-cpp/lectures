#include "print.h"

template<>
void print(const int &value) {
    std::cout << "foo " << value << "\n";
}

void foo() {
    print(2);
    print(2.3);
}
