#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>

struct CloserTo {
    int center;

    bool operator()(int a, int b) const {
        return std::abs(a - center) < std::abs(b - center);
    }
};

int main() {
    std::set<int, CloserTo> v1({1, 2, 3, 4, 5, 6, 7, 8}, CloserTo{3});
    std::set<int, CloserTo> v2({1, 2, 3, 4, 5, 6, 7, 8}, CloserTo{7});
    for (int x : v1) {
        std::cout << x << "\n";
    }
    std::cout << "=====\n";
    for (int x : v2) {
        std::cout << x << "\n";
    }
    std::cout << "=====\n";

    v1 = v2;
    // v1.assign(v2.begin(), v2.end());
    // v1 = set(v2.begin(), v2.end(), CloserTo{...});
    for (int x : v1) {
        std::cout << x << "\n";
    }
}
