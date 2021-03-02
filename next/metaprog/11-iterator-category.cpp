#include <iterator>
#include <iostream>
#include <vector>
#include <list>

// struct bidirectional_iterator_tag {};
// struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template<typename It>
void detect_iterator_impl(It it, std::bidirectional_iterator_tag) {
    std::cout << "bidirectional\n";
    it++; it--;
}

template<typename It>
void detect_iterator_impl(It it, std::random_access_iterator_tag) {
    std::cout << "random access\n";
    it += 1;
}

template<typename It>
void detect_iterator(It it) {
    detect_iterator_impl(it, typename std::iterator_traits<It>::iterator_category());
}

int main() {
    std::vector<int> v(10);
    std::list<int> l(10);
    std::istream_iterator<int> ii(std::cin);

    detect_iterator(v.begin());
    detect_iterator(l.begin());
    // detect_iterator(std::back_insert_iterator(v));
}
