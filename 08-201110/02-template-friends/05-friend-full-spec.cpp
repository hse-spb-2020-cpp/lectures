template<typename T>
struct MyTemplate;

template<typename U>
void foo(MyTemplate<U> &val, MyTemplate<void> &weird);

template<typename T>
struct MyTemplate {
private:
    int x = 0;
    // template<typename T>  // Not needed, we want a full friend specialization.
    friend void foo<T>(MyTemplate<T> &val, MyTemplate<void> &weird);

    friend void foo<T*>(MyTemplate<T*> &val, MyTemplate<void> &weird);
};

template<typename U>
void foo(MyTemplate<U> &val, [[maybe_unused]] MyTemplate<void> &weird) {
    val.x = 10;
    // weird.x = 10;  // Works with U=void or U=void*, but not U=int.
}

int main() {
    MyTemplate<int> a;
    MyTemplate<void*> b;
    MyTemplate<void> c;
    foo(a, c);
    foo(b, c);
}
