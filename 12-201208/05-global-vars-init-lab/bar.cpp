#include "main.h"
#include <iostream>

namespace {
struct TestRunner2 {
    TestRunner2() {
        std::cout << "TestRunner2() before\n";
        start_test("test2");
        std::cout << "TestRunner2() after\n";
    }
} test_runner_2;
}
