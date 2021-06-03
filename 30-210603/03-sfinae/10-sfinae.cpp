#include <cassert>
#include <vector>

/*
Substitution Failure Is Not An Error (SFINAE)

Стандартные шутки:
1. Segmentation Fault Is Not An Error
2. SFINAE отбивная

Нестандартные шутки:
3. Self-identification Failure Is Not An Error: https://twitter.com/ivn_finaev/status/1397975670173614080
*/

template<typename T>
void duplicate_element(T &container, typename T::iterator iter) {
    container.insert(iter, *iter);
}

template<typename T>
void duplicate_element(T *array, T *element) {
   assert(array != element);
   *(element - 1) = *element;
}

int main() {
    std::vector a{1, 2, 3};
    duplicate_element(a, a.begin() + 1);
    assert((a == std::vector{1, 2, 2, 3}));

    int b[] = {1, 2, 3};
    duplicate_element(b, b + 1);  // Нет ошибки, когда пробуем первую перегрузку: не бывает int[]::iterator, но это не ошибка компиляции. SFINAE.
    assert(b[0] == 2);
    assert(b[1] == 2);
    assert(b[2] == 3);
}
