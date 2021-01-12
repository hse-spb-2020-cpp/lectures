#include <vector>
#include <iostream>
#include <iterator>

template<typename T>
void print_min_element(T first, [[maybe_unused]] T last) {
    // Use in C++03, not in C++11.
    [[maybe_unused]] typename std::iterator_traits<T>::value_type cur_min = *first;  // remove_pointer<> for pointers, T::value_type otherwise: https://en.cppreference.com/w/cpp/iterator/iterator_traits
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
        print_min_element(v.begin(), v.end());
        std::cout << v[0] << "\n";
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
