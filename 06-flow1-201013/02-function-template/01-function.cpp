#include <cassert>
#include <vector>

template<typename T>
void swap(T &a, T &b) {
    T value = a;
    a = b;
    b = value;
}

template<typename T>
bool is_begin(const T &container, typename T::iterator it) {
    return container.begin() == it;
}

template<typename T>
bool is_begin2(typename T::iterator it) {
    return true;
}

template<template<typename> typename Container>
int front(Container<int> &container) {
    return *container.begin();
}

template<typename T, typename U>
void foo([[maybe_unused]] U v) {
}

template<typename T>
void bar([[maybe_unused]] std::vector<T> &vec) {
}

int main() {
    int x = 10, y = 20;
    swap<int>(x, y);

    foo<char>(x);  // T = char, U = int

    // template argument deduction
    swap(x, y);
    // auto &a = x;
    // auto &b = y;

    std::vector<int> v;
    assert(is_begin(v, v.begin()));
    assert(is_begin(v, v.end()));

//    assert(is_begin2(v.end()));

    v = {10, 20};
    assert(front(v) == 10);
    bar(v);
}
