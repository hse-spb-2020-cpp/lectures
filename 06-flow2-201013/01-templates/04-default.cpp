#include <iostream>
#include <vector>
#include <set>
#include <utility>

template<typename C = int, typename = char, typename = double, int = 10>
struct templ_foo {
};

template<typename C, C value>
struct templ_bar {
};

template<template<typename> typename Container, typename T>
struct templ_baz {
    Container<std::pair<T, T>> container;
};
/*
template<typename T, template<typename> typename Container = std::vector>
struct heap {
    Container<T> data;
};*/

int main() {
    [[maybe_unused]] templ_foo<std::vector<int>, char, bool> x;
    [[maybe_unused]] templ_foo<std::vector<int>> y;
    [[maybe_unused]] templ_foo<> z;

    [[maybe_unused]] templ_bar<int, 10> x1;
    [[maybe_unused]] templ_bar<unsigned, 4'000'000'000> y1;
    [[maybe_unused]] templ_bar<double, 4.0> z1;

    [[maybe_unused]] templ_baz<std::vector, int> x2;
    x2.container.push_back(std::pair(10, 20));

//    [[maybe_unused]] templ_baz<templ_bar, int> x3;
    [[maybe_unused]] templ_baz<templ_foo, int> x4;
}
