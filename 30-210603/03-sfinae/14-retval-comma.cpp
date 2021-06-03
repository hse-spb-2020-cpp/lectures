#include <iostream>
#include <type_traits>

template<typename T>
auto print_sum(const T &a, const T &b) -> /*std::enable_if_t<std::is_same_v<int, T>, int> */ decltype(a + b, std::declval<void>()) {
    std::cout << a + b << "\n";
}

auto print_sum(...) {  // Ellipsis has very low priority.
}

int main() {
    print_sum(10, 20);
    print_sum(nullptr, nullptr);
}
