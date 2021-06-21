#include <string>
#include <utility>

struct do_not_construct_base {};
struct Base {
    std::string name;

    Base(std::string name_) : name(std::move(name_)) {}
protected:
    Base(do_not_construct_base);  // not implemented
};

struct Derived1 : virtual Base {
    Derived1(std::string name_) : Base(std::move(name_)) {}
protected:
    Derived1(do_not_construct_base) : Base(do_not_construct_base{}) {}
};

struct Derived2 : virtual Base {
    Derived2(std::string name_) : Base(std::move(name_)) {}
protected:
    Derived2(do_not_construct_base) : Base(do_not_construct_base{}) {}
};

struct MegaDerived : Derived1, Derived2 {
    MegaDerived(std::string name_)
        : Base(std::move(name_))
        , Derived1(do_not_construct_base{})
        , Derived2(do_not_construct_base{}) {}
};
