#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>

template<typename T>
struct Greater1 {
    bool operator()(const T &a, const T &b) const {
        return a > b;
    }
};
// &std::greater<int>::operator() is defined

struct Greater2 {
    template<typename T>
    bool operator()(const T &a, const T &b) const {
        return a > b;
    }
};
// &Greater2::operator() is not defined, it's a template :(

int main() {
    std::set<int, Greater1<int>> v1{1, 2, 3, 4, 5, 6, 7, 8};
    std::set<int, Greater2> v2{1, 2, 3, 4, 5, 6, 7, 8};
    for (int x : v1) {
        std::cout << x << "\n";
    }
    std::cout << "=====\n";
    for (int x : v2) {
        std::cout << x << "\n";
    }
    std::cout << "=====\n";
}
