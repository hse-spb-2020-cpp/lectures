template<typename T>
struct optional {
    alignas(T) char buf[sizeof(T)];
    bool created = false;

    T& value() { return reinterpret_cast<T&>(buf); }

    void reset() noexcept {
        if (created) {
            value().~T();
            created = false;
        }
    }

    ~optional() {
        reset();  // noexcept
    }

    // ....
    optional &operator=(const T &newobj) {
        reset();  // noexcept
        // created = true;  // Здесь располагать неправильно.
        // Пусть у копирующего конструктора T строгая гарантия исключений.
        new (&value()) T(newobj);
        created = true;  // Здесь располагать правильно.
        return *this;
    }
    // ....
};

int main() {
}
