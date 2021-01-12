#include <iostream>

struct byte {
private:
    char data = 0;

    struct Proxy {
        char &data;
        int bit;

        Proxy(const Proxy&) = delete;
        Proxy(Proxy&&) = delete;

        Proxy& operator=(const Proxy &other) {  // Needed for x[1] = x[2];
            return *this = static_cast<bool>(other);
        }

        operator bool() const {  // const is important! E.g. for operator= above.
            return data & (1 << bit);
        }

        Proxy& operator=(bool new_value) {
            if (new_value) {
                data |= 1 << bit;
            } else {
                data &= ~(1 << bit);
            }
            return *this;
        }
    };

public:
    bool operator[](int bit) const {
        return data & (1 << bit);
    }

    Proxy operator[](int bit) {
        return Proxy{data, bit};
    }

    explicit operator char() const {
        return data;
    }
};

int main() {
    byte x;
    x[2] = true;
    std::cout << static_cast<int>(static_cast<char>(x)) << "\n";  // 4

    x[1] = x[2];
    std::cout << static_cast<int>(static_cast<char>(x)) << "\n";  // 6

    bool b1 = x[2];
    bool b2{x[2]};
    // bool &bref = x[2];  // Oops, cannot do that.
    // byte::Proxy bproxy = x[2];  // Proxy is private.
    if (x[2]) {}
    std::cout << x[2] << "\n";

    std::cout << "x[0]=" << x[0] << "\n";
    auto b3 = x[0];  // auto == Proxy
    // auto b4 = b3;  // auto == Proxy, copy/move are prohibited.
    // b4 = true;
    b3 = true;  // Still works :(
    std::cout << "x[0]=" << x[0] << "\n";  // WTF: x[0] == 1.
}
