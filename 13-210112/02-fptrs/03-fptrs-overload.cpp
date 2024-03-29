#include <iostream>

template<typename T>
void apply(void (*operation)(T), T data) { // cdecl.org
    operation(data);
}

template<typename T>
void apply10(void (*operation)(T)) { // cdecl.org
    operation(10);
}

void print(int x) {
    std::cout << x << "\n";
}

void print(double x) {
    std::cout << x << "\n";
}

int main() {
   apply<int>(print, 10);
   apply<int>(print, 20);

   apply(print, 10);

//   apply10(print);

   void (*ptr1)(int) = print;
   void (*ptr2)(double) = print;

   // auto ptr4 = print;
   auto ptr5 = static_cast< void(*)(int) >(print);
   void (*ptr6)(int) = print;
}
