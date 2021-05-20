#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    struct {
        int state = 100;
        void operator()(int value) {
            std::cout << "state=" << state << ", value=" << value << "\n";
            state++;
        }
    } functor;

    std::vector<int> vec{10, 20, 30};
    std::for_each(vec.begin(), vec.end(), functor);
    std::cout << functor.state << "\n";
    std::for_each(vec.begin(), vec.end(), std::ref(functor));
    std::cout << functor.state << "\n";
}
