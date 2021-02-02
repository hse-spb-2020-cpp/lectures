#include <iostream>
#include <vector>

struct Base {
    void foo() {
        std::cout << "Base::foo()\n";
    }
};

struct Derived : Base {
    void foo() {
        std::cout << "Derived::foo()\n";
    }
};

int main() {
    Base b;
    Derived d;
    b.foo();
    d.foo();

    Base &db = d;
    db.foo();
}
