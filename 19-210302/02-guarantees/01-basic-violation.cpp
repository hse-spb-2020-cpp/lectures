struct VectorInt {
    int *data;
    int length;

    VectorInt(int n = 0)
        : data(n > 0 ? new int[n]() : nullptr)  // Осторожно: n == 0.
        , length(n)
    {
    }

    VectorInt(const VectorInt &other)
        : data(other.length > 0 ? new int[other.length] : nullptr)  // Осторожно: other.length == 0.
        , length(other.length)
    {
        for (int i = 0; i < length; i++)
            data[i] = other.data[i];
    }

    ~VectorInt() {
        delete[] data;  // Осторожно: delete[], а не delete.
    }

    VectorInt &operator=(const VectorInt &other) {
        if (this == &other) {  // Осторожно: иначе удалим данные, а потом новый массив просто скопируем сам в себя.
            return *this;
        }

        delete[] data;
        try {
            data = new int[other.length];  // Осторожно: может вылететь исключение. Надо сохранить инварианты про data/length.
        } catch (...) {
            data = nullptr;  // Иначе в деструкторе будет double free.
            length = 0;  // Иначе не сошлось: data == nullptr, но длина ненулевая. Это нарушение инварианта, все доказательства корректности нивелируются.
                         // Можно, конечно, переделать инвариант и всё передоказать...
            throw;
        }
        length = other.length;
        for (int i = 0; i < length; i++)
            data[i] = other.data[i];
        return *this;
    }
};

int main() {
    VectorInt vec(5);
    vec = vec;  // Злой тест.
}
