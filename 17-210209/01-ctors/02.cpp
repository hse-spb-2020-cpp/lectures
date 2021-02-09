#include <memory>

struct nonmovable {
    nonmovable() {}
    nonmovable(const nonmovable &) = delete;
    nonmovable(nonmovable &&) = delete;
    nonmovable &operator=(const nonmovable &) = delete;
    nonmovable &operator=(nonmovable &&) = delete;
};

struct Base : private nonmovable {
    virtual ~Base() {}
    virtual std::unique_ptr<Base> clone() = 0;
};

struct Derived1 : Base {
    int x;

    Derived1() : x(100) {}
    Derived1(int x_) : x(x_) {}

protected:  // Derived11 этот конструктор тоже пригодится.
    Derived1(const Derived1 &other) : x(other.x) {}

public:
    std::unique_ptr<Base> clone() override {
        return std::make_unique<Derived1>(*this);
    }
};

struct Derived11 : Derived1 {
};

struct Derived2 : Base {
};

int main() {
    std::unique_ptr<Base> b1(new Derived1);
    //
    std::unique_ptr<Base> b2 = b1->clone();
}
