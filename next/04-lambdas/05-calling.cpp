#include <iostream>

template<typename T, typename F>
void apply(T value, F operation) {  // STL usually copies functors.
    operation(value);
}

int main() {
    apply(10, [offset = 23](int x) { std::cout << x + offset << "\n"; });
}
