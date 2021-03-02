#include <iostream>
#include <cstddef>

// Не забыть виртуальный деструктор.
// Иначе не сможете владеть объектом по указателю на его базу,
// а тогда неясно, зачем вам вообще наследование (хотя может быть).
struct Base1 { virtual ~Base1() {} };
struct Base2 { virtual ~Base2() {} };
struct Base3 { virtual ~Base3() {} };

/*
  B1  B2  B3
  /\  /\  /\
 /  \/  \/  \
D1  12  23  D3
*/
struct Derived1 : virtual Base1 {};
struct Derived12 : virtual Base1, virtual Base2 {};
struct Derived23 : virtual Base2, virtual Base3 {};
struct Derived3 : virtual Base3 {};

struct DerivedX : Derived1, Derived12, Derived23, Derived3 {};

void foo(Derived1 &d1);

int main() {
    DerivedX a;
    foo(a);
}
