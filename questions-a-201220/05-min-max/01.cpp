#include <iostream>

template<typename T>
const T& min(const T &a, const T &b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int foo() {
    return 4;
}

int bar() {
    return 5;
}

int main() {
    const int &x = foo();
    std::cout << x << "\n";  // OK.

    const int x1 = min(foo(), bar());
    std::cout << x1 << "\n";  // OK.

    const int &y = min(foo(), bar());
    // y is dandling reference!
    std::cout << y << "\n";  // UB.
}
