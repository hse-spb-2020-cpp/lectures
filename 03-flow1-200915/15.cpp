#include <string>
#include <vector>

struct Person {
    std::string name = "Ivan";
    std::string surname = "Ivanov";
    std::vector<int> vec;

    Person() {
    }
    Person(int x) : name("Petr"), vec(20) {  // member initialization list
    }
    Person(double x) : Person(10) { // delegating constructor
        surname = "Petrov";
    }
};

int main() {
    Person p1;  // Person()
    Person p2(10);  // Person(10)
}
