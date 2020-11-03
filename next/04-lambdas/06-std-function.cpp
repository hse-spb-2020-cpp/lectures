#include <functional>
#include <iostream>

int main() {
    auto lambda = [](int x) {
        std::cout << x << "\n";
    };
    std::cout << sizeof(lambda) << "\n";

    std::function<void(int)> f = [](int x) {
        std::cout << x << "\n";
    };
    std::cout << sizeof(f) << "\n";

    // However, recursion is tricky: works with 'f' (slow), not with 'lambda'.
    // Can use fixed point combinator, though.
}
