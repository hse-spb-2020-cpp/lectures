#include <algorithm>
#include <iostream>

namespace my_secret {
struct Basic {};
}

namespace std {
// void swap(my_secret&, my_secret&) {  // UB, overload.
template<> void swap(my_secret::Basic&, my_secret::Basic&) {  // Not UB, specialization.
    std::cout << "swap(Basic)\n";
}
};

namespace my_secret {
template<typename T>
struct Foo {};

template<typename T>
void swap(Foo<T> &, Foo<T> &) {
    std::cout << "swap(Foo<T>)\n";
}
};

int main() {
    {
        my_secret::Basic a, b;
        std::swap(a, b);  // OK swap.

        using std::swap;
        swap(a, b);  // OK swap
    }
    {
        my_secret::Foo<int> a, b;
        std::swap(a, b);  // Wrong swap.

        using std::swap;  // Optional, but is used for general case.
        swap(a, b);  // OK swap, ADL.
    }
}
