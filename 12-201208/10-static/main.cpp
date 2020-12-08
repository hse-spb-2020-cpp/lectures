// ЭтО вСё РаЗнОе.

// 1
int foo() {
    static int calls = 0;  // Инициаилизируется в момент первого прохода по этой строчке при выполнении.
                           // Сохраняется между вызовами функции.
    calls++;
}

// 2
static int x;  // internal linkage в языке Си, в C++ для совместимости.
static void foo() {  // internal linkage.
}
namespace {  // Абсолютно аналогично:
int y;  // internal linkage в языке C++
void bar() {  // internal linkage.
}
}

// 3
struct Foo {
    static int x;  // "Статическое поле".
    static void foo() {  // Static member function: есть доступ к приватным полям; external linkage.
    }
};

int main() {
    // 4
    int y = static_cast<int>(10.5);
}
