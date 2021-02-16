#include <exception>  // std::exception
#include <stdexcept>  // std::logic_error, std::invalid_argument
#include <iostream>

void bar(int n) {
    if (n % 2 == 0) {
        // std::invalid_argument : std::logic_error
        // std::logic_error : std::exception
        throw std::invalid_argument("N is even\n");
    }
}

void foo(int n) {
    try {
        bar(n);
    } catch (const std::runtime_error &err) {  // std::runtime_error : std::exception
        std::cout << "Caught runtime_error: " << err.what() << "\n";
    }
}

int main() {
    try {
        foo(2);
    } catch (const std::exception &err) {  // Reference!
        std::cout << "Exception caught: " << err.what() << "\n";
    }
}
