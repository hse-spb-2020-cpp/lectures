#include <cassert>
#include <charconv>
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>

// logic_error - инварианты, можно найти до запуска программы.
// runtime_error - некорректный ввод.
// Есть конструктор от std::string, можно использовать std::to_string.

struct my_error_1 : std::exception {
    const char *what() const noexcept override {
        return "hello";  // ok
//        return std::to_string(10).c_str();  // UB, но прячется (из-за Small String Optimization?)
//        return std::string(100, 'a').c_str();  // UB, меньше прячется.
    }
};

struct my_error_2 : std::exception {
    char str[10] = "msg?";

    my_error_2(int x) {
        assert(0 <= x && x <= 9);
        str[3] = '0' + x;
    }

    const char *what() const noexcept override {
        return str;  // ok
    }
};


struct my_error_3 : std::exception {
    std::string str;  // Oops: operator=() должен быть noexcept, но не может.

    my_error_3(int x) : str("hello " + std::to_string(x)) {
    }

    const char *what() const noexcept override {
        return str.c_str();  // ok
    }
};

struct my_error_4 : std::runtime_error {
    // Ok.
    my_error_4(int x) : std::runtime_error("hello " + std::to_string(x)) {
    }
};

int main() {
    try {
        throw my_error_4(123456);
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
    }
}
