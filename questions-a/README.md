# Общее
* В билете написано почти всё, что надо рассказать.
* Для каждой синтаксической конструкции должен быть приведён содержательный пример, когда это требуется или делает код проще/удобнее.
* Вас могут активно спрашивать вокруг билета: если вы сказали, что надо писать `Foo(bar)`, вас могут сразу же спросить, что будет при написании `Foo(&bar)`, вы должны ответить.
* "Не было" — не было на лекции, знать не надо, не спрашивают. Даже если было на практике.

# Обязательные знания
Если вы не знаете какие-то термины что-то из списка ниже, это автоматический неуд.

## Термины
* Свободная функция, функция-член
* Время жизни объекта: автоматическое, динамическое, статическое
* Undefined behavior: что может произойти, примеры:
  * Неинициализированная переменная: почему у неё нет никакого значения.
  * Выход за границы массива.
  * Dangling reference (висячая ссылка) при возврате из функции, при инвалидации в стандартном контейнере.
  * Разыменование `nullptr`.

## Переменные
* статическая типизация
* тип переменной
* размер переменной, размер типа
* типы <code>int</code>, <code>char</code>: типичные размеры. Например, на архитектуре <code>x86_64</code> под Linux в компиляторе <code>GCC</code>.

## Основные конструкции языков C и C++
* объявления переменных
* выражения и операторы:
  * арифметические (`+`, `-`, `*`, `/`, `%`, `+=`, `-=`, `*=`, `/=`, `%=`, `++`, `--`)
  * булевы (`<`, `<=`, `>`, `>=`, `==`, `!=`, `&&`, `||`, `!`)
  * на минимальную оценку необязательно знать: отличия постфиксных и префиксных операторов
* условный оператор `if`
* циклы `for`, `while`

## Функции
* объявление и определение функции, требуется отличать между собой (можно случайно перепутать, но после вопроса исправиться)
* вызов функции (синтаксис, не нужно знать mangling, конвенции вызовов)
* возвращаемое значение
* рекурсивный вызов

## Основные конструкции C++
* синтаксис `static_cast`
* синтаксис объявления пространств имён, обращения к элементу внутри пространства имён
* `auto` для объявления переменных
* range-based for, в том числе с `auto&` и `const auto&`
* синтаксис шаблонов, достаточный для написания минимального адаптера `stack<T>` поверх `deque`

## Классы
* определение класса, конструктор, деструктор, методы
* специальные методы (пять штук), правило нуля, правило пяти
* приватные/публичные поля и методы

## Const correctness
* синтаксис константных ссылок, применение при передаче аргументов
* невозможность изменять константные объекты и их поля
* const-qualifier у методов (const member function), перегрузка по const-qualifier (const overloading)

## Использование move-семантики
* эффективная инициализация полей класса из аргументов, принятых по значению или по rvalue-ссылке
* moved-from состояние у объектов: может быть не определено, может быть невозможно обнаружить, пример ошибки
* отсутствие необходимости `move` из результата функции, возвращённого по значению
* необходимость move для явной передачи владения `unique_ptr`
* почему `std::move` не выполняет никакого кода

## STL
* использование `vector` как динамического массива фиксированной длины, <code>push_back</code> и <code>emplace_back</code>
* использование `map` со стандартным компаратором, особенность <code>operator[]</code> (создаёт значение даже при чтении)

# Билеты
## 1. Базовый синтаксис
* Отличия и примерные границы значений встроенных типов ("на контесте"):
  * `int`, `double` (почему `0.1 + 0.2 != 0.3`), `bool`.
  * Знаковость и беззнаковость типов.
* Литералы: целочисленный и вещественный (в том числе `10'000` с C++14), символьный.
* Строковые литералы: обычный, raw string literal, экранирование (escaping).
* Склейка подряд написанных строковых литералов.
* `static_cast<>`: пример избавления от переполнения при умножении `int`'ов.
* Разница между `i++` и `++i`.

