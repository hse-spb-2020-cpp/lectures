#include <utility>

std::pair<int, int> foo() { return {1, 2}; }

int main() {
    auto [a, b] = foo();
    // a == 1
    // b == 2
}
