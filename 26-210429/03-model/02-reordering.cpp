#include <chrono>
#include <iostream>
#include <thread>

#pragma GCC optimize("-O0")

int main() {
    int data = 0;
    bool finished = false;

    std::thread t([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        // С точки зрения компилятора И процессора следующие две строчки можно свободно менять местами.
        // Никто же не заметит.
        data = 123;
        finished = true;
    });

    while (!finished) {}
    // Разве что другой поток может заметить :(
    std::cout << data << "\n";

    t.join();
}
