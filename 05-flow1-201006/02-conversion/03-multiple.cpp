struct Foo {
};

struct Bar {
    Bar() {}
    Bar(Foo) {}
};

struct Baz {
    Baz() {}
    Baz(Bar) {}
};

int main() {
    [[maybe_unused]] Foo foo;
    [[maybe_unused]] Bar bar;
    [[maybe_unused]] Baz baz;
    baz = bar;
    baz = foo;  // Does not compile: two user conversion.
}
