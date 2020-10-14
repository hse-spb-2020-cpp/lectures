#include <vector>
#include <iostream>

// Storage duration

struct Foo {
    std::vector<int> v;  // Automatic storage duration.
};

struct Bar {
    Bar() {
        std::cout << "Bar()\n";
    }
};

[[maybe_unused]] int y;  // Static storage duration. not default-initialized (UB),
                         //                          but value-initialiezd (0).
[[maybe_unused]] Bar b;  // Static storage duration.

int main() {
    std::cout << "main() started\n";
    [[maybe_unused]] int x;
    [[maybe_unused]] std::vector<int> v;  // Automatic storage duration.
                                          // "На стэке"
    [[maybe_unused]] int data[10'000];
    for (int &x : data) {
        x = 10;
    }
}
