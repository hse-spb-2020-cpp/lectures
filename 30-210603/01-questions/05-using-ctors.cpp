#include <exception>
#include <iostream>

struct Foo {
    Foo(int) {}
    Foo(double) {}
};

struct Bar : Foo {
};

struct MyError : std::runtime_error {
};

int main() {
    Foo(10);
    Foo(10.0);
    std::runtime_error("hello world");

    Bar(10);
    Bar(10.0);
    MyError("hello world");
}
