#include <string>
#include <iostream>

extern const int N;
const int N = 100;

void foo();
void bar();

int main_a[N];

int main() {
    std::cout << "N=" << N << "\n";
    foo();
    bar();
}
