typedef int global_baz;
using global_bar = int;

struct Foo {
    typedef int baz;
    using bar = int;
};

int main() {
    global_baz x = 10;
    [[maybe_unused]] global_bar y = x;

    Foo::baz x1 = 10;
    [[maybe_unused]] Foo::bar y1 = x1;

    [[maybe_unused]] global_baz &z = x1;
}
