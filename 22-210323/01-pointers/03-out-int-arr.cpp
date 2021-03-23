#include <iostream>

int create_arr(int **arr, int len) {
    *arr = new int[len];
    for (int i = 0; i < len; i++) {
        (*arr)[i] = 100 + i;
    }
    return 0;
}

int main() {
    int *arr;
    create_arr(&arr, 10);
    std::cout << arr[5] << "\n";
    delete[] arr;
}