* Составные операторы присваивания (compound assignment operator) вроде `*=`, `/=`.
* Expression и statement, что такое тип expression.
* Синтаксис: `for` (включая объявление переменной в `init`), `while`, `if`, где expression и statement.
* Range-based `for`, в том числе с использованием (константных) ссылок и `auto`, где возникают копирования.
* Порядок вычислений: https://notes.algoprog.ru/cpp/additional.html#id4
  * Внутри выражений: аргументы функции, операнды операторов.
  * При инициализации нескольких переменных.
  * При инициализации при помощи `{}`.
  * Что изменилось в C++17, почему в `a = b` важно сначала вычислить `b`, потом `a`.

## 2. Объявление объектов внутри одного файла
* Допустимые имена переменных, функций, констант, классов:
  * Нельзя начинать с цифры.
  * Где посмотреть ключевые слова.
  * Где можно и нельзя ставить `_`: https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier
  * Что происходит от некорректного имени в разных случаях.
* Объявление и определение: функции, класса, в том числе шаблонного.
* Взаимная рекурсия для: функций, классов, методов внутри одного класса, методов между классами (`A::foo()` возвращает `B` и наоборот).
* Пространства имён: глобальное, вложенное, синтаксис для объявления вложенных namespace с C++11.
  * Почему нельзя просто сделать класс со статическими членами?
* Обращение к вложенному namespace, к глобальному namespace.
* Псевдонимы типов: `typedef`, `using`, `template<> using`.
* `using namespace`, где можно и нельзя использовать и почему, особенности `using namespace <другая-библиотека-вроде-std>`.

Тесно связано с: линковка.

## 3. Объявление переменных
* Объявление нескольких переменных, указателей, ссылок, в том числе константных.
* Создание временного объекта.
* C++17: существование Class Template Argument Deduction, пример.
* Отличия copy initialization и direct initialization.
  * Тесно связано с: преобразования (conversions).
* Неинициализированные переменные/поля.
* `[[maybe_unused]]`
* Инициализация при помощи `{}`:
  * Для тривиальных типов.
  * Для нетривиальных типов.
  * Для массивов/векторов, в том числе вложенных.
  * Временных объектов.
  * Не было: точное определение агрегатных классов.
* Пример, где инициализация через `{}` и `()` компилируются и ведут себя по-разному.
* Ссылки.
  * Можно ли отличить ссылку от объекта, на который она указывает.
  * Использование константных ссылок.
  * Константная ссылка не обещает, что объект не меняется (если ссылка на мутабельный объект).
* `auto` и его модификации, как выводится тип.
  * Конвенция Almost Always Auto, в том числе для шаблонных типов.
* Необходимость слова `typename` в некоторых случаях.
* Structured binding для пар, простых структур, массивов, со ссылкой.
  * Не было: как делать для своих структур, что на самом деле происходит внутри, что происходит с временными значениями.

Тесно связно с: параметры функций.

## 4. Функции
* Параметры
  * Синтаксис (пропущенное имя, значение по умолчанию в объявлении/определении)
  * Передача параметров по: значению, `&`, `const&`, `&&`. Что выбрать при наличии или отсутствии move-семантики и почему.
  * Примеры: `push_back`, `Person(string first_name)`.
  * Передача `{}` в параметры.
* Возвращаемый тип
  * Использование `auto` и `->`, удобство при определении функций-членов
  * Как выводится просто `auto` (возможно, с модификаторами), в том числе для рекурсии и `void`.
* Возвращаемое значение
  * Возврат по значению, ссылке, константной ссылке.
  * Возврат `{}` и взаимодействие с `auto`.
  * `[[nodiscard]]`, возможные стратегии применения: когда не имеет смысла игнорировать возвращаемое значение, когда игнорировать опасно
* Перегрузка функций:
  * Что входит в сигнатуру, что не входит.
  * Синтаксис `= delete` с C++11.
  * Проблемы с разделением `nullptr`, `NULL`, `0`.
  * Не было: `noexcept`.
  * Не было: правил выбора перегрузки точнее "выбирается перегрузка наиболее точная или ambiguous".
