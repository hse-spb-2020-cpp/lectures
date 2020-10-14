struct Foo {
    explicit operator int() const {
        return 10;
    }
};

int main() {
    Foo f;
    [[maybe_unused]] int x = static_cast<int>(f);
}
