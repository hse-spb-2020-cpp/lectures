#include <vector>

template<typename T>
void print_min_element(T first, [[maybe_unused]] T last) {
    [[maybe_unused]] T *cur_min = *first;
}

int main() {
    std::vector<int> v{1, 2, 3};
    print_min_element(v.begin(), v.end());
}
