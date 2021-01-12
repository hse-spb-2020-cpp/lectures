#include <vector>
#include <iostream>

template<typename T>
void test() {
    std::vector<T> vec(100);

    std::cout << "==========\n";
    std::cout << vec[10] << "\n";
    {
        auto x = vec[10];  // Compiles with vector<bool>, but it's actually a reference.
        // typename std::vector<T>::value_type x = vec[10];  // Ok, but cumbersome.
        x = 1;
        std::cout << x << "\n";
    }
    std::cout << vec[10] << "\n";
    {
        //auto &x = vec[10];  // Does not compile with vector<bool>.
        auto &&x = vec[10];  // Compiles with all vectors, but WTF.
        // typename std::vector<T>::reference xx = vec[10];  // Ok, but cumbersome.
        x = 1;
        std::cout << x << "\n";
    }
    std::cout << vec[10] << "\n";
}

int main() {
    test<int>();
    test<bool>();
}
