#include <iostream>

struct Foo {
private:
    static inline int N = 10;
    static void foo() {
        N++;
    }

public:
    Foo() {
        Foo::foo();
        std::cout << "Foo()\n";
    }
};

Foo f;
int v;  // Static storage duration.

int main() {
    std::cout << "main() started\n";
}
