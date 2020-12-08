Инициализация глобальных переменных в C++: два этапа:

https://en.cppreference.com/w/cpp/language/initialization#Static_initialization

1. Zero-initialization: всё зануляется на уровне байт.
   Никаких конструкторов.
   // Секция .bss в exe: "заполнить нулями столько-то мегабайт".

2. (опционально) Constant initialization: инициализируются константы.
   // Секция .data в exe: заготовленные байты с константами.

3. "Deferred dynamic initialization" (термин неточный): всё остальное;
    вызываются конструкторы, вычисляются инициализаторы.

    Порядок инициализации переменных между разными translation unit не знаем.
    Внутри одного TU: сверху вниз.
    https://isocpp.org/wiki/faq/ctors#static-init-order

    TODO: можно ли "перемешать" инициализацию между разными TU?
