#include <iostream>
#include <vector>

struct Foo {
    int x;
    std::vector<int> y;
};

int main() {
    [[maybe_unused]] int x;  // Automatic storage duration.
                             // "На стэке".
    std::cout << "x created\n";

    for (int x = 0; x < 1; x++) {
        [[maybe_unused]] std::vector<int> v(10);
    }

    [[maybe_unused]] int data[100];
}
