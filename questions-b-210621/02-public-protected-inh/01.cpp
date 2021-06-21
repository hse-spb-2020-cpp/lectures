struct Base {
};

struct DerivedPub : /* public */ Base {
};

struct DerivedProt : protected Base {
};

struct SubDerivedProt : DerivedProt {
    Base b = DerivedProt();  // ok.
};

int main() {
    Base a = DerivedPub();
    Base b = DerivedProt();  // not ok.
}
