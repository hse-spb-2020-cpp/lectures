#include <stdio.h>

enum EventType { MOUSE, KEYBOARD };

struct MouseEvent {  // 12
    int x;
    int y;
    int button;
};

struct KeyboardEvent {  // 8
    int key;
    int is_down;
};

union AnyEvent {  // 12
    struct MouseEvent mouse;
    struct KeyboardEvent keyboard;
};

// tagged union: std::variant<MouseEvent, KeyboardEvent>
// Haskell: tagged union тоже есть, называется "тип-сумма", и там синтаксис
// хороший и безопасный.
struct Event {  // 16
    int type;
    union AnyEvent event;
};

int main(void) {
    printf("%d\n", sizeof(struct Event));
    struct Event ev;
    ev.type = MOUSE;
    ev.event.mouse.x = 11;
    ev.event.mouse.y = 22;
    ev.event.mouse.button = 1;
    // https://stackoverflow.com/a/25672839/767632
    // Implementation-defined in C (object representation).
    // UB in C++ (accessing to non-active union member).
    // OK in GCC in C++:
    // https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#Type-punning
    printf("%d\n", ev.event.keyboard.key);  // UB in C++, 11 in C.
}
