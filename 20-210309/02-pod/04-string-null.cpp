#include <string>
#include <iostream>

int main() {
    // std::string s = "h\0w";
    {
        std::string s{'h', 0, 'w'};
        std::cout << s << "\n";
        std::cout << s.size() << "\n";
        std::cout << s.c_str() << "\n";  // Сишная строка обрезалась по '0'.
        std::cout << s.data() << "\n";  // До C++11 UB: может быть не null-terminated. После C++11 то же самое, что c_str().
    }
}
