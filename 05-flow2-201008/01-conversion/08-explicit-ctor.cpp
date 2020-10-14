struct Foo {
    explicit Foo() {
    }
    Foo(int, int = 20) {
    }
};

Foo foo() {
    return {10, 20};
}

void bar(Foo) {
}

int main() {
    [[maybe_unused]] Foo f = {10, 20};
    bar({10, 20});

    [[maybe_unused]] Foo g = 30;
    Foo h1;
    Foo h2 = {};
    Foo h3{};
    bar(Foo());
}
