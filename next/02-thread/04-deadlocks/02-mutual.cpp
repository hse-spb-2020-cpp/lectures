#include <mutex>
#include <thread>

const int N = 10'000;

int main() {
    std::mutex m1, m2;
    std::thread t1([&]() {
        for (int i = 0; i < N; i++) {
            std::unique_lock a(m1);
            std::unique_lock b(m2);
        }
    });
    std::thread t2([&]() {
        for (int i = 0; i < N; i++) {
            std::unique_lock a(m2);
            std::unique_lock b(m1);
        }
    });
    t2.join();
    t1.join();
}
