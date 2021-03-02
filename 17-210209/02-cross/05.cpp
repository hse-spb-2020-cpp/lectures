#include <iostream>
#include <typeinfo>
#include <vector>
#include <boost/core/demangle.hpp>

// Важно, что Base полиморфный (есть хотя бы один виртуальный метод), иначе не включится RTTI.
// Тогда typeid() будет работать на этапе компиляции.
struct Base { virtual ~Base() {} };

struct Derived : Base {};

int foo() {
    std::cout << "foo()\n";
    return 10;
}

int main() {
    Base b;
    Derived d;

    // RTTI: Run-Time Type Information.
    // 1
    const std::type_info &info_base = typeid(Base);
    const std::type_info &info_derived = typeid(Derived);
    const std::type_info &info_int = typeid(int);
    // 2
    const std::type_info &info_int_expr = typeid(2 + 2 + foo());  // foo() не вызывается.
    // 3
    const std::type_info &info_b = typeid(b);
    const std::type_info &info_d = typeid(d);

    std::cout << (info_base == info_b) << "\n";
    std::cout << (info_base == info_d) << "\n";
    // std::type_index можно класть в set
    
    std::cout << info_int_expr.name() << "\n";
    std::cout << info_b.name() << "\n";
    std::cout << typeid(std::vector<int>).name() << "\n";

    std::cout << boost::core::demangle(info_int_expr.name()) << "\n";
    std::cout << boost::core::demangle(info_b.name()) << "\n";
    std::cout << boost::core::demangle(typeid(std::vector<int>).name()) << "\n";
}
