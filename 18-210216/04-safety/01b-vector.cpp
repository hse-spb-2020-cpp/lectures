#include <iostream>
#include <vector>

struct WeirdObject {
    WeirdObject() {}
    WeirdObject(WeirdObject &&) /*noexcept*/ {
        std::cout << "move\n";
    }
    WeirdObject(const WeirdObject &) {
        std::cout << "copy\n";
    }

    WeirdObject & operator=(WeirdObject &&) = delete;
    WeirdObject & operator=(const WeirdObject &) = delete;
};

int main() {
    std::vector<WeirdObject> vec(16);
    vec.resize(17);  // Делает move, если он noexcept, copy иначе.
                     // Чтобы была строгая гарантия исключений.
}
