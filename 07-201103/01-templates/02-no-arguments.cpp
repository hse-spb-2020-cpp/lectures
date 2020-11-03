template<typename> struct Templ1 {};
template<template<typename ArgOfArg>typename Arg> struct Templ2 {
    Arg</*ArgOfArg=*/int> x;
};

template<typename T>
struct Foo {
    // Foo ~ Foo<T>
    void foo(Foo/*<T>*/ &, Foo<char> &) {
    }

    void bar(Foo&);

    Foo baz1() {
        return {};
    }

    Foo baz2();

    void botva() {
        [[maybe_unused]] Templ1<Foo> x;
        [[maybe_unused]] Templ2<Foo> y;
    }
};

template<typename T>
void Foo<T>::bar(Foo &) {
}

template<typename T>
//Foo<T> Foo<T>::baz2() {
auto Foo<T>::baz2() -> Foo {
    return {};
} 

int main() {
    Foo<int> x, y;
    Foo<char> z;
    x.foo(y, z);

    x.bar(y);

    x.baz1();

    x.botva();
}
