#include <iostream>
#include <vector>

struct err1 {};
struct err2 {};

int main() {
    try {
        std::vector<int> vec(-1);
    } catch (const err1 &) {
        std::cout << "1\n";
    } catch (const err2 &) {
        std::cout << "2\n";
    } catch (...) {
        std::cout << "3\n";
    }
}
