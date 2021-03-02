#include <vector>

template<typename T>
struct stack {
    std::vector<T> data;

    T pop() {
        T result = std::move(data.back());
        data.pop_back();
        return result;
    }
};

int main() {
    stack<int> s;
    s.data = std::vector{1, 2, 3, 4, 5};

    int x = 10;
    x = s.pop();  // Если вылетело исключение в operator=, то 's' не может восстановить элемент.
                  // Снаружи не выглядит как строгая гарантия.
}
