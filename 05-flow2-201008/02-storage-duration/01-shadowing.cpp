#include <iostream>
#include <vector>

struct Foo {
    int x;
    Foo(int x) : x(x) {
        int y = x;
        int z = this->x;
    }
};

int main() {
    [[maybe_unused]] int x;
    std::cout << "x created\n";

    {
/*        for (int x : v) {
            [[maybe_unused]] std::vector<int> v(10);
//            int foo = 12;
        }*/

        // shadowing
        // -Wshadow
/*        for (int i = 0; i < 10; i++) {
           for (int i = 0; i < 20; i++) {
           }
        }*/
    }

    [[maybe_unused]] int data[100];
}
