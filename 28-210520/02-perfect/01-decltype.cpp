template<typename> struct TD;

int& foo();
int&& bar();

int main() {
    int x = 10;
    int &y = x;

    //TD<decltype(10)>{};  // int
    //TD<decltype(10 + 20)>{};  // int
    //TD<decltype(x)>{};  // int
    //TD<decltype(y)>{};  // int&
    //TD<decltype(y + 20)>{};  // int
    //TD<decltype(y + 0)>{};  // int
    //TD<decltype(  (y + 0)  )>{};  // int
    //TD<decltype(  (x + 0)  )>{};  // int
    // TD<decltype(  (x)  )>{};  // int& ?????

    // У decltype() есть два режима:
    // 1. decltype(expression)
    TD<decltype(10)>();  // int
    TD<decltype( (x) )>();  // int&
    TD<decltype( (y) )>();  // int&
    TD<decltype( x + 20 )>();  // int
    TD<decltype( foo() )>();  // int&
    TD<decltype( bar() )>();  // int&&
    // Возвращает: T (если prvalue), T& (если lvalue), T&& (если xvalue)

    // 2. decltype(name) - переменная/поле без скобок
    TD<decltype(x)>();  // int
    TD<decltype(y)>();  // int&
    // Возвращает: как name был объявлен
}
