struct Base {
    virtual void foo() {}
    void bar() {}
};

struct Foo : Base {
    void foo() override final {}
    void bar() final {}  // Compilation error: hiding, not a virtual function.
};

struct Bar final : Foo {
    void foo() {}
};

struct Baz : Bar {
};
