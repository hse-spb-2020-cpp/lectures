#include <iostream>
#include <vector>

// class template
template<typename /*class*/ T, int V> // requires (V > 0) // C++20
struct templ_foo {
    T value{};
    // bool exists();  // the most vexing parse
    bool exists{};

    void foo(T &value) {
        value.push_back(30);
    }
};

int main() {
    [[maybe_unused]] templ_foo<int, 10> x;
    [[maybe_unused]] templ_foo<int, 10> y;
    x = y;

    templ_foo<std::vector<int>, 0> z;
    std::vector<int> vec;
    z.foo(vec);

    templ_foo<templ_foo<int, 10>, 20> zzz;
//    int my_int = 0;
//    x.foo(my_int);
}
