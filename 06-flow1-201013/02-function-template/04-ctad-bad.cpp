#include <vector>
// C++17: class template argument deduction (CTAD)

template<typename T>
struct Foo {
    typename T::iterator value;

    Foo(typename T::iterator value_) : value(value_) {}
};

int main() {
    std::vector<int> v;
    [[maybe_unused]] auto x = Foo<std::vector<int>>(v.begin());
}
