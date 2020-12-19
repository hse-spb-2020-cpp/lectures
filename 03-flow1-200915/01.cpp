// Перегрузка функций (function overloading)

void print(int x) { // (1)
}

void print(double x) { // (2)
}

void print(int a, int b) {
}

void print(const char *a) {
}

int main() {
    print(1);  // (1)
    print(1.0);  // (2)

    double x = 1;
    print(x); // (2)

    print('A');  // (1)

    print(10, 20);

    //
    //#define NULL 0
    nullptr, NULL, 0
    print(nullptr); // print(const char*)
    print(0); // print(const char*)
    print(NULL);
}
