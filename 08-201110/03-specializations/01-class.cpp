#include <cassert>
#include <list>

template<typename T>
struct list_heap {
    std::list<T> data_;

    bool empty() const {
        return data_.empty();
    }

    void push(const T &value) {
        data_.push_back(value);
    }
};

template<>
struct list_heap<void> {
    bool empty() const {
        return true;
    }
};

int main() {
    {
        list_heap<int> a;
        assert(a.empty());
        a.push(10);
        assert(!a.empty());
    }

    {
        list_heap<void> b;
        assert(b.empty());
        // b.push();
    }
}
