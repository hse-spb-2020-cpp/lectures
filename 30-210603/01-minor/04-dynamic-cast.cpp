#include <iostream>
#include <typeinfo>

struct Base {
    virtual ~Base() {}
};

struct Derived1 : Base {
};

struct Derived2 : Base {
};

int main() {
    Derived1 d1;

    const Base &b = d1;
    std::cout << &d1 << "\n";
    std::cout << &b << "\n";

    std::cout << dynamic_cast<const Derived1*>(&b) << "\n";
    std::cout << dynamic_cast<const Derived2*>(&b) << "\n";

    dynamic_cast<const Derived1&>(b);

    try {
        dynamic_cast<const Derived2&>(b);
    } catch (std::bad_cast &e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}
