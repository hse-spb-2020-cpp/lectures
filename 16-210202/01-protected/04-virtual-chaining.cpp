#include <string>
#include <iostream>

struct Employee {
    std::string first_name;

protected:
    virtual void print(std::ostream &os) {
        os << first_name;
    }
};

struct Developer : Employee {
    std::string language;  // Хорошо бы сделать enum'ом.

protected:
    void print(std::ostream &os) override {
        Employee::print(os);
        os << " " << language;
    }
};

int main() {
}
