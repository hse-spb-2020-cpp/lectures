# Старые вопросы
12-201208/04-global-vars-init/TODO.md
21-210316/00-questions/01.cpp

Self-move на самом деле допускается: оставляет объект в valid, but unspecified state: https://stackoverflow.com/a/66952566/767632
У меня требования чуть строже, но на самом деле это необязательно: для swap хватает unspecified state.

## `23-*`
https://stackoverflow.com/questions/12355118/which-standards-allow-anonymous-structs-and-unions-in-c-and-c
union { struct{} struct {} }
anonymous unions: C++ (all); C11
anonymous structs: C11

# Прочее
Термин RTTI, когда его отключают.
Независимость виртуального наследования, виртуальных функций, RTTI. Но `dynamic_cast`/`typeid` требуют чего-то конкретного из этих трёх.
https://www.ralfj.de/blog/2020/12/14/provenance.html
нельзя(?) себя пересоздать (намекнуть про std::launder)
