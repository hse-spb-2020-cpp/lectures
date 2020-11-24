#include "mylib.h"
#include "mylib_private.h"
#include <iostream>

struct SomeStruct {
    SomeStruct(int x) {
        std::cout << "SomeStruct(" << x << ")\n";
    }
};

// Default: external linkage.
// 'static'/'namespace {' => internal linkage.
namespace {
SomeStruct s(10);

void foo() {
    std::cout << "Boo: private foo()!\n";
}
}  // namespace

int sum(int a, int b, int c) {
    return sum(sum(a, b), c);
}
