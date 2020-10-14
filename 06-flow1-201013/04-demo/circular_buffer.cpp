#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cassert>  // assert()
#include <cstddef>  // std::size_t
#include "doctest.h"

namespace lab_02 {

template <typename T, std::size_t MaxElements>
struct circular_buffer {
    bool empty() { return false; }
    std::size_t size() { return 0; }
};

namespace tests {
// ТЕСТЫ
//
// main() будет автоматически написан библиотекой doctest, запрещается его
// создавать самостоятельно. Библиотека запустит все тесты вида TEST_CASE() и
// проверит в них все условия CHECK(), не прерывая тест. Запрещается изменять
// или отключать существующие тесты, но вы можете дописывать новые в конец.

TEST_CASE("Empty circular_buffer") {
    circular_buffer<int, 5> buffer;
    CHECK(buffer.empty());
    CHECK(buffer.size() == 0);
}
#if 0
TEST_CASE("push_back(), front(), back()") {
    circular_buffer<int, 5> buffer;

    buffer.push_back(10);
    CHECK(buffer.front() == 10);
    CHECK(buffer.back() == 10);

    buffer.push_back(20);
    CHECK(buffer.front() == 10);
    CHECK(buffer.back() == 20);

    buffer.push_back(30);
    CHECK(buffer.front() == 10);
    CHECK(buffer.back() == 30);
}

TEST_CASE("push_back(), empty(), size()") {
    circular_buffer<int, 5> buffer;

    buffer.push_back(10);
    CHECK(!buffer.empty());
    CHECK(buffer.size() == 1);

    buffer.push_back(20);
    CHECK(!buffer.empty());
    CHECK(buffer.size() == 2);

    buffer.push_back(30);
    CHECK(!buffer.empty());
    CHECK(buffer.size() == 3);
}

TEST_CASE("push_back(), operator[]") {
    circular_buffer<int, 5> buffer;

    buffer.push_back(10);
    CHECK(buffer[0] == 10);

    buffer.push_back(20);
    CHECK(buffer[0] == 10);
    CHECK(buffer[1] == 20);

    buffer.push_back(30);
    CHECK(buffer[0] == 10);
    CHECK(buffer[1] == 20);
    CHECK(buffer[2] == 30);
}

TEST_CASE("modifying values") {
    circular_buffer<int, 5> buffer;
    buffer.push_back(10);

    buffer.front() = 20;
    CHECK(buffer.front() == 20);
    CHECK(buffer.back() == 20);
    CHECK(buffer[0] == 20);

    buffer.back() = 30;
    CHECK(buffer.front() == 30);
    CHECK(buffer.back() == 30);
    CHECK(buffer[0] == 30);

    buffer[0] = 40;
    CHECK(buffer.front() == 40);
    CHECK(buffer.back() == 40);
    CHECK(buffer[0] == 40);
}

TEST_CASE("const circular_buffer") {
    circular_buffer<int, 5> buffer;
    buffer.push_back(10);

    const auto &const_buffer = buffer;
    CHECK(!const_buffer.empty());
    CHECK(const_buffer.size() == 1);
    CHECK(const_buffer.front() == 10);
    CHECK(const_buffer.back() == 10);
    CHECK(const_buffer[0] == 10);
}

TEST_CASE("push_front(), front(), back()") {
    circular_buffer<int, 5> buffer;

    buffer.push_front(10);
    CHECK(buffer.front() == 10);
    CHECK(buffer.back() == 10);

    buffer.push_front(20);
    CHECK(buffer.front() == 20);
    CHECK(buffer.back() == 10);

    buffer.push_front(30);
    CHECK(buffer.front() == 30);
    CHECK(buffer.back() == 10);
}

TEST_CASE("push_front(), empty(), size()") {
    circular_buffer<int, 5> buffer;

    buffer.push_front(10);
    CHECK(!buffer.empty());
    CHECK(buffer.size() == 1);

    buffer.push_front(20);
    CHECK(!buffer.empty());
    CHECK(buffer.size() == 2);

    buffer.push_front(30);
    CHECK(!buffer.empty());
    CHECK(buffer.size() == 3);
}

TEST_CASE("push_back followed by pop_back") {
    circular_buffer<int, 5> buffer;
    buffer.push_back(10);
    buffer.pop_back();
    CHECK(buffer.empty());
    CHECK(buffer.size() == 0);
}

TEST_CASE("push_back followed by pop_front") {
    circular_buffer<int, 5> buffer;
    buffer.push_back(10);
    buffer.pop_front();
    CHECK(buffer.empty());
    CHECK(buffer.size() == 0);
}

TEST_CASE("comparison operators") {
    circular_buffer<int, 5> buf_a;
    circular_buffer<int, 6> buf_b;
    circular_buffer<int, 7> buf_c;
    buf_a.push_back(10);
    buf_b.push_back(10);

    CHECK(buf_a == buf_a);

    CHECK(buf_b == buf_b);

    CHECK(buf_a == buf_b);
    CHECK(buf_b == buf_a);

    CHECK(buf_a != buf_c);
    CHECK(buf_c != buf_a);

    CHECK(buf_b != buf_c);
    CHECK(buf_c != buf_b);
}

TEST_CASE("custom struct inside") {
    struct Foo {
        int data = 0;
    };
    circular_buffer<Foo, 5> buffer;

    buffer.push_back(Foo{123});

    CHECK(!buffer.empty());
    CHECK(buffer.size() == 1);

    CHECK(buffer.front().data == 123);
    CHECK(buffer.back().data == 123);
    CHECK(buffer[0].data == 123);

    buffer.pop_back();
}

TEST_CASE("comparison only uses operator==") {
    struct Foo {
        bool operator==(const Foo &) const {
            return true;
        }
    };
    circular_buffer<Foo, 5> buffer;
    CHECK(buffer == buffer);
}
#endif

}  // namespace tests
}  // namespace lab_02

TEST_CASE("in correct namespace") {
    [[maybe_unused]] lab_02::circular_buffer<int, 5> buffer;
}
