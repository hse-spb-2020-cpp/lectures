#include <iostream>
#include <type_traits>

struct Foo {
    void foo() {}
};

struct Bar {
};

namespace detect_foo {
// What if 'const T &'?
template<typename T>
std::true_type impl(T &x, decltype(x.foo())*);

std::false_type impl(...);

template<typename T>
constexpr bool has_foo = decltype(impl(std::declval<T&>(), nullptr))::value;
};

int main() {
    std::cout << detect_foo::has_foo<Foo> << "\n";
    std::cout << detect_foo::has_foo<Bar> << "\n";
}
