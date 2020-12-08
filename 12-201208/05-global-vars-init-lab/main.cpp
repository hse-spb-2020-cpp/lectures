#include <string>
#include <iostream>

struct MainInitLogger {
    MainInitLogger() {
        std::cout << "main.cpp initializes\n";
    }
} main_init_logger;

namespace {
std::string current_test;
}

void start_test(const std::string &name) {
    std::cout << "start_test() before: " << current_test << "\n";
    current_test = name;
    std::cout << "start_test() after: " << current_test << "\n";
}

int main() {
    std::cout << "main(): current_test: " << current_test << "\n";
}
