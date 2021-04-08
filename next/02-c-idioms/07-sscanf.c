#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[] = " 123+   45+8 79+4";
    int pos = 0;
    while (buf[pos]) {
        if (buf[pos] == '+') {
            pos++;
            continue;
        }
        int x, read;
        // May take linear time! Like in GTA.
        int res = sscanf(buf + pos, "%d%n", &x, &read);
        assert(res == 1);
        printf("pos=%d; read=%d; x=%d\n", pos, read, x);
        pos += read;
    }
}
