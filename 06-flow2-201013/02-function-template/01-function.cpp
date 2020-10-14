#include <cassert>
#include <vector>

// function template
template<typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename To, typename From>
To my_static_cast(From x) {
    return static_cast<To>(x);
}

template<template<typename> typename Container>
void foo(const Container<int> &) {
}

template<typename T>
void bar(const std::vector<T> &) {
}

template<typename C>
bool is_begin(typename C::iterator it, const C &c) {
    return c.begin() == it;
}

template<typename C>
bool is_begin2(typename C::iterator) {
    return true;
}

int main() {
    int x, y;
    swap<int>(x, y);

    // template argument deduction
    swap(x, y);  // T = int

    [[maybe_unused]] auto z = my_static_cast<int>(10.5);
    // boost::lexical_cast<int>("123");

    foo(std::vector<int>{});
    bar(std::vector<double>{});

    std::vector<int> vec;
    assert(is_begin(vec.end(), vec));

    is_begin2(vec.begin());
}
