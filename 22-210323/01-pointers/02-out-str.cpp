#include <cassert>
#include <iostream>

int read_line(char ** const s) {
    *s = new char[10];  // Assume noexcept.
    // *s = new char[10]{};
    // s[9] = 0;
    (*s)[9] = 0;
    if (!std::cin.read(*s, 9)) {
        return 1;
    }
    return 0;
}

int main() {
    char *s = nullptr;
    int err = read_line(&s);
    assert(err == 0);
    std::cout << s << "\n";
    delete[] s;
}
