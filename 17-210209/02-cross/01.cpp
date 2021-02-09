// https://isocpp.org/wiki/faq/multiple-inheritance#mi-delegate-to-sister

struct Base {
    virtual void foo() = 0;
    virtual void bar() = 0;
};

struct Derived1 : Base {
    void foo() override {
    }
};

struct Derived2 : Base {
    void bar() override {
    }
};

struct DerivedX : Derived1, Derived2 {
    // void foo() override {  // WTF: TODO Егору посмотреть.
    // }
};

int main() {
    DerivedX *a = nullptr;
    a->foo();  // ambiguous: foo() существует в двух экземплярах
    //a->Derived1::foo();  // без виртуальности
    //a->Derived1::bar();  // без виртуальности, undefined reference.
}
