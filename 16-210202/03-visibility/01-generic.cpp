struct Base {
    void foo() {}
};

struct Derived1 : public Base {};  // По умолчанию для struct Derived1; обычно используется оно.
struct Derived2 : protected Base {};
struct Derived3 : private Base {};  // По умолчанию для class Derived 3.

struct Derived22 : Derived2 {
    void bar() {
        Derived2 d2;
        const Base &b2 = d2;
    }
};

int main() {
    Derived1 d1;
    Derived2 d2;
    Derived3 d3;

    d1.foo();
    // d2.foo();
    // d2.Base::foo();

    const Base &b1 = d1;
    const Base &b2 = d2;
}
