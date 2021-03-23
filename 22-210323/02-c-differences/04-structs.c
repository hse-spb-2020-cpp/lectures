struct point1 {
    int x;
    int y;
};

// Also valid in C++, but not as useful.
typedef struct point2 {
    int x;  // = 0
    int y;

    // No: constructors, destructors, rule of five, methods, operator overloading
    // No: private/public
} point2;

int point2_dist2(const struct point2 *p) {
    return p->x * p->x + p->y * p->y;
}

typedef struct point3 {
    int x;
    int y;
} point3, *ppoint3;

int main() {
    struct point1 p1;
    point2 p2;
    point3 p3;
    ppoint3 pointer_p3 = &p3;
}
