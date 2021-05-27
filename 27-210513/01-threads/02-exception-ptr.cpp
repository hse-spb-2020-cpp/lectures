#include <exception>
#include <future>
#include <thread>
#include <iostream>

// https://habr.com/ru/post/160955/

struct my_exception {
    int value;
};

void foo(int x) {
    throw my_exception{x + 10};
}

int main() {
    auto f = std::async([]() {
        foo(0);
    });

    try {
        f.get();
    } catch (my_exception &e) {
        std::cout << "e=" << e.value << "\n";
    }

    std::exception_ptr err;  // shared_ptr<exception>
    // std::make_exception_ptr
    auto save_exception = [&]() {
        // В любой момент программы, необязательно непосредственно внутри catch.
        // Если нет текущего исключения - возвращает exception_ptr{}.
        err = std::current_exception();
    };

    try {
        foo(1);
    } catch (...) {
        save_exception();
        // Out-of-scope: можно сделать nested exceptions: https://en.cppreference.com/w/cpp/error/nested_exception
    }

    try {
        if (err) {
            std::rethrow_exception(err);  // Требует непустой err.
        } else {
            std::cout << "no exception\n";
        }
    } catch (my_exception &e) {
        std::cout << "e=" << e.value << "\n";
    }
}
