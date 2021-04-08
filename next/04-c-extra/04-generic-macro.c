#include <stdio.h>
// https://github.com/emscripten-core/emscripten/blob/ebf0c5fa37224d1d35a63062a43dc80072b07ed0/system/include/emscripten/em_asm.h#L41

#define _EM_ASM_SIG_CHAR(x) _Generic((x), \
    float: 'f', \
    double: 'd', \
    int: 'i', \
    unsigned: 'i', \
    default: 'i')

int main(void) {
    printf("%c\n", _EM_ASM_SIG_CHAR(1));
    printf("%c\n", _EM_ASM_SIG_CHAR(1.0));
    printf("%c\n", _EM_ASM_SIG_CHAR(1.0f));
    printf("%c\n", _EM_ASM_SIG_CHAR(1u));
    int x = 10;
    printf("%c\n", _EM_ASM_SIG_CHAR(x));
}
