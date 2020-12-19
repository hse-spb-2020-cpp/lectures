std::pair<int, double> foo() {
    return {10, 20.5};
}

int main() {
    {
        int x = 10;
        auto &y = x, &z = x;
    }

    // structured binding (C++17)
    {
//        std::pair<int, double> p = foo();
//        int a = p.first;
//        double b = p.second;
        auto [a, b] = foo();
        std::cout << p.first << "\n";
        std::cout << p.second << "\n";
    }

    {
        int arr[3] = {1, 2, 3};
        auto [x, y, z] = arr;
    }

    {
        std::tuple<int, int, double, int, double>
        struct Point { int x, y; };
        auto [x1, y1] = Point{10, 20};
    }
}
