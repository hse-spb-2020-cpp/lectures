#include <iostream>

struct Base {
    virtual void foo() = 0;
};

struct Derived : Base {
    void foo() override {
        Base::foo();  // Link error.
        std::cout << "Derived\n";
    }
};

int main() {
    Derived d;
    d.foo();

    d.Base::foo();  // Link error.
}
