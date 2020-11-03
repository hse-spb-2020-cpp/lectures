template<typename T>
struct MyTemplate {
private:
    int x = 0;

    friend void simple_func();

//    friend void non_simple_func(MyTemplate&);

    // For all T: for all U: foo(MyTemplate<U>&, MyTemplate<void>&) is a friend MyTemplate<T>
    template<typename U>
    friend void foo(MyTemplate<U> &, MyTemplate<void> &);
    // Take a look at 'full specialization' at cppreference.

    friend void bar(MyTemplate &val, MyTemplate<void> &weird) {
        val.x = 10;
        weird.x = 10;
    }

    template<typename U>
    friend void baz(MyTemplate &val, MyTemplate<U> &weird) {
        val.x = 10;
        weird.x = 10;
    }
};

void simple_func() {
    MyTemplate<int> val1;
    val1.x = 10;
}

/*template<typename T>
void non_simple_func(MyTemplate<T> &val) {
    val.x = 10;
}*/

template<typename U>
void foo(MyTemplate<U> &val, MyTemplate<void> &weird) {
    val.x = 10;
    weird.x = 10;
}

int main() {
    MyTemplate<int> val1;
    MyTemplate<char> val2;
    MyTemplate<void> weird;

//    non_simple_func(val1);
//    non_simple_func<int>(val1);

    foo(val1, weird);
    foo(val2, weird);

//    MyTemplate<int> val1b;
//    bar(val1, val1b);
    bar(val1, weird);
    bar(val2, weird);

    baz(val1, val1);
    baz(val1, weird);
}
