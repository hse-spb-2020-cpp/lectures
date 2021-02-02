#include <string>
#include <iostream>

struct Base {
    // Почему public? Пока забили.
    void (*bar_int_impl)(const Base*, int) = base_bar_int_impl;
    void (*bar_string_impl)(const Base*, std::string) = base_bar_string_impl;

    void foo(int) const {}
    void foo(std::string) const {}

    void bar(int arg) const { bar_int_impl(this, arg); }
    void bar(std::string arg) const { bar_string_impl(this, arg); }

private:
    static void base_bar_int_impl(const Base *b, int) {
        std::cout << "Base::bar(int)\n";
    }

    static void base_bar_string_impl(const Base *b, std::string) {
    }
};

struct Derived : Base {
    Derived() {
        // bar(10);  // base_int_impl(10)
        bar_int_impl = derived_bar_int_impl;
        bar_string_impl = derived_bar_string_impl;
    }

private:
    static void derived_bar_int_impl(const Base *b, int) {
        std::cout << "Derived::bar(int)\n";
    }
    static void derived_bar_string_impl(const Base *b, std::string) {
    }
};

void f(const Base &b) {
    b.bar(10);
    b.bar("str");
}

int main() {
    Derived d;
    f(d);
}
