struct Bar;  // Forward declaration.

struct Foo {
    Foo() {}
    Foo(Bar);  // Declaration (объявление).
               // Bar --> Foo.
};

struct Bar {
    operator Foo() { return {}; }  // Bar --> Foo.
};

Foo::Foo([[maybe_unused]] Bar b) {  // Definition (определение).
}

int main() {
    Foo f;
    Bar b;
    f = b;
}
