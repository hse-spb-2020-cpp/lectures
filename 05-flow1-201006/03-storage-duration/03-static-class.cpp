#include <cassert>

struct Counter {
private:
    static int calls;  // Declaration

public:
    static int counter() {
        return ++calls;
    }
};

int Counter::calls = 0;  // Definition

int counter() {
    return Counter::counter();
}

int main() {
    assert(counter() == 1);
    assert(counter() == 2);
    assert(counter() == 3);
    assert(counter() == 4);
}
