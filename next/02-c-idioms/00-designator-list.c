struct point {
    int x, y, z;
};

int main(void) {
    struct point p = {.x = 10};
    // https://docs.python.org/3/extending/newtypes_tutorial.html#defining-new-types)

    int arr[10] = { [3] = 5, [5] = 10 };
    for (int i = 0; i < 10; i++) {
        printf("arr[%d]=%d\n", i, arr[i]);
    }
}
