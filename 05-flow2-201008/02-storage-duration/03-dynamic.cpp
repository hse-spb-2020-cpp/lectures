#include <iostream>
#include <vector>

int main() {
    int *data = new int;  // Dynamic storage duration.
                          // "На куче" (heap)
    delete data;
}
