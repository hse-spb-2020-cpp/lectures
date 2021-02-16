#include <stdexcept>
#include <iostream>

struct WeirdObject {
    ~WeirdObject() /* noexcept */ {
        // C++03: вылетело исключение. Если нет второго текущего - всё норм.
        //        Если получилось два исключения - std::terminate().
        // C++11: сразу std::terminate(), потому что деструктор помечен noexcept.
        throw std::runtime_error("WTF1");
    }
};

int main() {
    try {
        {
            WeirdObject w;
        // throw std::runtime_error("WTF2");
        }
    } catch (const std::exception &e) {
        std::cout << "exception: " << e.what() << "\n";
    }
}
