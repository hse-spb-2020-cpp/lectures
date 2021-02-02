struct Foo {
protected:
    void magic() {}
};

struct Bar : Foo {
private:
    using Foo::magic;
};

struct Baz : Bar {
    void magic2() {
        // magic();
        Foo::magic();
    }
};

int main() {
    Bar b;
    b.magic();
}
