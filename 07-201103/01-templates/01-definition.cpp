template<typename T>
struct Foo {
    void foo();

    static int static_field;
};

template<typename T>
void Foo<T>::foo() {
}

template<typename T>
int Foo<T>::static_field = 10;

int main() {
    Foo<int> x;
    x.foo();

    Foo<char>::static_field = 10;
}
