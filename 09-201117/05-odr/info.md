ODR (One Definition Rule)

API (Application Programming Interface)
    void foo();
    foo();

Gets converted by the compiler to:

ABI (Application Binary Interface)
    '_Zvfoo' --> 
    (name mangling)

Different compilers/flags => different ABIs.
ABIs are incompatible and not checked.
