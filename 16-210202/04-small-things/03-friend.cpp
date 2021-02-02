struct Base {
private:
    int x = 0;
};

struct Derived1 : Base {
private:
    int y = 0;
    friend void foo();
};

struct Derived2 : Derived1 {
private:
    int z = 0;
};

void foo() {
    Derived2 d2;
    // d2.x++;
    d2.y++;
    // d2.z++;
}

int main() {
}