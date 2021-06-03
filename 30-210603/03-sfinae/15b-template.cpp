#include <iostream>
#include <type_traits>

template<typename T>
struct MyClass {
    template<typename U = T>  // Если написать сразу T, то будет hard ошибка компиляции.
    std::enable_if_t<std::is_same_v<U, int>, int> foo() {
        static_assert(std::is_same_v<T, int>);
        return 10;
    }
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
