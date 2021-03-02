#include <iostream>
#include <fstream>

#pragma pack(push, 1)
// Теперь нет padding.
// Но всё ещё проблемы с:
// 1. Порядок байт.
// 2. Не все процессоры умеют читать невыровненную память (AVR???).
// 3. Размеры int/float.
struct MyPod {
    int x = 10;
    char y = 20;
    float z = 30;
};
#pragma pack(pop)

int main() {
    MyPod p;
    std::ofstream f("02.bin", std::ios_base::out | std::ios_base::binary);
    f.write(reinterpret_cast<const char*>(&p), sizeof(p));
}
