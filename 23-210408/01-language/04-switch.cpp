#include <iostream>
#include <string>

int main() {
    for (int x = 1; x <= 5; x++) {
        std::cout << "x=" << x << "\n";

        switch (x) {
            case 1:
            case 10:
                std::cout << "  1 or 10\n";
                [[fallthrough]];
            case 2 + 2:  // Только константы, но 2+2 всё ещё можно.
                std::cout << "  4\n";
                [[fallthrough]];
            case 2:  // Обычно всё-таки сортируем по алфавиту или по смыслу
                std::cout << "  2\n";
                break;
            default:  // Обычно всё-таки пишется последним
                std::cout << "  default\n";
                [[fallthrough]];
            case 3:
                std::cout << "  3\n";
                break;  // Предупреждения у GCC нет, но лучше писать: а вдруг
                        // допишем ещё case?
        }
    }
    /*
    std::string s;
    switch (s) {  // Compilation Error :( Только целые числа.
    }
    */
}
