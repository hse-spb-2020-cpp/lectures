#include <iostream>
#include <type_traits>

template<typename T>
struct MyClass {
    template<typename U = T, typename /* X */ = std::enable_if_t<std::is_same_v<U, int>>>
    int foo() {
        static_assert(std::is_same_v<T, int>);
        return 10;
    }
    #if 0  // Две перегрузки с разным условием в значении по умолчанию нельзя. Это не считается разными функциями.
    template<typename U = T, typename = std::enable_if_t<std::is_same_v<U, double>>>
    int foo() {
        static_assert(std::is_same_v<T, int>);
        return 10;
    }
    #endif
    int foo() const {
        return 20;
    }
};

int main() {
    {
        MyClass<int> a;
        std::cout << a.foo() << "\n";  // 10

        const auto &b = a;
        std::cout << b.foo() << "\n";  // 20
    }
    {
        MyClass<double> a;
        std::cout << a.foo() << "\n";  // 20

        const auto &b = a;
        std::cout << b.foo() << "\n";  // 20
    }
}
