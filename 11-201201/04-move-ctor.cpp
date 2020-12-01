#include <string>
#include <iostream>

struct my_string {
    my_string() {
        std::cout << "my_string()\n";
    }

    my_string(const char*) {
        std::cout << "my_string(const char*)\n";
    }

    my_string(const my_string &) {
        std::cout << "my_string(const my_string&)\n";
    }

    my_string(my_string &&) {
        std::cout << "my_string(my_string&&)\n";
    }

    my_string& operator=(const my_string &) {
        std::cout << "operator=(const my_string&)\n";
        return *this;
    }

    my_string& operator=(my_string &&) {
        std::cout << "operator=(my_string&&)\n";
        return *this;
    }
};

struct Person {
    my_string first_name, last_name;
    #if 0
    // Наивный способ. Надо 2^k перегрузок.
    Person(const my_string &a, const my_string &b)
        : first_name(a)
        , last_name(b) {
    }
    Person(my_string &&a, my_string &&b)
        : first_name(/* xvalue */ std::move(/* lvalue */ a))
        , last_name(/* xvalue */ std::move(/* lvalue */ b)) {
    }
    Person(const my_string &a, my_string &&b)
        : first_name(/* lvalue */ a)
        , last_name(/* xvalue */ std::move(/* lvalue */ b)) {
    }
    // WTF
    #else
    // Хитрый способ. Одна перегрузка. Каждый аргумент независимо:
    // * Либо инициализируется напрямую из prvalue, после чего происходит move (как и выше).
    // * Либо инициализируется из lvalue копированием, после чего происходит move (лишний move, но это нестрашно).
    // * Либо инициализируется из xvalue перемещением, после чего происходит move (лишний move, но это нестрашно).
    // Дополнительно вызываются лишний раз деструкторы этих временных объектов. Но это тоже обычно нестрашно.
    Person(my_string a, my_string b)
        : first_name(std::move(a))
        , last_name(std::move(b)) {
        // assert(a.empty());  // Unspecified. Не UB, может упасть, может не упасть.
    }

    // При этом ни в одном из способов мы пока(!) не можем напрямую проинициализировать поля без перемещений/копирований.
    #endif
};

int main() {
    Person p1("Egor", "Suvorov");

    std::cout << "==========\n";
    my_string name("Egor");
    Person p2(name, "Suvorov");
    // name не должен испортиться, из него должны были скопировать.
}
