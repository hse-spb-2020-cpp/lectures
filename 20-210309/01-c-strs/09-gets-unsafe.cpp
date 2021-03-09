#include <cstring>
#include <cstdio>

int main() {
    std::printf("> ");

    char command[10];
    gets(command);  // Может случиться переполнение буфера (buffer overflow).
    // Top-1 уязвимостей в мире: https://ulearn.me/course/hackerdom/Perepolnenie_steka_3bda1c2c-c2a1-4fb0-9146-fccc47daf93b

    std::printf("command is |%s|\n", command);
}
