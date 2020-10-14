template<typename T>
struct Foo {
    T value;

    void foo() {
        value.template foo<int>();
    }
};

// #define true false

const int INT_MAX = 10;
// #define INT_MAX 20

int main() {
}
