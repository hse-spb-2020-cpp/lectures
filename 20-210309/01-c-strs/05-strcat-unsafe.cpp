#include <iostream>
#include <cassert>
#include <cstring>

void my_strcat(char *a, const char *b) {
    int a_pos = std::strlen(a);
    for (int b_pos = 0; b[b_pos]; b_pos++) {
        std::cout << "b_pos=" << b_pos << "\n";
        a[a_pos++] = b[b_pos];
    }
    a[a_pos] = 0;
}

int main() {
    // Расширение GCC: можно записывать строковой литерал в char* для совместимости со старым кодом.
    // Но писать туда всё ещё нельзя.

    /*const*/ char* a = "hello ";  // Время жизни строкового литерала - static, управляет компилятор.
    // a[0] = 'x';  // UB.

    const char* b = "world";
    // std::cout << (a + b) << "\n";
    // std::cout << ("Hello" + " World") << "\n";
    std::cout << ("Hello" " World") << "\n";  // Костыль на этапе компиляции(!).
                                              // Только для литералов.
    // std::cout << (a b) << "\n";
    // std::cout << ("Hello" b) << "\n";

    // my_strcat(a, b);  // Сразу UB: нельзя менять a.
    // std::cout << a << "\n";

    {
        const char *p1 = "hello";
        const char *p2 = "hello";
        // Литералы могут склеиваться.
        std::cout << static_cast<const void*>(p1) << " " << static_cast<const void*>(p2) << "\n";
    }

    {
        char arr[] = "hello ";
        my_strcat(arr, b);  // UB: выход за границу массива.
        std::cout << arr << "\n";
    }

    {
        char arr[11] = "hello ";
        my_strcat(arr, b);  // UB: нет места под null-terminator. Стреляет редко, но больно.
        std::cout << arr << "\n";
        std::cout << strlen(arr) << "\n";
        assert(strlen(arr) == 11);
    }
}
