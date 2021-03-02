#include <iostream>

// 17-210209/02-cross/01.cpp

struct Base1 {
    virtual void foo() {
        std::cout << "Base1\n";
    }
};

struct Base2 {
    virtual void foo() {
        std::cout << "Base2\n";
    }
};

struct DerivedSimple : Base1, Base2 {
};

struct DerivedOverride : Base1, Base2 {
    void foo() override {  // Действительно, перезаписывает оба метода.
                           // Возвращаемое значение должно быть совместимым (точное определение не разбирали).
        std::cout << "DerivedOverride\n";
    }
};

int main() {
    {
        std::cout << "===== DerivedSimple =====\n";
        DerivedSimple ds;
        ds.Base1::foo();
        ds.Base2::foo();
        static_cast<Base1&>(ds).foo();
        static_cast<Base2&>(ds).foo();
        // ds.foo();
    }
    {
        std::cout << "===== DerivedOverride =====\n";
        DerivedOverride dorr;
        dorr.Base1::foo();
        dorr.Base2::foo();
        static_cast<Base1&>(dorr).foo();
        static_cast<Base2&>(dorr).foo();
        dorr.foo();
    }
}
