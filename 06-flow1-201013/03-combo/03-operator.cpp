#include <cassert>
#include <iostream>

template<typename T, int N>
struct Foo {
};

template<typename T, int N1, int N2>
void bar(const Foo<T, N1> &, const Foo<T, N2> &) {
}

template<typename T, int N1, int N2>
bool operator==(const Foo<T, N1> &, const Foo<T, N2> &) {
    return true;
}

int main() {
    Foo<int, 10> x;
    Foo<int, 20> y;
    [[maybe_unused]] Foo<char, 20> z;
    bar(x, y);
    // bar(x, z);

    assert(x == y);
}
