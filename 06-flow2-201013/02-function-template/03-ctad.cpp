// C++17: class template argument deduction (CTAD)

template<typename T>
struct Foo {
    T value;

    Foo() {}
    Foo(T value_) : value(value_) {}
    // Foo(typename T::iterator value_) : value(value_) {}
};

int main() {
    [[maybe_unused]] auto x = Foo(10);
    Foo y(20);

    Foo<int> z;
    // Since C++17: std::pair(10, 20); {10, 20}
    // Before C++17: std::make_pair(10, 20); // function call
}
