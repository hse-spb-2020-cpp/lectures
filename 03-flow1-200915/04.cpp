#include <vector>

int main() {
//    Point p = {10, 20};
    std::vector<int> v1 = {10, 20, 30};  // C++11
    std::vector<int> v2{10, 20, 30};  // C++11
    std::vector v3{10, 20, 30};  // C++17 (CTAD, Class Template Argument Deduction)

    auto v4 = std::vector<int>{10, 20, 30};

    // Almost Always Auto
    auto v5 = std::vector{10, 20, 30};

    auto v6 = std::vector<int>{100};
    auto v7 = std::vector<int>(100);
    auto v8 = std::vector<int>(100, 20); // {20, 20, 20, 20, 20, ...}

    std::pair{10, 20.5};
    std::pair(10, 20.5);
}
