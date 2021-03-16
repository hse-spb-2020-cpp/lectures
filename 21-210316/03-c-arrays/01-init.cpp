#include <cassert>
#include <iterator>
#include <iostream>

int main() {
    int a1[10];
    int a2[10] = {};  // default-initialize всех элементов: 0.
    int a3[10]{};
    int a4[10] = {1, 2, 3};  // default-initialize всех элементов (кроме первых, они copy-initialize): 0.
    int a5[10]{1, 2, 3};
    int a6[10] = { 0 };  // массив нулей.
    int a7[10] = { 1 };  // массив нулей.

    char c1[] = {1, 2, 3, 4};
    char c2[] = "hello";  // Массив размера 6.
    char c3[10] = "hello";  // Массив размера 10, проинициализированы первые 6 символов.

    int *aptr = a1;
    assert(aptr == &a1[0]);
    assert(aptr + 1 == &a1[1]);
    assert(aptr + 9 == &a1[9]);
    aptr + 10;  // one-past-the-end, но нельзя разыменовать.
    // &a1[10];  // UB - обращение к несуществующему элементу массива.

    std::cout << sizeof(a1) << "\n";
    std::cout << std::size(a1) << " " << sizeof(a1) / sizeof(a1[0]) << "\n";
}
