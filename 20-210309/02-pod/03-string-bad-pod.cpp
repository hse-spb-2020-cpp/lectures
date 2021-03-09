#include <string>
#include <iostream>
#include <fstream>

struct Person {
    std::string first_name;
    std::string last_name;
};

int main() {
    Person p;
    p.first_name = "Ivan1234123412341234123412341234123412341234123412341234xxx";
    p.last_name = "Ivanov";

    {
        std::ofstream f("03.bin", std::ios::binary);
        f.write(reinterpret_cast<const char*>(&p), sizeof p);  // UB.
        // Потому что std::string - не POD. Точнее: не Trivial. Точнее: не TrivialCopyable.

        // Надо что-то такое (плюс как-то указать длину, чтобы можно было прочитать):
        // f.write(p.first_name.data(), p.first_name.size());
    }
}
