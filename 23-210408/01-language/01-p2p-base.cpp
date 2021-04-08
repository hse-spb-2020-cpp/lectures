struct Base {};
struct Derived : Base {};
struct Derived2 : Base {};

int main() {
    Base b;
    Derived d;
    Derived2 d2;

    {
        Base *pb = &b;
        Derived *pd = &d;
        pb = pd;
        // pd = pb;
        /* Причина:
        pb = &d2;  // Base* <-- Derived2*
        pd = pb;
        pd указывает на Derived2???
        */
    }
    // https://isocpp.org/wiki/faq/proper-inheritance#derivedptrptr-to-baseptrptr
    {
        Base *pb = &b;
        Base **ppb = &pb;
        Derived *pd = &d;
        Derived **ppd = &pd;

        // Simple
        // ppd = ppb;
        /* Причина
        pb = &d2;
        // *ppb == &d2
        ppd = ppb;
        // *ppd == &d2
        */

        // More complicated
        ppb = ppd;
        /* Причина
        ppb = ppd;
        *ppb = &d2;
        // *ppb == &d2
        // *ppd == &d2
        */
    }
}
