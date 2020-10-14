#include <cassert>
#include <iostream>

template<typename T, int N>
struct Foo {
/*    template<int N2>
    bool operator==(const Foo<T, N2>&) {
        return true;
    }*/
};

template<typename T, int N1, int N2>
bool operator==(const Foo<T, N1>&, const Foo<T, N2>&) {
    return true;
}

int main() {
    Foo<int, 10> x;
    Foo<int, 11> y;
    assert(x == y);
}
