#include <utility>

//#include <memory>
//using std::unique_ptr;

template<typename T>
struct unique_ptr {
    T *data;

    unique_ptr(T *data_)  : data(data_) {}

    unique_ptr(const unique_ptr&) = delete;

    unique_ptr& operator=(const unique_ptr&) = delete;

    unique_ptr(unique_ptr &&other) : data(other.data) {  // Or use std::exchange()
        other.data = nullptr;
    }

    unique_ptr& operator=(unique_ptr &&other) {
        if (this == &other) {
            return *this;
        }
        data = other.data;
        other.data = nullptr;
        return *this;
    }

    ~unique_ptr() {
        delete data;
    }
};

unique_ptr<int> foo(unique_ptr<int> x) {
    return x;
}

int main() {
    foo(unique_ptr<int>(new int{10}));

    unique_ptr<int> x(new int{10});
    unique_ptr<int> y = std::move(x);
//    foo(static_cast<unique_ptr<int>&&>(y));
    foo(std::move(y));
}
