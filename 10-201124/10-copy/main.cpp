#include <cassert>
#include <list>
#include <iterator>
#include <iostream>

struct list_heap {
    std::list<int> l;
    std::list<int>::iterator it;

    list_heap() : l{1, 2, 3}, it(std::next(l.begin())) {
    }

    // copy constructor
    list_heap(const list_heap &other)
        : l{other.l}
        , it{std::next(l.begin(), std::distance(other.l.begin(), static_cast<std::list<int>::const_iterator>(other.it)))}
    {
        std::cout << "copy constructor\n";
    }

    // copy assignment operator
    list_heap& operator=(const list_heap &other) {
        std::cout << "copy assignment\n";
        if (this == &other) {
            return *this;
        }
        l = other.l;
        it = std::next(
            l.begin(),
            std::distance(
                other.l.begin(),
                static_cast<std::list<int>::const_iterator>(other.it)
            )
        );
        return *this;
    }

    // copy-and-swap idiom
/*    list_heap& operator=(list_heap other) {
        std::cout << "copy assignment\n";
        using std::swap;
        swap(l, other.l);
        swap(it, other.it);
        return *this;
    }*/
};

void foo([[maybe_unused]] list_heap h) {
}

int main() {
    list_heap a;
    assert(*a.it == 2);
    {
        list_heap b;
        *b.it = 20;
        assert(*b.it == 20);
        std::cout << "before 'a = b'\n";
        a = b;
        // a.operator=(b);  // `const list_heap &other = b;` or `list_heap other = b;`
        std::cout << "after 'a = b'\n";
        assert(*a.it == 20);
        *b.it = 30;
    }
    {
        std::cout << "before 'c = a'\n";
        list_heap c = a;
        std::cout << "before 'foo(a)'\n";
        foo(a);
        std::cout << "after 'foo(a)'\n";
    }
    assert(*a.it == 20);
}
