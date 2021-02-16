#include <exception>  // std::exception
#include <stdexcept>  // std::logic_error, std::invalid_argument
#include <iostream>

void bar(int n) {
    if (n % 2 == 0) {
        throw std::invalid_argument("N is even\n");
    }
}

void foo(int n) {
    bar(n);
}

int main() {
    try {
        // Non exception-safe.
        int *x = new int(10);  // Should be unique_ptr.

        foo(2);

        delete x;
    } catch (const std::exception &err) {  // Reference!
        std::cout << "Exception caught: " << err.what() << "\n";
        // delete x;
    }
}
