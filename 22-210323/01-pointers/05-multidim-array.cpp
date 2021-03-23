#include <iostream>

using arr45 = int[4][5];

// void foo(int arr[3][4][5]) {
// void foo(int arr[][4][5]) {
// void foo(int (*arr)[4][5]) {  // What if: (*arr) --> *arr
void foo(arr45 *arr) {
    std::cout << arr[1][2][3] << "\n";
}

template<std::size_t N, std::size_t M, std::size_t K>
void foo2(int (&arr)[N][M][K]) {
    std::cout << arr[1][2][3] << "\n";
    std::cout << N << " " << M << " " << K << "\n";
}

void bar(int ***arr) {
    std::cout << arr[1][2][3] << "\n";
}

int main() {
    int arr[3][4][5]{};
    std::cout << sizeof(arr) << "\n";
    std::cout << &arr[0][0][0] << "\n";
    std::cout << &arr[0][0][1] << "\n";
    std::cout << &arr[0][0][2] << "\n";
    std::cout << &arr[0][0][3] << "\n";
    std::cout << &arr[0][0][4] << "\n";
    std::cout << &arr[0][1][0] << "\n";
    std::cout << &arr[0][1][1] << "\n";
    arr[1][2][3] = 123;
    foo(arr);
    foo2(arr);

    // int ***arr2 = arr;
    int ***arr2 = new int**[3];
    for (int i = 0; i < 3; i++) {
        arr2[i] = new int*[4];
        arr2[i][0] = new int[5];
        arr2[i][1] = new int[5];
        arr2[i][2] = new int[5];
        arr2[i][3] = new int[5];
    }
    arr2[1][2][3] = 123;
    std::cout << "=====\n";
    std::cout << &arr2[0][0][0] << "\n";
    std::cout << &arr2[0][0][1] << "\n";
    std::cout << &arr2[0][0][2] << "\n";
    std::cout << &arr2[0][0][3] << "\n";
    std::cout << &arr2[0][0][4] << "\n";
    std::cout << &arr2[0][1][0] << "\n";
    std::cout << &arr2[0][1][1] << "\n";
    bar(arr2);
}
