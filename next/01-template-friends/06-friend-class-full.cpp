template<typename T>
struct Bar;

template<typename T>
struct Foo {
private:
    int x = 0;

    friend struct Bar<T>;
};

template<typename T>
struct Bar {
    void bar() {
        Foo<T> f;
        f.x = 10;

        [[maybe_unused]] Foo<void> g;
        // g.x = 10;
    }
};

int main() {
    Bar<int>().bar();
}