* Указатели на функции: синтаксис, использование.
  * Не было: конверсии между указателями, что происходит с перегрузками.

Тесно связано с: методы.

## 5. Жизнь объектов
* Семантика копирования: что ожидается в C++ при переприсваивании объекта, передаче в качестве аргумента функции, возврата из функции.
  * А если не `Foo a;`, а `Foo &a = .....;`?
* Время жизни объектов (storage): автоматическое (automatic), ручное/динамическое (dynamic), статическое (static).
  * Синтаксис создания/удаления объекта.
  * Когда вызывается конструктор/деструктор и с какими параметрами.
* Время жизни временных объектов.
  * Когда создаётся/уничтожается временный объект ("наивный взгляд" до C++14 включительно).
  * Продление жизни временого объекта.
  * Проблема продления жизни в `std::min()`/`std::max()`.
  * Проблема продления жизни в range-based-for и цепочке вызовов `foo().bar()`.
* Локальные объекты со static storage duration (локальные статические переменные):
  * Когда создаётся/уничтожается.
  * Чем инициализируются, можно ли инициализировать параметром функции.

Тесно связано с: move-семантика.

## 6. Move-семантика
* Категории значений: lvalue/xvalue/prvalue; обобщённые glvalue/rvalue.
  * Определение в C++11/C++14.
  * Определение в C++17 и позже.
* rvalue-ссылки и lvalue-ссылки: что к чему привязывается
* Почему у move constructor и move assignment именно такая сигнатура, как работает разрешение перегрузок, почему не надо добавить `const`.
* `std::move`: как работает, почему ничего не делает, где используется, как реализовать свой.
* Примеры return value optimization, named return value optimization до C++17.
* Guaranteed copy elision в C++17: новый смысл prvalue.
* Возврат объектов:
  * Возврат неперемещаемых объектов из функции.
  * Когда (не) надо писать `return std::move(foo);`

Тесно связано с: функции (как передавать параметры), жизнь объектов.

## 7. Стандартная библиотека
* Что такое `namespace std`.
* Контейнеры
  * `std::vector`, `std::string`, `std::list`, `std::map`: когда что использовать
  * Основные операции и время работы: `push_back`/`emplace_back`, `front()`/`back()`, `operator[]`, `size()`, `capacity()`, `resize()`, `reserve()`.
  * Особенность `operator[]` у `std::map`: элемент всегда создаётся, даже если его не было, почему.
  * Инвалидация итераторов и ссылок на элементы: когда, какие последствия.
* Итераторы
  * Конвенции с `begin()`/`end()`
  * Не было: иерархия итераторов, `reverse_iterator`.
* Алгоритмы
  * `sort`, передача своего компаратора.
  * `lower_bound`, `upper_bound`, точные инварианты.
* Ввод-вывод
  * `cin`/`cout`/`ifstream`/`ofstream`/`istream`/`ostream`/`sstream`
  * Какие `#include` бывают (2 шт)
  * Синтаксис ввода и вывода.
  * Перегрузка операторов ввода-вывода для своих классов: конвенции, почему так работает, когда нужны friend-операторы и зачем.
  * Не было: манипуляторы, свои манипуляторы.

Тесно связано с: функторы, лямбда-функции, базовый синтаксис (порядок вычислений).

## 8. Указатели
* Базовый синтаксис: объявление, разыменование, взятие адреса, `->`.
  * Не было: многоуровневые указатели, aliasing.
* Реализация двусвязного списка, конструкции вроде `a.next->prev`.
* Нулевой указатель.
  * Отличия `nullptr` от `0`
  * Проверка на нулевой указатель.
  * Разменование `nullptr`.
* Ручное управление памятью: `new`, `delete`, `new[]`, `delete[]`, когда что использовать.
  * Не было: разница между `new int;` и `new int();`
  * Утечка памяти: UB ли, какие последствия, как ловить, как читать вывод sanitizer и Valgrind с примерами.

