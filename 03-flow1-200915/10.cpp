int a; // 1

namespace server {
int a; // 2

void foo() {
    a = 20; // 2
    ::a = 30;  // 1
}

namespace bar {
int x;
}
}

namespace client {
int a; // 3

void foo() {
    server::a = 1;  // 2
}
}

namespace server::bar {
int y;
}

int main() {
    server::a = 10; // 2
    client::a = 20; // 3
    server::bar::x = 50;
    server::bar::y = 60;

    a = 30; // 1
    ::a = 30; // 1
}
