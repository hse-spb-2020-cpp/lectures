#include <iostream>
#include <cstddef>
// https://isocpp.org/wiki/faq/multiple-inheritance#mi-delegate-to-sister

struct Base {
    int field = 100;
    virtual void foo() = 0;
    virtual void bar() = 0;
};

struct Derived1 : virtual Base {
    void foo() override {
    }
};

struct Derived2 : virtual Base {
    void bar() override {
    }
};

struct DerivedX : Derived1, Derived2 {
};

int main() {
    DerivedX a;
    a.foo();

    std::cout << sizeof(Base) << "\n";
    std::cout << sizeof(Derived1) << "\n";
    std::cout << sizeof(Derived2) << "\n";
    std::cout << sizeof(DerivedX) << "\n";

    std::cout << &static_cast<Base&>(a) << "\n";
    std::cout << &static_cast<Derived1&>(a) << "\n";
    std::cout << &static_cast<Derived2&>(a) << "\n";
    std::cout << &a << "\n";

    // TODO: что тут выводится?
    for (std::size_t i = 0; i < sizeof(DerivedX); i++) {
        char *ptr = reinterpret_cast<char*>(&a) + i;
        std::cout << (static_cast<int>(*ptr) & 0xFF) << " ";
        if (i % 4 == 3) {
            std::cout << "\n";
        }
    }
}
