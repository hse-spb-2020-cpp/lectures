#include <iostream>
#include <fstream>

// Plain Old Data (POD)
// Нет виртуальности, нет нетривиальных конструкторов/деструкторов/полей/базовых классов.
// Простые базовые классы могут быть.

struct MyPod {
    int x = 10;
    char y = 20;
    // Компилятор добавил padding: 3 левых байта.
    // А мог и не добавлять.
    float z = 30;
};

int main() {
    MyPod p;
    std::ofstream f("01.bin", std::ios_base::out | std::ios_base::binary);
    // Не UB.
    f.write(reinterpret_cast<const char*>(&p), sizeof(p));
}
