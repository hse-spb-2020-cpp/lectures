#include <vector>

template<typename C>
struct Foo {
    using my_iterator = typename C::iterator;

    void foo() {
        typename C::const_iterator foo;
        foo = C::jgregrtgtrhgigihtrgihrg();
    }
};

int main() {
    [[maybe_unused]] Foo<std::vector<int>> f;
//    f.foo();
}
