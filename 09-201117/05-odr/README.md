ODR (One Definition Rule)

API (Application Programming Interface)
    void foo();
    foo();

Gets converted by the compiler to:

ABI (Application Binary Interface)
    '_Zvfoo' --> 
    (name mangling)

Different compilers/flags => different ABIs => UB.
ABIs are incompatible and not checked.
    E.g.: size of `std::size_t`, `int*`, `int`, fields inside `std::vector`'s implementation...
