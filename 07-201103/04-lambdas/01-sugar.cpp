#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

int main() {
    auto f = [](int a, int b) { return a > b; };
    [[maybe_unused]] bool (*fptr)(int, int) = [](int a, int b) { return a > b; };  // Implicit cast operator.

    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    for (int x : v) {
        std::cout << x << "\n";
    }
    std::cout << "=====\n";

    std::set<int, decltype(f)> s({1, 2, 3, 4, 5, 6, 7, 8}, f);  // decltype([](){}) won't work: distinct types.
    for (int x : s) {
        std::cout << x << "\n";
    }
}
