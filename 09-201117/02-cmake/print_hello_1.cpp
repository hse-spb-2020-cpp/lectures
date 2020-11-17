// Translation unit 2, version 1.

#include <iostream>

void print_hello() {
    #ifdef DEBUG
    std::cout << "Hello Debug!\n";
    #endif
    std::cout << "Hello World 1!\n";
}
