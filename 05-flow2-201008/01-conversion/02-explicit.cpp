#include <string>

struct BigInt {
    explicit BigInt(std::string) {}
};

void foo(int) {}
void foo(double) {}
void foo(BigInt) {}

void bar(std::string) {}

BigInt baz() {
    return BigInt("1234");
}

int main() {
    double x = 10.0;
    foo(x);
    foo(static_cast<int>(x));

    std::string y = "1234hello";

//    foo(y);
    foo(static_cast<BigInt>(y));
    foo(BigInt(y));
    foo(BigInt{y});

    BigInt z1(y);
    BigInt z2{y};
//    z1 = y;
    // copy *** initialization
//    BigInt z3 = y;  // copy initialization?
//    BigInt z4 = {y};  // copy list initialization
}
