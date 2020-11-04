template<typename T>
struct MyTemplate {
private:
    int x = 0;

    friend void simple_func();

    // For all T: generate an independent non-template non_simple_func(MyTemplate<T>&) declaration, impossible to define outside the class.
//    friend void non_simple_func(MyTemplate&);

    // For all T: for all U: foo(MyTemplate<U>&, MyTemplate<void>&) is a friend MyTemplate<T>
    template<typename U>
    friend void foo(MyTemplate<U> &, MyTemplate<void> &);
    // Take a look at 'full specialization' at cppreference.

    // For all T: generate an independent non-template bar(MyTemplate<T>, MyTemplate<void>) which is a friend of MyTemplate<T>.
    friend void bar(MyTemplate &val, MyTemplate<void> &weird) {
        val.x = 10;
        weird.x = 10;  // Should not compile, but GCC compiles it anyway. Clang does not.
    }

    // For all T: generate an independent template bar<U>(MyTemplate<T>, MyTemplate<U>) which is a friend of MyTemplate<T> for any U.
    template<typename U>
    friend void baz(MyTemplate &val, MyTemplate<U> &weird) {
        val.x = 10;
        weird.x = 10;  // Should not compile when T != U because it's not a friend of MyTemplate<T>. Both GCC and Clang agree.
    }
};

void simple_func() {
    MyTemplate<int> val1;
    val1.x = 10;
}

/*
// Template non_simple_func<T>(), does not correspond to a non-template declaration inside MyTemplate.
template<typename T>
void non_simple_func(MyTemplate<T> &val) {
    val.x = 10;
}
*/

template<typename U>
void foo(MyTemplate<U> &val, MyTemplate<void> &weird) {
    val.x = 10;
    weird.x = 10;
}

int main() {
    MyTemplate<int> val1;
    MyTemplate<char> val2;
    MyTemplate<void> weird;

//    non_simple_func(val1);  // Attempts to call the friend declaration from MyTemplate, "no reference found".
//    non_simple_func<int>(val1);  // Attempts to call the template function, it's not a friend.

    foo(val1, weird);
    foo(val2, weird);

//    MyTemplate<int> val1b;
//    bar(val1, val1b);
    bar(val1, weird);
    bar(val2, weird);

    baz(val1, val1);
    baz(val1, weird);
}
