#include <memory>

// https://abseil.io/tips/134

struct Foo {
    static std::unique_ptr<Foo> make_foo() {
        // return std::make_unique<Foo>();
        return std::unique_ptr<Foo>(new Foo());
    }

private:  // Или protected, неважно
    Foo() {}

    // friend void std::unique_ptr<Foo> std::make_unique<Foo>();  // TODO: как указать namespace?
};

int main() {
}
