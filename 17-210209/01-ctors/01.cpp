struct nonmovable {
    nonmovable() {}
    nonmovable(const nonmovable &) = delete;
    nonmovable(nonmovable &&) = delete;
    nonmovable &operator=(const nonmovable &) = delete;
    nonmovable &operator=(nonmovable &&) = delete;
};

struct Base : private nonmovable {
    virtual ~Base() {}
};

struct Derived1 : Base {
};

struct Derived11 : Derived1 {
};

struct Derived2 : Base {
};

int main() {
    Derived1 d1a;
    Derived1 d1b = d1a;  // not slicing, but still prohibited.
    Derived11 d11;
    Derived1 d1c = d11;  // slicing
}
