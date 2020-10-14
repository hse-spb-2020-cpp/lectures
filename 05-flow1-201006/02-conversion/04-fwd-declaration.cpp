struct Bar;  // Forward declaration.

struct Foo {
    Foo(Bar)/* {
        b.x // Don't know :(
    }*/;  // Declaration (объявление).
};

struct Bar {
    Bar([[maybe_unused]] Foo f) {}
};

Foo::Foo([[maybe_unused]] Bar b) {  // Definition (определение).
}

int main() {
}
