#include <cstddef>
#include <vector>
#include <iostream>

struct invalid_vector_format {};

std::vector<int> readVector() {
    int n;
    if (!(std::cin >> n)) {
        throw invalid_vector_format();
    }
    std::vector<int> result(n); // может кинуть исключение.
    for (int i = 0; i < n; i++) {
        if (!(std::cin >> result[i])) {
            throw invalid_vector_format(); // кинул исключение, знаем, что кто-нибудь поймает.
        }
    }
    return result;
}

void writeAnswer(const std::vector<int> &vec) {
    for (std::size_t i = 0; i < vec.size(); i++) {
        if (i) std::cout << " ";
        std::cout << vec[i];
    }
    std::cout << "\n";
}

void solve() {
    std::vector<int> a = readVector();
    std::vector<int> b = readVector();  // исключение пролетело насквозь
    
    // Тут какие-то вычисления
    std::vector<int> answer = a;
    answer.insert(answer.end(), b.begin(), b.end());

    writeAnswer(answer);
}

int main() {
    try {
        solve(); // исключение пролетело насквозь
    } catch (const invalid_vector_format &err) {
        std::cout << "Invalid vector format\n";
    }
}
