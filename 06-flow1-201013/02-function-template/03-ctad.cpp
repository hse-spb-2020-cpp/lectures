// C++17: class template argument deduction (CTAD)

template<typename T>
struct Foo {
    T value;

    Foo(T value_) : value(value_) {}
};

int main() {
    [[maybe_unused]] auto x = Foo(10);
    Foo y(20);
}
