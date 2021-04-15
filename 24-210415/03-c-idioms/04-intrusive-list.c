#include <stdio.h>
#include <stddef.h>

typedef struct node {
    struct node *prev;
    struct node *next;
} node;

#define MAX_NAME_LEN 15

struct process {
    int id;
    char name[MAX_NAME_LEN + 1];

    node n_all;
    node n_alive;
};

void link(node *a, node *b) {
    if (a)
        a->next = b;
    if (b)
        b->prev = a;
}

int main() {
    node all = { NULL, NULL };
    node alive = { NULL, NULL };

    struct process a = {
        .id = 10,
        .name = "a",
    };
    struct process b = {
        .id = 11,
        .name = "b",
    };
    struct process c = {
        .id = 12,
        .name = "c",
    };

    link(&all, &a.n_all);
    link(&a.n_all, &b.n_all);
    link(&b.n_all, &c.n_all);
    link(&c.n_all, &all);

    link(&alive, &b.n_alive);
    link(&b.n_alive, &a.n_alive);
    link(&a.n_alive, &alive);

    ptrdiff_t offset_all = (char*)&a.n_all - (char*)&a;
    // ptrdiff_t offset_all = offsetof(struct process, n_all);  // macro from <stddef.h>, typically used inline
    for (node *n = all.next; n != &all; n = n->next) {
        struct process *p = (struct process*)((char*)n - offset_all);
        printf("all[]=%d %s\n", p->id, p->name);
        // container_of(n, struct process, all);
    }

#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
    // More complex with type checks: https://stackoverflow.com/questions/15832301/understanding-container-of-macro-in-the-linux-kernel
    for (node *n = alive.next; n != &alive; n = n->next) {
        struct process *p = container_of(n, struct process, n_alive);
        printf("alive[]=%d %s\n", p->id, p->name);
    }
}
