#include <vector>
#include <iostream>

struct Base {
    Base() {
        throw 0;
    }
};

struct Foo : Base {
    std::vector<int> a, b;

    Foo(const std::vector<int> &a_, const std::vector<int> &b_)
    try
        : a(a_)
        , b(b_)
    {
    } catch (const std::bad_alloc &) {
        // Поймали исключение из member initialization list или из тела.
        std::cout << "Allocation failed\n";
        // Поля и базовый класс здесь уже уничтожены.
        // Мы не знаем, откуда вылетело исключение.

        // Объект оживить нельзя. Если не написали throw; - добавляется автоматически.
    } catch (int x) {
        std::cout << "Oops\n";
        // Базовый класс тоже уже уничтожен.
        throw 10;
    }
};

int main() {
    try {
        Foo f({}, {});
    } catch (int x) {
        std::cout << "exception " << x << "\n";
    }
}
