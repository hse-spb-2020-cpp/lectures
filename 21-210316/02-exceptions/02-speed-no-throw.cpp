#include <chrono>
#include <iostream>

// Разницы от наличия noexcept на этих примерах не получилось, но она иногда бывает:
// 1. Привет от не-noexcept-move и строгой гарантии.
// 2. Можно оптимизировать код вроде `i++; my_noexcept(); i++;`
// 3. Не надо готовиться к раскрутке стэка.
//
// Стоит помечать, аналогично const.
//
// Разницы от отключения исключений тоже локально не нашлось.

bool foobar(int a, int b, bool please_throw) noexcept {
/*    if (please_throw) {
        if (a % b) {
            throw 0;
        }
        return true;
    }*/
    return a % b == 0;
}

const int STEPS = 100'000'000;

int main() {
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < STEPS; i++) {
//        try {
          foobar(10, 3, false);
//        } catch (...) {
//        }
    }

    auto duration = std::chrono::steady_clock::now() - start;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms\n";
}
