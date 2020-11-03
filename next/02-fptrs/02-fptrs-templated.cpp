#include <iostream>

template<typename T>
void apply(void (*operation)(T /*const&*/ value), T data) {
    std::cout << "calling with " << data << "\n";
    operation(data);
}

void print(int x) {
    std::cout << x << "\n";
}

void print_twice(int x) {
    std::cout << x << ", " << x << "\n";
}

int main() {
    //auto ptr = print;
    void (*ptr)(int) = print;
    apply(ptr, 10);

    ptr = print_twice;
    apply(ptr, 10);
}
