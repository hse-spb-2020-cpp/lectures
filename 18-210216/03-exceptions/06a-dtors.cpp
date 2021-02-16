#include <stdexcept>
#include <iostream>

struct WeirdObject {
    ~WeirdObject() /* noexcept */ {
        throw std::runtime_error("WTF1");
    }
};

int main() {
    try {
        WeirdObject w;
        throw std::runtime_error("WTF2");
    } catch (const std::exception &e) {
        std::cout << "exception: " << e.what() << "\n";
    }
}
