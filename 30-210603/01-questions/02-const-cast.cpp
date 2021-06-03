#include <stdio.h>
#include <cassert>
#include <utility>

void old_c_print_line(char *str) {
    printf("%s\n", str);
}

template<typename T>
class optional {
    T data{};
    bool initialized = true;

public:
    T& get() {
        return const_cast<T&>(std::as_const(*this).get());
    }

    const T &get() const {
        assert(initialized);
        return data;
    }
};

int main() {
    old_c_print_line(const_cast<char*>("hello"));

    optional<int> a;
    const optional<int> b;
    a.get() = 10;
    printf("%d\n", a.get());
    printf("%d\n", b.get());  // Should not const_cast inside! UB otherwise.
}
