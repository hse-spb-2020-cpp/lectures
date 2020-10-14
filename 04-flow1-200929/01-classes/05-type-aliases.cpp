// Type alias
typedef int global_baz;  // Old
using global_bar = int;  // New, C++11

struct Foo {
    typedef int bar;
    using baz = int;
    // What for? set<int>::iterator
};

void foo(global_baz&) {}

int main() {
    // All are 'int's.
    global_baz x = 10;
    [[maybe_unused]] global_bar y = x;

    Foo::bar x1 = 10;
    [[maybe_unused]] Foo::baz x2 = x1;
    foo(x1);
}
