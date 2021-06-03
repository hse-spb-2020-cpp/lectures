## 2.1.1. `std::tuple`
Аналог `std::pair`, но хранит произвольное количество элементов
(гетерогенный список).

```c++
std::tuple<int, vector<int>, string> t(10, vector<int>(2), "foo");
auto t2 = std::make_tuple(10, vector<int>(2), "foo");  // t == t2
int a = std::get<0>(t);     // 0, 2 — константа времени компиляции.
string c = std::get<2>(t);  // Цикла по tuple<> нет.
```

Есть неявная конверсия из `pair<>` и `tuple_cat` (пригодится в метапрограммировании):
```c++
std::pair<int, string> p(10, "foo");
std::tuple<int, string> t = p;  // Неявная конверсия pair --> tuple.
auto tt = std::tuple_cat(t, t);
```
Можно узнавать тип элемента и размер на этапе компиляции:
```c++
std::tuple_element_t<0, decltype(tt)> x = std::get<0>(tt);
static_assert(std::tuple_size_v<decltype(tt)> == 4);
```

---
## 2.1.2. Интересности с `std::tuple`
<!-- Можно пропустить -->
Пригодится нам потом в метапрограммировании:
```c++
void foo(int a, string b);
// ....
auto t = std::make_tuple(10, "hello");
std::apply(foo, t);  // foo(10, "hello");
```

Можно хранить ссылки (в `pair` тоже):
```c++
int a = 10; string b = "foo";
std::tuple<int&, string&> t(a, b);
t = std::make_tuple(20, "bar");  // a == 20, b == "bar"
assert(a == 20);
assert(b == "bar");
```
С этим есть эффекты, аккуратно разбирать пока не будем.

Можно почти как в Python:
```c++
// std::tuple<int, string> bar() { return {30, "baz"}; }
std::tie(a, b) = bar();  // a == 30, b == "baz"
```

---
## 2.2.1. Structured binding — базовое
С С++17 можно почти совсем как в Python:

```c++
std::pair<int, string> p(10, "foo");
auto [a, b] = p;  // a == 10, b == "foo"
b += "x";  // b == "foox", p.second == "foo"
```

К `auto` можно добавлять `const`/`&`/`static`:

```c++
auto& [a, b] = p;  // a == 10, b == "foo"
b += "x";  // b == p.second == "foox"
```

* Есть direct initialization: `auto [a, b](p);`.
* Есть list initialization: `auto [a, b]{p};`.
* Указать тип отдельных `a`/`b` нельзя.
* Нельзя вкладывать: `auto [[a, b], c] = ...`.
* Нельзя в полях.
* Происходит на этапе компиляции: можно с массивами, но не с векторами.
* Также работает с очень простыми структурами.

---
## 2.2.2. Structured binding — применения
Удобно получать значения `pair` из `.insert`.
```c++
map<int, string> m = ....;
if (auto [it, inserted] = m.emplace(10, "foo"); inserted) {
    cout << "Inserted, value is " << it->second << '\n';
} else {
    cout << "Already exists, value is " << it->second << '\n';
}
```

Удобно итерироваться по `map`.
```c++
for (const auto &[key, value] : m) {
    cout << key << ": " << value << '\n';
}
```

---
## 2.3.1. Как работает
```c++
auto [key, value] = *m.begin();
/*                  ^^^EXPR^^^ */
```
превращается в
```c++
// 1. Объявляем невидимую переменную ровно так же.
//    Для примера тут copy initialization.
auto e = *m.begin();  // map<int, string>::value
                      // pair<const int, string>
using E = pair<const int, string>;
// 2. Проверяем количество аргументов.
static_assert(std::tuple_size_v<E> == 2);
// 3. Объявляем элементы.
std::tuple_element_t<0, E> &key   = get<0>(e);  // Или e.get<0>()
std::tuple_element_t<1, E> &value = get<1>(e);  // Или e.get<1>()
```

* На самом деле `key` и `value` — ссылки в невидимый `e`.
* Время жизни такое же, как у `e`.
* Костантность и ссылочность получаем от `tuple_element_t`.
  * В частности, `const auto &[a, b] = foo()` продлит жизнь временному
    объекту.

---
## 2.3.2. Подробности structured binding
Поддерживаются три формы привязки:

