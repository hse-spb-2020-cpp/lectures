#include <iostream>

template<typename T>
void apply(void (*operation)(T), T data) { // cdecl.org
    operation(data);
}

template<typename T>
void apply10(void (*operation)(T)) { // cdecl.org
    operation(10);
}

template<typename T>
void print(T x) {
    std::cout << x << "\n";
}

void print_twice(int x) {
    std::cout << x << ", " << x << "\n";
}

template<typename T>
void (*print_ptr)(T) = print;

int main() {
   apply<int>(print, 10);
   apply<int>(print_twice, 20);

   apply(print, 10);
   apply(print_twice, 20);

   // apply10(print);
   apply10(print_twice);

   void (*ptr1)(int) = print;
   void (*ptr2)(double) = print;
   ptr1 = print_twice;

   auto ptr3 = print_twice;
   // auto ptr4 = print;

   void (*ptr5)(int) = print_ptr<int>;
}
