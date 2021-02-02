#include <iostream>

struct Base {
    void foo() {
        std::cout << "Base\n";
    }
};

struct Derived : Base {
    void foo() {
        Base::foo();
        std::cout << "Derived\n";
    }
};

int main() {
    Derived d;
    d.foo();

    d.Base::foo();
}
