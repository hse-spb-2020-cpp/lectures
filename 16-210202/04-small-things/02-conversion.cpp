template<typename T>
struct Base {
    int x;
};

template<typename T>
struct Derived1 : Base<T> {
};

template<typename T>
struct Derived2 {
    Base<T> b;

    operator Base<T>&() { return b; }
};

template<typename T>
void foo(Base<T> &) {
}

int main() {
    Derived1<int> d1;
    foo(d1);

    Derived2<int> d2;
    foo<int>(d2);
}
