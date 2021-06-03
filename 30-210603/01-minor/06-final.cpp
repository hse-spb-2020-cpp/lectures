struct Base {
    virtual void foo() {
    }
    void bar() {
    }
};

struct Foo : Base {
    void foo() override final {
    }

    // Compilation error: hiding, not a virtual function.
    // void bar() final {}
};

struct Bar final : Foo {
    // void foo() {}
};

// struct Baz : Bar {
// };
