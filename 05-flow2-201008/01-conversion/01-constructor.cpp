#include <cassert>
#include <iostream>

struct BigInt {
    BigInt([[maybe_unused]] int x) {
    }
};

void foo(BigInt) {
}

BigInt bar() {
    return 40;
}

//BigInt operator+(const BigInt &a, const BigInt &b) {
//}

int main() {
    BigInt x = 10;
    x = 20;
    foo(30);

//    BigInt(30) + x;

    [[maybe_unused]] int y = 50.5;
}
