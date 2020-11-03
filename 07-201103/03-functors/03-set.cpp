#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>

struct Greater {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int compare_gt(int a, int b) {
    return a > b;
}

int main() {
    std::set<int, Greater/*compare_gt*/> v{1, 2, 3, 4, 5, 6, 7, 8};
    for (int x : v) {
        std::cout << x << "\n";
    }
}
