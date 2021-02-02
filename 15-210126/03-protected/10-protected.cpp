struct Base {
private:
    void foo() {}

protected:
    void bar() {}

public:
    void baz() {}
};

struct Derived : Base {
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
