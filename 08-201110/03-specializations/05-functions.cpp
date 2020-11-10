#include <algorithm>
#include <iostream>

template<typename T>
void foo(const T &) {
    std::cout << "1\n";
}

template<>
void foo(const char &) {  // Not 'char', arguments should be the same.
                          // Does not participate in overload resolution, only appears
                          // when the general case is chosen by the overload resolution.
    std::cout << "2\n";
}

void foo(double) {
    std::cout << "3\n";
}

// No partial specializations for functions, unlike classes.

int main() {
    foo(10);
    foo('x');
    foo(10.0);
    foo<double>(10.0);
}
