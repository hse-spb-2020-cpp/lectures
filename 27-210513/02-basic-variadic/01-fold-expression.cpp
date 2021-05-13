#include <iostream>

template<typename ...Ts>  // Parameter pack
void print_all(const Ts &...value) {
    (std::cout << ... << value);  // C++17: fold expression: std::cout << v1 << v2 << v3;
}

template<typename ...Ts>
auto sum_all(const Ts &...value) {
    return (10 + ... + value);  // Скобки важны: fold expression должен быть отдельным выражением.
    // return (value + ... + 10);
}

template<typename ...Ts>
auto sum_all2(const Ts &...value) {
    return (... + value);  // Не требует левого/правого значения
}

int main() {
    print_all(10, 10.23);
    std::cout << "\n" << sum_all(1, 2, 3) << "\n";
    std::cout << "\n" << sum_all2(1, 2, 3) << "\n";
    // std::cout << "\n" << sum_all2() << "\n";
}

// pass types to another template
// pass arguments to another function
// int... Xs; auto... Ys
// sizeof...
// recursively parse
//
// initialize dummy array
