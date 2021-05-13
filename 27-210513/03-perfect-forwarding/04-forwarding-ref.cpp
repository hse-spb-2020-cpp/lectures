#include <utility>

template<typename> struct TD;  // Type Display

template<typename T>
void foo(T &&x) {  // Special `T` deduction rules for 'T&&', not 'vector<T>&&', not 'const T&&': "forwarding reference".
    TD<T>();
    TD<decltype(x)>();  // TD<T&&>
}

int main() {
    int v = 20;
    const int cv = 30;

    //foo(10);             // T=      int  ,       int &&x = T&&
    //foo(v);              // T=      int& ,       int  &x = T&&
    //foo(cv);             // T=const int& , const int  &x = T&&
    //foo(std::move(v));   // T=      int  ,       int &&x = T&&
    //foo(std::move(cv));  // T=const int  , const int &&x = T&&

    /* reference collapsing
     * T    &
     * T    &&
     * (U&) & =====> U&
     * (U&) && =====> U&
     * (U&&) & =====> U&
     * (U&&) && =====> U&&
     */
}
