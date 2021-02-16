#include <iostream>

struct err1 {};
struct err2 {};

struct WithDestructor {
    int key;
    WithDestructor(int key_) : key(key_) {}
    ~WithDestructor() {
        std::cout << "Destructed " << key << "\n";
    }
};

void bar() {
    WithDestructor wd31(31);  // Implementation-defined раскрутка.
    try {
        WithDestructor wd40(40);
        std::cout << "3\n";
        throw err1();
        std::cout << "x3\n";
    } catch (const err1 &e) {
        std::cout << "4\n";
        throw err2();
        std::cout << "x4\n";
    }
    std::cout << "bar end\n";
}

void foo() {
    WithDestructor wd20(20);  // Implementation-defined раскрутка.
    try {
        WithDestructor wd30(30);  // Implementation-defined раскрутка.
        std::cout << "2\n";
        bar();
        std::cout << "x2\n";
    } catch (const err1 &e) {
        std::cout << "z\n";
    }
    std::cout << "foo end\n";
}

int main() {
    std::cout << "1\n";
    {
        WithDestructor wd10(10);
    }
    //try {
        foo();
    //} catch (...) {
    //    throw;  // "Перебрось текущее исключение".
    //}
    std::cout << "main end\n";
}
