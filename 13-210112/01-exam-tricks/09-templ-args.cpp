#include <vector>
#include <iostream>
#include <type_traits>
#include <iterator>

template<typename value_type, typename container_type>
void print_min_element(typename container_type<value_type>::iterator first,
                       typename container_type<value_type>::iterator last) {
   // Problem 1: no arrays.
   // Problem 2: no autodeduction. Need: print_min_element<int, std::vector>(v.begin(), v.end());
   // Problem 3:
   //     template<typename value_type, typename container_type>
   //     ---->
   //     template<typename value_type, template<typename> typename container_type>
}

int main() {
    const std::vector<int> v{1, 2, 3};
    print_min_element(v.begin(), v.end());
    std::cout << v[0] << "\n";

    int arr[]{1, 2, 3};
    print_min_element(std::begin(arr), std::end(arr));
    // C-style:
    // print_min_element(arr, arr + 3);
}
