#include <chrono>
#include <iostream>
#include <thread>

#pragma GCC optimize("-O2")

int main() {
    int data = 0;
    bool stop = false;

    std::thread t([&]() {
        while (!stop) {
            data++;
        }
    });

    while (data < 100) {}
    std::cout << "done " << data << "\n";
    stop = true;

    t.join();
}
