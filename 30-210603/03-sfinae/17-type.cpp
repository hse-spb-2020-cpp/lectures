// https://github.com/emscripten-core/emscripten/pull/9089
#include <iostream>

template<typename T, typename = void>
struct Formatter {
};

template<typename T>
struct Formatter<T, std::enable_if_t<std::is_integral_v<T>>> {
    void format_integral();
};

template<typename T>
struct Formatter<T, std::enable_if_t<std::is_pointer_v<T>>> {
    void format_pointer();
};

int main() {
//    Formatter<double>().format_integral();
    Formatter<int>().format_integral();
//    Formatter<int*>().format_integral();

//    Formatter<double>().format_pointer();
//    Formatter<int>().format_pointer();
    Formatter<int*>().format_pointer();
}
