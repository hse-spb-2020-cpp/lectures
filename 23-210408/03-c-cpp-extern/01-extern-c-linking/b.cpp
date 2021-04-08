#include <vector>
#include <cstdio>
#include <iostream>

extern "C" int foo();  // Disable name mangling, and link like C.

int foo(int x) {  // OK
    return x + 1;
}

namespace a {
// extern "C" int foo(int);  // Warning: same as foo(), but different set of arguments. It's ok in C, though (e.g. printf).
}

struct Foo {
    Foo() {
        std::printf("Foo\n");
    }
    ~Foo() {
        std::printf("~Foo\n");
    }
} f;

extern "C" int my_main() {
    std::vector<int> v;
    std::cout << foo() << "\n";
    std::cout << foo(100) << "\n";
    return 0;
}
