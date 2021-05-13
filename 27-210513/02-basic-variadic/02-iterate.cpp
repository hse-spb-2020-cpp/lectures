#include <iostream>

template<typename ...Ts>
void print_all(const Ts &...args) {
    ((std::cout << args << "\n"), ...);
}

template<typename ...Ts>
void print_all2(const Ts &...args) {
    auto f = [](auto arg) {
        std::cout << arg << "\n";
    };
    (f(args), ...);
}

int main() {
    print_all(10, 12.34, "hello");
    print_all2(10, 12.34, "hello");
}
