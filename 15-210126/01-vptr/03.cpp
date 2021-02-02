#include <string>
#include <iostream>

struct Base;
struct BaseVtable {
    void (*bar_int_impl)(const Base*, int);
    void (*bar_string_impl)(const Base*, std::string);
};

struct Base {
    // Почему public? Пока забили.
    const BaseVtable *vtable = &BASE_VTABLE;

    void foo(int) const {}
    void foo(std::string) const {}

    void bar(int arg) const { vtable->bar_int_impl(this, arg); }
    void bar(std::string arg) const { vtable->bar_string_impl(this, arg); }

private:
    static void base_bar_int_impl(const Base *b, int) {
        std::cout << "Base::bar(int)\n";
    }

    static void base_bar_string_impl(const Base *b, std::string) {
    }

    static inline const BaseVtable BASE_VTABLE{base_bar_int_impl, base_bar_string_impl};
};

// На самом деле: struct DerivedVtable : BaseVtable, чтобы можно было добавлять новые виртуальные методы.
struct Derived : Base {
    Derived() {
        vtable = &DERIVED_VTABLE;
    }

private:
    static void derived_bar_int_impl(const Base *b, int) {
        std::cout << "Derived::bar(int)\n";
    }
    static void derived_bar_string_impl(const Base *b, std::string) {
    }

    static inline const BaseVtable DERIVED_VTABLE{derived_bar_int_impl, derived_bar_string_impl};
};

void f(const Base &b) {
    b.bar(10);
    b.bar("str");
}

int main() {
    Derived d;
    f(d);
}
