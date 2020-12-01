#include <utility>

int& foo() {
    static int z = 0;
    return z;
}

int bar() {
    static int z = 0;
    return z;
}

int& bad_foo() {
    int x = 10;
    return x;  // no lifetime extension! dangling reference.
}

int main() {
    int x = /* prvalue */ 10;
    x;  // lvalue
    std::move(x);  // xvalue

    // lvalue-ссылки.
    int &x1 = /* should be lvalue */ ((((x))));
    int &x2 = /* should be lvalue */ foo();
    // int &x3 = /* prvalue, CE */ bar();
    // int &x4 = /* prvalue */ (/* lvalue */ x + /* prvalue */ 10 + /* prvalue */ bar());  // CE
    // int &x5 = /* xvalue - это частный случай rvalue, CE */ std::move(x);

    // rvalue-ссылки, обычно только как параметры функций, не как переменные/поля.
    int &&y1 = /* prvalue */ 10;
    int &&y2 = /* prvalue */ bar();  // lifetime extension: время жизни объекта продлевается аналогично y2
    int &&y2b = /* xvalue */ std::move(/* prvalue */ bar());  // no lifetime extension, нельзя читать y2b.
        // Никогда не надо делать move(prvalue).
    int &&y3 = /* xvalue */ std::move(x);

    const int &z1 = /* lvalue */ x;
    const int &z2 = /* prvalue */ 10;  // lifetime extension
    const int &z3 = /* xvalue */ std::move(x);  // move(x) == static_cast<int&&>(x)
    const int &z4 = bar();  // lifetime extension

    // Так тоже бывает, но обычно бесполезно.
    const int &&zz1 = 10;
    // const int &&zz2 = x1;

    int (&(zzz)) = x;  // Это не про выражения, это синтаксис объявлений странный.
    ((x)) = 20;
}
