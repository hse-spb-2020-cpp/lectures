#include <iostream>

struct Base {
    virtual void foo() {};
};

struct Derived1 : Base {
//    void foo() override {}
};

struct MegaDerived1 : Derived1 {
};

struct Derived2 : Base {
//    void foo() override {}
};

void f(const Base &b) {
    // dynamic_cast работает только если Base "полиморфный".
    // Класс "полиморфный" <=> есть хотя бы одна виртуальная функция (обычно есть виртуальный деструктор).
    const Derived1 *d1 = dynamic_cast<const Derived1*>(&b);
    if (d1) std::cout << "Derived1\n";

    const MegaDerived1 *md1 = dynamic_cast<const MegaDerived1*>(&b);
    if (md1) std::cout << "MegaDerived1\n";

    const Derived2 *d2 = dynamic_cast<const Derived2*>(&b);
    if (d2) std::cout << "Derived2\n";
}

int main() {
     MegaDerived1 d1;
     Derived2 d2;
     f(d1);
     f(d2);
}
