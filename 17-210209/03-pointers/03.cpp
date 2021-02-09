int main() {
    int arr[4];

    // В C++ почти не используется, используется в C.
    void *x = arr;
    // *x;
//    static_cast<int*>(x)
    x++;  // O_O: расширение GCC: работает, как с char*.
}
