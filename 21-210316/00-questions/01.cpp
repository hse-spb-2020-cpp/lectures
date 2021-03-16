#include <iostream>
#include <cstddef>

int main() {
    std::cout << sizeof(int) << " " << alignof(int) << "\n";
    std::cout << sizeof(std::uint32_t) << " " << alignof(std::uint32_t) << "\n";
    // TODO: а почему можно вообще читать невыровненно, а ссылки передавать нельзя?
    // Пример: std::swap().
}
