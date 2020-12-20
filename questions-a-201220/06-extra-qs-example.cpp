template<typename T>
struct Foo;

template<typename T>
struct Bar {
    Foo<T> *f;
};

template<typename T>
struct Foo {
    Foo *f;
};


Foo<T> is friend of Bar<T>, Bar<void>

struct Baz {
    Baz(const Baz&) { ... }
    Baz(const Baz&& other) : str(std::move(other.str)) { ... }
    .... operator= ....
}
