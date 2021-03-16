#include <cstring>
#include <iostream>

//void print_all(const char *arr[]) {
void print_all(const char **arr) {  // примерно vector<vector<char>>, только совсем руками.
    for (int i = 0; arr[i] != nullptr; i++) {
        //std::cout << "i=" << i << ": " << arr[i] << "\n";
        std::cout << "i=" << i << ": ";
        for (int j = 0; arr[i][j] != 0; j++) {
            std::cout << arr[i][j];
        }
        std::cout << "\n";
    }
}

int main() {
    const char *arr[] = {
        "Hello123456",
        "World",
        nullptr  // NULL в языке Си.
    };
    print_all(arr);
}
