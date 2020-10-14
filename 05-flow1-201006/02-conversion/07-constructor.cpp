struct Foo {
    explicit Foo() {}
    explicit Foo(int, double) {
    }
};

int main() {
    [[maybe_unused]] Foo f0;
    //[[maybe_unused]] Foo f1 = {};
    //[[maybe_unused]] Foo f2 = {1, 2.0};
    [[maybe_unused]] Foo f3 = Foo{};
    [[maybe_unused]] Foo f4 = Foo{1, 2.0};
    [[maybe_unused]] Foo f5 = Foo();
    [[maybe_unused]] Foo f6 = Foo(1, 2.0);
    // [[maybe_unused]] Foo f7 = static_cast<Foo>();
    // [[maybe_unused]] Foo f8 = static_cast<Foo>(1, 2.0);
}
