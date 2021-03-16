#include <chrono>
#include <iostream>

// Мораль: обрабатываем только исключительные ситуации! "Прямые не пересеклись" скорее не подходит.

bool foobar(int a, int b, bool please_throw) {
    if (please_throw) {
        if (a % b) {
            throw 0;
        }
        return true;
    }
    return a % b == 0;
}

const int STEPS = 1'000'000;

int main() {
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < STEPS; i++) {
        try {
            foobar(10, 3, true);
        } catch (...) {
        }
    }

    auto duration = std::chrono::steady_clock::now() - start;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms\n";
}
