## 210112
* `iterator_traits<T>`:
  * `::value_type`, отличия от `T::value_type`.
  * Зачем нужен, когда в C++11 есть `auto`.
* Прокси-объекты (вроде `vector<bool>::iterator`)
  * Когда и зачем нужны.
  * Реализация: чтение, запись, `operator[]() const`, самоприсваивание.
  * Проблемы с `auto`, решение через `iterator_traits`
* Указатели на функции: синтаксис, использование, что происходит с перегрузками и шаблонами.
  * Не было: конверсии между указателями.