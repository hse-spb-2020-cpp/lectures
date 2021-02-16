#include <exception>  // std::exception
#include <iostream>
#include <vector>
#include <string>

void bar(long long n) {
    std::vector<int> vec(n);
    std::string s = "hello world";
    std::string s2 = s;
}

void foo(long long n) {
    bar(n);
}

int main() {
    try {
        foo(100LL * 1024 * 1024 * 1024);
    } catch (const std::exception &err) {  // Reference!
        std::cout << "Exception caught: " << err.what() << "\n";
    }
}
