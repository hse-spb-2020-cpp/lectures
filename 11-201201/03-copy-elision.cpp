#include <cstddef>
#include <iostream>
#include <utility>

struct Foo {
    Foo() {
        std::cout << "Foo()\n";
    }

    Foo(const Foo &) {
        std::cout << "Foo(const Foo&)\n";
    }

    Foo(Foo &&) {
        std::cout << "Foo(Foo&&)\n";
    }

    Foo& operator=(const Foo &) {
        std::cout << "operator=(const Foo&)\n";
        return *this;
    }

    Foo& operator=(Foo &&) {
        std::cout << "operator=(Foo&&)\n";
        return *this;
    }

    void do_something() {
    }
};

Foo foo() {
    // Return Value Optimization (RVO).
    std::cout << "hello\n";
    return /* prvalue */ Foo{};
}

Foo bar() {
    // Named Return Value Optimization (NRVO).
    Foo a;
    a.do_something();
    std::cout << "world: " << &a << "\n";
    return a;
}

Foo baz() {
    // Named Return Value Optimization (NRVO) fail.
    Foo a, b;
    if (true) {  // rand()?
       return a;
    } else {
       return b;
    }
}

Foo global_var;
Foo que() {
    return global_var;
}

Foo que2() {
    return std::move(global_var);
}

Foo copy_foo(Foo f) {
    std::cout << "copy_foo\n";
    return f;
}

Foo&& pass_foo(Foo &&f) {
    std::cout << "pass_foo\n";
    return std::move(/* lvalue */ f);
}

int main() {
    Foo a = /* prvalue */ Foo(/* prvalue */ Foo(/* prvalue */ Foo()));
    Foo b = /* prvalue */ foo();
    Foo c = /* prvalue */ bar();
    std::cout << "&c == " << &c << "\n";
    Foo d = baz();
    Foo e = que();
    Foo e2 = que2();

    // C++17: guaranteed copy elision.
    // prvalue - это теперь не "временный объект без имени", а "инструкция по его созданию".
    // 'return <локальная переменная>' по значению -- тоже оптимизируется
    // prvalue автоматически превращается в xvalue (temporary materialization), когда:
    //    берём на него ссылку
    //    спрашиваем поле
    std::cout << "before copy_foo\n";
    Foo f1 = /* prvalue, проинициализирует f1 конструктором перемещения */ copy_foo(/* prvalue, проинициализирует по значению аргумент Foo f */ Foo());
    std::cout << "before pass_foo\n";
    Foo f2 = /* xvalue, вызовется конструктор перемещения от него */ pass_foo(/* prvalue, материализуется для инициализации аргумента-ссылки Foo &&f */ Foo());
}
