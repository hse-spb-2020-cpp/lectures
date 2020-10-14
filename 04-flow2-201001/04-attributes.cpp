#include <cassert>

// ABI Application Binary Interface

[[nodiscard]] int sum(int a, int b, /*[[maybe_unused]] */int x1, [[maybe_unused]] int y1, [[maybe_unused]] int x2) {
    static_cast<void>(x1);
    return a + b;
};

int main() {
    assert(sum(2, 3, 100, 200, 300) == 5);
    // sum(2, 3);
    static_cast<void>(sum(2, 3, 100, 300, 500));

    [[maybe_unused]] int x = 10, y = 20;
    int z [[maybe_unused]] = 10;//, /*[[maybe_unused]] z2 = 20,*/ z3 = 30;

    //assert(freopen(...));
    return 0;
}
