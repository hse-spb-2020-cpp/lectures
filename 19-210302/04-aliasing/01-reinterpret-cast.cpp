#include <cstddef>
#include <iostream>

int main() {
    int x = 123456;
    char *xc = reinterpret_cast<char*>(&x);
    // Разворачивается в такую штуку:
    // char *xc = static_cast<char*>(static_cast<void*>(&x));
    for (std::size_t i = 0; i < sizeof(x); i++) {
        std::cout << static_cast<int>(xc[i]) << "\n";
    }
}
