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
};

void f(const Base &b) {
    if (const Derived1 *d1 = dynamic_cast<const Derived1*>(&b); d1) {
        std::cout << "Derived1\n";
        // d1 видно
    }
    // d1 не видно

    if (const MegaDerived1 *md1 = dynamic_cast<const MegaDerived1*>(&b); md1) {
        std::cout << "MegaDerived1\n";
    }

    if (const Derived2 *d2 = dynamic_cast<const Derived2*>(&b); d2) {
        std::cout << "Derived2\n";
    }

    if (2 + 2 /* БЕСПОЛЕЗНЫЙ statement */; 4) {  // if with init statement (C++17)
    }
}

int main() {
     MegaDerived1 d1;
     Derived2 d2;
     f(d1);
     f(d2);
}
