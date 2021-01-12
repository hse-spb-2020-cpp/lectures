#include <vector>
#include <iostream>

template<typename T>
void print_min_element(T first, [[maybe_unused]] T last) {
    // Please don't.
    [[maybe_unused]] decltype(*first) cur_min = *first;  // FIXME: '*first' is a reference, so cur_min is a reference as well: https://en.cppreference.com/w/cpp/language/decltype
    cur_min = 100;
}

int main() {
    {
        std::vector<int> v{1, 2, 3};
        print_min_element(v.begin(), v.end());
        std::cout << v[0] << "\n";  // WTF: 100, not 1.
    }

    {
        const std::vector<int> v{1, 2, 3};
        // print_min_element(v.begin(), v.end());  // FIXME: *first returns 'const T&' for const vector
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
