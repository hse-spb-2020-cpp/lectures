#include <memory>
#include <vector>
#include <iostream>

int main() {
    char data[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<char> *v = new (data) std::vector<char>(100);
    std::cout << v->size() << "\n";
    std::cout << static_cast<int>((*v)[0]) << "\n";
}
// 1
// 0
// 0x01020304 (big-endian) или 0x04030201 (little-endian)
