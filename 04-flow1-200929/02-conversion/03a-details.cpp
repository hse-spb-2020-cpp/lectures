#include <iostream>

struct Foo {
    Foo(int x) {
        std::cout << "implicit " << x << "\n";
    }
};

Foo func(Foo) {
    std::cout << "entered foo\n";
    return 50;
}

int main() {
    [[maybe_unused]] Foo f1(10);
    [[maybe_unused]] Foo f2 = 20;
    f2 = 30;
    func(40);
    [[maybe_unused]] Foo f3 = {60};
    [[maybe_unused]] Foo f4{70};
    Foo{80};
    Foo(90);
}
