#include <memory>

// https://abseil.io/tips/134

struct Foo {
    static std::unique_ptr<Foo> make_foo() {
        // return std::make_unique<Foo>();
        return std::unique_ptr<Foo>(new Foo());
    }

private:  // Или protected, неважно
    Foo() {}

    // Техническая возможность есть, но так лучше не делать.
    friend std::unique_ptr<Foo> std::make_unique<Foo>();
};

int main() {
    auto p = std::make_unique<Foo>();
    // Но всё равно не помогает: std::make_unique() может вызывать не напрямую, а через что-то промежуточное.
}
