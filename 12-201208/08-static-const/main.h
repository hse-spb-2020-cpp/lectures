#ifndef MAIN_H_
#define MAIN_H_

#include <string>

struct Foo {
    static int N;  // Не путать со static внутри функций! Нельзя тут определить, потому что классы обычно в .h, а они включаются в несколько TU.
    static const int N2 = 20;  // Так можно: тривиальная константа; такой "объект" даже не создаётся.
    static const int N3 = 30;
    // static const std::string s = "hello";  // Так снова нельзя O_O.
    static const std::string s;  // Нетривиальные константы надо определять в .cpp

    static inline const std::string s2 = "hello";  // C++17: если очень-очень-очень надо (никогда).
};

#endif  // MAIN_H_
