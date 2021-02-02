#include <string>

//enum KindOfBase { BASE, DERIVED };

struct Base {
    //KindOfBase kind = BASE;

    void foo(int) const {}
    void foo(std::string) const {}

    virtual void bar(int) const {}
    virtual void bar(std::string) const {}
};

struct Derived : Base {
    Derived() : kind(DERIVED) {}
    void bar(int) const override {}
    void bar(std::string) const override {}
};

void f(const Base &b) {
    b.bar(10);
    // if (b.kind == BASE) b.bar(10);
    // else if (b.kind == DERIVED) static_cast<const Derived&>(b).bar(10);
    // else ........

    b.bar("str");
}

int main() {
    Derived d;
    f(d);
}
