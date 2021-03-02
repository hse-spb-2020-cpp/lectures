#include <algorithm>

struct VectorInt {
    int *data;
    int length;

    VectorInt(int n = 0)
        : data(n > 0 ? new int[n]() : nullptr)
        , length(n)
    {
    }

    VectorInt(const VectorInt &other)
        : data(other.length > 0 ? new int[other.length] : nullptr)
        , length(other.length)
    {
        for (int i = 0; i < length; i++)
            data[i] = other.data[i];
    }

    ~VectorInt() {
        delete[] data;  // Осторожно: было delete.
    }

    VectorInt &operator=(const VectorInt &other) {
        if (this == &other) {
            return *this;
        }

        // Так можно добавить строгую гарантию в любую операцию,
        // где была базовая гарантия:
        //
        // 1. Сначала сделать всё, что может кидать исключения и
        //    создать новое состояние объекта.
        //    Старый объект вообще не меняем.
        VectorInt other_copy(other);

        // 2. Сделать swap(). Он исключений не кидает.
        std::swap(data, other_copy.data);
        std::swap(length, other_copy.length);
        return *this;
    }

#if 0
    void push_back(int x) & {
        // 1. Копируем (за линию, правда - упс).
        VectorInt new_vec(*this);
        new_vec.push_back_basic_guarantee(x);
        // new_vec.resize(new_vec.size() + 1);
        // new_vec[new_vec.size() - 1] = x;

        // 2. Меняемся местами.
        std::swap(data, new_vec.data);
        std::swap(length, new_vec.length);
    }
#endif
};

int main() {
    VectorInt vec(5);
    vec = vec;
}
