foo(
  bar1(x(), y()),
  bar2(x(), y())
)

foo(i++, i)
Before C++17: undefined
After C++17: unspecified

i++  postfix
++i  prefix

 cout << foo() << bar()   // 1. foo(); 2. bar()
(cout << foo()) << bar()  // 1. foo(); 2. bar()
>>
+=
-=
a = b;

cout << (foo() + bar());  // foo(), bar() OR bar(), foo()
