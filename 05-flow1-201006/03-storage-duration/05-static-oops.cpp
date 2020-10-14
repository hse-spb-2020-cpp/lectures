#include <cassert>
#include <vector>

void foo(bool condition, int n) {
    if (condition) {
        static std::vector<int> v;
        v.clear();
        v.resize(n);
        // OR: v.assign(n);
        assert(static_cast<int>(v.size()) == n);
    }
}

int main() {
    foo(false, 9);
    foo(true, 10);
//    foo(true, 11);
}
