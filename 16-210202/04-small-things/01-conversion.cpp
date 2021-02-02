struct Base {
    int x;
};

struct Derived {
    Base b;

    operator Base&() { return b; }
    // Пропадают: виртуальные функции, совместимость по указателям, красивый доступ к 'x'.
};

int main() {
    Derived d;
    d.b.x = 10;

    Base &b = d;
    b.x = 20;
}
