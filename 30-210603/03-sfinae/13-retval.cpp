#include <iostream>
#include <type_traits>

template<typename T>
auto add(const T &a, const T &b) -> /*std::enable_if_t<std::is_same_v<int, T>, int> */ decltype(a + b) {
    return a + b;
}

auto add(...) {  // Ellipsis has very low priority.
    return 239;
}

int main() {
    std::cout << add(10, 20) << "\n";
    std::cout << add(nullptr, nullptr) << "\n";
}
