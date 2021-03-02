#include <iostream>
#include <vector>

struct WeirdObject {
    WeirdObject() {}
    WeirdObject(WeirdObject &&) {}
    WeirdObject & operator=(WeirdObject &&) { return *this; }

    WeirdObject(const WeirdObject &) = delete;
    WeirdObject & operator=(const WeirdObject &) = delete;
};

int main() {
    {
        int a = 10, b = 20;
        a = b;  // 1. no throw.
    }
    {
        std::vector<int> a;
        std::vector<int> b(1'000'000);
        a = b;  // может кинуть std::bad_alloc.
    }
    {
        std::vector<int> a(1'000'000);
        try {
            a.push_back(20);  // 2. strong exception safety (сильная гарантия исключений): a.size() == 1'000'000.
            assert(a.size() == 1'000'001);  // Если дошли до сюда, то верно.
        } catch (...) {
        }
        assert(a.size() == 1'000'000 || a.size() == 1'000'001);  // Верно только из-за сильной гарантии.
        std::cout << std::is_nothrow_move_constructible_v<int> << "\n";
    }
    {
        std::vector<WeirdObject> a(1'000'000);
        try {
            a.push_back(WeirdObject());  // 3. basic exception safety: не знаем содержимое a.
            assert(a.size() == 1'000'001);  // Если дошли до сюда, то верно.
        } catch (...) {
        }

        assert(a.size() == 1'000'000 || a.size() == 1'000'001);  // Может быть неверно! WeirdObject нельзя move с гарантией noexcept => не можем дать сильную тут.
        a.clear();  // Но вот так, скорее всего, можем.

        std::cout << std::is_nothrow_move_constructible_v<WeirdObject> << "\n";
    }
}
