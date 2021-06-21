union Union {
    std::vector<int> a;
    std::string b;
};

union UnionAlsoBad {
    std::vector<int> a;
    int b;
};

int main() {
    Union x;
    x.a.clear();  // UB
    x.a = std::vector<int>{};  // UB

    new (&x.a) std::vector<int>();
    x.a.clear();  // OK
    x.b;  // UB.
    x.a.~std::vector<int>();

    x.b = "";  // UB
    new (&x.b) std::string();
    x.b = "";  // OK
    x.b.~std::string();
}
// Можно написать безопасную обёртку, получим std::variant<>
