struct Foo;

Foo* get_foo();

int main() {
    Foo *f = get_foo();
    delete f;  // Oops, UB: `Foo` should be non-trivially deleted, but we don't know that here.
               // Thankfully, GCC gives a warning.
}
