#include <type_traits>

int main() {
    int x[10]{};
    const int cx[10]{};

    static_assert(std::is_same_v<int *, decltype(&x[0])>);
    {
        int *px = &x[0];
        px++;
        px--;
        *px = 10;
        px = nullptr;
    }
    {
        const int *px = &cx[0];
        px++;
        px--;
        // *px = 10;
        px = nullptr;
    }
    {
        int *const px = &x[0];
        // px++;
        // px--;
        *px = 10;
        // px = nullptr;
    }
    {
        const int *const px = &cx[0];
        // px++;
        // px--;
        // *px = 10;
        // px = nullptr;
    }

    {
        int *px = &x[0];
        const int *pcx = px;
        const int *const cpcx = px;
    }
    {
        int *const cpx = &x[0];
        const int *pcx = cpx;
        const int *const cpcx = cpx;
    }
    {
        const int *pcx = &cx[0];
        // int *const cpx = pcx;
        const int *const cpcx = pcx;
    }
}
