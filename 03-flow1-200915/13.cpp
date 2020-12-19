struct Foo {
    int pub_x;
    void pub_foo(Foo &g) {
        g.priv_x = 123;
        g.priv_foo();
    }

private:
    int priv_x;
    void priv_foo() {
    }
};

int main() {
    Foo f, g;
    f.pub_x = 10;
    f.pub_foo(g);
//    f.priv_x = 20;
//    f.priv_foo();
}