struct Foo {
};

int main() {
    Foo *f = new Foo;  // Dynamic storage duration for 'Foo'.
                       // "На куче" (heap)
    delete f;
}
