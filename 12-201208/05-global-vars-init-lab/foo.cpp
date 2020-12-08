#include "main.h"
#include <iostream>

namespace {
struct TestRunner1 {
    TestRunner1() {
        std::cout << "TestRunner1() before\n";
        start_test("test1");
        std::cout << "TestRunner1() after\n";
    }
} test_runner_1;
}
