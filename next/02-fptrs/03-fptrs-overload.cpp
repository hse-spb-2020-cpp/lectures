#include <iostream>

template<typename T>
void apply(void (*operation)(T /*const&*/ value), T data) {
    std::cout << "calling with " << data << "\n";
    operation(data);
}

void print(int x) {
    std::cout << x << "\n";
}

void print(double x) {
    std::cout << "double=" << x << "\n";
}

void print_twice(int x) {
    std::cout << x << ", " << x << "\n";
}

int main() {
    apply(print, 10);
    apply(print_twice, 10);

    auto ptr = static_cast<void(*)(int)>(print);
    apply(ptr, 10);
}
