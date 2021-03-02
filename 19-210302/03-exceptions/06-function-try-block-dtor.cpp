#include <iostream>

struct Base {
    ~Base() noexcept(false) {
        throw 0;
    }
};

struct Foo : Base {
    ~Foo() try {
    } catch (...) {
        // Ловит исключения не только из тела,
        // но и из деструкторов полей и базовых классов.
        // Они уже уничтожены, обращаться к ним нельзя.

        std::cout << "destruction exception\n";
        // Деструктор не может завершиться корректно, throw;
    }
};

int main() {
    try {
        Foo f;
    } catch (...) {
        std::cout << "exception\n";
    }
}
