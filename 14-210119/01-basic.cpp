#include <iostream>

struct Base {  // Базовый класс (base) в C++. Родительский/предок/надкласс/суперкласс (Python, Java).
    int x = 10;
    void foo() const {
        std::cout << "x=" << x << "\n";
    }
};

struct Derived : Base {  // Производный класс (derived). Дочерний/подкласс.
    int y = 20;
    void bar() const {
        foo();
        std::cout << "y=" << y << "\n";
    }
};

struct Container {
    Base b;  // Композиция: взяли один объект и над ним надстроили новый.
    int y = 20;
    int &x = b.x;

    void foo() const {
        b.foo();
    }

    void bar() const {
        foo();
        std::cout << "y=" << y << "\n";
    }
};

int main() {
    {
        Derived d;
        std::cout << "d.x=" << d.x << ", d.y=" << d.y << "\n";
        d.foo();
        d.bar();
    }
    {
        Container c;
        c.x = 55;
        std::cout << "c.x=" << c.x << ", c.y=" << c.y << "\n";
        c.foo();
        c.bar();
    }
    {
        Container c1, c2;
        c1.x = 55;
        c2.x = 60;
        std::cout << c1.x << " " << c2.x << "\n";
    }
    std::cout << sizeof(Base) << "," << sizeof(Derived) << "," << sizeof(Container) << "\n";
//    std::cout << sizeof(int*) << "\n";
}
