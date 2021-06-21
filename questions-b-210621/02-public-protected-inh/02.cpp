#include <iostream>

struct Base {
    virtual ~Base() {}
};

struct DerivedPub : /* public */ Base {
};

struct DerivedProt : protected Base {
};

struct SubDerivedProt : DerivedProt {
    Base b = DerivedProt();  // ok.
    Base *bthis = this;
};

int main() {
    SubDerivedProt obj;
    Base *b = obj.bthis;
    std::cout << b << "\n";
    std::cout << &obj << "\n";
    std::cout << dynamic_cast<DerivedPub*>(b) << "\n";
    std::cout << dynamic_cast<DerivedProt*>(b) << "\n";
    std::cout << dynamic_cast<SubDerivedProt*>(b) << "\n";
}
