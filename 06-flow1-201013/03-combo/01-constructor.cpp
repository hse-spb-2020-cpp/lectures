#include <iostream>

template<typename T, int Value>
struct Foo {
    Foo() {}

    template<int Value2>
    Foo(const Foo<T, Value2> &) {
        std::cout << Value2 << " --> " << Value << "\n";
        [[maybe_unused]] int arr1[Value], arr2[Value2];
    }

    template<typename W>
    void foo(const W &) {
    }

    template<typename U, typename W>
    void bar(const W &) {
    }
};

int main() {
    [[maybe_unused]] Foo<int, 10> x;
    [[maybe_unused]] Foo<int, 11> y;
    [[maybe_unused]] Foo<char, 11> z;

    x = y;
//    x = z;

    x.foo(z);
    x.bar<int>(z);
}
