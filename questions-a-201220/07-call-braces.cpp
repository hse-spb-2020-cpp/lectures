#include <iostream>
#include <utility>

void foo(std::pair<int, float>, int) {
    std::cout << "1\n";
}

void foo(std::pair<double, double>, double) {
    std::cout << "2\n";
}

void bar(std::pair<int, char*>) {
    std::cout << "1\n";
}

void bar(std::pair<int, double>) {
    std::cout << "2\n";
}

int main() {
    foo({10, 5.5}, 5);  // 1
    foo({10, 5.5}, 5.0);  // 2

    bar({10, nullptr});  // 1
    bar({10, 10});  // 2
}
