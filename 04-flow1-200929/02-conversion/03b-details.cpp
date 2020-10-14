#include <iostream>

struct Foo {
    explicit Foo(int x) {
        std::cout << "explicit " << x << "\n";
    }
};

Foo func(Foo) {
//    std::cout << "entered foo\n";
    return Foo{50};
    return Foo(50);
    return {50};
    // return 50;
}

int main() {
    [[maybe_unused]] Foo f1(10);
//    [[maybe_unused]] Foo f2 = 20;
//    f1 = 30;
    func(static_cast<Foo>(40));
    func(Foo(40));
    // func(40);
//    [[maybe_unused]] Foo f3 = {60};
    [[maybe_unused]] Foo f4{70};
    Foo{80};
    Foo(90);
}
