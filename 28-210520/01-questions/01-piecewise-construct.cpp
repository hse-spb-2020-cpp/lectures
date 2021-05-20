#include <string>
#include <utility>
#include <tuple>

struct Foo {
    explicit Foo(int) {}
    explicit Foo(int, std::string) {}

    Foo(const Foo &) = delete;
    Foo(Foo &&) = delete;
    Foo &operator=(const Foo &) = delete;
    Foo &operator=(Foo &&) = delete;
};

int main() {
    // std::pair<Foo, Foo> p1(Foo(10, "a"), Foo(20, "b"));
    // map<K, V>::value_type = pair<const K, V>
    // insert(value_type) ~ insert(pair(....))
    // emplace(параметры конструктора для value_type) ~ emplace(первый элемент, второй элемент)

    [[maybe_unused]] std::pair<Foo, Foo> p2(
        std::piecewise_construct,
        std::tuple{10, std::string("a")},
        std::tuple{20, std::string("b")}
    );

    std::pair<Foo, Foo> p3{20, 30};  // explicit, потому что Foo(int) - explicit.
                                     // Работает, потому что у конструктора Foo(int) один параметр.
}
