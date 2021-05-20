#include <functional>
#include <iostream>
#include <thread>
#include <vector>

void worker(int x, int &y, const std::vector<int> &z) {
    std::cout << x << " " << y << " " << z.size() << "\n";
    y += 5;
}

// std::ref(T t) --> std::reference_wrapper<T> (хранит T*)
// неявно конвертируется в T&

int main() {
    int y = 20;
    std::vector<int> z(1'000'000);
    std::thread t(worker, 10, std::ref(y), std::cref(z));  // Если z передать без ref/cref, то скопируется.
    t.join();
    std::cout << y << "\n";
}
