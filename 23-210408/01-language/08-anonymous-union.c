#include <stdio.h>

enum EventType { MOUSE, KEYBOARD };

// tagged union: std::variant<MouseEvent, KeyboardEvent>
// Standard C and C++
struct Event {  // 16
    int type;
    union {  // Anonymous union, стандартный C и C++
        struct {
            int x;
            int y;
            int button;
        } mouse;
        struct {
            int key;
            int is_down;
        } keyboard;
    } /* event */;
};

int main() {
    printf("%d\n", sizeof(struct Event));
    struct Event ev;
    ev.type = MOUSE;
    ev /*.event*/.mouse.x = 11;
    ev /*.event*/.mouse.y = 22;
    ev /*.event*/.mouse.button = 1;
}
