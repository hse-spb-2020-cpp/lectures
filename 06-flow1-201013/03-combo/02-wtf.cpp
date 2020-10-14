template<typename T>
struct Foo {
    T value;

    void foo() {
        value.template foo<int>();
    }
};

int main() {
}
