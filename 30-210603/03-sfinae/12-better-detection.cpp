#include <type_traits>
#include <iostream>

template<typename T>
struct MyClass {
    MyClass() {}
    MyClass(const MyClass&) {
        static_assert(std::is_same_v<T, int>);
    }
};

int main() {
    MyClass<int> a;
    MyClass<int> b = a;  // Копируется

    MyClass<double> c;
    std::cout << std::is_copy_constructible_v<MyClass<double>>;
    // MyClass<double> d = c;  // Как бы копируется (строчка выше выведет 1), но не компилируется :(
    // Для метапрограммирования полезно знать происходящее.
}
