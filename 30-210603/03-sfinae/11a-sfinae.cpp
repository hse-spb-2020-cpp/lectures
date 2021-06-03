#include <iostream>

struct BotvaHolder {
    using botva = int;
};

template<typename T> using GetBotva = typename T::botva;

template<typename T>
void foo(T, GetBotva<T>) {  // Просто псевдоним, так можно, проблемы возникают как бы "тут".
    std::cout << "1\n";
}

template<typename T>
void foo(T, std::nullptr_t) {
    std::cout << "2\n";
}

int main() {
    foo(BotvaHolder(), 10);  // 1
    foo(BotvaHolder(), nullptr);  // 2
    // foo(10, 10);  // CE
    foo(10, nullptr); // 2
}
