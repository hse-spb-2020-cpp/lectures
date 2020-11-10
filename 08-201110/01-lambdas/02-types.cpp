#include <iostream>
#include <string>
#include <utility>

int main() {
    std::cout << []() -> double {
        return 1;
    }() / 2 << "\n";

    auto id = [](auto x) {
        return x;
    };
    std::cout << id(1) / 2 << "\n";
    std::cout << id(1.0) / 2 << "\n";

    auto make_pair = [](auto x, auto y) {
        return std::pair(x, y);
    };
    auto p = make_pair(10, std::string("hello"));
}
