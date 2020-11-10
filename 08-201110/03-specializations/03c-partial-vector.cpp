#include <vector>

template<typename T>
struct Foo {};

template<typename T>
struct Foo<std::vector<T>> {};

int main() {
}
