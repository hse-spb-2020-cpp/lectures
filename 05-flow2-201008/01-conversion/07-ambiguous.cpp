struct Bar;

struct Foo {
    Foo() {}
    Foo(Bar);  // Prefer this.
};

struct Bar {
    operator Foo() { return {}; }
};

Foo::Foo(Bar) {}

int main() {
    Foo f;
    Bar b;
    f = b;
}