## 9. Классы
* Синтаксис.
* Поля: обычные, константные, ссылки, порядок создание и уничтожения и когда он важен.
* Семантика копирования, особенности полей-констант/ссылок при копировании и инициализации.
* Конструктор: синтаксис, параметры, когда вызывается, делегирующие конструкторы.
* Инициализация полей: когда что можно и нужно использовать, как они взаимодействуют между собой и с делегирующим конструктором
  * По умолчанию (тривальных и с конструктором по умолчанию)
  * Default member initializer (C++11)
  * Member initialization list
  * Переприсваивание в конструкторе
* Приватные/публичные поля и методы
  * Кто к кому может обращаться в том числе не у `this`
  * Паттерн: геттеры и сеттеры для поддержания инвариантов
  * Не было: `protected`, наследование.
* Отличия `struct`/`class`.
* Агрегатная инициализация простых классов через `{}`
  * Не было: строгое определение "простого класса" и его отличия между стандартами C++11, C++14, C++17, C++20.

## 10. Функции-члены (методы)
* Синтаксис объявления и вызова через `.` или `->`.
* Ключевое слово `this`
  * Где его можно не писать, зачем писать хоть где-то.
  * Чем метод отличается от свободной функции.
  * Захват `this` в лямбды: `[]`, `[=]`, `[&]`, `[this]`, `[*this]`.
* Ключевое слово `template` при вызове некоторых методов.
* Const correctness: ограничение доступа к полям (в том числе ссылочным и указателям) при константном `this`.
  * Когда возникает константный `this`.
  * Const qualifier и ограничения внутри такого метода.
  * Перегрузка по const qualifier, когда нужна.
* Ref qualifier `&` в терминах категорий значений, когда нужен.
  * Не было: ref qualifier `&&`.
* Определение методов внутри и снаружи класса, неявный `inline` и зачем.
* Удобство `auto foo() -> Foo` при определении методов снаружи класса.

## 11. Статические члены класса
* Статические поля: объявление, определение, когда что необходимо и где, обращение изнутри класса и снаружи, отличие от глобальных переменных.
* Статические константы: объявления, определение, когда что нужно и где (для тривиальных и нетривиальных типов).
  * Не было: `constexpr`, `char[]`.
* Статические методы, отличие от свободных функций.
* Паттерн: статический метод как конструктор с именем.

Тесно связано с: линковка.

## 12. Специальные методы
* Деструктор, конструктор копирования/перемещения, оператор присваивания/перемещения.
  * Когда что вызывается: разная инициализация (copy, direct), передача как аргумента, возврат из функции.
* Реализация `unique_ptr` и `shared_ptr` (без deleter и массивов).
* Правило пяти: формулировка.
  * Проблемы с самоприсваиванием.
    * Не было: корректность self-move, считаем, что не отличается от self-assignment.
  * Copy-swap-idiom превращает в правило четырёх.
* "Нарушение" правила пяти: когда деструктор может быть тривиальным, а копирование нетривиальным (list-heap и обобщение).
* Как писать специальные методы в шаблонных классах.

## 13. Друзья и перегрузка операторов
* Друзья-классы (в том числе шаблонные).
* Друзья-функции (шаблонные — в отдельном билете).
  * Определение внутри класса, снаружи класса.
  * Объявление до класса, внутри класса.
* Виды перегружаемых операторов
  * Унарные, постфиксные/префиксные (как отличить при перегрузке?), бинарные, составное присваивание, сравнение.
  * `operator*`, `operator->` (в том числе вызов по цепочке).
  * `operator()`.
  * `operator[]`.
* Для каждого вида:
  * Что через кого выражать для минимизации лишних копирований и кода.
  * Конвенция для типов параметров, типа возвращаемого значения.
  * Делать оператор свободной функцией или членом, последствия для преобразований (conversions).
* Отличия `a + b`, `a.operator+(b)`, `a.operator+()`.
* Проблемы с самоприсваиванием и самомодификацией (пример простой некорректной реализации `/=` для класса рациональной дроби `Ratio`).
* Не было: `operator<=>`

