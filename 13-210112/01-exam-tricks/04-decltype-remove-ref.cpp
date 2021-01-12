#include <vector>
#include <iostream>
#include <type_traits>

template<typename T>
void print_min_element(T first, [[maybe_unused]] T last) {
    // Please don't.
    [[maybe_unused]] std::remove_reference_t<decltype(*first)> cur_min = *first;
    cur_min = 100;
}

int main() {
    {
        std::vector<int> v{1, 2, 3};
        print_min_element(v.begin(), v.end());
        std::cout << v[0] << "\n";
    }

    {
        const std::vector<int> v{1, 2, 3};
        // print_min_element(v.begin(), v.end());  // FIXME: *first returns 'const T&', so `cur_min` is `const`.
        // std::cout << v[0] << "\n";
    }

    {
        int v[]{1, 2, 3};
        print_min_element(std::begin(v), std::end(v));
        std::cout << v[0] << "\n";
    }

    {
        int v[]{1, 2, 3};
        print_min_element(v, v + 3);  // C-style.
        std::cout << v[0] << "\n";
    }
}
