https://stackoverflow.com/questions/12355118/which-standards-allow-anonymous-structs-and-unions-in-c-and-c

anonymous unions: C++ (all); C11
   Они нужны понятно зачем, смотри lab09-calc

anonymous structs: C11
    Они нужны, чтобы писать вот так:
    union { struct{} struct {} }
