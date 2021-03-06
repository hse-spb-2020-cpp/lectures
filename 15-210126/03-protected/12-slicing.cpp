#include <algorithm>

struct Base {
    Base() {}

protected:
    Base(const Base &) = default;
    Base(Base &&) = default;
    Base &operator=(const Base &) = default;
    Base &operator=(Base &&) = default;
};

struct Derived1 : Base {
    int value = 123;
};

struct Derived2 : Base {
    int value = 456;
};

int main() {
    Derived1 d1;
    Derived2 d2;
//    Base b = d2;

    d1.foo();

    Base &b1 = d1;
    Base &b2 = d2;
//    std::swap(b1, b2);

    Derived2 d2b = d2;
}
