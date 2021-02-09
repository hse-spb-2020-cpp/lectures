int main() {
    int arr[4];

    int *x0 = &arr[0];
    int *x3 = &arr[3];
    int *x4 = &arr[4];  // UB: не существует arr[4].

    int *p = arr;
    int *p0 = p + 0;
    int *p3 = p + 3;
    int *p4 = p + 4;  // OK: указатель на one-past-last брать можно. Но разыменовывать нельзя.
    *p4;  // UB
    int *p5 = p + 5;  // UB
    int *p5b = p + 5 - 1;  // UB: (p + 5) - 1
    int *p5c = p + (5 - 1);  // OK: p + 4
    int *p0b = p - 1 + 1;  // UB: (p - 1) + 1
}
