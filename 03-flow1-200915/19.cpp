class Ratio {
    int num = 0, denom = 1;

public:
    Ratio(int x) : num(x), denom(1) {}
    Ratio(int num_, int denom_) : num(num_), denom(denom_) {}

    friend Ratio operator+(const Ratio &a, const Ratio &b) {
        return Ratio(
            a.num * b.denom + b.num * a.denom,
            a.denom * b.denom
        );
    }
};

int main() {
    Ratio a = 10, b = 15;
    a = a + b;
//    a += b;

//    std::cout << a << "\n";
}
