#include <mutex>

struct atomic_int {
    int get() const {
        std::unique_lock l(m);
        return value;
    }

    void set(int new_value) {
        std::unique_lock l(m);
        value = new_value;
    }

private:
    mutable std::mutex m;  // Можно менять даже в const-qualified методах.
    int value;
};

int main() {
}
