#include <iostream>

double get();  // UB: return type differs from get.cpp

int main() {
    std::cout << get() << "\n";
}
