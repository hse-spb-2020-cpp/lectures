#include <iostream>
#include <vector>

template<typename C>
void printAll(const C &container) {
    for (const auto &item : container) {
        std::cout << item << "\n";
    }
}

void printAll2(const auto &container) {
    for (const auto &item : container) {
        std::cout << item << "\n";
    }
}

template<typename U, typename V>
bool operator==(const U &, const V &) {  // operator==(const auto &, const auto &)
    return true;
}

int main() {
    printAll(std::vector{10, 20, 30});
    printAll2(std::vector{10, 20, 30});
}
