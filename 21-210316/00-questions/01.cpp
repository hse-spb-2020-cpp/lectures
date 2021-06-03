#include <algorithm>
#include <iostream>
#include <cstddef>

#pragma pack(push, 1)
struct S {
    char c;
    int a = 10, b = 20;
};
#pragma pack(pop)

int main() {
    std::cout << sizeof(int) << " " << alignof(int) << "\n";
    std::cout << sizeof(std::uint32_t) << " " << alignof(std::uint32_t) << "\n";
    std::cout << sizeof(int*) << " " << alignof(int*) << "\n";

    // Вопрос: а почему можно вообще читать невыровненно, а ссылки на невыровненную память брать нельзя?
    // Даже в std::swap(). Undefined sanitizer будет ругаться. Или на x86_64 всё хорошо?
    //
    // Ответ от 05.04.2021: на самом деле всё плохо: https://stackoverflow.com/questions/8568432/is-gccs-attribute-packed-pragma-pack-unsafe
    // Это действительно UB: нельзя создавать ссылку или указатель на объект, у которого кривое выравнивание.
    // Может упасть даже на x86_64, если компилятор соптимизирует: https://stackoverflow.com/a/46790815/767632
    S s;
    s.a = 30;  // Тут ссылка не берётся, компилятор знает, что потенциально объект не выровнен.
    std::cout << s.a << " " << s.b << "\n";  // Тут ссылка не берётся, потому что operator<< принимает инты по значению.
    std::swap(s.a, s.b);  // Тут ссылка берётся: UB, это корректно ловится undefined sanitizer.
    static_cast<void>(&s.a);  // Тут берётся указатель: UB, это не ловится undefined sanitizer.
                              // Но если использовать struct __attribute__((packed)), то GCC предупредит.
}
