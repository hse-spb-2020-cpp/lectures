Было на практике 19.11.2020, повторить вопросы:

* Сборка сторонней библиотеки: include path, library path
* Anonymous namespace/сишный `static`.
  * Кстати, это называется external/internal linkage.
* Order Initialization Fiasco. Решение Construct On First Use Idiom: `Object*`, чтобы не обманываться, что мы решили удаление.
  * UPD 04.12.2020: осторожно: clang-tidy хочет, чтобы владеющие указатели оборачивались в `gsl::owner<>`.
