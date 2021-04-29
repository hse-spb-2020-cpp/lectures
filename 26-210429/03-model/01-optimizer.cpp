#include <chrono>
#include <iostream>
#include <thread>

#pragma GCC optimize("-O2")

int main() {
    int data = 0;
    bool stop = false;

    std::thread t([&]() {
        while (!stop) {  // Оптимизируем до while (true), потому что stop внутри цикла не меняется.
            data++;
        }
    });

    while (data < 100) {}  // Оптимизируем до "не делай ничего", потому что бесконечный цикл без зависимостей — UB.
    std::cout << "done " << data << "\n";
    stop = true;

    // Если считать, что любая переменная в любой момент меняется, то вообще ничего не получится соптимизировать/закэшировать.

    t.join();
}
