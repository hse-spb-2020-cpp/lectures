#include <iostream>
#include <fstream>

#pragma pack(push, 1)
// Теперь нет padding, меньше зависим от ключей компиляции
//
// Но всё ещё проблемы с:
// 1. Порядок байт (x86 little-endian; старые Mac, некоторые роутеры на 'mips', но не 'mipsel').
// 2. Не все процессоры умеют читать невыровненную память (ARM, но я не специалист).
// 3. Точные размеры int/float.
struct MyPod {
    int x = 10;
    char y = 20;
    float z = 30;
};
#pragma pack(pop)

int main() {
    MyPod p;
    std::ofstream f("02.bin", std::ios_base::out | std::ios_base::binary);
    // Не UB.
    f.write(reinterpret_cast<const char*>(&p), sizeof(p));
}
