#include <string>
#include <iostream>

struct my_string {
    my_string() {
        std::cout << "my_string()\n";
    }

    my_string(const char*) {
        std::cout << "my_string(const char*)\n";
    }

    my_string(const my_string &) {
        std::cout << "my_string(const my_string&)\n";
    }

    my_string(my_string &&) {
        std::cout << "my_string(my_string&&)\n";
    }

    my_string& operator=(const my_string &) {
        std::cout << "operator=(const my_string&)\n";
        return *this;
    }

    my_string& operator=(my_string &&) {
        std::cout << "operator=(my_string&&)\n";
        return *this;
    }
};

my_string foo() {
    my_string a;
    return /* локальная переменная, отдельный случай для return */ a;  // Гарантированная оптимизация.
}

my_string bar() {
    my_string a;
    return /* xvalue */ std::move(a);  // Негарантированная оптимизация, так лучше не делать.
}

int main() {
    std::cout << "===== a =====\n";
    my_string a = foo();
    std::cout << "===== b =====\n";
    my_string b = bar();
}
