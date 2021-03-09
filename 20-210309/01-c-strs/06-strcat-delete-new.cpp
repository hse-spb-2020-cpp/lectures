#include <cstring>
#include <iostream>

void my_strcat(char *&a, const char *b) {
    char *out = new char[strlen(a) + strlen(b) + 1];

    std::strcpy(out, a);
    std::strcpy(out + strlen(a), b);

    delete[] a;
    a = out;
}

int main() {
    {
        // ОК, но очень странно выглядит.
        char *a = new char[6];
        std::strcpy(a, "hello");

        char b[] = " world";

        my_strcat(a, b);
        // my_strcat(a + 1, b);  // UB: будет delete из середины куска памяти.
        std::cout << a << "\n";

        delete[] a;
    }

    {
        // UB
        char a[] = "hello";
        char b[] = " world";

        char *aptr = a;
        my_strcat(aptr, b);
        std::cout << aptr << "\n";
    }
}
