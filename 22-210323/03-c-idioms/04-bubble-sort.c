#include <stddef.h>
#include <stdio.h>
#include <strings.h>

void swap(char *a, char *b, size_t size) {
    for (; size > 0; a++, b++, size--) {
        char t = *a;
        *a = *b;
        *b = t;
    }
}

// Look up qsort()
void bubble_sort(void *data, size_t num, size_t size, int (*compar)(const void*, const void*)) {
    // compar ~~ strcmp ~~ (a - b): a < b => (<0); a == b => 0; a > b => (>0).
    char *end = (char*)data + num * size;
    for (size_t i = 1; i < num; i++) {
        for (char *a = data, *b = a + size; b != end; a += size, b += size) {
           printf("compare %p %p (%s %s); %d\n", a, b, *(char**)a, *(char**)b, compar(a, b));
           if (compar(a, b) > 0) {
               // Tradition: everything is trivially copiable/movable.
               // Trivially ~ bytewise (a term from C and C++).
               swap(a, b, size);
           }
        }
    }
}

int my_strcmp(const void *a, const void *b) {  // !!! Not just strcmp!
    const char **a_str = a;
    const char **b_str = b;
    return strcmp(*a_str, *b_str);
}

int main() {
    const char *strs[] = {
        "Hello",
        "World",
        "Egor",
        "Suvorov"
    };
    bubble_sort(strs, sizeof strs / sizeof strs[0], sizeof strs[0],
        my_strcmp
    );
    for (int i = 0; i < 4; i++) {
        printf("%s\n", strs[i]);
    }
}
