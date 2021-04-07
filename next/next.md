# Старые вопросы
12-201208/04-global-vars-init/TODO.md
21-210316/00-questions/01.cpp

Self-move на самом деле допускается: оставляет объект в valid, but unspecified state: https://stackoverflow.com/a/66952566/767632
У меня требования чуть строже, но на самом деле это необязательно: для swap хватает unspecified state.

# Исключения
## exception_ptr, nested exceptions
Для многопоточности и чего-то такого?
https://habr.com/ru/post/160955/

# Си
## Трюк с `OpaqueVendorType` для типобезопасности в Си
после extern "C", mangling и остального

https://stackoverflow.com/a/573574/767632

# Прочее
Термин RTTI, когда его отключают.
Независимость виртуального наследования, виртуальных функций, RTTI. Но `dynamic_cast`/`typeid` требуют чего-то конкретного из этих трёх.
https://www.ralfj.de/blog/2020/12/14/provenance.html
нельзя(?) себя пересоздать (намекнуть про std::launder)
union{}
