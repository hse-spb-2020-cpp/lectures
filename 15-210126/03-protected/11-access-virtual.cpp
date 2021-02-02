struct Base {
private:
    virtual void foo() {}  // Пример: printTo()

protected:
    virtual void bar() {}

public:
    virtual void baz() {}
};

struct Derived : Base {
    void foo() override {}
    void bar() override {}
    void baz() override {}

    void der() {
        // foo();
        bar();
        baz();
    }
};

int main() {
    Derived d;
    // d.foo();
    // d.bar();
    d.baz();
}