## 14. Преобразования
* Конструкторы для преобразований и операторы преобразования.
  * Зачем два способа.
  * Что когда выбирается, когда возникают неоднозначности.
* Допустимые цепочки преобразований: не более одного пользовательского, но числовые можно.
* Где вызывается явное преобразование (explicit), а где неявное (implicit).
  * В том числе в `static_cast<>`.
  * В том числе при работе с функциями (параметры, возвращаемое значение) и комбинировании с `{}`. Например, `return {}`.
  * В том числе для `bool`, но не других числовых типов.
      Не было: safe bool idiom.
* Ключевое слово `explicit`, зачем нужно для конструкторов с несколькими параметрами или с нулём параметров.

## 15. Шаблоны классов
* Шаблоны классов.
  * Синтаксис объявления.
  * Параметры шаблона: типы (разница `typename`/`class`), значения простых типов (без строго определения "простоты").
  * Параметры по умолчанию, отсутствие имени у параметра.
  * Параметры-шаблоны, передача в них шаблонов с параметрами по умолчанию.
  * Ключевые слова `typename`, `template` для обращения внутрь зависимых типов.
* Отличие шаблона `Foo` и инстанцирования шаблона с параметрами по умолчанию `Foo<>`, когда что
  * Когда можно писать `Foo` вместо `Foo<T>`, удобство с `auto Foo<T>::foo() -> Foo`.
* Инстанцирование
  * Независимость по методам.
  * Когда происходит неявное инстанцирование.
  * Когда тип шаблона может быть incomplete, а когда не может.
  * Не было: явное инстанцирование.
* Независимость инстанциаций шаблона.
* Определение методов и статических членов шаблонного класса внутри и вне класса.

## 16. Прочие шаблоны
* Шаблоны функций.
  * Автовывод параметров шаблона, когда не сработает.
  * Базовое взаимодействие с перегрузками, синтаксис `foo<>(10);`.
* Шаблонные методы/конструкторы в обычных и шаблонных классах.
  * Определение внутри и вне класса.
* Автовывод параметров шаблона класса (Class Template Argument Deduction) из конструкторов: при инициализации переменных, при создании временных объектов.
* Шаблоны переменных (C++17).

## 17. Специализации
* Полные и частичные специализации шаблона класса: синтаксис, независимость специализаций.
* Использование для метапрограммирования: `is_void`, `is_reference`, `is_same`, `is_vector`, `conditional`.
* Полные специализации функций.
  * Ограничения по сравнению со полными специализациями шаблонов класса.
  * Влияение на автовывод типов.
  * Отличия от перегрузки.
* Как использовать `std::swap`, чтобы работали сторонние контейнеры.
  * Запрет на добавление перегрузок в `namespace std` и необходимость частичной специализации.
  * Костыль через `using std::swap;` и ADL (Argument-Dependent Lookup).
  * Не было: детальных правил ADL.

## 18. Шаблонные друзья
* Про всех рассказывать и показать примеры: когда работает, когда нет, к чему у кого есть доступ.
  * Будьте осторожны с багами GCC и Clang при демонстрации.
* Шаблонные друзья нешаблонных классов:
  * Класс-друг: общий случай, полные специализации.
  * Функция-друг: общий случай, полные специализации.
* Нешаблонные друзья шаблонных классов:
  * Класс-друг.
  * Функция-друг, реализация внутри и снаружи класса, с зависимостью от параметров шаблона и без.
* Шаблонные друзья шаблонных классов:
  * Класс-друг: общий случай, полные специализации.
  * Функция-друг: общий случай, полные специализации, реализация внутри и снаружи класса, с зависимостью от параметров шаблона и без.
* Стандартные проблемы и решение:
  * Multiple definition при определении шаблонной функции-друга внутри шаблонного класса, причём функция не зависит от параметров класса.
  * Пример реализации `Ratio<int>::operator+=(Ratio<int>&)` (увеличение рациональной дроби с числителем и знаменателем типа `int`) внутри класса и вне класса, отличия.

