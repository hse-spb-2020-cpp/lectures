/*
struct BigInt {
    BigInt operator++(int) {
       BigInt old = *thisl
       ++*this;
       return old;
    }

    BigInt& operator++() {
       // ....
    }

private:
    vector<int> digits_;
};
*/

struct Bar;  // Forward-declaration (объявление)

struct Foo { // Definition (Определение)
    Foo(Bar x);  // Declaration
};

struct Bar {  // Definition (Определение)
    Bar(Foo) {}
};

Foo::Foo([[maybe_unused]] Bar x) {  // Definition
}

int main() {
//    int ((x)) {};
}
