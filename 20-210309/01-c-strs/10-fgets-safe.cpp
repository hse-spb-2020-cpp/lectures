#include <cstring>
#include <cstdio>

int main() {
    std::printf("> ");

    char command[10];
    // Мы за безопасный gets!
    std::fgets(command, sizeof command, stdin);  // Всегда делает null-terminated строчку.
                                                 // Обрезает ввод.

    // Плюсовый std::string не обрезает, но может слопать всю память :(

    std::printf("command is |%s|\n", command);
}
