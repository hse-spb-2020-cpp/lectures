## 1.1.1. Мотивация метапрограммирования-1
Обобщение:
* `std::distance` должен работать для разных итераторов по-разному:
  * `last - first`
  * `while (first != last) ++first;`
* `vector<T>::resize` может вести себя по-разному:
  * Если есть nothrow move constructor, то можно сразу перемещать элементы из буфера в буфер
  * Если нет, то надо всегда копировать, чтобы была strong exception safety.
* `std::any`/`std::function` — хотим small object optimization.
  * В зависимости от того, что скормили в конструктор, объект ведёт себя по-разному

---
## 1.1.2. Мотивация метапрограммирования-2
Хотим, чтобы компилятор делал рутину за нас:

```c++
int dijkstra(const Graph &g, int start, int end);
int floyd(const Graph &g, int start, int end);
int random_shuffle(const Graph &g, int start, int end);
// Хотим, чтобы можно было писать так:
check_answer_same(dijkstra, floyd, random_shuffle)(some_graph, 0, n - 1);
```
```c++
using PersonSerializer =
    Serialize<"name", &Person::getName,
              "age", &Person::getAge>;
PersonSerializer s(std::cin);
s << getPerson();  // name=Ivan, age=23
```
```c++
CalculatorFunctions functions = {
    {"sin", std::sin},
    {"func", [](double a, double b, double c) { return a + b * c; }}
};
```

DFS в compile time (dependency injection): есть куча классов с конструкторами, надо собрать объект.

---
## 1.1.3. Что такое метапрограммирование?
* Программирование — пишем программу, которая работает.
* Метапрограммирование — пишем программу, которая пишет программу, которая работает.

Из хорошего: смотри "мотивация".

Из плохого:

* Потенциально сложный код.
  * От `#define` приходишь в ужас.
  * Метапрограммирование на шаблонах (TMP, template metaprogramming) в C++ "открыли", а не придумали.
  * Из-за этого тоже можно прийти в ужас.
  * С C++11 становится всё лучше и лучше.
* Получается "язык программирования в языке программирования"
  * Надо учить.
  * Надо проектировать (а это сложно!)
* Время компиляции.

---
## 1.2. Каков план?
* Надо что-то вычислять на этапе компиляции.
  * `constexpr`, шаблоны.
* Надо что-то узнавать и понимать про типы.
  * Type traits, шаблоны.
* Надо что-то узнавать и понимать про код вообще.
  * `noexcept(...)`, `decltype(...)`, шаблоны.
* Надо уметь работать во всех случаях.
  * Всякие тонкости, о которых обычно не думаешь.

---
## 2.1.1. Вычисления без constexpr
```c++
int factorial(int n) {
    int res = 1;
    optional<int> unused1;
    vector<int> unused2(n);
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}
// static_assert(factorial(5) == 120);
// ...
assert(factorial(5) == 120);
std::vector<int> vec(factorial(5));
// std::array<int, factorial(5)> arr;
std::cout << factorial(readInt());
```
* Можно использовать любые конструкции языка.
* Можно объявлять свои классы, поля, переменные.
* Можно менять переменные.
* Можно выделять память.
* Нельзя использовать результат в константных выражениях.

---
## 2.1.2. Вычисления с constexpr
```c++
constexpr int factorial(int n) {
    int res = 1;
    optional<int> unused1;
    // vector<int> unused2(n);
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}
static_assert(factorial(5) == 120);
// ...
assert(factorial(5) == 120);
std::vector<int> vec(factorial(5));
std::array<int, factorial(5)> arr;
std::cout << factorial(readInt());
```

* Можно использовать многие конструкции языка: нельзя `goto` и не-`constexpr` функции.
* Можно использовать скалярные типы и типы с `constexpr`-конструктором и тривиальным деструктором (вроде `optional` от простых типов).
* С C++14 можно менять переменные внутри функций!
* До C++20 нельзя выделять память => нельзя `vector`

