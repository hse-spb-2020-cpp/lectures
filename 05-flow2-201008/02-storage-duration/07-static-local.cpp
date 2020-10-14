#include <vector>
#include <cassert>

int counter() {
    static int c = 0;
    return ++c;
}

void foo(int n) {
//    if (....) {
        static std::vector<int> v(n);
        v.clear();
        v.resize(n);
        static int x;
        x = n;
        assert(static_cast<int>(v.size()) == n);
//    }
}

int main() {
    for (int i = 0; i < n; i++) {
        static char buf[100'000'000];
        readWord(buf);
    }

    {
        static char buf[100];
    }
    foo(10);
    foo(10);
    foo(11);
}
