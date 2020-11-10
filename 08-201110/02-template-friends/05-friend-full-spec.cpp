template<typename T>
struct MyTemplate;

template<typename U>
void foo(MyTemplate<U> &val, MyTemplate<void> &weird);

template<typename T>
struct MyTemplate {
private:
    int x = 0;
    friend void foo</*T*/>(MyTemplate<T> &val, MyTemplate<void> &weird);
};

template<typename U>
void foo(MyTemplate<U> &val, [[maybe_unused]] MyTemplate<void> &weird) {
    val.x = 10;
    // weird.x = 10;
}

int main() {
    MyTemplate<int> a;
    MyTemplate<void> c;
    foo(a, c);
}