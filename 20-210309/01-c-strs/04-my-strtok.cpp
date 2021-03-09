#include <cstring>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    char command_line[] = "arg1 arg2 arg3";
    // std::strtok занимается примерно этим.
    for (int i = 0; command_line[i]; i++) {
        if (command_line[i] == ' ') {
            command_line[i] = 0;
        }
    }

    std::vector<char*> args = {
        command_line + 0,
        command_line + 5,
        command_line + 10,
    };
    std::cout << args[0] << "\n";
    std::cout << args[1] << "\n";
    std::cout << args[2] << "\n";

    std::cout << "argc=" << argc << "\n";
    for (int i = 0; i < argc; i++) {
        std::cout << "argv[]="
                  << argv[i]
                  << "; strlen="
//                  << sizeof(argv[i])  // Так нельзя делать никогда! Это sizeof(char*)
                  << std::strlen(argv[i])
                  << "; p="
                  << static_cast<void*>(argv[i]) << "\n";
    }
}
