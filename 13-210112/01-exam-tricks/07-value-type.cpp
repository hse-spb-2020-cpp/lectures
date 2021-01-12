#include <vector>
#include <iostream>

template<typename T>
void print_min_element(T first, [[maybe_unused]] T last) {
    // Works in C++03, badly.
    [[maybe_unused]] typename T::value_type cur_min = *first;  // Fails for arrays, may fail for vector<> as well.
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
        // print_min_element(std::begin(v), std::end(v));  // FIXME: array's iterator is 'int*', it does not have 'value_type'.
        // std::cout << v[0] << "\n";
    }

    {
        int v[]{1, 2, 3};
        // print_min_element(v, v + 3);  // C-style.  // FIXME: array's iterator is 'int*', it does not have 'value_type'.
        // std::cout << v[0] << "\n";
    }
}
