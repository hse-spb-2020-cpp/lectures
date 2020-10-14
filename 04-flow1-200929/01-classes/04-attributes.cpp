#include <cassert>

[[nodiscard]] int sum(int a, int b, [[maybe_unused]] int c) {
    return a + b;
}

int main() {
    assert(sum(2, 3, 100) == 5);
    // sum(2, 3, 100);

    [[maybe_unused]] int x = 10, y = 20;
    int z [[maybe_unused]] = 40, zz [[maybe_unused]] = 50;
}
