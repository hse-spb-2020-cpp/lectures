#include <iostream>
#include <iterator>
#include <cstddef>

// void foo(int arr[]) {  // То же самое, что int *arr
// void foo(int arr[5]) {  // То же самое, что int *arr
void foo(int arr[15]) {  // То же самое, что int *arr
    std::cout << arr[0] << "\n";
    std::cout << sizeof(arr) << "\n";
}

void foo_good(int arr[], int arr_len) {
    std::cout << arr[0] << " " << arr_len << "\n";
}

void foo_cpp_wtf(int (&arr)[10]) {  // C++-only, ok
// void foo_cpp_wtf(int (&arr)[5]) {  // C++-only, compilation error
// void foo_cpp_wtf(int (&arr)[15]) {  // C++-only, compilation error
}

template<std::size_t N>
void foo_cpp_templ(int (&arr)[N]) {
    std::cout << "N=" << N << "\n";
}

int main() {
    int arr[10]{1, 2, 3};
    foo(arr);
    foo_good(arr, sizeof arr / sizeof arr[0]);  // C style.
    foo_cpp_wtf(arr);
    foo_cpp_templ(arr);
}
