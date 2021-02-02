#include <iostream>
#include <vector>

struct Human {
    std::string first_name, last_name;  // Possibly wrong.
};

struct Student : Human {
    std::string group;  // Possibly wrong.
};

int main() {
    std::vector<Human> people;
    std::vector<Student> students;
}
