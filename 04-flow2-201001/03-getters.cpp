#include <cassert>

struct Foo {
private:
    int x;  // x % 2 == 0

public:
    [[nodiscard]] int get_x() const {
        return x;
    }

    void set_x(int new_x) {
        assert(new_x % 2 == 0);
        x = new_x;
    }
};

int main() {
    Foo f;

    f.set_x(10);
    assert(f.get_x() == 10);
}
