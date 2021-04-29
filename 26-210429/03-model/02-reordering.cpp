#include <chrono>
#include <iostream>
#include <thread>

#pragma GCC optimize("-O0")

int main() {
    int data = 0;
    bool finished = false;

    std::thread t([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        // Order? CPU?
        data = 123;
        finished = 1;
    });

    while (!finished) {}
    std::cout << data << "\n";

    t.join();
}
