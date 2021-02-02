#include <iostream>

struct Base {
    virtual void foo() {
        std::cout << "Base\n";
    }
};

struct Derived : Base {
    void foo() override {
        Base::foo();  // Отключили виртуальность.
        std::cout << "Derived\n";
    }
};

int main() {
    Derived d;
    d.foo();

    d.Base::foo();  // Отключили виртуальность.

    Base &b = d;
    b.foo();  // Виртуальный вызов.
    b.Base::foo();  // Невиртуальный вызов. Всегда.
}
