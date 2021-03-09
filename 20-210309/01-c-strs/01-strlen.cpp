#include <cstring>
#include <iostream>
#include <iterator>
#include <boost/core/demangle.hpp>

int my_strlen(const char *s) {
    int len = 0;
    while (s[len] != 0) {
        len++;
    }
    return len;
}

int main() {
    {
        char arr[] = "Hello";
        std::cout << sizeof(arr) << "\n";

        char *str = arr;
        std::cout << str << "\n";
    }
    {
        char arr[] = {'H', 'e', 'l', 'l', 'o', 0 /*'\0'*/};
        std::cout << sizeof(arr) << "\n";

        char *str = arr;
        std::cout << str << "\n";
    }
    {
        char arr[] = {'H', 'i', 'H', 'i'};
        std::cout << sizeof(arr) << "\n";

        char *str = arr;
        std::cout << str << "\n";
    }
    {
        char arr[] = "Hello";
        char *str = arr + 2;
        std::cout << str << "\n";
    }
    {
        std::cout << boost::core::demangle(typeid("Hello").name()) << "\n";
        char arr[] = "Wow\0Foo";
        std::cout << sizeof(arr) << "\n";
        std::cout << arr << "\n";
        std::cout << std::string(arr) << "\n";
        std::cout << std::string(arr, arr + sizeof(arr)) << "\n";
        std::cout << std::string(std::begin(arr), std::end(arr)) << "\n";
        std::cout << arr + 4 << "\n";
    }
    {
        char arr[] = "Hello World";
        std::cout << std::strlen(arr) << "\n";
        std::cout << std::strlen(arr + 3) << "\n";
        std::cout << my_strlen(arr) << "\n";
        std::cout << my_strlen(arr + 3) << "\n";
    }
}
