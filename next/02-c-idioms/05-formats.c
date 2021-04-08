#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    // https://en.cppreference.com/w/c/io/fscanf
    char buf1[10], buf2[20];
    int x;
    scanf("%9[^-]-%19s%*d%d", buf1, buf2, &x);

    float a;
    double b;
    scanf("%f%lf", &a, &b);  // types should match!

    // https://en.cppreference.com/w/c/io/fprintf
    printf("buf1=|%s|\nbuf2=|%s|\nx=%d\n", buf1, buf2, x);
    printf("     01234567890123456789\nbuf1=%9s\nbuf2=%19s\nx=%05d\n", buf1,
           buf2, x);
    printf("\n% d\n% d\n% d\n", 0, 5, -5);
    printf("\n%+d\n%+d\n%+d\n", 0, 5, -5);
    printf("%010.3f\n", a);
    printf("%010.3f\n", b);  // not %lf! ellipsis conversions.
}
