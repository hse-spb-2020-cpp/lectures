#include <iostream>

struct Foo {
    // C++03: safe bool idiom.
    // C++11:
    explicit operator bool() {  // if, while, for, &&, ||
        return true;
    }
};

int main() {
    Foo f;
    if (f) {
    }

//    std::cout << (10 + f) << "\n";
}
