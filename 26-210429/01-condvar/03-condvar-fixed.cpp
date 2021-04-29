#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

int main() {
    std::mutex m;
    std::string input;
    bool input_available = false;
    std::condition_variable cond;

    std::thread producer([&]() {
        while (true) {
            std::string input_buf;
            std::cin >> input_buf;

            std::unique_lock l(m);
            input = std::move(input_buf);
            input_available = true;
            cond.notify_one();
        }
    });

    std::thread consumer([&]() {
        while (true) {
            std::unique_lock l(m);
            while (!input_available) {  // while, не if! Ещё бывает wait_for.
                cond.wait(l);
            }
            std::string input_snapshot = std::move(input);
            input_available = false;
            l.unlock();

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            std::cout << "Got string: " << input_snapshot << "\n";
        }
    });

    consumer.join();
    producer.join();
}
