#include <chrono>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

void calculate(int n) {
    const int inf = 1'000'000'000;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, inf));
    std::mt19937 gen;
    std::uniform_int_distribution distrib(0, 100000);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = distrib(gen);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                graph[j][k] = std::min(graph[j][i], graph[i][k]);
}

template<typename Fn, typename Arg0>
void timed(Fn fn, Arg0 arg0) {
    auto start = std::chrono::steady_clock::now();
    fn(std::move(arg0));
    auto duration = std::chrono::steady_clock::now() - start;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms\n";
}

int main() {
    timed(calculate, 500);
}
