#include <cassert>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <sstream>

int read_int(const char *s) {
    int value = 0;
    for (std::size_t i = 0; i < std::strlen(s); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            value = value * 10 + s[i] - '0';
        } else {
            break;
        }
    }
    return value;
}

int main() {
    static char str[10'000'000];
    for (std::size_t i = 0; i < sizeof(str); i++)
        str[i] = '0' + i % 10;
    str[sizeof(str) - 1] = 0;

    str[5] = ' ';
    str[10] = ' ';
    std::cout << read_int(str) << "\n";
    for (int i = 0; i < 100'000; i++) {
        assert(read_int(str) == 1234);
    }
}
