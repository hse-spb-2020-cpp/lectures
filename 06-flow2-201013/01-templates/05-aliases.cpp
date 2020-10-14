#include <vector>

using vi1 = std::vector<int>;
typedef std::vector<int> vi2;

template<typename T>
using v = std::vector<T>;

template<typename T>
using i = typename T::iterator;

int main() {
    v<int> v2;
    i<v<int>> it1;
    v<int>::iterator it2;
}
