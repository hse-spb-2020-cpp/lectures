#include <iostream>

int main() {
    std::size_t x;
    // Compiles wrongfully: size_t is only guaranteed in <cstddef> and few other headers, not <iostream>.
    // Unfortunately, <iostream> _may_ also include other headers by an accident or a virtue or implementation.
    // DO NOT RELY ON THAT!

    // Include explicitly everything you use.
    // With your headers: only assume that `foo.h` includes stuff defined in `foo.cpp`.
}
