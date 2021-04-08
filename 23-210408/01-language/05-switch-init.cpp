#include <iostream>

int main() {
    for (int x = 1; x <= 5; x++) {
        std::cout << "x=" << x << "\n";

        switch (x) {
            case 1:
                std::cout << "  1\n";
                break;
            case 4:
                std::cout << "  4\n";
                break;
            case 2: {
                int wtf0 = 0;
                std::cout << "  2\n";
            } break;
            default: /*{*/
                int wtf1 = 0;  // Compilation Error в C++, в Си можно оставить
                               // неинициализированной.
                std::string s;  // Compilation Error ещё хуже: надо как-то
                                // запомнить, вызывать ли деструктор, лень.
                std::cout << "  default\n";
                /*}*/ break;
            case 3:
                int wtf2 = 0;  // case ниже нет, поэтому никакого "crosses
                               // initialization"
                std::cout << "  3\n";
                break;
        }
    }
}
