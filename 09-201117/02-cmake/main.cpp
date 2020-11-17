// Translation unit 1.

#ifdef DEBUG
#include <iostream>
#endif

// No <iostream>: we do not use it in main() at all.
void print_hello();

int main() {
    #ifdef DEBUG
    std::cout << "Debug mode!\n";
    #endif
    print_hello();
}
