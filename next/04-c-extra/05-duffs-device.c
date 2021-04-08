#include <assert.h>

// https://ru.wikipedia.org/wiki/%D0%A3%D1%81%D1%82%D1%80%D0%BE%D0%B9%D1%81%D1%82%D0%B2%D0%BE_%D0%94%D0%B0%D1%84%D1%84%D0%B0
// Please don't.

void my_memcpy(char *dest, const char *src, size_t n) {
    size_t blocks = (n + 7) / 8;
    if (!blocks) return;
    switch (n % 8) {
    case 0: do { *dest++ = *src++;
    case 7:      *dest++ = *src++;
    case 6:      *dest++ = *src++;
    case 5:      *dest++ = *src++;
    case 4:      *dest++ = *src++;
    case 3:      *dest++ = *src++;
    case 2:      *dest++ = *src++;
    case 1:      *dest++ = *src++;
               } while (--blocks > 0);
    }
}

int main(void) {
    char src[100];
    for (int i = 0; i < 100; i++) {
        src[i] = i;
    }

    char dest[100];
    my_memcpy(dest, src, sizeof src);
    for (int i = 0; i < 100; i++) {
        assert(dest[i] == i);
    }
}
