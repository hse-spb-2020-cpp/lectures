#include <iostream>
#include <boost/core/demangle.hpp>

struct Base {
    int x, y;
};

int main() {
    Base b[4]{
       {100, 200},
       {300, 400},
       {500, 600},
       {700, 800}
    };
    std::cout << &b << "\n";
    std::cout << &b[0] << "\n";
    std::cout << &b[1] << "\n";
    std::cout << &b[2] << "\n";

    Base *bptr = &b[0];
    std::cout << bptr << "\n";
    std::cout << bptr + 1 << "\n";
    std::cout << bptr + 2 << "\n";

    Base *bptr2 = &b[1];
    std::cout << bptr2 - 1 << "\n";
    std::cout << bptr2 << "\n";
    std::cout << bptr2 + 1 << "\n";

    // a[b]  ~~ *(a + b)
    std::cout << bptr2[0].x << " " << bptr2[0].y << "\n";  // (*(bptr2 + 0)).x ~~ (*&b[1]).x
    std::cout << bptr2[-1].x << " " << bptr2[-1].y << "\n";  // (*(bptr2 - 1)).x ~~ (*(&b[1] - 1)).x ~~ (*&b[0]).x
    // Смешно, но бесполезно.
    std::cout << (-1)[bptr2].x << "\n";  // (*(-1 + bptr2)).x
    std::cout << 1[bptr2].x << "\n";  // (*(1 + bptr2)).x

    // Осторожно: в C++ есть тип "указатель на массив".
    // Base *bp1 = &b;  // не компилируется: &b - это "указатель на массив", а не "указатель на элемент".
    Base *bp2 = b;  // array-to-pointer decay
    auto *bp3 = b;
    auto bp4 = b;  // auto тоже делает array-to-pointer decay; массивы-то копировать нельзя.
    std::cout << boost::core::demangle(typeid(bp2).name()) << "\n";
    std::cout << boost::core::demangle(typeid(bp3).name()) << "\n";
    std::cout << boost::core::demangle(typeid(bp4).name()) << "\n";

    //
    // int arr[]{1, 2, 3, 4};
    // std::sort(arr, arr + 4);
}
