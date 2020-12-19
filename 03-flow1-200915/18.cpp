struct Ratio {
    int num = 0, denom = 1;

    Ratio(int x) : num(x), denom(1) {}

    Ratio& operator/=(const Ratio &other) {
        num *= other.denom;
        denom *= other.num;
        return *this;
    }

    bool operator<(const Ratio &other) { return false; }
    bool operator<=(const Ratio &other) { return false; }
    bool operator>(const Ratio &other) { return false; }
    bool operator>=(const Ratio &other) { return false; }
    bool operator==(const Ratio &other) { return false; }
    bool operator!=(const Ratio &other) { return false; }

    Ratio& operator++() {  // prefix
        num += denom;
        return *this;
    }
    Ratio operator++(int) {  // postfix
        Ratio old = *this;
        ++*this;
        return old;
    }
};

int main() {
    Ratio a = 10, b = 15;
    a /= b;           // this == &a, other == b
    a.operator/=(b);  // this == &a, other == b

    ++a;
    a++;
//    std::cout << a << "\n";
}
