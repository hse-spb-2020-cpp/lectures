struct Base {
    virtual void foo() = 0;
};

struct Derived : Base {
    void foo() override final {
    }
};

struct MegaDerived : Derived {
    void foo() override {
    }
};
