#include <cassert>

struct Base {
    virtual void foo() const = 0;  // Base::foo() - чисто виртуальный метод.
};

struct Derived : Base {
    void foo() const override {}
    // Derived::foo() - обычный виртуальный метод.
    // Derived - обычный класс, не абстрактный.
};

void foo(const Base &b) {
    b.foo();
}

// void bar(Base b) {  // Запрещено создавать объекты типа "абстрактный класс".
// }

int main() {
    Derived d;
    foo(d);
}
