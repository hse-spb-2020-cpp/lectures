#include <string>
#include <iostream>

struct BigInt {
    int x;
};

BigInt operator""_BIGINT(const char *str) {
    std::string cpp_str = str;
    return {static_cast<int>(cpp_str.size())};
}

int main() {
    BigInt bigint = 45874326587876432587843875_BIGINT;
    std::cout << bigint.x << "\n";
}
