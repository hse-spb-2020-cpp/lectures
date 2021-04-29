#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <thread>

int main() {
    std::promise<std::string> input_promise;
    std::future<std::string> input_future = input_promise.get_future();

    std::thread producer([&]() {
        std::string input;
        std::cin >> input;
        input_promise.set_value(std::move(input));
    });
/*    std::future<std::string> input_future = std::async([]() {
        std::string input;
        std::cin >> input;
        return input;
    });*/

    std::thread consumer([&]() {
        std::string input = input_future.get();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << "Got string: " << input << "\n";
    });

    // Можно дальше накрутить себе .then() и std::async, но это не очень хороший стиль
    // https://ericniebler.com/2020/11/08/structured-concurrency/
    // https://vorpus.org/blog/notes-on-structured-concurrency-or-go-statement-considered-harmful/
    // Сложности с отменой, например.

    consumer.join();
    producer.join();
}