## 19. Функторы и лямбды
* Реализация своих функторов.
  * Перегрузка `operator()`, когда нужен const qualifier.
  * Как использовать с `std::sort`, `std::set`, в том числе функтор без конструктора по умолчанию.
  * Использование указателя на функцию как функтор.
  * Конвенция стандартной библиотеки C++ про отсутствие состояния у функторов, `std::ref`.
* Использование функторов.
  * Передача в качестве аргумента функции.
  * Сохранение в поле класса.
* Лямбда-функции (C++11):
  * Синтаксис и expression для создания, во что превращается лямбда.
  * Возвращаемый тип: неявный вывод, явное указание.
  * Независимость типов у разных лямбда-функций, почему нельзя запихнуть лямбду в `set`.
  * Неявное преобразование лямбда-функции без захватов в указатель на функцию.
  * Захваты: отсутствие, по значению, по ссылке, всех по значению, всех по ссылке, `*this` (C++17), с инициализацией (C++14).
  * Ключевое слово `mutable`.
  * Шаблонные лямбды.

## 20. Препроцессор
* Как пользоваться `#ifdef DEBUG`, `#define` и ключом `-DDEBUG` (в случае GCC/Clang).
* Что делает `#include`, в том числе `#include <iostream>` и `#include <iosfwd>`.
* Проблемы с `assert(v == std::vector{1, 2, 3})` и как их решать.
* Проблемы с `operator,` и вызовом макросов: как добиться, чтобы `assert(true), assert(false);` работало.
* Как использовать `#macro_arg`, `__FILE__`, `__LINE__` для создания своего макроса `CHECK` в тестовом фреймворке.
* Возможность писать в макросах лишь куски корректного кода.
  * Общая идея создания фреймворка для автотестов с авторегистрацией тестов: `TEST_CASE("hi") { CHECK(1 == 2); }`.
  * Не было: точный код, макросная магия для генерации уникальных имён тестов, склейка токенов через `##`.

## 21. Программы из нескольких файлов
* Мотивация.
* Единицы трансляции и файлы.
* Как из одного файла заиспользовать глобальную/переменную/класс/функцию из другого (нешаблонные)?
* External linkage/internal linkage.
  * Слово `static` и anonymous namespace, где применять.
* Формулировка One Definition Rule, пример ошибок линковщика: multiple definition, undefined reference.
* Требования к совпадению определений классов.
* Типичный заголовочный файл.
  * Конвенция именования заголовочных файлов.
  * Include guards: зачем, как правильно, осторожно с `_`.
  * Опастность неявного включения, концепция include what you use, примеры из стандартной библиотеки вашего компилятора.
  * Запрет на реализацию функций.
* Взаимная рекурсия между заголовками и forward header.
* Что обычно (не) пишут в своих заголовочных файлах (в том числе forward); `using namespace std;`.
* Где объявляются/определяются шаблонные функции/классы/константы.

## 22. One Definition Rule
* One Definition Rule (ODR).
  * Как можно нарушить и получить IFNDR (Ill-Formed, No Diagnostic Required) и ошибку компиляции.
  * Как можно нарушить и получить IFNDR, но не ошибку компиляции: для переменной, для функции, для класса.
* Ситуации, где нельзя гарантировать единственное определение (шаблоны, inline-функции, пример из фреймворка для автотестов).
* Использование `inline`-переменных/функций/методов для обхода ODR.
  * Требования к нескольким определениям.
* Отличия `inline` от `static`/anonymous namespace.

## 23. Static initialization order fiasco
* Глобального состояние программы: когда можно избавиться, когда необходимо.
* Создание и уничтожение объектов со статическим временем жизни.
  * У кого статическое время жизни? В том числе у некоторых локальных переменных.
  * Гарантии про порядок создания и уничтожения объектов.
* Пример static initialization order fiasco.
  * Когда существует некорректный порядок инициализации.
  * Когда не существует корректного порядка инициализации.
  * Когда происходит UB (выглядящий как утечка памяти), при этом в программе используется только `std::string`.
* Решение: идиома construct on first use.
  * Отличия решения с автоматическим временем жизни и с динамическим.
