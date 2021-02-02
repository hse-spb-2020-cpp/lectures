struct Base {
protected:
    void foo() {}
};

struct Derived : Base {
    void bar() {
        foo();
        this->foo();

        Derived &d = *this;
        d.foo();

        Base &b = *this;
        b.foo();

        Base b2;
        b2.foo();
    }
};

int main() {
}
