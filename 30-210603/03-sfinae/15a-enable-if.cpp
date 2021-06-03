#include <iostream>
#include <type_traits>

template<bool Cond, typename T>
struct enable_if {};

template<typename T>
struct enable_if<true, T> { using type = T; };

template<bool Cond, typename T>
using enable_if_t = typename enable_if<Cond, T>::type;

template<typename T>
//enable_if_t<std::is_same_v<T, int>, int> foo(T) {  // Можно записать и просто возвращаемый тип.
auto foo(T) -> enable_if_t<std::is_same_v<T, int>, int> {

    static_assert(std::is_same_v<T, int>);
    return 10;
}

int foo(long double) {
    return 20;
}

int main() {
    int x;
    std::cout << foo(x) << "\n";  // Выбирается первая перегрузка, она идеально подходит.

    double y;
    std::cout << foo(y) << "\n";  // Первая перегрузка вырезана по SFINAE, осталась только вторая.
}