1. Если массив известного размера:
   ```c++
   Foo arr[3];
   auto [a, b, c] = arr;
   // превращается в
   auto e[3] = { arr[0], arr[1], arr[2] };
   Foo &a = e[0], &b = e[1], &c = e[2];
   ```
* Если не массив, то `tuple_size<>`, `get<>`...
  * Можно предоставить для своего типа, но надо думать про `get`
    от `const` (deep или shallow?) и
    [прочие тонкости](https://stackoverflow.com/questions/61340567).
* Иначе пробуем привязаться ко _всем_ нестатическим полям.
  ```c++
  struct Good { int a, b; }
  struct GoodDerived : Good {};

  struct BadPrivate { int a; private: int b; }  // Приватные запрещены.
  struct BadDerived : Good { int c; }  // Все поля должны быть в одном классе.
  ```

---
## 2.3.3. Тонкости structured binding
В зависимости от `auto`/`auto&`/`const auto&` и инициализатора у нас получаются немного разные типы.

* `auto&` попробует привязать ссылку.
* `const auto&` продлит жизнь временному объекту.
* `auto` всегда скопирует объект целиком, а не просто его кусочки.

Если внутри объекта лежали ссылки, то может [сломаться время жизни](https://stackoverflow.com/a/51503253/767632):
```c++
namespace std {
    std::pair<const T&, const T&> minmax(const T&, const T&);
}
auto [min, max] = minmax(10, 20);  // Только копирование значений?
// перешло в
const pair<const int&, const int&> e = {10, 20};
// Сам `e` — не временный, поэтому продления жизни нет.
// e.first и e.second ссылаются на уже умершие 10 и 20.
const int &min = e.first;   // Oops.
const int &max = e.second;  // Oops.
```

Рекомендация: осторожно с функциями, которые возвращают ссылки.
С ними лучше `std::tie`.

---
## 4.1.1. Argument-dependent lookup (ADL)
Ссылки: [GotW 30](http://www.gotw.ca/gotw/030.htm), [StackOverflow](https://stackoverflow.com/a/8111750/767632).
Для unqualified lookup: [TotW 49](https://abseil.io/tips/49) и [Cppreference](https://en.cppreference.com/w/cpp/language/adl).

```c++
namespace std {
    ostream& operator<<(ostream &os, string &s);
}
// ....
std::ostream &output = ....;
std::string s;
output << s;  // Почему не std::operator<<(output, s); ?
```
ADL: если видим _неквалифицированный_ вызов функции, то смотрим на типы
аргументов и ищем функции во всех связанных namespace'ах.

Удобно для операторов.

<blockquote style="font-style: italic">
Во-первых, в зависимости от типа аргумента, ADL работает девятью разными способами, убиться веником.
(<a href="https://habr.com/ru/company/jugru/blog/447900/">источник</a>)
</blockquote>

---
## 4.1.2. Примеры работающего ADL
[Обобщение](http://www.gotw.ca/publications/mill02.htm): если мы вместе с классом дали пользователю какую-то функцию,
то она должна иметь те же моральные права, что и методы.

```c++
std::filesystem::path from("a.txt");  // C++17
std::filesystem::path to("a-copy.txt");
copy_file(from, to);  // copy_file не метод, ей не нужен доступ к приватным полям.
copy_file("a.txt", "a-copy-2.txt");  // Не компилируется, ADL не помог.
std::filesystem::copy_file("a.txt", "a-copy-2.txt");  // Надо явно указать.
```

Range-based-for и structured binding ищут `begin()`/`end()`/`get()` через ADL:
```c++
namespace ns {
    struct Foo { int x; };
    const int* begin(const Foo &f) { return &f.x; }
    const int* end(const Foo &f) { return &f.x + 1; }
};
int main() {
    ns::Foo f{20};
    for (int x : f) std::cout << x << '\n';
}
```
Причём _только_ через ADL: объявить `begin`/`end` глобально — ошибка.

---
## 4.1.3 Примеры отключённого ADL
```c++
namespace foo {
    namespace impl {
        struct Foo { int x; };
        int func(const Foo &f) { return f.x; }
        int foo(const Foo &f) { return f.x; }
    }
    using impl::Foo;
}
namespace bar::impl {
    struct Bar{ int x; };
    int func(const Bar &f) { return f.x; }
}

int main() {
    foo::Foo f;
    bar::impl::Bar b;
    func(f);  // ok
    func(b);  // ok
    foo::impl::func(f);  // Qualified lookup, no ADL, ok.
    foo::impl::foo(f);  // Qualified lookup, no ADL, ok.
    foo::func(f);  // Qualified lookup, no ADL, compilation error.
    foo::foo(f);  // Qualified lookup, no ADL, compilation error.
    foo(f);  // compilation error: namespace foo
}
```

---
## 4.1.4. `std::swap` и ADL
[Откуда взялся текущий `std::swap`](https://stackoverflow.com/a/5695855):

```c++
namespace std {
    template<typename T> void swap(T&, T&);
}
template<typename T> struct MyVec { .... };
namespace std {
    template<typename T> void swap<MyVec<T>>(...);  // Частичная специализация:(
    // В std:: можно только специализировать, но не перегружать.
    // template<typename T> void swap(MyVec<T>, MyVec<T>);  // Нельзя :(
}
```

* Плохой вариант: требовать от всех `a.swap(b)`: не работает с `int`.
* Вариант получше: ADL, и правильно использовать вот так:
  ```с++
  using std::swap;  // На случай, если стандартный через move подойдёт.
  swap(a, b);  // Вызываем с ADL.
  ```

Есть [ниблоиды](https://habr.com/ru/company/jugru/blog/447900/):
вызываем всегда через `std::swap`, который сам проверит `.swap`, ADL и стандартный.
Используется в C++20 для constrained algorithms.

---
## 4.3.1. Тонкости ADL: hidden friends
```c++
#include <iostream>
namespace ns {
    struct Foo {
        friend void foo(Foo) {}  // implicitly inline.
    };
    // void foo(Foo);  // (1)
}
// ....
ns::Foo f;
foo(f);      // ok
ns::foo(f);  // compilation error
```
Если функция-друг определена внутри класса, то её можно найти __только__ через ADL

* Плюсы: функции можно вызвать только через ADL (примерно как методы), сложнее опечататься.
* Минусы: теперь эту функцию нельзя никуда явно передать, только лямбдой.

Можно раскомментировать `(1)` и функция станет видна в namespace.

---
## 4.3.2. Прочие тонкости ADL
* Unqualified lookup смотрит на конструкторы, но ADL — нет:
    ```c++
    namespace ns {
        struct Foo {};
        struct Bar { Bar(Foo) {} };
        void foo() {
            Foo f;
            auto x = Bar(f);  // ok
        }
    }
    // ....
    ns::Foo f;
    auto x = Bar(f);  // compilation error
    ```
* ADL [иногда не может понять](https://stackoverflow.com/a/45493969/767632),
  что мы вызываем шаблон функции с явными шаблонными параметрами:
    ```c++
    std::tuple<int, int> a;
    std::get<0>(a);  // Ок.
    get<0>(a);       // (get < 0) > (a); ???
                     // В structured binding стоит костыль, чтобы работало.
    ```

---
## 4.3.3. Возможный стиль: отключение ADL
До:
```c++
namespace ns {
    struct Foo { .... };
    struct Bar { .... };
    void func1(....);
    void func2(....);
    struct Baz { .... };
    void func_baz(Baz);
}
```

После (только пробелы надо нормальные):
```c++
namespace ns {
    namespace no_adl  { struct Foo { .... }; struct Bar { .... };   }
                        using no_adl::Foo;   using no_adl::Bar;
    void func1(....);
    void func2(....);
    namespace baz_adl { struct Baz { .... }; void func_baz(Baz);      }
                        using baz_adl::Baz;  using baz_adl::func_baz;
}
```

---
## 4.3.4 Практические следствия ADL
* Вспомогательные для класса функции и операторы вроде `copy_file` должны быть в namespace класса
  ([1](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c5-place-helper-functions-in-the-same-namespace-as-the-class-they-support),
  [2](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c168-define-overloaded-operators-in-the-namespace-of-their-operands)).
* Можно пользоваться ADL, но осторожно:
  * `count(vec.begin(), vec.end())` может не скомпилироваться
  * `vector::iterator` — это класс из `std`/`vector` или `typedef int*`?
* Осторожно с рефакторингами:
  * Перемещение функций, типов
* Если у вас вызывается странная функция без namespace — это ADL.
* Всегда пишите `using std::swap; swap(a, b)`.
