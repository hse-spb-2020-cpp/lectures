#include <iostream>

int main() {
    int x = 10;  // Automatic, "на стэке".
    static int y = 20;  // Static, "в глобальной памяти".
    std::cout << x << " " << y << "\n";

    {
        static int data[100'000'000];
        std::vector<int> v(10);
        std::cout << data[0] << "\n";
    }

    // data[10] = 123;
}
