#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[10];
    int pos = 0, out;

    out = snprintf(buf, sizeof buf, "%d+", 10);
    assert(out >= 0);
    pos += out;

    out = snprintf(buf + pos, sizeof buf - pos, "%d", 12345);
    assert(out >= 0);
    pos += out;

    out = snprintf(buf + pos, sizeof buf - pos, "+%d", 426);
    assert(out >= 0);
    pos += out;

    // OOPS: UB is close by because of (buf + pos)

    printf("buf=|%s|, pos=%d\n", buf, pos);
}
