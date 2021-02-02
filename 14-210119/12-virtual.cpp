#include <iostream>
#include <vector>

struct Base {
    // В начале добавляется vptr.
    virtual void foo() {
        std::cout << "Base::foo()\n";
    }
};

struct Derived : Base {
    void foo() override /* C++11 */ {  // override: добавить virtual, проверить, что в родителе virtual есть.
                                       // На самом деле virtual добавляется автоматически, если был в родителе.
        std::cout << "Derived::foo()\n";
    }
};

struct Derived2 : Derived {
    void foo() override /* C++11 */ {
        std::cout << "Derived2::foo()\n";
    }
};

int main() {
    std::cout << sizeof(Base) << "\n";

    Base b;
    Derived d;
    b.foo();
    d.foo();

    Base &db = d;
    db.foo();

    Derived2 d2;
    static_cast<Derived&>(d2).foo();
}
