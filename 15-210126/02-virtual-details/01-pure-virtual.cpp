#include <cassert>

struct Base {
    virtual void foo() const = 0;  // Base::foo() - чисто виртуальный метод.
};

struct Derived : Base {
//    void foo() override {}
    // Так как foo() нет, то Derived::foo() - чисто виртуальный метод.
    // Следствие: Derived - "абстрактный класс".
};

void foo(const Base &b) {
    b.foo();
}

int main() {
    Derived d;  // Запрещено создавать абстрактные классы.
    foo(d);
}
