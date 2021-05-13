#include <iostream>
#include <type_traits>

template<typename ...Ts>
void print_all(const Ts &...args) {
    ((std::cout << args << "\n"), ...);
}

template<typename ...Ts>
void print_all_increased(const Ts &...args) {
    static_assert((... && std::is_same_v<Ts, int>));
    print_all(">", args..., "<", (args + 10)..., "!");
}

int main() {
    print_all_increased(1, 2, 3);
    print_all_increased(1, 2, 3.0);
}
