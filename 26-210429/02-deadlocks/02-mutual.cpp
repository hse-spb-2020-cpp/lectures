#include <cassert>
#include <cstdlib>
#include <mutex>
#include <thread>

int main(int argc, char *argv[]) {
    assert(argc == 2);
    const int N = std::atoi(argv[1]);

    std::mutex m1, m2;
    std::thread t1([&]() {
        for (int i = 0; i < N; i++) {
            std::scoped_lock a(m1, m2);
        }
    });
    std::thread t2([&]() {
        for (int i = 0; i < N; i++) {
            std::scoped_lock b(m2, m1);
        }
    });
    // if (&m1 < &m2)  // UB
    // std::less<std::mutex*>()(&m1, &m2)  // OK
    // std::lock(....) <--- std::scoped_lock(....)
    t2.join();
    t1.join();
}
