#include <memory>

struct Base {
protected:
    Base() {}

    Base(const Base &) = default;

    Base(Base &&) = delete;
    Base &operator=(const Base &) = delete;
    Base &operator=(Base &&) = delete;

public:
    virtual ~Base() {}
    virtual std::unique_ptr<Base> clone() = 0;
};

struct Derived1 : Base {
    int x;

    Derived1() : x(100) {}
    Derived1(int x_) : x(x_) {}

protected:
    Derived1(const Derived1 &) = default;

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
    Derived11 d11;
    Derived1 d1 = d11;  // slicing!

    std::unique_ptr<Base> b1(new Derived1);
    //
    std::unique_ptr<Base> b2 = b1->clone();
}
