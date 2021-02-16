#include <exception>  // std::exception
#include <iostream>

struct my_error : std::exception {
    // std::string err;  // Oops: bad_alloc!
    const char *what() const noexcept override {
        return "my_error";
    };
};

int main() {
    try {
        throw my_error();
    } catch (const std::exception &err) {  // Reference!
        std::cout << "Exception caught: " << err.what() << "\n";
    }
}