---
## 2.1.3. Строковые литералы
```c++
template<size_t N>  // Лучше не const char*, чтобы сразу знать размер.
constexpr auto parse_format(const char (&s)[N]) {
    int specifiers = 0;
    array<char, N> found{};
    for (size_t i = 0; i < N; i++) {  // strlen не constexpr
        if (s[i] == '%') {
            if (i + 1 >= N)
                throw std::logic_error("Expected specifier after %");
            i++;
            found[specifiers++] = s[i];
            if (!(s[i] == 'd' || s[i] == 'c' || s[i] == 's'))
                throw std::logic_error("Unknown specifier");
        }
    }
    return pair{specifiers, found};
}
static_assert(parse_format("hello%d=%s").first == 2);
static_assert(parse_format("hello%d=%s").second[0] == 'd');
static_assert(parse_format("hello%d=%s").second[1] == 's');
```
* Так можно распарсить [что угодно](https://github.com/hanickadot/compile-time-regular-expressions)
  и получить информацию для дальнейшего исследования:
  `ctre::match<"[a-z]+([0-9]+)">(s)`
* С функцией `format("%d+%d\n", 10, 20)` сложнее:
  * Смешивать `constexpr`/не-`constexpr` аргументы нельзя
  * В C++17 не проверить(?), как аргументы соотносятся с форматом
  * С C++20 можно использовать [трюк с `consteval`](https://godbolt.org/z/ao4WxK7bv)

---
## 2.2.1. Функции из типов в типы
Ещё с C++98 бывают функции из типов в типы:
```c++
template<typename T>
struct iterator_traits {  // Общий случай
    using value_type = typename T::value_type;
    using difference_type = typename T::difference_type;
};
template<typename T>
struct iterator_traits<T*> {  // Частный случай
    using value_type = T;
    using difference_type = std::ssize_t;
};
```

Можно несколько входов, можно несколько выходов, можно
простые типы в качестве параметров шаблона.

Вызов:
```c++
typename iterator_traits<Iterator>::value_type x = *it;
```
Важно указать `typename`, иначе компилятор не поймёт смысл `<`.

---
## 2.2.2. Функция из типов в один тип
Если такая "функция" возвращает ровно один тип, есть конвенция:
```c++
template<typename T> struct remove_const {
    using type = T;
};
template<typename T> struct remove_const<const T> {
    using type = T;
};
```
В C++11 появились псевдонимы шаблонов (alias template), конвенция:
```c++
// В библиотеке делаем псевдоним с суффиксом _t
template<typename T> using remove_const_t = typename remove_const<T>::type;
// В коде
remove_const_t<const int> x = 10;
```
Получаем вызов функции, только `<>` вместо `()`, и в качестве параметров — и значения, и типы.

---
## 2.2.3. Функция из типов в число
```c++
template<typename T> struct rank {
    static constexpr size_t value = 0;  // Стандартное имя.
};
template<typename T> struct rank<T[]> {
    static constexpr size_t value = rank<T>::value + 1;
};
template<typename T, size_t N> struct rank<T[N]> {
    static constexpr size_t value = rank<T>::value + 1;
};
static_assert(rank<int[][10]>::value == 2);
```
* [Давным-давно писали](https://stackoverflow.com/a/205000/767632) `struct rank { enum { value = 10 }; }` <!-- бажные компиляторы -->
* `constexpr`-функции тут не хватит.

С C++17 есть конвенция создавать template variable:
```c++
// В библиотеке делаем псевдоним с суффиксом _v
template<typename T> constexpr size_t rank_v = rank<T>::value;
// В коде
static_assert(rank_v<int[][10]> == 2);
```

Снова получаем вызов функции с `<>` вместо `()`.

---
## 2.2.4. Стандартные вспомогательные классы
```c++
template<typename T> struct rank
    : std::integral_constant<size_t, 0> {};
template<typename T> constexpr size_t rank_v = rank<T>::value;
template<typename T> struct rank<T[]>
    : std::integral_constant<size_t, rank_v<T> + 1> {};
template<typename T, size_t N> struct rank<T[N]>
    : std::integral_constant<size_t, rank_v<T> + 1> {};
static_assert(rank<int[][10]>::value == 2);
```

Обычно пишут через них, так короче:


```c++
template<typename T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    constexpr operator T() const noexcept { return v; }
    ....
};
template<bool v>
struct bool_constant : integral_constant<bool, v> {};
using true_type = bool_constant<true>;
using false_type = bool_constant<false>;
```

---
## 2.3. Тонкости с числами в параметрах
Бывают ограничения. В специализации нельзя фиксировать значение, но не тип значения:
```c++
template<typename T, T N> struct fac { .... };
template<typename T>      struct fac<T, 0> { .... };  // Упс :(
```

Их можно обходить, если специализировать сразу весь параметр
при помощи прослойки из `integral_constant`:
```c++
template<typename /*N*/> struct fac {};  // Базовый случай, не вызывается.
template<typename T, T N> constexpr auto fac_v =
    fac<std::integral_constant<T, N>>::value;
//
template<typename T, T N> struct fac<std::integral_constant<T, N>>
    : std::integral_constant<T, N * fac_v<T, N - 1>> {};
template<typename T>      struct fac<std::integral_constant<T, 0>>
    : std::integral_constant<T, 1> {};
static_assert(fac_v<int, 5> == 120);
```

Так как это дело "открывали", могут быть ещё сюрпризы.

---


## 3.1.1. Простые type traits
Классы или структуры, которые только таскают информацию в типах, называются "типажи" (traits).

Есть встроенные в язык "кирпичики" из `type_traits`, которые можно сделать самому:
* `std::remove_const` (уже видели)
* ```c++
  template<typename, typename> struct is_same : false_type {};
  template<typename T>         struct is_same<T, T> : true_type {};
  // is_same_v тоже есть
  ```
* `is_convertible<From, To>` — можно ли сконвертировать `From` в `To` неявно?
  * ```c++
    To foo() { return /*From{}*/; }
    ```
* `is_nothrow_convertible<T, U>` — а если `noexcept`?
* `is_constructible<T, A, B>` — можно ли построить `T` из `A` и `B`?
  * ```c++
    T foo(/*A{}*/, /*B{}*/);
    ```

---
## 3.1.2. Сложные type traits
Некоторые принципиально требуют поддержки компилятора:

```с++
// Цитата из моей libc++: вызываем кусок компилятора  __is_polymorphic
template<typename _Tp>
  struct is_polymorphic
  : public integral_constant<bool, __is_polymorphic(_Tp)>
  { };
```

Какие-то можно писать самому, но лучше не надо:
```c++
template<typename> struct is_integral       : false_type {};
template<>         struct is_integral<int>  : true_type {};
template<>         struct is_integral<char> : true_type {};
// И так далее; зависит от компилятора и библиотеки.
```

Некоторые есть в библиотеках (например, `boost::function_traits`):
```c++
template<typename> struct function_traits {};
template<typename Ret, typename Arg0>  // Можно написать обобщённо для N аргументов.
struct function_traits<Ret(*)(Arg0)> {
    static constexpr std::size_t arity = 1;
    using return_value = Ret;
    using arg_0 = Arg0;
};
```

---
## 3.2.1. Расширяемые type traits
Некоторые traits предполагаются для расширения пользователем.

`iterator_traits` — по умолчанию берёт `typename` изнутри типа, но:
```c++
namespace std {
    template<typename T> struct iterator_traits<MyMagicIterator<T>> {
        using value_type = typename MyMagicIterator<T>::magic_value_type;
        // ....
    };
}
```

`char_traits` — задаёт логику работы с "символами", [пример с SO](https://stackoverflow.com/a/5319855/767632):
```c++
  struct CaseInsensitiveTraits : std::char_traits<char> {
      static bool lt(char a, char b) { return tolower(a) < tolower(b); }
      static bool eq(char a, char b) { return tolower(a) == tolower(b); }
      static int compare (const char *a, const char *b, size_t length) {
          ....
      }
  };
  using CaseInsensitiveString = std::basic_string<char, CaseInsensitiveTraits>;
  ```
* Теперь `CaseInsensitiveString` сравнивается без учёта регистра.
* И заодно даёт UB на не-латинице из-за `tolower`.
* Говорят, что из-за своих `char_traits` получается неудобный ужас :(

---
## 3.2.2. Свои расширяемые type traits
```c++
// Библиотека
template<typename T> struct serialization_traits {
    static void serialize(ostream &os, const T &x) {      x.serialize(os); }
    static T deserialize(istream &is)              { T x; x.deserialize(is); return x; }
};
template<> struct serialization_traits<int> {
    static void serialize(ostream &os, int x) { os.write(....); }
    static int deserialize(istream &is)       { int x; is.read(....); return x; }
};
// Полезные функции, работают через serialization_traits
template<typename T>
void saveToFile(string fileName, T data) {
    ofstream os(fileName, std::ios::binary);
    serialization_traits<T>::serialize(os, std::move(data));
}
```

В пользовательском коде можем обернуть даже "не свой" тип:
```c++
template<typename T>
struct serialization_traits<vector<T>> {
    static void serialize(ostream &os, const vector<T> &data) {
        serialization_traits<size_t>::serialize(os, data.size());
        for (const auto &item : data)
            serialization_traits<T>::serialize(os, item);
    }
};
saveToFile("foo.txt", std::vector<int>{1, 2, 3, 4}); // Работает!
```

---
## 4.1.1. Свойства выражений: `noexcept`
Про типы всё можем узнавать, теперь давайте что-нибудь узнаем про выражения и функции.

* Оператор `noexcept` позволяет узнать, может ли из выражения теоретически
  вылететь исключение (по спецификаторам `noexcept`).
* Возвращает `true`/`false` _на этапе компиляции_, не вычисляя выражение.


```c++
int foo() noexcept { return 1; }
int bar()          { return 2; }
// ....
int a = 10;
vector<int> b;
static_assert(noexcept(a == 10));
static_assert(!noexcept(new int{}));   // Утечки не будет: не вычисляется.
static_assert(noexcept(a == foo()));
static_assert(!noexcept(a == bar()));  // bar() не noexcept
static_assert(!noexcept(b == b));      // vector::operator== не noexcept
bool x = noexcept(a = 10);
assert(x);
```

---
## 4.1.2. Условный `noexcept`
У _спецификатора_ (не оператора) `noexcept` есть две формы:

```c++
template<typename T> struct optional {
    optional() noexcept;  // Не кидает никогда
    optional(optional &&other) noexcept(  // noexcept только при условии...
        std::is_nothrow_move_constructible_v<T>
    );
};
```

Можно вызвать оператор внутри спецификатора:
```c++
template<typename T> struct optional {
    optional() noexcept;
    optional(optional &&other) noexcept(    // noexcept только при условии...
       noexcept(  // ...что следующее выражение noexcept...
           T(std::move(other))  // вызов move-конструктора T
       )
   );
}
```

Получаем:
```c++
template<typename T> struct optional {
    optional() noexcept;
    optional(optional &&other) noexcept(noexcept(T(std::move(other))));
}
```

---
## 4.1.3. Применение `noexcept`
Полезно для `vector` со строгой гарантией исключений.

Если у элементов `is_nothrow_move_constructible`, то можно перевыделять буфер
без копирований:

```c++
void increase_buffer() {
    vector_holder new_data = allocate(2 * capacity);  // Может быть исключение.
    for (size_t i = 0; i < len; i++)
        new (new_data + i) T(std::move(data[i]));     // Портим data, боимся исключений.
    data.swap(new_data);                              // Исключений точно нет.
}
```

Иначе мы обязаны копировать.
Уже есть готовая функция:

```c++
void increase_buffer() {
    vector_holder new_data = allocate(2 * capacity);
    for (size_t i = 0; i < len; i++)
        new (new_data + i) T(std::move_if_noexcept(data[i]));
    data.swap(new_data);
}
template<typename T> auto move_if_noexcept(T &arg) {  // Упрощённо
    if constexpr (std::is_nothrow_move_constructible_v<T>)
        return std::move(arg);  // Перемещаем аргумент в возвращаемое значение
    else
        return arg;             // Копируем аргумент в возвращаемое значение
}
```

---
## 4.2.1. Функция `declval<>`
Внутри `noexcept` иногда не хватает переменных:
```c++
template<typename T>
constexpr bool is_nothrow_move_assignable_v = noexcept(
    /* переменная типа T */ = std::move(/*что-нибудь типа T???*/)
);
```
При этом конструкторов у `T` может вообще не быть:
```c++
template<typename T>
constexpr bool is_nothrow_move_assignable_v = noexcept(
    /* переменная типа T */ = T{} /* rvalue, но не всегда скомпилируется */
);
```

Функция `std::declval<T>()` создаёт значение любого типа:
```c++
template<typename T>
static constexpr is_nothrow_move_assignable_v = noexcept(
    std::declval<T&>() = std::declval<T/*&&*/>()
);
```

* Это легально только внутри _невычислимых контекстов_.
  * `int x = std::declval<int>();  // Ошибка компиляции`

---
## 4.2.2. Оператор `sizeof`
Ещё невычислимый контекст: оператор `sizeof`

* Можно вызвать от типа:
  ```c++
  static_assert(sizeof(char) == 1);
  ```
* Можно вызывать от выражения, оно не будет вычислено:
  ```c++
  char& foo();
  static_assert(sizeof(foo()) == 1);
  static_assert(sizeof(&foo()) == sizeof(char*));
  ```

Самый первый оператор такого вида, единственный в C++03,
из-за этого часто применяется в костылях.

---
## 4.2.3. Оператор `decltype`
Есть с C++11: `decltype(expr)` — это некоторый тип.

Если в скобках имя сущности, то её тип из объявления:
```c++
int a = 10; int &b = a;
struct { int& field; } c{a};
decltype(a) x = a;              // int x = a;
decltype(b) y = b;              // int& y = b;
decltype(s.field) z = c.field;  // int& z = c.field;
```

Если в скобках выражение, то 
* Берём чистый тип выражения: с константностью, но без ссылок.
* Смотрим на категорию и добавляем соответствующую ссылку.

```c++
Foo func1();
Foo& func2();
Foo&& func3();
Foo a;
// ....
decltype(func1()) x = func1();  // prvalue, Foo x = func1();
decltype(func2()) y = func2();  // lvalue,  Foo &y = func2();
decltype(func3()) z = func3();  // xvalue,  Foo &&z = func3();
decltype(std::move(a))  v2 = std::move(a);  // xvalue,  Foo &&v2 = std::move(a);
decltype(Foo{})         v3 = Foo{};         // prvalue, Foo v3 = Foo{};
```

---
## 4.2.4. Тонкости оператора `decltype`
Дополнительные скобки делают из имени выражение:

```c++
Foo a;
const Foo &b = a;
decltype( a ) v1 = a; //  a  — имя.               Foo v1 = a;
decltype((a)) v2 = a; // (a) — выражение. lvalue, Foo &v2 = a;
decltype( b ) v3 = b; //  b  — имя.               const Foo &v3 = b;
decltype((b)) v4 = b; // (b) — выражение. lvalue, const Foo &v4 = b;
```

Сильно отличается от `auto`: второй снимает ссылки и константность.
```c++
auto x = a;  // Foo v1 = a;
auto y = b;  // Foo v3 = b;
```

* Будет использоваться, когда нужно отличать типы друг от друга (до С++11
  использовались костыли с `sizeof`)
* Может использовать для _очень_ правильного вывода типов параметров и
  возвращаемого значения функций:
  ```c++
  decltype(auto) v1 = a;    // Foo v1 = a;
  decltype(auto) v2 = (a);  // Foo &v2 = a;
  decltype(auto) v3 = b;    // const Foo &v3 = b;
  decltype(auto) v4 = (b);  // const Foo &v4 = b;
  ```

---
## 4.2.5. Type display trick
Трюк, чтобы поэкспериментировать с типом сущностей:

```c++
template<typename> struct TD;  // Type Display
                               // Forward-declaration структуры, не определяем.
// ....
int x = 10;
int &y = x;
TD<decltype(x)>{};  // Ошибка компиляции: TD<int> is incomplete.
TD<decltype(y)>{};  // Ошибка компиляции: TD<int&> is incomplete.
```

Например, можно проверить, какие типы выводятся в шаблонах:
```c++
template<typename T>
void foo(T) {
    TD<T>{};
    // ... тут какой-то сложный код ...
}
// ....
int x = 10;
int &rx = x;
const int cx = x;
checkTemplateTypeInfo(x);   // Ошибка компиляции: TD<int> is incomplete
checkTemplateTypeInfo(rx);  // Ошибка компиляции: TD<int> is incomplete
checkTemplateTypeInfo(cx);  // Ошибка компиляции: TD<int> is incomplete
```
Скорее всего, компилятор выведет эту ошибку только в первый раз.

---
## 5.1.1. Тонкости указателей: мотивация `std::addressof`
```c++

void some_c_api(const void*);
template<typename T>
void CallSomeCApi(const T &value) {
    some_c_api(static_cast<const void*>(&value));
}
// ....
S s;
CallSomeCApi(10);  // Компилируется.
CallSomeCApi(s);   // Почему ошибка компиляции внутри CallSomeCApi?
```

---
## 5.1.2. Тонкости указателей: `std::addressof`
```c++
struct S { int operator&() const { return 7; } };
void some_c_api(const void*);
template<typename T>
void CallSomeCApi(const T &value) {
    some_c_api(static_cast<const void*>(&value));
}
// ....
S s;
CallSomeCApi(10);  // Компилируется.
CallSomeCApi(s);   // Почему ошибка компиляции внутри CallSomeCApi?
```

* Теоретически можно перегрузить `operator&`
* К счастью, там был `static_cast`, иначе бы оно передало [число `7` как значение указателя](https://habr.com/ru/post/203276/).

Решение:
```c++
// Так в обобщённом коде правильно.
some_c_api(static_cast<const void*>(std::addressof(value)));
```

Упрощённая реализация:
```c++
template<typename T> T* addressof(T& value) {
    return reinterpret_cast<T*>(&reinterpret_cast<const char&>(value));
}
```

---
## 5.2.1. Тип "функция"
* Такой тип имеют функции:
  ```c++
  void func1();
  void func2(int x);
  void func3(int y);
  int func4(int x, char y);
  // ....
  TD<decltype(func1)>{}; // Ошибка компиляции: TD<void()> is incomplete
  TD<decltype(func2)>{}; // Ошибка компиляции: TD<void(int)> is incomplete
  TD<decltype(func3)>{}; // Ошибка компиляции: TD<void(int)> is incomplete
  TD<decltype(func4)>{}; // Ошибка компиляции: TD<int(int, char)> is incomplete
  ```
* Объявить переменную такого типа нельзя.
* В метапрограммировании обычно применяется для упрощения синтаксиса: `function<void(int)>`.
* Неявно приводится к _указателю_ на функцию.

---
## 5.2.2. Тип "указатель на функцию"
Добавили между типом и аргументами `(*)`, получили `void(*)(int)`.

```c++
char foo(int);
// ....
auto x = [](int val) -> char { return val; };
auto y = [&](int val) -> char { return val; };
char (*func1)(int) = &foo;  // Ок.
char (*func2)(int) = foo;   // Ок, функция неявно преобразуется в указатель на себя.
char (*func3)(int) = x;     // Ок: лямбда без захвата — почти свободная функция.
char (*func4)(int) = y;     // Не ок: лямбда с захватом должна знать своё состояние.
```

А ещё функции и данные могут вообще в совсем разной памяти лежать:
```c++
void *x = static_cast<void*>(&foo);  // Ошибка компиляции.
```
* Но Linux пофиг: там какие-то функции возвращают `void*` вместо указателей на функции.

Между собой указатели на функции несовместимы:
```c++
void (*func5)() = func4;
void (*func6)(int) = func4;
```

---
## 5.2.3. Указатели на перегруженную функцию
```c++
void foo(int x);
char foo(char x);
// ....
TD<decltype(&foo)>{};  // Ошибка компиляции: какую перегрузку выбрать decltype?
```

Вывод: у `&foo` нет типа (примерно как у `{1, 2, 3}`).

```c++
void (*func1)(int)  = &foo;  // Если в точности указать тип, то перегрузка разрешится.
char (*func2)(char) = &foo;
```

Вызывает проблемы в шаблонных функциях или с `auto`:
```c++
template<typename Fn> void bar(Fn fn) { fn(10); }
// ....
bar(&foo);  // no matching function for call to 'bar(<unresolved overloaded function>)'
bar(static_cast<void(*)(int)>(&foo));  // Ок.
bar([](int x) { return foo(x); });     // Ок, у лямбды фиксированный параметр.
```

---
## 5.3.1. Указатель на члены класса
Ссылка: [C++ FAQ](https://isocpp.org/wiki/faq/pointers-to-members).
Типобезопасный `offsetof`, можно писать и читать:

```c++
struct S { int x = 1, y = 2; };
S s;
S *sptr = &s;
int (S::*a) = &S::x;  // Можно даже без скобок слева.
int (S::*b) = &S::y;  // А вот &(S::y) уже нельзя.
assert(s.*a == 1);
assert(sptr->*a == 1);

a = b;  // Теперь `a` "указывает" на поле `y`.
assert(s.*a == 2);
assert(sptr->*a == 2);

// Но вообще рекомендуют typedef или using:
using IntMemberOfS = int S::*;
IntMemberOfS c = &S::x;

// С наследниками тоже работает.
struct S2 : S { int z = 3; };
S2 s2;
assert(s2.*a == 2);  // Можно пользоваться указателем из родителя.
int (S2::*d) = a;  // Можно неявно преобразовать типы.
assert(s2.*d == 2);
IntMemberOfS e = static_cast<IntMemberOfS>(d);  // Можно явно.
```

---
## 5.3.2. Указатели на методы
Синтаксис аналогичный:

```c++
struct S {
    int field = 100;
    int foo1(int x) { return x + 10 + field; }
    int foo2(int x) { return x + 20 + field; }
    int bar1(int x) const { return x + 30 + field; }
    int bar2(int x) const { return x + 40 + field; }
};
S s;
int (S::*a)(int) = &S::foo1;
assert((s.*a)(9) == 119);  // Сначала скобки вокруг .*!
a = &S::foo2;
assert((s.*a)(8) == 128);
```

Важно [сохранить const-qualifier](https://isocpp.org/wiki/faq/pointers-to-members#memfnptr-to-const-memfn):
```c++
int (S::*b)(int) const = &S::bar1;  
assert((s.*b)(7) == 137);
b = &S::bar2;
assert((s.*b)(6) == 146);
```

* Есть все стандартные проблемы с выбором перегрузки

---
## 5.3.3. Тонкости с указателями на члены
Во всех случаях работает и `.*`, и `->*`.
* Но вообще [рекомендуют](https://isocpp.org/wiki/faq/pointers-to-members#macro-for-ptr-to-memfn) сделать `typedef` и `std::invoke(pointer_to_member, obj, arg1, arg2..)`
* Для чтения из полей тоже работает `std::invoke(pointer_to_field, obj)`

Почему-то в умных указателях `->*` не перегружен :(
*  Делаем `*` и `.*`

Указатели на члены категорически несовместимы с обычными указателями.
* Поле — потому что это сдвиг внутри объекта. Не `void*`, не указатель на объект.
* Функция — даже с указателем на обычную функцию. 
  * Бывают виртуальные функции и виртуальное наследование.
  * Надо поддерживать преобразования по иерархии.
  * Может быть надо хранить сразу структуру, а не один указатель.
