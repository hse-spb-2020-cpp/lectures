#include <vector>
#include <cstdio>
//#include <iostream>

extern "C" int foo();

struct Foo {
    Foo() {
        std::printf("Foo\n");
    }
    ~Foo() {
        std::printf("~Foo\n");
    }
} fo;

extern "C" int my_main() {
//    std::vector<int> v;
//    std::cout << foo() << "\n";
}
