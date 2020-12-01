template<typename T>
struct list_heap {
    #if 1
    // Вариант покороче.
    void push(T value) {
        list.push_back(std::move(value));
    }
    #else
    // Вариант пооптимальнее, будет на один move меньше при копировании.
    void push(const T& value) {
        list.push_back(value);
    }

    void push(T &&value) {
        list.push_back(std::move(value));
    }
    #endif

    // Всегда по ссылке, потому что нам не надо копировать внутрь это значение.
    bool contains(const T &value) {
        return std::find(....) != list.end();
    }
}
