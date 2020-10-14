#include <iostream>

#define DECLARE_VECTOR(T) \
    struct vector##T { \
        T *data; \
        int length; \
    };

struct templ_foo {
    std::string value;
    bool exists;
};

int main() {
    [[maybe_unused]] templ_foo x;
    [[maybe_unused]] templ_foo y;
    x = y;
}
