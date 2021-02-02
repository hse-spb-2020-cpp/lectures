#include <algorithm>

struct Base {
    Base() {}

protected:
    Base(const Base &) = default;
    Base(Base &&) = default;
    Base &operator=(const Base &) = default;
    Base &operator=(Base &&) = default;
};

struct MegaDerived1;

struct Derived1 : Base {
    int value = 123;

    Derived1(const Derived1 &) = default;
    Derived1(const MegaDerived1 &) = delete;  // Костыль, надо явно перечислять всех наследников. Как лучше?
};

struct MegaDerived1 : Derived1 {
    int value2 = 10000;
};

struct Derived2 : Base {
    int value = 456;
};

int main() {
    MegaDerived1 md1;
    Derived1 d1 = md1;
}
