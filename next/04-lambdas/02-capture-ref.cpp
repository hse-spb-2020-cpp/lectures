#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

// cppinsights.io

int main() {
    int x = 10;
    std::cout << "x=" << x << "\n";
    
    auto f = [&x]() {  // or [&], 'this' is weird
        std::cout << "f(): x=" << x << "\n";
        x++;
    };

    f();
    std::cout << "x=" << x << "\n";

    f();
    std::cout << "x=" << x << "\n";
}
